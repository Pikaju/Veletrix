#include "Build.h"

#include "Veletrix.h"
#include "debug/Exception.h"
#include "graphics/GraphicsAPI.h"
#include "memory/Heap.h"

#ifdef VT_GRAPHICS_SDL
#include <SDL/SDL_main.h>
int SDL_main(int argc, char** agrv)
{
	vt::initialize();
	vtmain();
	vt::cleanup();
	return 0;
}
#else
int main(int agrc, char** argv)
{
	vt::initialize();
	vtmain();
	vt::cleanup();
}
#endif

namespace vt {

	void runtimeAssert(bool condition)
	{
		if (!condition) {
			vt::log::fatal("Assertion failed");
			vt::exception::crash();
		}
	}

	void runtimeAssert(bool condition, const char* message)
	{
		if (!condition) {
			vt::log::fatal("Assertion failed: ", message);
			vt::exception::crash();
		}
	}

}