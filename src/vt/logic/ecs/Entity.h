#pragma once

#include "../../Build.h"
#include "../../PrimitiveTypes.h"

namespace vt {

	class Entity
	{
	public:
		Entity();
		~Entity();
	private:
		ui32f m_id;
	};

}