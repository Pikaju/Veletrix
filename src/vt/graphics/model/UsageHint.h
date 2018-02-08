#pragma once

#include "../../Build.h"
#include "../../PrimitiveTypes.h"

namespace vt {

	enum UsageHint {
		// The data is set once and used many times.
		USAGE_HINT_STATIC,
		// The data is set and used many times.
		USAGE_HINT_DYNAMIC,
		// The data is set and used once.
		USAGE_HINT_STREAM
	};

	namespace usagehint {

		// Returns the OpenGL constant for the given usage hint.
		extern VT_API i32 getGLUsageHint(UsageHint usageHint);

	}

}