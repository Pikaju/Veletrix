#pragma once

#include "../../../Build.h"
#include "../../../PrimitiveTypes.h"
#include "../../../math/SIMD.h"

#include "../function/Function.h"

namespace vt {

	template<Function function>
	class SIMDNeuronF32
	{
	public:
		inline SIMDNeuronF32(ui32f numInputs) : m_weights(VT_SIMD_MALLOC((numInputs + 1) * sizeof(f32))), m_numInputs(numInputs) { VT_ZERO_MEMORY(m_weights, (m_numInputs + 1) * sizeof(f32)); }
		inline ~SIMDNeuronF32() { VT_SIMD_FREE(m_weights); }

		f32 getOutput(const f32* inputs) {
			__m128 weightedSum = _mm_set1_ps(0.0f);
			for (ui32f i = 0; i < m_numInputs; i += 4) {
				_m128 a = _mm_load_ps(&m_weights[i]);
				_m128 b = _mm_load_ps(&inputs[i]);
				_m128 p = _mm_mul_ps(a, b);
				weightedSum = _mm_add_ps(weightedSum, p);
			}
			weightedSum = _mm_hadd_ps(weightedSum, weightedSum);
			weightedSum = _mm_hadd_ps(weightedSum, weightedSum);
			f32 result;
			_mm_store_ss(&result, weightedSum);
			return function(result + m_weights[m_numInputs]);
		}
	private:
		f32* m_weights;
		ui32f m_numInputs;
	};

}