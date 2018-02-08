#include "Window.h"

#include "GLFWWindow.h"
#include "SDLWindow.h"

#include "../GraphicsAPI.h"

namespace vt {

	Window* Window::create()
	{
		switch (graphics::getAPI()) {
#ifdef VT_GRAPHICS_GLFW
		case GRAPHICS_GLFW: return new GLFWWindow(); break;
#endif
#ifdef VT_GRAPHICS_SDL
		case GRAPHICS_SDL: return new SDLWindow(); break;
#endif
		}
		return nullptr;
	}

}