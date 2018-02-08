#pragma once

#include "GLModel.h"
#include "Attribute.h"
#include "../../util/Vector.h"

namespace vt {

	template<typename Vertex>
	class Mesh
	{
	public:
		VT_CONSTEXPR Mesh() : m_vertices(), m_attributes() {  }
		~Mesh() {  }

		// Adds a vertex attribute to the mesh.
		inline void addAttribute(const Attribute& attribute) { m_attributes.pushBack(attribute); }

		// Sets the data of the model to the vertices and attributes stored in the mesh.
		void createGLModel(GLModel& model, UsageHint usageHint = USAGE_HINT_STATIC) {
			model.setData(m_vertices.data(), m_vertices.size(), m_attributes.data(), m_attributes.size(), usageHint);
		}

		// Adds a vertex to the mesh.
		inline void vertex(const Vertex& v) { m_vertices.push_back(v); }

		// Adds a triangle to the mesh.
		void triangle(const Vertex& v0, const Vertex& v1, const Vertex& v2)
		{
			m_vertices.pushBack(v0);
			m_vertices.pushBack(v1);
			m_vertices.pushBack(v2);
		}

		// Adds a quad to the mesh. It is treated as two triangles: (v0, v1, v2) and (v0, v2, v3).
		void quad(const Vertex& v0, const Vertex& v1, const Vertex& v2, const Vertex& v3)
		{
			m_vertices.pushBack(v0);
			m_vertices.pushBack(v1);
			m_vertices.pushBack(v2);

			m_vertices.pushBack(v0);
			m_vertices.pushBack(v2);
			m_vertices.pushBack(v3);
		}

		// Clears the meshes vertex data. The vertex attributes are not affected.
		void clear()
		{
			m_vertices = Vector<Vertex>();
		}

		// Calculates the normals for the mesh. Both the positions and
		// the normals have to be 3 dimensional 4-byte floating point vectors.
		// positionOffset: The offset of the position vector inside a vertex
		// normalOffset: The offset of the normal vector inside a vertex
		void calculateNormals(ui32f positionOffset, ui32f normalOffset)
		{
			for (unsigned int i = 0; i < m_vertices.getSize(); i += 3) {
				f32v3* p0 = reinterpret_cast<f32v3>(reinterpret_cast<ui8*>(&m_vertices[i + 0]) + positionOffset);
				f32v3* p1 = reinterpret_cast<f32v3>(reinterpret_cast<ui8*>(&m_vertices[i + 1]) + positionOffset);
				f32v3* p2 = reinterpret_cast<f32v3>(reinterpret_cast<ui8*>(&m_vertices[i + 2]) + positionOffset);
				f32v3 normal = (*p1 - *p0).cross(*p2 - *p0).normalized();
				*reinterpret_cast<f32v3>(reinterpret_cast<ui8*>(&m_vertices[i + 0]) + normalOffset) = normal;
				*reinterpret_cast<f32v3>(reinterpret_cast<ui8*>(&m_vertices[i + 1]) + normalOffset) = normal;
				*reinterpret_cast<f32v3>(reinterpret_cast<ui8*>(&m_vertices[i + 2]) + normalOffset) = normal;
			}
		}

		inline Vector<Vertex>& getVertices() { return m_vertices; }
		inline Vector<Attribute>& getAttributes() { return m_attributes; }
		// Returns true if the mesh's vertices are empty.
		inline bool isEmpty() const { return m_vertices.size() == 0; }

		// Reserves the given amount of vertices in the vector.
		inline void reserveVertices(ui32f count) { m_vertices.reserve(count); }
		// Reserves the given amount of attributes in the vector.
		inline void reserveAttributes(ui32f count) { m_attributes.reserve(count); }

		inline void shrinkVertices() { m_vertices.shrinkToFit(); }
		inline void shrinkAttributes() { m_attributes.shrinkToFit(); }
	private:
		Vector<Vertex> m_vertices;
		Vector<Attribute> m_attributes;
	};

}