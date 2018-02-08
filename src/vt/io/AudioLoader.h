#pragma once

#include "../Build.h"
#include "../Types.h"

namespace vt {
	namespace io {

		extern VT_API void loadWAV(cString file, ui16f* numChannels, ui16f* bitsPerSample, ui8** data, i32* size, i32* frequency);

	}
}