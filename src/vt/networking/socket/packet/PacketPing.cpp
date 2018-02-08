#include "PacketPing.h"

namespace vt {

	PacketPing::PacketPing()
	{
	}

	PacketPing::~PacketPing()
	{
	}

	void PacketPing::readData(Serializer& serializer)
	{
		m_systemTime = serializer.readUInt64();
	}

	void PacketPing::writeData(Serializer& serializer)
	{
		serializer.writeUInt64(m_systemTime);
	}

}