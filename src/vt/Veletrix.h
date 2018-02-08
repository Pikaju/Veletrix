#pragma once

#include "Build.h"

namespace vt {

	// Initializes the Veletrix Engine. Is called in the before the vtmain function.
	extern VT_API void initialize();

	// Cleans up the engine. Is called in the after the vtmain function.
	extern VT_API void cleanup();

}