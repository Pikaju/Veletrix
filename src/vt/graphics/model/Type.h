#pragma once

#include "../../Types.h"

namespace vt {

	enum Type
	{
		TYPE_FLOAT,
		TYPE_DOUBLE,
		TYPE_UNSIGNED_BYTE,
		TYPE_UNSIGNED_SHORT,
		TYPE_UNSIGNED_INT,

		TYPE_UNKOWN
	};

	namespace type {

		extern ui32 getGLType(const Type& type);
		extern ui32 getGLTypeSize(const Type& type);

	}
}