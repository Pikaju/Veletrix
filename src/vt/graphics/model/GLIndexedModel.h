#pragma once

#include "../../Build.h"
#include "../../Types.h"

#include "UsageHint.h"

namespace vt {

	class Attribute;
	enum Type;
	enum Primitive;

	class VT_API GLIndexedModel
	{
	public:
		GLIndexedModel();
		~GLIndexedModel();

		// Initializes the model. Do not call this method if the model is already initialized.
		void initialize();
		// Cleans up the model. Do not call this method if the model is not initialized.
		void cleanup();

		// Sends the desired vertex and index data to the GPU.
		// vertexData: An array of all the vertices
		// numVertices: The number of vertices in the array
		// indexData: An array of all the indices
		// numIndices: The number of indices in the array
		// indexType: The integer type used to store the indices in the array
		// attributes: An array of all the vertex attributes
		// numAttributes: The number of attributes in the array
		// usageHint: A hint for the GPU on how to store the data (default: USAGE_HINT_STATIC)
		void setData(const void* vertexData, ui32 numVertices, const void* indexData, ui32 numIndices, const Type& indexType, const Attribute* attributes, ui32 numAttributes, UsageHint usageHint = USAGE_HINT_STATIC);

		// Executes a draw call using the current vertex and index data.
		void render() const;

		// Changes the primitive that is used to render the vertices.
		// The default is PRIMITIVE_TRIANGLE.
		void setPrimitive(const Primitive& primitive);

		// Returns true if the model has been initialized.
		inline bool isInitialized() const { return m_vbo != 0; }
	private:
		ui32 m_vbo;
		ui32 m_ibo;
		ui32 m_vao;

		ui32 m_primitive;
		ui32 m_indexType;
		ui32 m_numIndices;
	};

}