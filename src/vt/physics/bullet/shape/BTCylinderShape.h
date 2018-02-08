#pragma once

#include "BTCollisionShape.h"

namespace vt {

	class VT_API BTCylinderShape : public BTCollisionShape
	{
	public:
		BTCylinderShape(f32 radius, f32 height);
		~BTCylinderShape();

		inline f32 getRadius() const { return m_radius; }
		inline void setRadius(f32 radius) { m_radius = radius; }

		btCollisionShape* getBulletCollisionShape() const override;
	private:
		f32 m_radius;
		f32 m_height;
	};

}