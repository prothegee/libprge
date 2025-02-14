#ifndef LIBPRGE_CONFIG_HH
#define LIBPRGE_CONFIG_HH
#include <gdextension_interface.h>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/dir_access.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/resource_importer.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/tree.hpp>
#include <godot_cpp/classes/window.hpp>
#include <godot_cpp/classes/audio_bus_layout.hpp>
#include <godot_cpp/classes/audio_server.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/engine_ptrcall.hpp>
#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/gdvirtual.gen.inc>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

#ifndef LIBPRGE_DEBUG
    #define LIBPRGE_DEBUG @LIBPRGE_DEBUG@
#endif // LIBPRGE_DEBUG

#ifndef LIBPRGE_BUILD_COMPILER_ID
    // 0:undefined 1:GNU 2:MSVC 3:[Cc]lang
    #define LIBPRGE_BUILD_COMPILER_ID @LIBPRGE_BUILD_COMPILER_ID@
#endif // LIBPRGE_BUILD_COMPILER_ID

#ifndef LIBPRGE_COMPILER_GNU
    // current compiler is gnu
    #define LIBPRGE_COMPILER_GNU @LIBPRGE_COMPILER_GNU@
#endif // LIBPRGE_COMPILER_GNU

#ifndef LIBPRGE_COMPILER_MSVC
    // current compiler is msvc
    #define LIBPRGE_COMPILER_MSVC @LIBPRGE_COMPILER_MSVC@
#endif // LIBPRGE_COMPILER_MSVC

#ifndef LIBPRGE_COMPILER_CLANG
    // current compiler is clang
    #define LIBPRGE_COMPILER_CLANG @LIBPRGE_COMPILER_CLANG@
#endif // LIBPRGE_COMPILER_CLANG

#ifndef LIBPRGE_CPP_STANDARD
    #define LIBPRGE_CPP_STANDARD @LIBPRGE_CPP_STANDARD@
#endif // LIBPRGE_CPP_STANDARD

#ifndef LIBPRGE_VERSION_MAJOR
    #define LIBPRGE_VERSION_MAJOR @LIBPRGE_VERSION_MAJOR@
#endif // LIBPRGE_VERSION_MAJOR

#ifndef LIBPRGE_VERSION_MINOR
    #define LIBPRGE_VERSION_MINOR @LIBPRGE_VERSION_MINOR@
#endif // LIBPRGE_VERSION_MINOR

#ifndef LIBPRGE_VERSION_PATCH
    #define LIBPRGE_VERSION_PATCH @LIBPRGE_VERSION_PATCH@
#endif // LIBPRGE_VERSION_PATCH

#ifndef LIBPRGE_VERSION_DATES
    #define LIBPRGE_VERSION_DATES @LIBPRGE_VERSION_DATES@
#endif // LIBPRGE_VERSION_DATES

#ifndef LIBPRGE_VERSION_STRING
    #define LIBPRGE_VERSION_STRING "@LIBPRGE_VERSION_STRING@"
#endif // LIBPRGE_VERSION_STRING

inline static const double __DOUBLE_ZERO__     =    0.00000000000000000;
inline static const double __DOUBLE_ZERO_MIN__ =   -0.00000000000000000;
inline static const double __DOUBLE_360__      =  360.00000000000000000;
inline static const double __DOUBLE_359__      =  359.99999999999999999;

namespace libprge
{
} // namespace libprge

// godot utility functions
using gdufunc = godot::UtilityFunctions;

#if defined(__GNUC__) || defined(__clang__)
    #define DEPRECATED(msg) __attribute__((deprecated(msg)))
#elif defined(_MSC_VER)
    #define DEPRECATED(msg) __declspec(deprecated(msg))
#else
    #define DEPRECATED(msg)
#endif

#endif // LIBPRGE_CONFIG_HH
