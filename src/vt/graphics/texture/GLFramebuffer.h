#pragma once

#include <vector>

#include "../../Build.h"
#include "Attachment.h"
#include "Format.h"

namespace vt {

	class VT_API GLFramebuffer
	{
	public:
		GLFramebuffer();
		~GLFramebuffer();

		void initialize(ui32f width, ui32f height, ui8f numTextures, const Attachment* attachments, const Format* formats, unsigned int numSamples = 0);
		void cleanup();

		void bind() const;
		void use(ui32 texture = 0, ui32 slot = 0) const;

		void blit(const GLFramebuffer& target);

		inline ui32f getWidth() const { return m_width; }
		inline ui32f getHeight() const { return m_height; }
		inline f32 getAspectRatio() const { return static_cast<f32>(m_width) / static_cast<f32>(m_height); }
		inline ui8f getNumTextures() const { return m_numTextures; }
	private:
		ui32f m_width;
		ui32f m_height;

		ui32* m_textures;
		ui8f m_numTextures;
		ui32 m_framebuffer;

		ui8f m_numColorAttachments;

		ui8f m_numSamples;
	};

}