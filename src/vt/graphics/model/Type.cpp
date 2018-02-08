#include "Type.h"

#include "../../../glad/glad.h"
#include "../../io/Console.h"

namespace vt {
	namespace type {

		ui32 getGLType(const Type& type)
		{
			switch (type) {
			case TYPE_FLOAT: return GL_FLOAT; break;
			case TYPE_DOUBLE: return GL_DOUBLE; break;
			case TYPE_UNSIGNED_BYTE: return GL_UNSIGNED_BYTE; break;
			case TYPE_UNSIGNED_SHORT: return GL_UNSIGNED_SHORT; break;
			case TYPE_UNSIGNED_INT: return GL_UNSIGNED_INT; break;
			default: log::error("Invalid type: ", type); break;
			}
			return 0;
		}

		ui32 getGLTypeSize(const Type& type)
		{
			switch (type) {
			case TYPE_FLOAT: return sizeof(GLfloat); break;
			case TYPE_DOUBLE: return sizeof(GLdouble); break;
			case TYPE_UNSIGNED_BYTE: return sizeof(GLubyte); break;
			case TYPE_UNSIGNED_SHORT: return sizeof(GLushort); break;
			case TYPE_UNSIGNED_INT: return sizeof(GLuint); break;
			default: log::error("Invalid type: ", type); break;
			}
			return 0;
		}

	}
}