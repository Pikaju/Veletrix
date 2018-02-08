#pragma once

#include "Function.h"

namespace vt {

	template<typename T>
	class StepFunction : public Function
	{
	public:
		inline VT_CONSTEXPR T operator()(T x) const override { return x >= static_cast<T>(0) ? static_cast<T>(1) : static_cast<T>(0); }
	};

}