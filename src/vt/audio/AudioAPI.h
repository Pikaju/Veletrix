#pragma once

#include "../Build.h"

#define VT_AUDIO_OPENAL

namespace vt {

	enum AudioAPI
	{
		AUDIO_OPENAL
	};

	namespace audio {

		extern VT_API void initialize(const AudioAPI& api);
		extern VT_API void cleanup();
		extern VT_API const AudioAPI& getAPI();

	}
}