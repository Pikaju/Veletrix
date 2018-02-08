#include "Veletrix.h"

#include "memory/Heap.h"

namespace vt {

	void initialize()
	{
		heap::initialize();
	}

	void cleanup()
	{
		heap::cleanup();
	}

}