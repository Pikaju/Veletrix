#include "Serializer.h"

#include "../System.h"

namespace vt {

	Serializer::Serializer(ui8* buffer, bool useBigEndian) : m_buffer(buffer), m_index(0), m_bigEndianInteger(system::isBigEndianInteger()), m_bigEndianFloat(system::isBigEndianFloat()), m_useBigEndian(useBigEndian)
	{
	}

	Serializer::~Serializer()
	{
	}

	void Serializer::writeUInt16(ui16 v)
	{
		if (m_bigEndianInteger != m_useBigEndian) v = swapEndian(v);
		VT_COPY_MEMORY(&v, m_buffer + m_index, sizeof(v));
		m_index += sizeof(v);
	}

	void Serializer::writeUInt32(ui32 v)
	{
		if (m_bigEndianInteger != m_useBigEndian) v = swapEndian(v);
		VT_COPY_MEMORY(&v, m_buffer + m_index, sizeof(v));
		m_index += sizeof(v);
	}

	void Serializer::writeUInt64(ui64 v)
	{
		if (m_bigEndianInteger != m_useBigEndian) v = swapEndian(v);
		VT_COPY_MEMORY(&v, m_buffer + m_index, sizeof(v));
		m_index += sizeof(v);
	}

	void Serializer::writeFloat32(f32 v)
	{
		if (m_bigEndianFloat != m_useBigEndian) v = swapEndian(v);
		VT_COPY_MEMORY(&v, m_buffer + m_index, sizeof(v));
		m_index += sizeof(v);
	}

	void Serializer::writeFloat64(f64 v)
	{
		if (m_bigEndianFloat != m_useBigEndian) v = swapEndian(v);
		VT_COPY_MEMORY(&v, m_buffer + m_index, sizeof(v));
		m_index += sizeof(v);
	}

	void Serializer::writeFloat128(f128 v)
	{
		if (m_bigEndianFloat != m_useBigEndian) v = swapEndian(v);
		VT_COPY_MEMORY(&v, m_buffer + m_index, sizeof(v));
		m_index += sizeof(v);
	}
	void Serializer::writeString(const String& string)
	{
		VT_COPY_MEMORY(string.c_str(), m_buffer + m_index, sizeof(char) * (string.length() + 1));
		m_index += sizeof(char) * (string.length() + 1);
	}

	ui16 Serializer::readUInt16()
	{
		ui16 v;
		VT_COPY_MEMORY(m_buffer + m_index, &v, sizeof(v));
		m_index += sizeof(v);
		if (m_bigEndianInteger != m_useBigEndian) v = swapEndian(v);
		return v;
	}

	ui32 Serializer::readUInt32()
	{
		ui32 v;
		VT_COPY_MEMORY(m_buffer + m_index, &v, sizeof(v));
		m_index += sizeof(v);
		if (m_bigEndianInteger != m_useBigEndian) v = swapEndian(v);
		return v;
	}

	ui64 Serializer::readUInt64()
	{
		ui64 v;
		VT_COPY_MEMORY(m_buffer + m_index, &v, sizeof(v));
		m_index += sizeof(v);
		if (m_bigEndianInteger != m_useBigEndian) v = swapEndian(v);
		return v;
	}

	f32 Serializer::readFloat32()
	{
		f32 v;
		VT_COPY_MEMORY(m_buffer + m_index, &v, sizeof(v));
		m_index += sizeof(v);
		if (m_bigEndianFloat != m_useBigEndian) v = swapEndian(v);
		return v;
	}

	f64 Serializer::readFloat64()
	{
		f64 v;
		VT_COPY_MEMORY(m_buffer + m_index, &v, sizeof(v));
		m_index += sizeof(v);
		if (m_bigEndianFloat != m_useBigEndian) v = swapEndian(v);
		return v;
	}

	f128 Serializer::readFloat128()
	{
		f128 v;
		VT_COPY_MEMORY(m_buffer + m_index, &v, sizeof(v));
		m_index += sizeof(v);
		if (m_bigEndianFloat != m_useBigEndian) v = swapEndian(v);
		return v;
	}

	String Serializer::readString()
	{
		String string(reinterpret_cast<cString>(m_buffer + m_index));
		m_index += sizeof(char) * (string.length() + 1);
		return string;
	}

	f32 Serializer::swapEndian(f32 v) const
	{
		f32 r;
		ui8* data = reinterpret_cast<ui8*>(&v);
		ui8* swap = reinterpret_cast<ui8*>(&r);
		for (size_t i = 0; i < sizeof(v); i++) {
			swap[i] = data[sizeof(v) - i - 1];
		}
		return r;
	}

	f64 Serializer::swapEndian(f64 v) const
	{
		f64 r;
		ui8* data = reinterpret_cast<ui8*>(&v);
		ui8* swap = reinterpret_cast<ui8*>(&r);
		for (size_t i = 0; i < sizeof(v); i++) {
			swap[i] = data[sizeof(v) - i - 1];
		}
		return r;
	}

	f128 Serializer::swapEndian(f128 v) const
	{
		f128 r;
		ui8* data = reinterpret_cast<ui8*>(&v);
		ui8* swap = reinterpret_cast<ui8*>(&r);
		for (size_t i = 0; i < sizeof(v); i++) {
			swap[i] = data[sizeof(v) - i - 1];
		}
		return r;
	}

}