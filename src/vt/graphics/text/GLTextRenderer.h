#pragma once

#include "Font.h"

namespace vt {

	class GLShaderProgram;

	class VT_API GLTextRenderer
	{
	public:
		static void renderText(const Font& font, const GLShaderProgram& shader, cString text, f32 x, f32 y);
	};

}