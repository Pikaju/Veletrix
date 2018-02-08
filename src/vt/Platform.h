#pragma once

#if defined(_WIN64)
	// The build platform is 64-bit Windows.
	#define VT_PLATFORM_WINDOWS_64
	// The build platform is a 64-bit environment.
	#define VT_ENVIRONMENT_64
#elif defined(_WIN32)
	// The build platform is 32-bit Windows.
	#define VT_PLATFORM_WINDOWS_32
	// The build platform is a 32-bit environment.
	#define VT_ENVIRONMENT_32
#elif defined(__APPLE__) || defined(__MACH__)
	// The build platform is macOS.
	#define VT_PLATFORM_MAC_OS
#elif defined(__linux__)
	// The build platform is Linux.
	#define VT_PLATFORM_LINUX
#elif defined(__unix) || defined(__unix__)
	// The build platform is Unix.
	#define VT_PLATFORM_UNIX
#else
	// The build platform is unkown.
	#define VT_PLATFORM_UNKNOWN
#endif

#if defined(VT_PLATFORM_WINDOWS_32) || defined(VT_PLATFORM_WINDOWS_64)
	// The build platform is either 32-bit or 64-bit Windows.
	#define VT_PLATFORM_WINDOWS
#endif