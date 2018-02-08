#pragma once

#include "../Build.h"

#include "ALSource.h"

namespace vt {

	class VT_API ALBuffer
	{
		friend class ALSource;
	public:
		ALBuffer();
		~ALBuffer();

		void initialize();
		void cleanup();

		void setData(ui16f numChannels, ui16f bitsPerSample, const void* data, i32 size, i32 frequency);
		void loadWAV(cString file);
	private:
		ui32 m_buffer;
	};

}