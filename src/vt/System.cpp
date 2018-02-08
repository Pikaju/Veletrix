#include "System.h"

#include "PrimitiveTypes.h"

namespace vt {
	namespace system {

		bool isBigEndianInteger()
		{
			union {
				ui32 type;
				ui8 bytes[sizeof(ui32)];
			} test = { 0x01000000 };
			return test.bytes[0] != 0;
		}

		bool isBigEndianFloat()
		{
			union {
				f32 type;
				ui8 bytes[sizeof(f32)];
			} test = { 1.0f };
			return test.bytes[0] != 0;
		}

	}
}