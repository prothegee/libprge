cmake_minimum_required(VERSION 3.15...3.30)


# versions
set(LIBPRGE_VERSION_MAJOR  0)
set(LIBPRGE_VERSION_MINOR  0)
set(LIBPRGE_VERSION_PATCH  0)
set(LIBPRGE_VERSION_DATES  20250214)
set(LIBPRGE_VERSION_STRING "${LIBPRGE_VERSION_MAJOR}.${LIBPRGE_VERSION_MINOR}.${LIBPRGE_VERSION_PATCH}.${LIBPRGE_VERSION_DATES}")


# project info
project(libprge
    VERSION "${LIBPRGE_VERSION_MAJOR}.${LIBPRGE_VERSION_MINOR}.${LIBPRGE_VERSION_PATCH}"
    DESCRIPTION "an addons/extensions for godot game engine"
    HOMEPAGE_URL "https://dev.prothegee.com/en/libprge"
    LANGUAGES CXX
)


# option/s
## build example, default false/OFF
option(LIBPRGE_BUILD_EXAMPLE "libprge: build example for godot game engine" OFF)


# build system variables
if(NOT DEFINED LIBPRGE_SYSTEM_NAME)
    set(LIBPRGE_SYSTEM_NAME "")
endif()

if(NOT DEFINED LIBPRGE_SYSTEM_PROCESSOR)
    set(LIBPRGE_SYSTEM_PROCESSOR "")
endif()

if(NOT DEFINED LIBPRGE_SYSTEM_BUILD_TYPE)
    set(LIBPRGE_SYSTEM_BUILD_TYPE "")
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()


string(TOLOWER "${CMAKE_SYSTEM_NAME}"      LIBPRGE_SYSTEM_NAME)
string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" LIBPRGE_SYSTEM_PROCESSOR)
string(TOLOWER "${CMAKE_BUILD_TYPE}"       LIBPRGE_SYSTEM_BUILD_TYPE)


# [V] 0:undefined
# [V] 1:linux
# [V] 2:windows
# [V] 3:macos
# [X] 4:android
# [X] 5:ios
# [X] 6:web
# [X] 7:ps
# [X] 8:xbox
# [X] 9:nintendo
set(LIBPRGE_BUILD_TARGET 0)

# assign build target num
if(${LIBPRGE_SYSTEM_NAME} STREQUAL "linux")
    set(LIBPRGE_BUILD_TARGET 1)
elseif(${LIBPRGE_SYSTEM_NAME} STREQUAL "windows")
    set(LIBPRGE_BUILD_TARGET 2)
elseif(${LIBPRGE_SYSTEM_NAME} STREQUAL "macos")
    set(LIBPRGE_BUILD_TARGET 3)
else()
    message(NOTICE "-- ${PROJECT_NAME}:\n   build system is unknown")
endif()

# overwrite
if(${LIBPRGE_SYSTEM_NAME} STREQUAL "darwin")
    set(LIBPRGE_BUILD_TARGET 3)
    set(LIBPRGE_SYSTEM_NAME "macos")
endif()

# RESERVED: android, ios, & etc.


# 0:undefined 1:debug 2:staging 3:demo 4:release
set(LIBPRGE_BUILD_STATUS 0)

# libprge build status
if(LIBPRGE_SYSTEM_BUILD_TYPE STREQUAL "debug")
    set(LIBPRGE_BUILD_STATUS 1)
elseif(LIBPRGE_SYSTEM_BUILD_TYPE STREQUAL "profile")
    set(LIBPRGE_BUILD_STATUS 1)
elseif(LIBPRGE_SYSTEM_BUILD_TYPE STREQUAL "relwithdebinfo")
    set(LIBPRGE_BUILD_STATUS 2)
elseif(LIBPRGE_SYSTEM_BUILD_TYPE STREQUAL "release")
    set(LIBPRGE_BUILD_STATUS 3)
elseif(LIBPRGE_SYSTEM_BUILD_TYPE STREQUAL "minsizerel")
    set(LIBPRGE_BUILD_STATUS 4)
endif()

# libprge debug status, release & misizerel is not debug
if(LIBPRGE_SYSTEM_BUILD_TYPE STREQUAL "release")
    set(LIBPRGE_IS_DEBUG false)
elseif(LIBPRGE_SYSTEM_BUILD_TYPE STREQUAL "minsizerel")
    set(LIBPRGE_IS_DEBUG false)
