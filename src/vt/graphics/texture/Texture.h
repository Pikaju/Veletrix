#pragma once

#include "Format.h"
#include "Filter.h"
#include "AnisotropicFiltering.h"
#include "Wrapping.h"
#include "../../Build.h"

namespace vt {

	class VT_API Texture
	{
	public:
		VT_CONSTEXPR Texture() : m_width(0), m_height(0) {  }
		virtual ~Texture() {  }

		virtual void initialize() = 0;
		virtual void cleanup() = 0;

		virtual void setData(ui32f width, ui32f height, Filter filter) = 0;
		virtual void setData(const ui8* pixels, ui32f width, ui32f height, Format format, Filter filter, AnisotropicFiltering anisotropicFiltering, Wrapping wrapping) = 0;

		virtual void enable(ui32 slot) const = 0;
		virtual void disable(ui32 slot) const = 0;

		inline ui32f getWidth() const { return m_width; }
		inline ui32f getHeight() const { return m_height; }
	protected:
		ui32f m_width;
		ui32f m_height;
	};

}