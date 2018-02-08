#include "GLFramebuffer.h"

#include "../../../glad/glad.h"
#include "../../io/Console.h"

namespace vt {

	GLFramebuffer::GLFramebuffer() : m_width(0), m_height(0), m_textures(nullptr), m_numTextures(0), m_framebuffer(0), m_numColorAttachments(0), m_numSamples(0)
	{
	}
	
	GLFramebuffer::~GLFramebuffer()
	{
	}

	void GLFramebuffer::initialize(ui32f width, ui32f height, ui8f numTextures, const Attachment* attachments, const Format* formats, unsigned int numSamples)
	{
		m_width = width;
		m_height = height;
		m_numTextures = numTextures;
		m_numSamples = numSamples;
		m_numColorAttachments = 0;
		m_textures = new ui32[m_numTextures];
		glGenTextures(m_numTextures, m_textures);
		
		ui32 textureType = m_numSamples != 0 ? GL_TEXTURE_2D_MULTISAMPLE : GL_TEXTURE_2D;

		for (ui8f i = 0; i < m_numTextures; i++) {
			glBindTexture(textureType, m_textures[i]);
			glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, attachments[i] == ATTACHMENT_COLOR ? GL_LINEAR : GL_NEAREST);
			glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, attachments[i] == ATTACHMENT_COLOR ? GL_LINEAR : GL_NEAREST);
			glTexParameteri(textureType, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(textureType, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			if (formats[i] >= FORMAT_SHADOW16_NEAREST) {
				glTexParameteri(textureType, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
				glTexParameteri(textureType, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
				glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, formats[i] >= FORMAT_SHADOW16_LINEAR ? GL_LINEAR : GL_NEAREST);
				glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, formats[i] >= FORMAT_SHADOW16_LINEAR ? GL_LINEAR : GL_NEAREST);
			}
			else {
				glTexParameteri(textureType, GL_TEXTURE_COMPARE_MODE, GL_NONE);
			}
			if (textureType == GL_TEXTURE_2D_MULTISAMPLE) {
				glEnable(GL_MULTISAMPLE);
				glTexImage2DMultisample(textureType, m_numSamples, format::getGLInternalFormat(formats[i]), m_width, m_height, false);
			}
			else {
				glTexImage2D(textureType, 0, format::getGLInternalFormat(formats[i]), m_width, m_height, 0, format::getGLFormat(formats[i]), format::getGLType(formats[i]), nullptr);
			}
		}

		glGenFramebuffers(1, &m_framebuffer);
		glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
		std::vector<ui32> drawBuffers;

		for (ui8f i = 0; i < m_numTextures; i++) {
			drawBuffers.push_back(attachment::getGLAttachment(attachments[i], m_numColorAttachments));
			glFramebufferTexture(GL_FRAMEBUFFER, drawBuffers.back(), m_textures[i], 0);
			if (attachments[i] == ATTACHMENT_DEPTH) {
				drawBuffers[i] = GL_NONE;
			}
			if (attachments[i] == ATTACHMENT_COLOR) {
				m_numColorAttachments++;
			}
		}
		glDrawBuffers(static_cast<i32>(drawBuffers.size()), drawBuffers.data());

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
			log::error("Failed to create framebuffer");
		}
	}

	void GLFramebuffer::cleanup()
	{
		glDeleteTextures(m_numTextures, m_textures);
		glDeleteFramebuffers(1, &m_framebuffer);
		delete[] m_textures;
	}

	void GLFramebuffer::bind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
		glViewport(0, 0, m_width, m_height);
	}

	void GLFramebuffer::use(ui32 texture, ui32 slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_textures[texture]);
	}

	void GLFramebuffer::blit(const GLFramebuffer& target)
	{
		glBindFramebuffer(GL_READ_FRAMEBUFFER, m_framebuffer);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, target.m_framebuffer);
		for (ui32 i = 0; i < m_numColorAttachments; i++) {
			glReadBuffer(GL_COLOR_ATTACHMENT0 + i);
			glDrawBuffer(GL_COLOR_ATTACHMENT0 + i);
			glBlitFramebuffer(0, 0, m_width, m_height, 0, 0, target.m_width, target.m_height, GL_COLOR_BUFFER_BIT, GL_NEAREST);
		}
		glBlitFramebuffer(0, 0, m_width, m_height, 0, 0, target.m_width, target.m_height, GL_DEPTH_BUFFER_BIT, GL_NEAREST);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

}