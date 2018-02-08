#pragma once

#include "Type.h"
#include "../../Build.h"

namespace vt {

	class VT_API Attribute
	{
	public:
		Type type;
		ui32 amount;
		bool normalized;

		VT_CONSTEXPR Attribute(const Type& type = TYPE_UNKOWN, ui32 amount = 0, bool normalized = false) : type(type), amount(amount), normalized(normalized) {  }
		~Attribute() {  }
	};

}