#include "BTSphereShape.h"

#include <Bullet/btBulletDynamicsCommon.h>

namespace vt {

	BTSphereShape::BTSphereShape(f32 radius) : m_radius(radius)
	{
	}

	BTSphereShape::~BTSphereShape()
	{
	}

	btCollisionShape* BTSphereShape::getBulletCollisionShape() const
	{
		return new btSphereShape(m_radius);
	}

}