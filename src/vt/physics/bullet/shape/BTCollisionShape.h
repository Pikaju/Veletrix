#pragma once

#include "../../../Build.h"
#include "../../../Types.h"

class btCollisionShape;

namespace vt {

	class VT_API BTCollisionShape
	{
	public:
		BTCollisionShape() {  }
		~BTCollisionShape() {  }

		virtual btCollisionShape* getBulletCollisionShape() const = 0;
	protected:
	};

}