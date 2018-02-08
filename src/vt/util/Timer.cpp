#include "Timer.h"

#include <chrono>
#include <thread>

// Time point at which the program started.
std::chrono::high_resolution_clock::time_point g_programStartupTime = std::chrono::high_resolution_clock::now();

namespace vt {

	Timer::Timer()
	{
		reset();
	}

	Timer::~Timer()
	{
	}

	ui64f Timer::getProgramNanoseconds()
	{
		return static_cast<ui64f>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - g_programStartupTime).count());
	}

	void Timer::sleep(ui32f millis)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(millis));
	}

}