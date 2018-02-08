#pragma once

#include "../Build.h"
#include "../Types.h"

namespace vt {

	class ALBuffer;

	class VT_API ALSource
	{
	public:
		ALSource();
		~ALSource();

		void initialize();
		void cleanup();

		void play(const ALBuffer& buffer);
		void stop();

		void setLooping(bool looping);

		void setPosition(const f32v3& position);
		void setVelocity(const f32v3& velocity);
	private:
		ui32 m_source;
	};

}