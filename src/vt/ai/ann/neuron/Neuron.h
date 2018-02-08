#pragma once

#include "../../../Build.h"
#include "../../../PrimitiveTypes.h"

#include "../function/Function.h"

#include <cstring>

namespace vt {

	template<typename T, ui32f numInputs, Function function>
	class ConstantSizeNeuron
	{
	public:
		inline ConstantSizeNeuron() { VT_ZERO_MEMORY(m_weights, sizeof(m_weights)); }
		inline ~ConstantSizeNeuron() {  }

		T getOutput(const T* inputs) {
			T output = m_weights[numInputs];
			for (ui32f i = 0; i < numInputs; i++) {
				output += m_weights[i] * inputs[i];
			}
			return function(output);
		}
	private:
		T m_weights[numInputs + 1];
	};

	template<typename T, Function function>
	class Neuron
	{
	public:
		inline Neuron(ui32f numInputs) : m_weights(new T[numInputs + 1]), m_numInputs(numInputs) { VT_ZERO_MEMORY(m_weights, (m_numInputs + 1) * sizeof(T)); }
		inline ~Neuron() { delete[] m_weights; }

		T getOutput(const T* inputs) {
			T output = m_weights[m_numInputs];
			for (ui32f i = 0; i < m_numInputs; i++) {
				output += m_weights[i] * inputs[i];
			}
			return function(output);
		}
	private:
		T* m_weights;
		ui32f m_numInputs;
	};

}