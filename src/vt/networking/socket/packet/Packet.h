#pragma once

#include <unordered_map>

#include "../../../memory/Serializer.h"

namespace vt {

	static const ui32 PACKET_ID_UNDEFINED = -1;

	class Packet
	{
	public:
		Packet() : m_type(), m_id(PACKET_ID_UNDEFINED) {  }
		~Packet() {  }

		virtual void readData(Serializer& serializer) = 0;
		virtual void writeData(Serializer& serializer) = 0;

		inline ui16 getType() const { return m_type; }

		inline ui32 getID() const { return m_id; }
		inline void setID(ui32 id) { m_id = id; }
	private:
		ui16 m_type;
		ui32 m_id;
	};

	typedef Packet* (*PacketFactoryFunction)(void);

	class PacketManager
	{
	public:
		ui16 registerPacketType(PacketFactoryFunction function);
		Packet* constructFromType(ui16 type);

		Packet* readPacket(Serializer& serializer);
		void writePacket(Serializer& serializer, Packet* packet);
	private:
		ui16 m_currentType;
		std::unordered_map<ui16, PacketFactoryFunction> m_factoryFunctions;
		std::unordered_map<PacketFactoryFunction, ui16> m_types;
	};

}