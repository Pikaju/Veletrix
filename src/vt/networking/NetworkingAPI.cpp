#include "NetworkingAPI.h"

#include "../debug/Exception.h"

#ifdef VT_NETWORKING_VELETRIX
	#ifdef VT_PLATFORM_WINDOWS
		#include <WinSock2.h>
		#ifdef VT_VISUAL_C_PLUS_PLUS
			#pragma comment(lib, "wsock32.lib")
		#endif
	#endif
#endif

namespace vt {
	namespace networking {

		NetworkingAPI api;

		void initialize(const NetworkingAPI& api)
		{
			switch (api) {
#ifdef VT_NETWORKING_VELETRIX
			case NETWORKING_VELETRIX:
#ifdef VT_PLATFORM_WINDOWS_32
				WSADATA wsaData;
				if (WSAStartup(MAKEWORD(2, 2), &wsaData) != NO_ERROR) {
					log::fatal("Could not initialize networking API");
					exception::crash();
				}
#endif
				break;
#endif
			default:
				log::fatal("Invalid networking API: ", api);
				exception::crash();
			}
			networking::api = api;
		}

		void cleanup()
		{
			switch (api) {
#ifdef VT_NETWORKING_VELETRIX
			case NETWORKING_VELETRIX:
#ifdef VT_PLATFORM_WINDOWS_32
				WSACleanup();
#endif
				break;
#endif
			default:
				log::fatal("Invalid networking API: ", api);
				exception::crash();
			}
		}

		const NetworkingAPI& getAPI()
		{
			return api;
		}

	}
}