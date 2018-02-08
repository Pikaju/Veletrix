#include "GLAttributelessRenderer.h"

#include "../../../glad/glad.h"

namespace vt {

	GLAttributelessRenderer::GLAttributelessRenderer()
	{
	}

	GLAttributelessRenderer::~GLAttributelessRenderer()
	{
	}

	void GLAttributelessRenderer::render(Primitive primitive, ui32f vertexCount) const
	{
		glDrawArrays(primitive::getGLPrimitive(primitive), 0, vertexCount);
	}

}