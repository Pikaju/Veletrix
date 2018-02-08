#pragma once

#include <vector>

#include "../Build.h"

namespace vt {

	class StringBuilder;

	class VT_API Compiler
	{
	public:
		static void compile(const char* file);
	private:
		static void load(const char* file, StringBuilder& source);
	};

}