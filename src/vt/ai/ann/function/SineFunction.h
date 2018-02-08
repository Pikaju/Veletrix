#pragma once

#include "Function.h"
#include "../../../math/Math.h"

namespace vt {

	template<typename T>
	class SineFunction : public Function
	{
	public:
		inline VT_CONSTEXPR T operator()(T x) const override { return vt::sin(x); }
	};

}