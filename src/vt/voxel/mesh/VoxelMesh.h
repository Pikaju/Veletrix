#pragma once

#include "../../graphics/model/IndexedMesh.h"
#include "../../graphics/model/GLIndexedModel.h"

namespace vt {

	template<typename Vertex, typename Index>
	class VoxelMesh
	{
	public:
	
	private:
		IndexedMesh<Vertex, Index> m_mesh;
		GLIndexedModel m_model;
	};

}