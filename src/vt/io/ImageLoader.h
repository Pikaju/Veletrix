#pragma once

#include "../Build.h"
#include "../Types.h"

namespace vt {

	class GLTexture;
	enum Format;
	enum Filter;
	enum AnisotropicFiltering;
	enum Wrapping;

	namespace io {

		extern VT_API GLTexture loadGLTexture(cString file, const Filter& filter, const AnisotropicFiltering& anisotropicFiltering, const Wrapping& wrapping);
		extern VT_API void loadImage(cString file, ui8** data, ui32f* width, ui32f* height, Format* format);

	}
}