else()
    set(LIBPRGE_IS_DEBUG true)
endif()


# output dir
set(LIBPRGE_OUTPUT_DIR)

if(LIBPRGE_IS_DEBUG)
    set(LIBPRGE_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/addons/libprge/bin/${LIBPRGE_SYSTEM_NAME}/debug")
    # set(LIBPRGE_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/addons/libprge/bin/${LIBPRGE_SYSTEM_NAME}_${LIBPRGE_SYSTEM_PROCESSOR}/debug") # tmp: don't remove
else()
    set(LIBPRGE_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/addons/libprge/bin/${LIBPRGE_SYSTEM_NAME}/release")
    # set(LIBPRGE_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/addons/libprge/bin/${LIBPRGE_SYSTEM_NAME}_${LIBPRGE_SYSTEM_PROCESSOR}/release") # tmp: don't remove
endif()

## addons dir
if(NOT EXISTS "${LIBPRGE_OUTPUT_DIR}")
    file(MAKE_DIRECTORY "${LIBPRGE_OUTPUT_DIR}")
endif()


# MAYBE: pre-configuration


# include base
include(CheckIncludeFileCXX)
include(CMakeDependentOption)
include(FindPackageHandleStandardArgs)


# subdirs vendors
## jsoncpp
set(JSONCPP_WITH_TESTS false)
set(JSONCPP_WITH_EXAMPLE false)
add_subdirectory(vendors/jsoncpp LIBPRGE_JSONCPP)
link_directories(${CMAKE_BINARY_DIR}/LIBPRGE_JSONCPP/src/lib_json)
include_directories(vendors/jsoncpp/include)

## cryptopp-cmake
set(CRYPTOPP_BUILD_TESTING false)
add_subdirectory(vendors/cryptopp-cmake LIBPRGE_CRYPTOPP_CMAKE)

## sdl
set(SDL_TESTS false)
set(SDL_EXAMPLES false)
add_subdirectory(vendors/sdl LIBPRGE_SDL)

## godot-cpp
add_subdirectory(vendors/godot-cpp LIBPRGE_GODOT_CPP)


# packages
## python3
find_package(Python3 REQUIRED)
if(Python3_FOUND)
    set(LIBPRGE_USING_PYTHON3 true)
else()
    message(FATAL_ERROR "-- python3 package is required to create docs")
endif()


# static lib
add_library(${PROJECT_NAME} SHARED
    library/inc/libprge/libprge.hh library/src/libprge/libprge.cc
)


# c++ std
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_CXX_STANDARD LESS 17)
    set(CMAKE_CXX_STANDARD 17)
else()
    # do nothing
endif()


# prefixes
set(PREFIX                      "")
set(IMPORT_PREFIX               "")
set(OUTPUT_NAME                 "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")


# compiler config
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(LIBPRGE_COMPILER_ID    1)
    set(LIBPRGE_COMPILER_GNU   true)
    set(LIBPRGE_COMPILER_MSVC  false)
    set(LIBPRGE_COMPILER_CLANG false)

    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-value
        -Wno-unused-variable
        -Wno-reorder
        -Wno-parentheses
        -Wno-switch
        -Wno-format
        -Wno-invalid-offsetof
        -Wno-multichar
        -Wno-char-subscripts
        -Wno-empty-body
        -Wno-unused-function
        -Wno-deprecated-declarations
    )

    # c++ std
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${CMAKE_CXX_STANDARD}")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(LIBPRGE_COMPILER_ID    2)
    set(LIBPRGE_COMPILER_GNU   false)
    set(LIBPRGE_COMPILER_MSVC  true)
    set(LIBPRGE_COMPILER_CLANG false)

    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
        /wd4996
    )

    # c++ std
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++${CMAKE_CXX_STANDARD}")

    # # exception handling
    # if(NOT CMAKE_CXX_FLAGS MATCHES "/EHa")
    #     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHa")
    # endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "[Cc]lang")
    set(LIBPRGE_COMPILER_ID    3)
    set(LIBPRGE_COMPILER_GNU   false)
    set(LIBPRGE_COMPILER_MSVC  false)
    set(LIBPRGE_COMPILER_CLANG true)

    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-value
        -Wno-unused-variable
        -Wno-reorder
        -Wno-parentheses
        -Wno-switch
        -Wno-format
        -Wno-dynamic-class-memaccess
        -Wno-unused-private-field
        -Wno-invalid-offsetof
        -Wno-multichar
        -Wno-char-subscripts
        -Wno-null-conversion
        -Wno-empty-body
        -Wno-unused-lambda-capture
        -Wno-unused-function
        -Wno-tautological-constant-out-of-range-compare
        -Wno-deprecated-declarations
    )

    # c++ std
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${CMAKE_CXX_STANDARD}")
else()
    set(LIBPRGE_COMPILER_ID    0)
    set(LIBPRGE_COMPILER_GNU   false)
    set(LIBPRGE_COMPILER_MSVC  false)
    set(LIBPRGE_COMPILER_CLANG false)

    message(NOTICE "-- ${PROJECT_NAME}:\n   -DCMAKE_CXX_COMPILER_ID is not supported as ${CMAKE_CXX_COMPILER_ID}")
