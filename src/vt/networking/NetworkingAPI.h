#pragma once

#include "../Build.h"

#define VT_NETWORKING_VELETRIX

namespace vt {

	enum NetworkingAPI
	{
		NETWORKING_VELETRIX
	};

	namespace networking {

		extern VT_API void initialize(const NetworkingAPI& api);
		extern VT_API void cleanup();
		extern VT_API const NetworkingAPI& getAPI();

	}
}