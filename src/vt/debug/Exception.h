#pragma once

#include "../Build.h"
#include "../util/String.h"
#include "../io/Console.h"

namespace vt {
	namespace exception {

		// Crashes the application. It is halted to be able to display
		// debug information in the console.
		extern VT_API void crash();

	}
}