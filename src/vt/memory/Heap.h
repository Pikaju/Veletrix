#pragma once

#include "../Build.h"

namespace vt {
	namespace heap {

		extern VT_API void initialize();
		extern VT_API void cleanup();

		extern VT_API void* allocate(size_t size);
		extern VT_API void* allocateZero(size_t size);
		extern VT_API void* reallocate(void* block, size_t size);
		extern VT_API void deallocate(void* block);

	}
}