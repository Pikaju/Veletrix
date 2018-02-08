#pragma once

#include "../Build.h"
#include "../Types.h"
#include "../util/Camera.h"

namespace vt {

	class VT_API ALListener
	{
	public:
		ALListener();
		~ALListener();

		void setPosition(const f32v3& position);
		void setVelocity(const f32v3& velocity);
		void setOrientation(const f32v3& direction, const f32v3& up);

		void applyCamera(const Camera<f32>& camera);
	};

}