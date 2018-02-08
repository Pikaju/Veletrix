#pragma once

namespace vt {

	template<typename T1, typename T2>
	class Pair
	{
	public:
		T1 a;
		T2 b;

		inline Pair(const T1& a, const T2& b) : a(a), b(b) {  }
		inline ~Pair() {  }
	};

}