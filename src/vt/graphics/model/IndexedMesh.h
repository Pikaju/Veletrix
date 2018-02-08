#pragma once

#include "GLIndexedModel.h"
#include "Attribute.h"
#include "../../io/Console.h"
#include "../../util/Vector.h"

namespace vt {

	template<typename Vertex, typename Index>
	class IndexedMesh
	{
	public:
		VT_CONSTEXPR IndexedMesh() : m_vertices(), m_indices(), m_attributes() {  }
		~IndexedMesh() {  }

		// Adds a vertex attribute to the mesh.
		inline void addAttribute(const Attribute& attribute) { m_attributes.pushBack(attribute); }

		// Sets the data of the model to the vertices, indices and attributes
		// stored in the mesh. The index type has to be an integer that is
		// either 1, 2 or 4 bytes in size.
		void createGLModel(GLIndexedModel& model, UsageHint usageHint = USAGE_HINT_STATIC) {
			Type indexType;
			switch (sizeof(Index)) {
			case 1: indexType = TYPE_UNSIGNED_BYTE; break;
			case 2: indexType = TYPE_UNSIGNED_SHORT; break;
			case 4: indexType = TYPE_UNSIGNED_INT; break;
			default: log::error("Index type of size ", sizeof(Index), " not supported"); break;
			}
			model.setData(m_vertices.data(), m_vertices.size(), m_indices.data(), m_indices.size(), indexType, m_attributes.data(), m_attributes.size(), usageHint);
		}

		// Adds a vertex to the mesh.
		void vertex(const Vertex& v)
		{
			m_indices.pushBack(static_cast<Index>(m_vertices.size()));
			m_vertices.pushBack(v);
		}

		// Adds a triangle to the mesh.
		void triangle(const Vertex& v0, const Vertex& v1, const Vertex& v2)
		{
			m_indices.pushBack(static_cast<Index>(m_vertices.size() + 0));
			m_indices.pushBack(static_cast<Index>(m_vertices.size() + 1));
			m_indices.pushBack(static_cast<Index>(m_vertices.size() + 2));
			
			m_vertices.pushBack(v0);
			m_vertices.pushBack(v1);
			m_vertices.pushBack(v2);
		}

		// Adds a quad to the mesh. Indices are used to treat the quad
		// as two triangles: (v0, v1, v2) and (v0, v2, v3).
		void quad(const Vertex& v0, const Vertex& v1, const Vertex& v2, const Vertex& v3)
		{
			m_indices.pushBack(static_cast<Index>(m_vertices.size() + 0));
			m_indices.pushBack(static_cast<Index>(m_vertices.size() + 1));
			m_indices.pushBack(static_cast<Index>(m_vertices.size() + 2));
			m_indices.pushBack(static_cast<Index>(m_vertices.size() + 0));
			m_indices.pushBack(static_cast<Index>(m_vertices.size() + 2));
			m_indices.pushBack(static_cast<Index>(m_vertices.size() + 3));

			m_vertices.pushBack(v0);
			m_vertices.pushBack(v1);
			m_vertices.pushBack(v2);
			m_vertices.pushBack(v3);
		}

		// Clears the mesh's vertex and index data. The vertex attributes are not affected.
		void clear()
		{
			m_vertices = Vector<Vertex>();
			m_indices = Vector<Index>();
		}

		inline Vector<Vertex>& getVertices() { return m_vertices; }
		inline Vector<Index>& getIndices() { return m_indices; }
		inline Vector<Attribute>& getAttributes() { return m_attributes; }
		// Returns true if the mesh is empty.
		inline bool isEmpty() const { return m_indices.size() == 0; }

		// Reserves the given amount of vertices in the vector.
		inline void reserveVertices(ui32f count) { m_vertices.reserve(count); }
		// Reserves the given amount of indices in the vector.
		inline void reserveIndices(ui32f count) { m_indices.reserve(count); }
		// Reserves the given amount of attributes in the vector.
		inline void reserveAttributes(ui32f count) { m_attributes.reserve(count); }

		inline void shrinkVertices() { m_vertices.shrinkToFit(); }
		inline void shrinkIndices() { m_indices.shrinkToFit(); }
		inline void shrinkAttributes() { m_attributes.shrinkToFit(); }
	private:
		Vector<Vertex> m_vertices;
		Vector<Index> m_indices;
		Vector<Attribute> m_attributes;
	};

}