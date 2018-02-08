#include "GraphicsAPI.h"

#include "../../glfw/include/GLFW/glfw3.h"
#include <SDL/SDL.h>

#include "../debug/Exception.h"

#ifdef VT_VISUAL_C_PLUS_PLUS
	#ifdef VT_GRAPHICS_OPENGL
		#pragma comment(lib, "opengl32.lib")
	#endif

	#ifdef VT_GRAPHICS_SDL
		#ifdef VT_ENVIRONMENT_32
			#pragma comment(lib, "x86/SDL/SDL2.lib")
			#pragma comment(lib, "x86/SDL/SDL2main.lib")
		#else
			#pragma comment(lib, "x64/SDL/SDL2.lib")
			#pragma comment(lib, "x64/SDL/SDL2main.lib")
		#endif
	#endif
#endif

namespace vt {
	namespace graphics {

		GraphicsAPI api;

		void initialize(const GraphicsAPI& api)
		{
			switch (api) {
#ifdef VT_GRAPHICS_GLFW
			case GRAPHICS_GLFW:
				if (!glfwInit()) {
					log::fatal("Could not initialize GLFW");
					exception::crash();
				}
				break;
#endif
#ifdef VT_GRAPHICS_SDL
			case GRAPHICS_SDL:
				if (SDL_Init(SDL_INIT_VIDEO) != 0) {
					log::fatal("Could not initialize SDL");
					exception::crash();
				}
				break;
#endif
			default:
				log::fatal("Invalid graphics API: ", api);
				exception::crash();
			}
			graphics::api = api;
		}
		
		void cleanup()
		{
			switch (api) {
#ifdef VT_GRAPHICS_GLFW
			case GRAPHICS_GLFW:
				glfwTerminate();
				break;
#endif
#ifdef VT_GRAPHICS_SDL
			case GRAPHICS_SDL:
				SDL_Quit();
				break;
#endif
			default:
				log::fatal("Invalid graphics API: ", api);
				exception::crash();
			}
		}

		const GraphicsAPI& getAPI()
		{
			return api;
		}

	}
}