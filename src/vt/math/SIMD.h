#pragma once

#define VT_SIMD_SSE

#ifdef VT_SIMD_SSE
#include <xmmintrin.h>

#define VT_SIMD_REQUIRED_ALIGNMENT 16

#define VT_SIMD_ALIGNED_MALLOC(size, alignment) _mm_malloc(size, alignment)
#define VT_SIMD_ALIGNED_FREE(block) _mm_free(block)

#define VT_SIMD_MALLOC(size) VT_SIMD_ALIGNED_MALLOC(size, VT_SIMD_REQUIRED_ALIGNMENT)
#define VT_SIMD_FREE(block) VT_SIMD_ALIGNED_FREE(block)


#endif

