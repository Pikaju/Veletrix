#include "UsageHint.h"

#include "../../../glad/glad.h"

namespace vt {
	namespace usagehint {

		VT_API i32 getGLUsageHint(UsageHint usageHint)
		{
			switch (usageHint) {
			case USAGE_HINT_STATIC: return GL_STATIC_DRAW; break;
			case USAGE_HINT_DYNAMIC: return GL_DYNAMIC_DRAW; break;
			case USAGE_HINT_STREAM: return GL_STREAM_DRAW; break;
			}
			return 0;
		}

	}
}

