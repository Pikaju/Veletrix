#include "StringBuilder.h"

namespace vt {

	StringBuilder::StringBuilder() : m_main(), m_buffer(), m_bufferSize(1024)
	{
	}

	StringBuilder::~StringBuilder()
	{
	}

	StringBuilder& StringBuilder::append(const String& string)
	{
		m_buffer += string;
		// Append buffer to main, if the maximum buffer size is exceeded.
		if (m_buffer.size() > m_bufferSize) {
			m_main += m_buffer;
			m_buffer.resize(0);
		}
		return *this;
	}

	const String& StringBuilder::getString()
	{
		// Append buffer to main, if the buffer isn't empty.
		if (m_buffer.size() > 0) {
			m_main += m_buffer;
			m_buffer.resize(0);
		}
		return m_main;
	}

}