endif()


# target link libs
## jsoncpp
target_link_libraries(${PROJECT_NAME} PRIVATE jsoncpp)

## cryptopp-cmake
target_link_libraries(${PROJECT_NAME} PRIVATE cryptopp::cryptopp)

## sdl
target_link_libraries(${PROJECT_NAME} PRIVATE SDL_uclibc)

## godot-cpp
if(LIBPRGE_IS_DEBUG)
    target_link_libraries(${PROJECT_NAME} PRIVATE godot-cpp::template_debug)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE godot-cpp::template_release)
endif()


# generate docs if debug
if(LIBPRGE_IS_DEBUG AND LIBPRGE_USING_PYTHON3)
    set(LIBPRGE_DOC_DATA_SOURCE "${CMAKE_CURRENT_BINARY_DIR}/library/src/libprge/libprge_docs.gen.cc")

    file(REMOVE "${LIBPRGE_DOC_DATA_SOURCE}")    

    file(GLOB_RECURSE LIBPRGE_DOC_XML
        LIST_DIRECTORIES NO
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/library/xml/libprge/*.xml"
    )

    generate_doc_source("${LIBPRGE_DOC_DATA_SOURCE}" "${LIBPRGE_DOC_XML}")

    target_sources(${PROJECT_NAME} PRIVATE "${LIBPRGE_DOC_DATA_SOURCE}")
endif()


# libprge config
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/library/inc/libprge/config.in.hh
    ${CMAKE_CURRENT_SOURCE_DIR}/library/inc/libprge/config.hh
)


# aux source & target source
aux_source_directory(${PROJECT_SOURCE_DIR}/library/src/libprge LIBPRGE_SRC_DIR)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${LIBPRGE_SRC_DIR}
)


# target include dirs
target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/library/inc
)


# post build
## libprge lib files
file(GLOB LIBPRGE_BUILD_FILES "${CMAKE_BINARY_DIR}/libprge.*")

foreach(file ${LIBPRGE_BUILD_FILES})
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            ${file}
            ${LIBPRGE_OUTPUT_DIR}
            COMMENT "copying ${file} to addons of libprge"
    )
endforeach()

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${PROJECT_SOURCE_DIR}/.gitignore
        ${PROJECT_SOURCE_DIR}/addons/.gitignore
    COMMENT "copying .gitignore to addons of libprge"
)
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${PROJECT_SOURCE_DIR}/README.md
        ${PROJECT_SOURCE_DIR}/addons/README.md
    COMMENT "copying readme to addons of libprge"
)
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/docs
        ${PROJECT_SOURCE_DIR}/addons/libprge/docs
    COMMENT "copying docs to addons of libprge"
)

# apporgame/example
if(LIBPRGE_EXAMPLE)
    message(NOTICE "-- configuring post build for approgame/example")
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/addons
            ${PROJECT_SOURCE_DIR}/apporgame/addons
            COMMENT "copy addons to apporgame/example dir"
    )
endif()


# supply last log cxx flags and linker flags
if(NOT CMAKE_CXX_FLAGS STREQUAL "")
    message(NOTICE "-- ${PROJECT_NAME}: CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
endif()
if(NOT CMAKE_EXE_LINKER_FLAGS STREQUAL "")
    message(NOTICE "-- ${PROJECT_NAME}: CMAKE_EXE_LINKER_FLAGS: ${CMAKE_EXE_LINKER_FLAGS}")
endif()


# supply last log configuration
message(NOTICE "-- ${PROJECT_NAME} v${LIBPRGE_VERSION_STRING} for ${LIBPRGE_SYSTEM_BUILD_TYPE} using c++${CMAKE_CXX_STANDARD} configured")
