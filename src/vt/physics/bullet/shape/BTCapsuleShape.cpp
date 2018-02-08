#include "BTCapsuleShape.h"

#include <Bullet/btBulletDynamicsCommon.h>

namespace vt {

	BTCapsuleShape::BTCapsuleShape(f32 radius, f32 height) : m_radius(radius), m_height(height)
	{
	}

	BTCapsuleShape::~BTCapsuleShape()
	{
	}

	btCollisionShape* BTCapsuleShape::getBulletCollisionShape() const
	{
		return new btCapsuleShape(m_radius, m_height - m_radius * 2.0f);
	}

}