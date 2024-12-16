#ifndef LIBPRGE_CONFIG_HH
#define LIBPRGE_CONFIG_HH
#include "internal/internal_base_types.hh"

#include <godot_cpp/variant/utility_functions.hpp>

// godot utility functions
using gdufunc = godot::UtilityFunctions;


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


#endif // LIBPRGE_CONFIG_HH
