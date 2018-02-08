#include "VTServer.h"

namespace vt {

	VTServer::VTServer() : m_socket(), m_maxConnections(UNLIMITED_CONNECTIONS)
	{
	}

	VTServer::~VTServer()
	{
	}

	void VTServer::start(ui16 port)
	{
		m_socket.open(port);
	}

	void VTServer::stop()
	{
		m_socket.close();
	}

}