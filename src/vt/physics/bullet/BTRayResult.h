#pragma once

#include "../../Types.h"

namespace vt {

	class BTRayResult
	{
	public:
		BTRayResult(bool hasHit, const f32v3& hitPoint, const f32v3& hitNormal) : m_hasHit(hasHit), m_hitPoint(hitPoint), m_hitNormal(hitNormal) {  }
		~BTRayResult() {  }
		
		inline bool hasHit() const { return m_hasHit; }
		inline const f32v3& getHitPoint() const { return m_hitPoint; }
		inline const f32v3& getHitNormal() const { return m_hitNormal; }
	private:
		bool m_hasHit;
		f32v3 m_hitPoint;
		f32v3 m_hitNormal;
	};

}