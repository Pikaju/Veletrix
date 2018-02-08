#pragma once

#include <vector>

#include "../../Build.h"
#include "../../PrimitiveTypes.h"

#include "Address.h"

namespace vt {

	class VTDatagramPacket
	{
	public:
		VT_CONSTEXPR VTDatagramPacket(ui32f size, const Address& address = Address()) : m_data(size), m_address(address) {  }
		VTDatagramPacket(const ui8* data, ui32f size, const Address& address = Address()) : m_data(size), m_address(address) { memcpy(m_data.data(), data, size); }
		~VTDatagramPacket() {  }

		inline ui8* getPointer() { return m_data.data(); }
		inline const ui8* getData() const { return m_data.data(); }
		inline ui32f getSize() const { return m_data.size(); }

		inline const Address& getAddress() const { return m_address; }
		inline void setAddress(const Address& address) { m_address = address; }
	private:
		std::vector<ui8> m_data;
		Address m_address;
	};

}