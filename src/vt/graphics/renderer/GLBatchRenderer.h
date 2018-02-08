#pragma once

#include "GLRenderer.h"
#include "../model/GLModel.h"

namespace vt {

	class VT_API GLBatchRenderer : public GLRenderer
	{
	public:
		GLBatchRenderer();
		~GLBatchRenderer();

		// Initializes the batch renderer. Do not call this method if the batch renderer is already initialized.
		void initialize();
		// Cleans up the batch renderer. Do not call this method if the batch renderer is not initialized.
		void cleanup();

		// Allocates enough space for the given number of vertices with the array of attributes.
		// numVertices: The number of vertices to allocate
		// attributes: An array of vertex attributes that are used for rendering.
		// numAttributes: The number of attributes in the array.
		// usageHint: A hint for the GPU on how to store the data (default: USAGE_HINT_DYNAMIC)
		void allocate(ui32f numVertices, const Attribute* attributes, ui16f numAttributes, UsageHint usageHint = USAGE_HINT_DYNAMIC);

		void begin();
		void end();
		void submit(const void* vertex);
		inline void submit(const void* v0, const void* v1, const void* v2) { submit(v0); submit(v1); submit(v2); }

		inline void setPrimitive(Primitive primitive) { m_model.setPrimitive(primitive); }
	private:
		GLModel m_model;
		ui16f m_vertexSize;
		ui32 m_numVertices;
		void* m_pointer;
	};

}