#include "GLBatchRenderer.h"

#include "../model/Attribute.h"

namespace vt {

	GLBatchRenderer::GLBatchRenderer() : m_model(), m_vertexSize(0), m_numVertices(0), m_pointer(nullptr)
	{
	}

	GLBatchRenderer::~GLBatchRenderer()
	{
	}

	void GLBatchRenderer::initialize()
	{
		VT_DEBUG_ASSERT_M(!m_model.isInitialized(), "Cannot initialize a batch renderer that is already initialized.");
		m_model.initialize();
	}

	void GLBatchRenderer::cleanup()
	{
		VT_DEBUG_ASSERT_M(m_model.isInitialized(), "Cannot clean up a batch renderer that is not initialized.");
		m_model.cleanup();
	}

	void GLBatchRenderer::allocate(ui32f numVertices, const Attribute* attributes, ui16f numAttributes, UsageHint usageHint)
	{
		m_model.setData(nullptr, numVertices, attributes, numAttributes, usageHint);
		m_vertexSize = 0;
		for (ui16f i = 0; i < numAttributes; i++) {
			m_vertexSize += type::getGLTypeSize(attributes[i].type) * attributes[i].amount;
		}
	}

	void GLBatchRenderer::begin()
	{
		m_numVertices = 0;
		m_pointer = m_model.map();
	}

	void GLBatchRenderer::end()
	{
		m_model.unmap();
		m_pointer = nullptr;
		m_model.render(m_numVertices);
	}

	void GLBatchRenderer::submit(const void* vertex)
	{
		if (m_numVertices >= m_model.getNumVertices()) {
			end();
			begin();
		}
		memcpy(reinterpret_cast<ui8*>(m_pointer) + m_numVertices * m_vertexSize, vertex, m_vertexSize);
		m_numVertices++;
	}

}