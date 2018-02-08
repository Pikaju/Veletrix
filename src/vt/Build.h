#pragma once
#pragma warning(disable:4251)

#include "Platform.h"
#include "Compiler.h"

// Main function for an application using the Veletrix Engine.
// Do not specify your own main function when using the engine.
extern "C" void vtmain();

namespace vt {

	// Crashes the program if the condition is false.
	extern void runtimeAssert(bool condition);
	// Crashes the program if the condition is false and logs a message.
	extern void runtimeAssert(bool condition, const char* message);

}

#ifdef _DEBUG
	// The program is built in debug mode.
	#define VT_DEBUG
#else
	// The program is built in release mode.
	#define VT_RELEASE
#endif

// Assertions

// Runtime assertion that crashes if the parameter is false.
#define VT_ASSERT(condition) vt::runtimeAssert(condition)
// Runtime assertion that crashes and displays a message if the parameter is false.
#define VT_ASSERT_M(condition, message) vt::runtimeAssert(condition, message)
// Static assertion that interrupts compilation if the parameter is false.
#define VT_STATIC_ASSERT(condition) static_assert(condition)

#ifdef VT_DEBUG
	// Runtime assertion that crashes if the parameter is false and the program is in debug mode.
	#define VT_DEBUG_ASSERT(condition) VT_ASSERT(condition)
	// Runtime assertion that crashes and displays a message if the parameter is false and the program is in debug mode.
	#define VT_DEBUG_ASSERT_M(condition, message) VT_ASSERT_M(condition, message)
	// Runtime assertion that crashes if the parameter is false and the program is in release mode.
	#define VT_RELEASE_ASSERT(condition)
	// Runtime assertion that crashes and displays a message if the parameter is false and the program is in release mode.
	#define VT_RELEASE_ASSERT_M(condition)
#else
	// Runtime assertion that crashes if the parameter is false and the program is in debug mode.
	#define VT_DEBUG_ASSERT(condition)
	// Runtime assertion that crashes and displays a message if the parameter is false and the program is in debug mode.
	#define VT_DEBUG_ASSERT_M(condition, message)
	// Runtime assertion that crashes if the parameter is false and the program is in release mode.
	#define VT_RELEASE_ASSERT(condition) VT_ASSERT(condition)
	// Runtime assertion that crashes and displays a message if the parameter is false and the program is in release mode.
	#define VT_RELEASE_ASSERT_M(condition, message) VT_ASSERT_M(condition, message)
#endif

// DLL export and import

#ifdef VT_PLATFORM_WINDOWS
	#ifdef VT_DLL_EXPORT
		// Macro that handles DLL export and import.
		#define VT_API __declspec(dllexport)
	#elif defined(VT_DLL_IMPORT)
		// Macro that handles DLL export and import.
		#define VT_API __declspec(dllimport)
	#else
		// Macro that handles DLL export and import. Use VT_DLL_EXPORT or VT_DLL_IMPORT.
		#define VT_API
	#endif
#else
	// Macro that handles DLL export and import on Windows.
	#define VT_API
#endif

// Declares that the expression can be evaluated during compile time.
#define VT_CONSTEXPR constexpr

// Copies a block of memory to somewhere else in an efficient way.
#define VT_COPY_MEMORY(source, destination, size) memcpy(destination, source, size)

// Sets a block of memory to 0 in an efficient way.
#define VT_ZERO_MEMORY(block, size) memset(block, 0, size)

#ifdef VT_VISUAL_C_PLUS_PLUS
	// Forces a function to be inlined. Does not work on all compilers.
	#define VT_FORCE_INLINE __forceinline
#else
	// Forces a function to be inlined. Since it is not supported by the current compiler, regular inline is used.
	#define VT_FORCE_INLINE inline
#endif