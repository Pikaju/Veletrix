#pragma once

#include "VTDatagramSocket.h"

namespace vt {

	static const ui32f UNLIMITED_CONNECTIONS = 0;

	class VT_API VTServer
	{
	public:
		VTServer();
		~VTServer();

		void start(ui16 port);
		void stop();

		inline ui32f getMaxConnections() const { return m_maxConnections; }
		inline void setMaxConnections(ui32f maxConnections) { m_maxConnections = maxConnections; }
	private:
		VTDatagramSocket m_socket;
		ui32f m_maxConnections;
	};

}