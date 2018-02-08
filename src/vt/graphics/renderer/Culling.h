#pragma once

namespace vt {

	enum Culling
	{
		// Culling is disabled.
		CULLING_DISABLED,
		// The front side of the polygons are culled.
		CULLING_FRONT,
		// The back side of the polygons are culled.
		CULLING_BACK
	};

}