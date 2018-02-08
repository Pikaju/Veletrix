#pragma once

#include <cstdint>

typedef const char* cString;

// Integer types

// 1 byte signed integer type.
typedef int8_t i8;
// 2 byte signed integer type.
typedef int16_t i16;
// 4 byte signed integer type.
typedef int32_t i32;
// 8 byte signed integer type.
typedef int64_t i64;

// Fastest signed integer type that is at least 1 byte in size.
typedef int_fast8_t i8f;
// Fastest signed integer type that is at least 2 bytes in size.
typedef int_fast16_t i16f;
// Fastest signed integer type that is at least 4 bytes in size.
typedef int_fast32_t i32f;
// Fastest signed integer type that is at least 8 bytes in size.
typedef int_fast64_t i64f;

// Smallest signed integer type that is at least 1 byte in size.
typedef int_least8_t i8l;
// Smallest signed integer type that is at least 2 bytes in size.
typedef int_least16_t i16l;
// Smallest signed integer type that is at least 4 bytes in size.
typedef int_least32_t i32l;
// Smallest signed integer type that is at least 8 bytes in size.
typedef int_least64_t i64l;

// 1 byte unsigned integer type.
typedef uint8_t ui8;
// 2 byte unsigned integer type.
typedef uint16_t ui16;
// 4 byte unsigned integer type.
typedef uint32_t ui32;
// 8 byte unsigned integer type.
typedef uint64_t ui64;

// Fastest unsigned integer type that is at least 1 byte in size.
typedef uint_fast8_t ui8f;
// Fastest unsigned integer type that is at least 2 bytes in size.
typedef uint_fast16_t ui16f;
// Fastest unsigned integer type that is at least 4 bytes in size.
typedef uint_fast32_t ui32f;
// Fastest unsigned integer type that is at least 8 bytes in size.
typedef uint_fast64_t ui64f;

// Smallest signed integer type that is at least 1 byte in size.
typedef uint_least8_t ui8l;
// Smallest signed integer type that is at least 2 bytes in size.
typedef uint_least16_t ui16l;
// Smallest signed integer type that is at least 4 bytes in size.
typedef uint_least32_t ui32l;
// Smallest signed integer type that is at least 8 bytes in size.
typedef uint_least64_t ui64l;

// Float types

// Floating point type that is likely to be 4 bytes in size.
// Define VT_REQUIRE_F32 to ensure it is 4 bytes.
typedef float f32;
#ifdef VT_REQUIRE_F32
static_assert(sizeof(f32) == 4, "Floats have to be 32 bit, since VT_REQUIRE_F32 is defined");
#endif

// Floating point type that is likely to be 8 bytes in size.
// Define VT_REQUIRE_F64 to ensure it is 8 bytes.
typedef double f64;
#ifdef VT_REQUIRE_F64
static_assert(sizeof(f64) == 8, "Doubles have to be 64 bit, since VT_REQUIRE_F64 is defined");
#endif

// Floating point type that is at least as big as f64.
// Will most likely not be 16 bytes in size.
// Define VT_REQUIRE_F128 to ensure it is 16 bytes.
typedef long double f128;
#ifdef VT_REQUIRE_F128
static_assert(sizeof(f128) == 16, "Long doubles have to be 128 bit, since VT_REQUIRE_F128 is defined");
#endif