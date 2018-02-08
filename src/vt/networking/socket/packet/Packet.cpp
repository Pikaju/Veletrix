#include "Packet.h"

namespace vt {

	ui16 PacketManager::registerPacketType(PacketFactoryFunction function)
	{
		m_factoryFunctions[m_currentType] = function;
		return m_currentType++;
	}

	Packet* PacketManager::constructFromType(ui16 type)
	{
		return m_factoryFunctions[type]();
	}

	Packet* PacketManager::readPacket(Serializer& serializer)
	{
		Packet* packet = constructFromType(serializer.readUInt16());
		packet->setID(serializer.readUInt32());
		packet->readData(serializer);
		return packet;
	}

	void PacketManager::writePacket(Serializer& serializer, Packet* packet)
	{
		serializer.writeUInt16(packet->getType());
		serializer.writeUInt32(packet->getID());
		packet->writeData(serializer);
	}

}