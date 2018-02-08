#pragma once

#include "../../Types.h"
#include "Renderer.h"

namespace vt {

	class VT_API GLRenderer : public Renderer
	{
	public:
		GLRenderer();
		~GLRenderer();

		void setDepthRead(bool flag) override;
		void setDepthWrite(bool flag) override;
		void setCulling(Culling flag) override;
		void setWireframe(bool flag) override;
		void setBlending(Blending flag) override;

		void clear(bool color, bool depth, bool stencil) override;
	};

}