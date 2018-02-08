#pragma once

#include "Function.h"

namespace vt {

	template<typename T, T slope = static_cast<T>(1)>
	class LinearFunction : public Function
	{
	public:
		inline VT_CONSTEXPR T operator()(T x) const override { return x * slope; }
	};

}