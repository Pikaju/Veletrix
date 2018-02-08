#pragma once

#include "../../Types.h"

namespace vt {

	enum Primitive
	{
		// Each vertex is rendered seperately as a point.
		PRIMITIVE_POINT,
		// The vertices are treated as pairs, each pair is connected by a line.
		PRIMITIVE_LINE,
		// Each vertex is connected by a line to its successor.
		PRIMITIVE_LINE_STRIP,
		// Each vertex is connected by a line to its successor.
		// The first and last vertex are also connected by a line.
		PRIMITIVE_LINE_LOOP,
		// Three vertices make up a triangle.
		PRIMITIVE_TRIANGLE,
		// Each vertex is connected to the previous 2 vertices to make a triangle.
		PRIMITIVE_TRIANGLE_STRIP,
		// Each vertex is connected to the previous and the first vertex to make a triangle.
		PRIMITIVE_TRIANGLE_FAN
	};

	namespace primitive {

		extern ui32 getGLPrimitive(const Primitive& primitive);

	}
}