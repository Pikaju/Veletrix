#pragma once

namespace vt {

	enum Blending
	{
		// Blending is disabled.
		BLENDING_DISABLED,
		// The alpha value of the source is used to determine the opacity.
		BLENDING_TRANSPARENCY,
		// Source and destination are added.
		BLENDING_ADDITIVE
	};

}
