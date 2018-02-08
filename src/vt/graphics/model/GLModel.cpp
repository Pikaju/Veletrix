#include "GLModel.h"

#include "../../../glad/glad.h"
#include "Attribute.h"
#include "Primitive.h"

namespace vt {

	GLModel::GLModel() : m_vbo(0), m_vao(0), m_primitive(0), m_mappedPointer(nullptr)
	{
		setPrimitive(PRIMITIVE_TRIANGLE);
	}
	
	GLModel::~GLModel()
	{
	}

	void GLModel::initialize()
	{
		VT_DEBUG_ASSERT_M(!isInitialized(), "Cannot initialize a model that is already initialized.");
		// Generates the vertex buffer and vertex array.
		glGenBuffers(1, &m_vbo);
		glGenVertexArrays(1, &m_vao);
	}

	void GLModel::cleanup()
	{
		VT_DEBUG_ASSERT_M(isInitialized(), "Cannot clean up a model that is not initialized.");
		// Deletes the vertex buffer and vertex array.
		glDeleteBuffers(1, &m_vbo);
		glDeleteVertexArrays(1, &m_vao);
		m_vbo = 0;
		m_vao = 0;
	}

	void GLModel::setData(const void* vertexData, ui32 numVertices, const Attribute* attributes, ui32 numAttributes, UsageHint usageHint)
	{
		m_numVertices = numVertices;

		glBindVertexArray(m_vao);

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		
		// Calculates the stride of a vertex.
		ui32 stride = 0;
		for (ui32 i = 0; i < numAttributes; i++) {
			stride += type::getGLTypeSize(attributes[i].type) * attributes[i].amount;
		}

		// Sends vertex data to the GPU.
		glBufferData(GL_ARRAY_BUFFER, stride * numVertices, vertexData, usagehint::getGLUsageHint(usageHint));
		
		// Sets up the vertex attributes in the order they were passed in.
		ui32 pointer = 0;
		for (ui32 i = 0; i < numAttributes; i++) {
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, attributes[i].amount, type::getGLType(attributes[i].type), attributes[i].normalized, stride, reinterpret_cast<const void*>(pointer));
			pointer += type::getGLTypeSize(attributes[i].type) * attributes[i].amount;
		}
		
		glBindVertexArray(0);
	}

	void GLModel::render(ui32 numVertices) const
	{
		glBindVertexArray(m_vao);
		glDrawArrays(m_primitive, 0, numVertices);
		glBindVertexArray(0);
	}

	void* GLModel::map()
	{
		VT_DEBUG_ASSERT_M(isInitialized(), "Cannot map an uninitialized model.");
		VT_DEBUG_ASSERT_M(m_numVertices, "Cannot map an empty model.");
		VT_DEBUG_ASSERT_M(m_mappedPointer == nullptr, "Cannot map an already mapped model.");
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		m_mappedPointer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		return m_mappedPointer;
	}

	void GLModel::unmap()
	{
		VT_DEBUG_ASSERT_M(m_mappedPointer != nullptr, "Cannot unmap a model that is not mapped.");
		glUnmapBuffer(GL_ARRAY_BUFFER);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		m_mappedPointer = nullptr;
	}

	void GLModel::setPrimitive(const Primitive& primitive)
	{
		m_primitive = primitive::getGLPrimitive(primitive);
	}

}