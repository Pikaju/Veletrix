#pragma once

#include "UnpackedFont.h"

namespace vt {

	class GLShaderProgram;

	class VT_API GLUnpackedTextRenderer
	{
	public:
		static void renderText(const UnpackedFont& font, const GLShaderProgram& shader, cString text, f32 x, f32 y);
	};

}