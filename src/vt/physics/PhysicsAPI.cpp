#include "PhysicsAPI.h"

#include "../debug/Exception.h"

#ifdef VT_VISUAL_C_PLUS_PLUS
	#ifdef VT_PHYSICS_BULLET
		#ifdef VT_ENVIRONMENT_32
			#ifdef VT_DEBUG
				#pragma comment(lib, "x86/Bullet/Debug/BulletDynamics_Debug.lib")
				#pragma comment(lib, "x86/Bullet/Debug/BulletCollision_Debug.lib")
				#pragma comment(lib, "x86/Bullet/Debug/LinearMath_Debug.lib")
			#else
				#pragma comment(lib, "x86/Bullet/Release/BulletDynamics.lib")
				#pragma comment(lib, "x86/Bullet/Release/BulletCollision.lib")
				#pragma comment(lib, "x86/Bullet/Release/LinearMath.lib")
			#endif
		#else
			#ifdef VT_DEBUG
				#pragma comment(lib, "x64/Bullet/Debug/BulletDynamics_Debug.lib")
				#pragma comment(lib, "x64/Bullet/Debug/BulletCollision_Debug.lib")
				#pragma comment(lib, "x64/Bullet/Debug/LinearMath_Debug.lib")
			#else
				#pragma comment(lib, "x64/Bullet/Release/BulletDynamics.lib")
				#pragma comment(lib, "x64/Bullet/Release/BulletCollision.lib")
				#pragma comment(lib, "x64/Bullet/Release/LinearMath.lib")
			#endif
		#endif
	#endif
#endif

namespace vt {
	namespace physics {

		PhysicsAPI api;

		void initialize(const PhysicsAPI& api)
		{
			switch (api) {
#ifdef VT_PHYSICS_BULLET
			case PHYSICS_BULLET:
				break;
#endif
			default:
				log::fatal("Invalid physics API: ", api);
				exception::crash();
			}
			physics::api = api;
		}

		void cleanup()
		{
			switch (api) {
#ifdef VT_PHYSICS_BULLET
			case PHYSICS_BULLET:
				break;
#endif
			default:
				log::fatal("Invalid physics API: ", api);
				exception::crash();
			}
		}

		const PhysicsAPI& getAPI()
		{
			return api;
		}

	}
}