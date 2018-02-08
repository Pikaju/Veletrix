#pragma once

#include "../../Build.h"
#include "../../Types.h"

#include "UsageHint.h"

namespace vt {

	class Attribute;
	enum Type;
	enum Primitive;

	class VT_API GLModel
	{
	public:
		GLModel();
		~GLModel();

		// Initializes the model. Do not call this method if the model is already initialized.
		void initialize();
		// Cleans up the model. Do not call this method if the model is not initialized.
		void cleanup();

		// Sends the desired vertex data to the GPU.
		// vertexData: An array of all the vertices
		// numVertices: The number of vertices in the array
		// attributes: An array of all the vertex attributes
		// numAttributes: The number of attributes in the array
		// usageHint: A hint for the GPU on how to store the data (default: USAGE_HINT_STATIC)
		void setData(const void* vertexData, ui32 numVertices, const Attribute* attributes, ui32 numAttributes, UsageHint usageHint = USAGE_HINT_STATIC);

		// Executes a draw call using the current vertex data.
		inline void render() const { render(m_numVertices); }
		// Executes a draw call using the given amount of vertices.
		void render(ui32 numVertices) const;

		// Maps the GPU buffer to a modifiable pointer.
		// Do not call the render function while the buffer is mapped.
		// Do not call this method if the model is already mapped.
		void* map();
		// Unmaps the GPU buffer.
		// Do not call this method if the model is not mapped.
		void unmap();

		// Changes the primitive that is used to render the vertices.
		// The default is PRIMITIVE_TRIANGLE.
		void setPrimitive(const Primitive& primitive);

		// Returns true if the model has been initialized.
		inline bool isInitialized() const { return m_vbo != 0; }
		// Returns the number of vertices in the model.
		inline ui32f getNumVertices() const { return m_numVertices; }
	private:
		ui32 m_vbo;
		ui32 m_vao;

		ui32 m_primitive;
		ui32 m_numVertices;

		void* m_mappedPointer;
	};

}