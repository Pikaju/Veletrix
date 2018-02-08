#pragma once

#include "../../PrimitiveTypes.h"

namespace vt {

	template<typename VoxelData, ui32f width, ui32f height, ui32f length>
	class VoxelContainer
	{
	public:
		VoxelContainer() {  }
		virtual ~VoxelContainer() {  }
	
		virtual const VoxelData& getData(ui32f x, ui32f y, ui32f z) const = 0;
		virtual void setData(ui32f x, ui32f y, ui32f z, const VoxelData& data) = 0;

		virtual void clear(const VoxelData& data) = 0;
	};

}