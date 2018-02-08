#pragma once

#include "../Build.h"
#include "../Types.h"

namespace vt {

	class VT_API Timer
	{
	public:
		Timer();
		~Timer();

		// Resets the timer.
		inline void reset() { m_currentNanoseconds = getProgramNanoseconds(); }

		// Returns the passed nanoseconds since the last reset.
		inline ui64f getPassedNanoseconds() const { return getProgramNanoseconds() - m_currentNanoseconds; }
		// Returns the passed seconds since the last reset as a floating point value.
		inline f64 getPassedSeconds() const { return static_cast<f64>(getPassedNanoseconds()) / static_cast<f64>(1000000000); }

		// Returns the passed nanoseconds since the beginning of the program.
		static ui64f getProgramNanoseconds();
		// Returns the passed seconds since the beginning of the program.
		static inline f64 getProgramSeconds() { return static_cast<f64>(getProgramNanoseconds()) / static_cast<f64>(1000000000); }

		// Makes the current thread sleep for the given amount of milliseconds.
		static void sleep(ui32f millis);
	private:
		ui64f m_currentNanoseconds;
	};

}