#include "Primitive.h"

#include "../../../glad/glad.h"
#include "../../io/Console.h"

namespace vt {
	namespace primitive {

		ui32 getGLPrimitive(const Primitive& primitive)
		{
			switch (primitive) {
			case PRIMITIVE_POINT: return GL_POINTS; break;
			case PRIMITIVE_LINE: return GL_LINES; break;
			case PRIMITIVE_LINE_STRIP: return GL_LINE_STRIP; break;
			case PRIMITIVE_LINE_LOOP: return GL_LINE_LOOP; break;
			case PRIMITIVE_TRIANGLE: return GL_TRIANGLES; break;
			case PRIMITIVE_TRIANGLE_STRIP: return GL_TRIANGLE_STRIP; break;
			case PRIMITIVE_TRIANGLE_FAN: return GL_TRIANGLE_FAN; break;
			default: log::error("Invalid primitive: ", primitive); break;
			}
			return 0;
		}

	}
}