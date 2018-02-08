#pragma once

#include "BTCollisionShape.h"

namespace vt {

	class VT_API BTBoxShape : public BTCollisionShape
	{
	public:
		BTBoxShape(const f32v3& size);
		~BTBoxShape();

		inline const f32v3& getSize() const { return m_size; }
		inline void setSize(const f32v3& size) { m_size = size; }

		btCollisionShape* getBulletCollisionShape() const override;
	private:
		f32v3 m_size;
	};

}