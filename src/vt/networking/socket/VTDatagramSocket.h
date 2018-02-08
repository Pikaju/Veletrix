#pragma once

#include "../../Types.h"
#include "VTDatagramPacket.h"

namespace vt {

	class VT_API VTDatagramSocket
	{
	public:
		VTDatagramSocket();
		~VTDatagramSocket();

		void open(ui16 port = 0);
		void close();

		void send(const VTDatagramPacket& packet);
		bool receive(VTDatagramPacket& packet);

		void setBlocking(bool blocking);
	private:
		i32 m_handle;
	};

}