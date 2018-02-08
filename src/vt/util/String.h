#pragma once

#include <string>

#include "../Build.h"
#include "../PrimitiveTypes.h"
#include "Vector.h"

namespace vt {

	typedef std::string String;

	// Returns a vector containing the string split at all places
	// where it matches the given sequence.
	extern VT_API Vector<String> splitString(const String& string, const String& sequence);

	template<typename T> static inline String toString(T v)
	{
		return std::to_string(v);
	}

	template<> static inline String toString(char* v)
	{
		return String(v);
	}

	template<> static inline String toString(cString v)
	{
		return String(v);
	}

	template<> static inline String toString(const String v)
	{
		return v;
	}

	template<> static inline String toString(bool v)
	{
		return v ? "true" : "false";
	}

}