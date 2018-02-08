#pragma once

#include "BTCollisionShape.h"
#include "../../../util/Vector.h"

class btTriangleMesh;

namespace vt {

	class VT_API BTBVHTriangleMeshShape : public BTCollisionShape
	{
	public:
		BTBVHTriangleMeshShape();
		~BTBVHTriangleMeshShape();

		inline void addVertex(const f32v3& v) { m_triangles.pushBack(v); }
		inline void addTriangle(const f32v3& v0, const f32v3& v1, const f32v3& v2) { addVertex(v0); addVertex(v1); addVertex(v2); }

		inline void clear() { m_triangles.clear(); }

		btCollisionShape* getBulletCollisionShape() const override;
	private:
		vt::Vector<f32v3> m_triangles;
	};

}