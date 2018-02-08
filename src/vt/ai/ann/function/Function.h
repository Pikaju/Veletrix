#pragma once

#include "../../../Build.h"

namespace vt {

	template<typename T>
	class Function
	{
	public:
		virtual VT_CONSTEXPR T operator()(T x) const = 0;
	};

}