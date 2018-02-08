#pragma once

#include "../Build.h"
#include "../Types.h"

#include "../graphics/texture/Format.h"

namespace vt {
	namespace io {

		extern VT_API void savePNG(cString file, const ui8* data, ui32f width, ui32f height, const Format& format);
		extern VT_API void saveBMP(cString file, const ui8* data, ui32f width, ui32f height, const Format& format);

	}
}