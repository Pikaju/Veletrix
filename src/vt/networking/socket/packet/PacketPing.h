#pragma once

#include "Packet.h"

namespace vt {

	class PacketPing : public Packet
	{
	public:
		PacketPing();
		~PacketPing();

		void readData(Serializer& serializer) override;
		void writeData(Serializer& serializer) override;

		inline ui64 getSystemTime() const { return m_systemTime; }
		inline void setSystemTime(ui64 systemTime) { m_systemTime = systemTime; }

		inline static Packet* factoryFunction() { return new PacketPing(); }
	private:
		static ui16 m_type;

		ui64 m_systemTime;
	};

}