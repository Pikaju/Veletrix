#include "BTBoxShape.h"

#include <Bullet/btBulletCollisionCommon.h>

namespace vt {

	BTBoxShape::BTBoxShape(const f32v3& size) : m_size(size)
	{
	}

	BTBoxShape::~BTBoxShape()
	{
	}

	btCollisionShape* vt::BTBoxShape::getBulletCollisionShape() const
	{
		return new btBoxShape(btVector3(m_size.x / 2.0f, m_size.y / 2.0f, m_size.z / 2.0f));
	}

}