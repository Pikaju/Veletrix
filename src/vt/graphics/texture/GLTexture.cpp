#include "GLTexture.h"

#include "../../../glad/glad.h"

#include "Format.h"

namespace vt {

	GLTexture::GLTexture() : m_texture(0)
	{
	}

	GLTexture::~GLTexture()
	{
	}

	void GLTexture::initialize()
	{
		glGenTextures(1, &m_texture);
	}

	void GLTexture::cleanup()
	{
		glDeleteTextures(1, &m_texture);
	}

	void GLTexture::setData(ui32f width, ui32f height, Filter filter)
	{
		m_width = width;
		m_height = height;
		setData(nullptr, width, height, FORMAT_RGB8, filter, ANISOTROPIC_FILTERING_NONE, WRAPPING_CLAMP);
	}

	void GLTexture::setData(const ui8* pixels, ui32f width, ui32f height, Format format, Filter filter, AnisotropicFiltering anisotropicFiltering, Wrapping wrapping)
	{

		m_width = width;
		m_height = height;
		enable(0);
		switch (filter) {
		case FILTER_NEAREST:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			break;
		case FILTER_LINEAR:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			break;
		case FILTER_NEAREST_MIPMAP_NEAREST:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			break;
		case FILTER_LINEAR_MIPMAP_NEAREST:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			break;
		case FILTER_NEAREST_MIPMAP_LINEAR:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			break;
		case FILTER_LINEAR_MIPMAP_LINEAR:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			break;
		}

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapping == WRAPPING_CLAMP ? GL_CLAMP_TO_EDGE : GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapping == WRAPPING_CLAMP ? GL_CLAMP_TO_EDGE : GL_REPEAT);

		glPixelStorei(GL_UNPACK_ALIGNMENT, format::getGLAlignment(format));

		glTexImage2D(GL_TEXTURE_2D, 0, format::getGLInternalFormat(format), m_width, m_height, 0, format::getGLFormat(format), format::getGLType(format), pixels);
		if (filter >= FILTER_NEAREST_MIPMAP_NEAREST) {
			glGenerateMipmap(GL_TEXTURE_2D);
			f32 anisotropicFilteringLevel = 0.0f;
			switch (anisotropicFiltering) {
			case ANISOTROPIC_FILTERING_2: anisotropicFilteringLevel = 2.0f; break;
			case ANISOTROPIC_FILTERING_4: anisotropicFilteringLevel = 4.0f; break;
			case ANISOTROPIC_FILTERING_8: anisotropicFilteringLevel = 8.0f; break;
			case ANISOTROPIC_FILTERING_16: anisotropicFilteringLevel = 16.0f; break;
			case ANISOTROPIC_FILTERING_32: anisotropicFilteringLevel = 32.0f; break;
			}
			f32 maxAnisotropicFilteringLevel;
			glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropicFilteringLevel);
			if (anisotropicFilteringLevel > maxAnisotropicFilteringLevel) {
				anisotropicFilteringLevel = maxAnisotropicFilteringLevel;
			}
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, anisotropicFilteringLevel);
		}
	}

	void GLTexture::enable(ui32 slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_texture);
	}

	void GLTexture::disable(ui32 slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	ui32f GLTexture::getMaxTextureSize()
	{
		i32 size;
		glGetIntegerv(GL_MAX_TEXTURE_SIZE, &size);
		return size;
	}


}