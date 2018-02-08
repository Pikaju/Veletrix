#pragma once

#include "BTCollisionShape.h"

namespace vt {

	class VT_API BTSphereShape : public BTCollisionShape
	{
	public:
		BTSphereShape(f32 radius);
		~BTSphereShape();

		inline float getRadius() const { return m_radius; }
		inline void setRadius(f32 radius) { m_radius = radius; }

		btCollisionShape* getBulletCollisionShape() const override;
	private:
		f32 m_radius;
	};

}