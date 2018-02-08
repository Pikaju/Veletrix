#pragma once

#include "Function.h"

namespace vt {

	template<typename T>
	class RectifiedLinearUnitFunction : public Function
	{
	public:
		inline VT_CONSTEXPR T operator()(T x) const override { return x > static_cast<T>(0) ? x : static_cast<T>(0); }
	};

}