#pragma once

#include "../Build.h"

#define VT_GRAPHICS_OPENGL

#ifdef VT_GRAPHICS_OPENGL
	#define VT_GRAPHICS_GLFW
	//#define VT_GRAPHICS_SDL
#endif

namespace vt {

	enum GraphicsAPI
	{
		GRAPHICS_GLFW, GRAPHICS_SDL
	};

	namespace graphics {

		extern VT_API void initialize(const GraphicsAPI& api);
		extern VT_API void cleanup();
		extern VT_API const GraphicsAPI& getAPI();

	}
}