#include "Exception.h"

#include <iostream>

namespace vt {
	namespace exception {

		void crash()
		{
			vt::log::fatal("The application has crashed");
			std::cin.get();
			exit(1);
		}

	}
}