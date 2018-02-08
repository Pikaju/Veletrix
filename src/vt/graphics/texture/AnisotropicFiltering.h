#pragma once

namespace vt {

	enum AnisotropicFiltering
	{
		// Disables anisotropic filtering.
		ANISOTROPIC_FILTERING_NONE,
		// Uses 2x anisotropic filtering, or the highest supported.
		ANISOTROPIC_FILTERING_2,
		// Uses 4x anisotropic filtering, or the highest supported.
		ANISOTROPIC_FILTERING_4,
		// Uses 8x anisotropic filtering, or the highest supported.
		ANISOTROPIC_FILTERING_8,
		// Uses 16x anisotropic filtering, or the highest supported.
		ANISOTROPIC_FILTERING_16,
		// Uses 32x anisotropic filtering, or the highest supported.
		ANISOTROPIC_FILTERING_32
	};

}