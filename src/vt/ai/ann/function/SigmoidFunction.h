#pragma once

#include "Function.h"
#include "../../../math/Math.h"

namespace vt {

	template<typename T>
	class SigmoidFunction : public Function
	{
	public:
		inline VT_CONSTEXPR T operator()(T x) const override { return static_cast<T>(1) / (static_cast<T>(1) + vt::pow(e<T>(), x)); }
	};

}