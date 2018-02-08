#include "Console.h"

#define VT_USE_IOSTREAM
#ifdef VT_PLATFORM_WINDOWS
	#define VT_LOG_COLORS 1
#else
	#define VT_LOG_COLORS 0
#endif

#include <iostream>

#if VT_LOG_COLORS
	#include <Windows.h>
#endif

#include "../Platform.h"

namespace vt {
	namespace log {
		namespace internal {
	
			void printString(cString message)
			{
#ifdef VT_USE_IOSTREAM
				std::cout << message;
#else
				printf(message);
#endif
			}

			VT_API void setColor(ui8f color)
			{
#if VT_LOG_COLORS
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, color);
#endif
			}
	
		}
	}
}