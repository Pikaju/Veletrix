#include "BTCylinderShape.h"

#include <Bullet/btBulletDynamicsCommon.h>

namespace vt {

	BTCylinderShape::BTCylinderShape(f32 radius, f32 height) : m_radius(radius), m_height(height)
	{
	}

	BTCylinderShape::~BTCylinderShape()
	{
	}

	btCollisionShape* BTCylinderShape::getBulletCollisionShape() const
	{
		return new btCylinderShape(btVector3(m_radius, m_height / 2.0f, m_radius));
	}

}