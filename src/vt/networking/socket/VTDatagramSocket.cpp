#include "VTDatagramSocket.h"

#include "../../debug/Exception.h"

#if defined(VT_PLATFORM_WINDOWS)
	#include <WinSock2.h>
#elif defined(VT_PLATFORM_MAC_OSX) || defined(VT_PLATFORM_LINUX) || defined(VT_PLATFORM_UNIX)
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <fcntl.h>
#endif

namespace vt {

	VTDatagramSocket::VTDatagramSocket() : m_handle(0)
	{
	}

	VTDatagramSocket::~VTDatagramSocket()
	{
	}

	void VTDatagramSocket::open(ui16 port)
	{
		m_handle = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (m_handle <= 0) {
			log::fatal("Failed to initialize socket");
			exception::crash();
		}

		if (port != 0) {
			sockaddr_in address;
			address.sin_family = AF_INET;
			address.sin_addr.s_addr = INADDR_ANY;
			address.sin_port = htons(port);

			if (bind(m_handle, reinterpret_cast<const sockaddr*>(&address), sizeof(address)) < 0) {
				log::fatal("Failed to bind socket");
				exception::crash();
			}
		}
	}

	void VTDatagramSocket::close()
	{
#ifdef VT_PLATFORM_WINDOWS
		closesocket(m_handle);
#elif VT_PLATFORM == VT_PLATFORM_MAC_OSX || VT_PLATFORM == VT_PLATFORM_LINUX || VT_PLATFORM == VT_PLATFORM_UNIX
		close(m_handle);
#endif
	}

	void VTDatagramSocket::send(const VTDatagramPacket& packet)
	{
		sockaddr_in address;
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = htonl(packet.getAddress().getIP());
		address.sin_port = htons(packet.getAddress().getPort());
		i32f sent = sendto(m_handle, reinterpret_cast<const char*>(packet.getData()), packet.getSize(), 0, reinterpret_cast<sockaddr*>(&address), sizeof(address));
		if (sent != packet.getSize()) {
			log::warning("Failed to send packet");
		}
	}

	bool VTDatagramSocket::receive(VTDatagramPacket& packet)
	{
#ifdef VT_PLATFORM_WINDOWS
		typedef i32f socklen_t;
#endif
		sockaddr_in from;
		socklen_t fromLength = sizeof(from);
		i32f bytes = recvfrom(m_handle, reinterpret_cast<char*>(packet.getPointer()), packet.getSize(), 0, reinterpret_cast<sockaddr*>(&from), &fromLength);
		if (bytes <= 0) {
			return false;
		}
		packet.setAddress(Address(ntohl(from.sin_addr.s_addr), ntohs(from.sin_port)));
		return true;
	}

	void VTDatagramSocket::setBlocking(bool blocking)
	{
#if defined(VT_PLATFORM_MAC_OSX) || defined(VT_PLATFORM_LINUX) || defined(VT_PLATFORM_UNIX)
		if (fcntl(m_handle, F_SETFL, O_NONBLOCK, blocking ? 0 : 1) == -1) {
			log::fatal("Failed to set socket blocking mode");
			exception::crash();
		}
#elif defined(VT_PLATFORM_WINDOWS_32)
		DWORD nonBlocking = blocking ? 0 : 1;
		if (ioctlsocket(m_handle, FIONBIO, &nonBlocking) != 0) {
			log::fatal("Failed to set socket blocking mode");
			exception::crash();
		}
#endif
	}

}