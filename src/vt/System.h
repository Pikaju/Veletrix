#pragma once

#include "Build.h"

namespace vt {
	namespace system {

		// Returns true if the current system uses big endian integers.
		extern VT_API bool isBigEndianInteger();
		// Returns true if the current system uses big endian floats.
		extern VT_API bool isBigEndianFloat();

		// Returns true if the current system uses little endian integers.
		inline bool isLittleEndianInteger() { return !isBigEndianInteger(); }
		// Returns true if the current system uses little endian floats.
		inline bool isLittleEndianFloat() { return !isBigEndianFloat(); }

	}
}