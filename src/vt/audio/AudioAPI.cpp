#include "AudioAPI.h"

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

#include "../debug/Exception.h"

#ifdef VT_VISUAL_C_PLUS_PLUS
	#ifdef VT_AUDIO_OPENAL
		#ifdef VT_ENVIRONMENT_32
			#pragma comment(lib, "x86/OpenAL/OpenAL32.lib")
		#else
			#pragma comment(lib, "x64/OpenAL/OpenAL32.lib")
		#endif
	#endif
#endif

namespace vt {
	namespace audio {

		AudioAPI api;

#ifdef VT_AUDIO_OPENAL
		ALCdevice* g_device;
		ALCcontext* g_context;
#endif

		void initialize(const AudioAPI& api)
		{
			switch (api) {
#ifdef VT_AUDIO_OPENAL
			case AUDIO_OPENAL:
				g_device = alcOpenDevice(nullptr);
				if (g_device == nullptr) {
					log::error("Could not initialize OpenAL");
				}
				else {
					g_context = alcCreateContext(g_device, nullptr);
					alcMakeContextCurrent(g_context);
				}
				break;
#endif
			default:
				log::fatal("Invalid audio API: ", api);
				exception::crash();
			}
			audio::api = api;
		}

		void cleanup()
		{
			switch (api) {
#ifdef VT_AUDIO_OPENAL
			case AUDIO_OPENAL:
				alcDestroyContext(g_context);
				alcCloseDevice(g_device);
				break;
#endif
			default:
				log::fatal("Invalid audio API: ", api);
				exception::crash();
			}
		}

		const AudioAPI& getAPI()
		{
			return api;
		}

	}
}
