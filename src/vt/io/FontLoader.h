#pragma once

#include "../Build.h"
#include "../PrimitiveTypes.h"

#include "../graphics/text/Font.h"
#include "../graphics/text/UnpackedFont.h"

namespace vt {
	namespace io {

		extern VT_API void loadGLFont(Font& font, ui16f fontSize, cString file, i32 index = 0);
		extern VT_API void loadGLFontUnpacked(UnpackedFont& font, ui16f fontSize, cString file, i32 index = 0);

	}
}