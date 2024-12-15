#ifndef LIBPRGE_CONFIG_HH
#define LIBPRGE_CONFIG_HH
#include <cstdint>
#include <string>
#include <array>

#include <godot_cpp/variant/utility_functions.hpp>

#ifndef LIBPRGE_PROJECT_NAME
    #define LIBPRGE_PROJECT_NAME "@LIBPRGE_PROJECT_NAME@"
#endif // LIBPRGE_PROJECT_NAME

#ifndef LIBPRGE_IS_DEBUG
    // libprge is debug mode
    #define LIBPRGE_IS_DEBUG @LIBPRGE_IS_DEBUG@
#endif // LIBPRGE_IS_DEBUG

#ifndef LIBPRGE_BUILD_COMPILER_ID
    // 0:undefined 1:GNU 2:MSVC 3:[Cc]lang
    #define LIBPRGE_BUILD_COMPILER_ID @LIBPRGE_BUILD_COMPILER_ID@
#endif // LIBPRGE_BUILD_COMPILER_ID

#ifndef LIBPRGE_COMPILER_IS_GNU
    // using gnu compiler
    #define LIBPRGE_COMPILER_IS_GNU @LIBPRGE_COMPILER_IS_GNU@
#endif // LIBPRGE_COMPILER_IS_GNU

#ifndef LIBPRGE_COMPILER_IS_MSVC
    // using msvc compiler
    #define LIBPRGE_COMPILER_IS_MSVC @LIBPRGE_COMPILER_IS_MSVC@
#endif // LIBPRGE_COMPILER_IS_MSVC

#ifndef LIBPRGE_COMPILER_IS_CLANG
    // using clang compiler
    #define LIBPRGE_COMPILER_IS_CLANG @LIBPRGE_COMPILER_IS_CLANG@
#endif // LIBPRGE_COMPILER_IS_CLANG

#ifndef LIBPRGE_VERSION_MAJOR
    // libprge major version
    #define LIBPRGE_VERSION_MAJOR @LIBPRGE_VERSION_MAJOR@
#endif // LIBPRGE_VERSION_MAJOR

#ifndef LIBPRGE_VERSION_MINOR
    // libprge minor version
    #define LIBPRGE_VERSION_MINOR @LIBPRGE_VERSION_MINOR@
#endif // LIBPRGE_VERSION_MINOR

#ifndef LIBPRGE_VERSION_PATCH
    // libprge patch version
    #define LIBPRGE_VERSION_PATCH @LIBPRGE_VERSION_PATCH@
#endif // LIBPRGE_VERSION_PATCH

#ifndef LIBPRGE_VERSION_STRING
    // libprge string version
    #define LIBPRGE_VERSION_STRING "@LIBPRGE_VERSION_STRING@"
#endif // LIBPRGE_VERSION_STRING

// godot utility functions
using gdufunc = godot::UtilityFunctions;

namespace libprge
{

#ifndef UINT64_MAX
    #define UINT64_MAX 18446744073709551615ULL
#endif // UINT64_MAX

#pragma region custom types
// alter type of int32_t
typedef int32_t i32;

// alter type of int64_t
typedef int64_t i64;

// alter type of signed int 128
// has two array partition, which 0 & 1
using int128_t = std::array<int64_t, 2>;

// alter type of int128_t
// has two array partition, which 0 & 1
struct i128
{
    i128() { data = { 0,0 }; }
    i128(i64 first, i64 second) { data = { first, second }; }
    ~i128() {}

    int128_t data;
};

// alter type of uint32_t
typedef uint32_t ui32;

// alter type of uint64_t
typedef uint64_t ui64;

// alter type of unsigned int 128
// has two array partition, which 0 & 1
using uint128_t = std::array<uint64_t, 2>;

// alter type of uint128_t
// has two array partition, which 0 & 1
struct ui128
{
    ui128() { data = { 0, 0 }; }
    ui128(ui64 first, ui64 second) { data = { first, second }; }
    ~ui128() {}

    uint128_t data;
};

// alter type of float
typedef float f32;

// alter type of double
typedef double f64;
#pragma endregion

#ifndef LIBPRGE_USING_JSONCPP
    // libprge using jsoncpp
    #define LIBPRGE_USING_JSONCPP @LIBPRGE_USING_JSONCPP@
#endif // LIBPRGE_USING_JSONCPP

#ifndef LIBPRGE_USING_SDL3
    // libprge using sdl3
    #define LIBPRGE_USING_SDL3 @LIBPRGE_USING_SDL3@
#endif // LIBPRGE_USING_SDL3

#ifndef LIBPRGE_USING_OPENCV
    // libprge using opencv
    #define LIBPRGE_USING_OPENCV @LIBPRGE_USING_OPENCV@
#endif // LIBPRGE_USING_OPENCV

#ifndef LIBPRGE_USING_OPENSSL
    // libprge using openssl
    #define LIBPRGE_USING_OPENSSL @LIBPRGE_USING_OPENSSL@
#endif // LIBPRGE_USING_OPENSSL

#ifndef LIBPRGE_USING_CRYPTOPP
    // libprge using cryptopp
    #define LIBPRGE_USING_CRYPTOPP @LIBPRGE_USING_CRYPTOPP@
#endif // LIBPRGE_USING_CRYPTOPP

#ifndef LIBPRGE_USING_STEAMSDK
    // libprge using steamworks-sdk
    #define LIBPRGE_USING_STEAMSDK @LIBPRGE_USING_STEAMSDK@
#endif // LIBPRGE_USING_STEAMSDK

} // namespace libprge

#endif // LIBPRGE_CONFIG_HH
