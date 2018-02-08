#pragma once

namespace vt {

	enum Wrapping {
		// The texture is repeated as many times as necessary.
		WRAPPING_REPEAT,
		// The texture is clamped at its edges.
		WRAPPING_CLAMP
	};

}