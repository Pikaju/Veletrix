#pragma once

#include <vector>

#include "../../Build.h"
#include "Attachment.h"
#include "Format.h"

namespace vt {

	class VT_API GLFramebufferCubeMap
	{
	public:
		GLFramebufferCubeMap();
		~GLFramebufferCubeMap();

		void initialize(ui32f width, ui32f height, ui8f numTextures, const Attachment* attachments, const Format* formats);
		void cleanup();

		void bind(ui32 face) const;
		void use(ui32 texture = 0, ui32 slot = 0) const;

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

		std::vector<ui32> m_drawBuffers;
	};

}