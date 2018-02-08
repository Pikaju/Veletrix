#include "BTBVHTriangleMeshShape.h"

#include <Bullet/btBulletDynamicsCommon.h>

namespace vt {

	BTBVHTriangleMeshShape::BTBVHTriangleMeshShape() : m_triangles()
	{
		
	}

	BTBVHTriangleMeshShape::~BTBVHTriangleMeshShape()
	{
	}

	btCollisionShape* BTBVHTriangleMeshShape::getBulletCollisionShape() const
	{
		btTriangleMesh* mesh = new btTriangleMesh();
		for (ui32f i = 0; i < m_triangles.size(); i += 3) {
			mesh->addTriangle(btVector3(m_triangles[i].x, m_triangles[i].y, m_triangles[i].z), btVector3(m_triangles[i + 1].x, m_triangles[i + 1].y, m_triangles[i + 1].z), btVector3(m_triangles[i + 2].x, m_triangles[i + 2].y, m_triangles[i + 2].z));
		}
		return new btBvhTriangleMeshShape(mesh, false);
	}

}