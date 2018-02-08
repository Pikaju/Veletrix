#pragma once

#include "../../Build.h"

#define VT_ADDRESS_LOCALHOST 127, 0, 0, 1
#define VT_PORT_UNDEFINED 0

namespace vt {

	class Address
	{
	public:
		inline VT_CONSTEXPR Address(ui32 a, ui32 b, ui32 c, ui32 d, ui16 port) : m_ip((a << 24) | (b << 16) | (c << 8) | d), m_port(port) {  }
		inline VT_CONSTEXPR Address(ui32 ip, ui16 port) : m_ip(ip), m_port(port) {  }
		inline VT_CONSTEXPR Address() : m_ip(0), m_port(VT_PORT_UNDEFINED) {  }
		inline ~Address() {  }

		inline ui8f getA() const { return (m_ip >> 24) & 0xff; }
		inline ui8f getB() const { return (m_ip >> 16) & 0xff; }
		inline ui8f getC() const { return (m_ip >> 8) & 0xff; }
		inline ui8f getD() const { return (m_ip >> 0) & 0xff; }
		inline ui32 getIP() const { return m_ip; }
		inline ui16 getPort() const { return m_port; }
	private:
		ui32 m_ip;
		ui16 m_port;
	};

}