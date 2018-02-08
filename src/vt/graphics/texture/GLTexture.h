#pragma once

#include "Texture.h"

namespace vt {

	class VT_API GLTexture : public Texture
	{
	public:
		GLTexture();
		~GLTexture();

		void initialize() override;
		void cleanup() override;

		void setData(ui32f width, ui32f height, Filter filter) override;
		void setData(const ui8* pixels, ui32f width, ui32f height, Format format, Filter filter, AnisotropicFiltering anisotropicFiltering, Wrapping wrapping) override;

		void enable(ui32 slot) const override;
		void disable(ui32 slot) const override;

		static ui32f getMaxTextureSize();
	private:
		ui32 m_texture;
	};

}