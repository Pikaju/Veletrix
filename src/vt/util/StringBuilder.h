#pragma once

#include "../Types.h"
#include "String.h"

namespace vt {

	class VT_API StringBuilder
	{
	public:
		StringBuilder();
		~StringBuilder();

		// Appends the string to the buffer.
		StringBuilder& append(const String& string);
		// Returns the built string.
		const String& getString();
		// Clears the string builder.
		inline void clear() { m_main.clear(); m_buffer.resize(0); }
		// Changes the maximum buffer size to the given value.
		inline void setBufferSize(ui16f bufferSize) { m_bufferSize = bufferSize; }
	private:
		String m_main;
		String m_buffer;
		ui16f m_bufferSize;
	};

}