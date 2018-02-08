#include "GLFramebufferCubeMap.h"

#include "../../../glad/glad.h"
#include "../../io/Console.h"

namespace vt {

	GLFramebufferCubeMap::GLFramebufferCubeMap() : m_width(0), m_height(0), m_textures(nullptr), m_numTextures(0), m_framebuffer(0), m_drawBuffers()
	{
	}

	GLFramebufferCubeMap::~GLFramebufferCubeMap()
	{
	}

	void GLFramebufferCubeMap::initialize(ui32f width, ui32f height, ui8f numTextures, const Attachment* attachments, const Format* formats)
	{
		m_width = width;
		m_height = height;
		m_numTextures = numTextures;
		m_textures = new ui32[m_numTextures];
		glGenTextures(m_numTextures, m_textures);

		ui32 textureType = GL_TEXTURE_CUBE_MAP;

		for (ui8f i = 0; i < m_numTextures; i++) {
			glBindTexture(textureType, m_textures[i]);
			glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, attachments[i] == ATTACHMENT_COLOR ? GL_LINEAR : GL_LINEAR);
			glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, attachments[i] == ATTACHMENT_COLOR ? GL_LINEAR : GL_LINEAR);
			glTexParameteri(textureType, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(textureType, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(textureType, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
			if (formats[i] >= FORMAT_SHADOW16_NEAREST) {
				glTexParameteri(textureType, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
				glTexParameteri(textureType, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
				glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, formats[i] >= FORMAT_SHADOW16_LINEAR ? GL_LINEAR : GL_NEAREST);
				glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, formats[i] >= FORMAT_SHADOW16_LINEAR ? GL_LINEAR : GL_NEAREST);
			}
			else {
				glTexParameteri(textureType, GL_TEXTURE_COMPARE_MODE, GL_NONE);
			}

			for (ui32 j = 0; j < 6; j++) {
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + j, 0, format::getGLInternalFormat(formats[i]), m_width, m_height, 0, format::getGLFormat(formats[i]), format::getGLType(formats[i]), nullptr);
			}
		}

		glGenFramebuffers(1, &m_framebuffer);
		glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);

		ui8f numColorAttachments = 0;
		for (ui8f i = 0; i < m_numTextures; i++) {
			m_drawBuffers.push_back(attachment::getGLAttachment(attachments[i], numColorAttachments));
			glFramebufferTexture2D(GL_FRAMEBUFFER, m_drawBuffers[i], GL_TEXTURE_CUBE_MAP_POSITIVE_X, m_textures[i], 0);
			if (attachments[i] == ATTACHMENT_DEPTH) {
				m_drawBuffers[i] = GL_NONE;
			}
			if (attachments[i] == ATTACHMENT_COLOR) {
				numColorAttachments++;
			}
		}

		glDrawBuffers(static_cast<i32>(m_drawBuffers.size()), m_drawBuffers.data());

		numColorAttachments = 0;
		for (ui8f i = 0; i < m_numTextures; i++) {
			m_drawBuffers[i] = attachment::getGLAttachment(attachments[i], numColorAttachments);
		}

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
			log::error("Failed to create framebuffer");
		}
	}

	void GLFramebufferCubeMap::cleanup()
	{
		glDeleteTextures(m_numTextures, m_textures);
		glDeleteFramebuffers(1, &m_framebuffer);
		delete[] m_textures;
	}

	void GLFramebufferCubeMap::bind(ui32 face) const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
		
		for (unsigned int i = 0; i < m_numTextures; i++) {
			glFramebufferTexture2D(GL_FRAMEBUFFER, m_drawBuffers[i], GL_TEXTURE_CUBE_MAP_POSITIVE_X + face, m_textures[i], 0);
		}

		glViewport(0, 0, m_width, m_height);
	}

	void GLFramebufferCubeMap::use(ui32 texture, ui32 slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_textures[texture]);
	}

}