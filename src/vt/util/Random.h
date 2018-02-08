#pragma once

#include <random>

#include "../PrimitiveTypes.h"
#include "Timer.h"

namespace vt {

	class Random
	{
	public:
		Random(ui32 seed = static_cast<ui32>(Timer::getProgramNanoseconds())) : m_engine(seed) {  }
		~Random() {  }

		inline ui8 nextUI8(ui16 range) { return static_cast<ui8>(std::uniform_int_distribution<ui16>(0, range)(m_engine)); }
		inline ui16 nextUI16(ui16 range) { return std::uniform_int_distribution<ui16>(0, range)(m_engine); }
		inline ui32 nextUI32(ui32 range) { return std::uniform_int_distribution<ui32>(0, range)(m_engine); }
		inline ui64 nextUI64(ui64 range) { return std::uniform_int_distribution<ui64>(0, range)(m_engine); }

		inline f32 nextF32() { return std::uniform_real_distribution<f32>(0.0f, 1.0f)(m_engine); }
		inline f64 nextF64() { return std::uniform_real_distribution<f64>(0.0, 1.0)(m_engine); }
		inline f128 nextF128() { return std::uniform_real_distribution<f128>(0.0, 1.0)(m_engine); }

		inline f32 nextF32(f32 min, f32 max) { return std::uniform_real_distribution<f32>(min, max)(m_engine); }
		inline f64 nextF64(f64 min, f64 max) { return std::uniform_real_distribution<f64>(min, max)(m_engine); }
		inline f128 nextF128(f128 min, f128 max) { return std::uniform_real_distribution<f128>(min, max)(m_engine); }
	private:
		std::mt19937 m_engine;
	};

}