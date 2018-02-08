#pragma once

#include "../Build.h"

#define VT_PHYSICS_BULLET

namespace vt {

	enum PhysicsAPI
	{
		PHYSICS_BULLET
	};

	namespace physics {

		extern VT_API void initialize(const PhysicsAPI& api);
		extern VT_API void cleanup();
		extern VT_API const PhysicsAPI& getAPI();

	}
}