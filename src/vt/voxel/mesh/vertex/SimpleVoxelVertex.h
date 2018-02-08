#pragma once

#include "../../../Types.h"

namespace vt {

	class SimpleVoxelVertex
	{
	public:
		f32v3 position;

		SimpleVoxelVertex() {  }
		SimpleVoxelVertex(const f32v3& position) : position(position) {  }
		~SimpleVoxelVertex() {  }
	};

}