#pragma once

#include "GLRenderer.h"
#include "../model/Primitive.h"

namespace vt {

	class VT_API GLAttributelessRenderer : public GLRenderer
	{
	public:
		GLAttributelessRenderer();
		~GLAttributelessRenderer();

		// Executes a draw call using the given primitive and vertex count without
		// sending any attributes to the GPU.
		void render(Primitive primitive, ui32f vertexCount) const;
	};

}