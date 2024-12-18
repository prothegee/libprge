# start: check toolchain
if("${CMAKE_TOOLCHAIN_FILE}" STREQUAL "")
    message(NOTICE "-- ${PROJECT_NAME}:\n   cmake toolchain file is empty")
else()
    message(NOTICE "-- ${PROJECT_NAME}:\n   including cmake toolchain file \"${CMAKE_TOOLCHAIN_FILE}\"")
    include(${CMAKE_TOOLCHAIN_FILE})
endif()
# end: check toolchain

# start: vcpkg
set(VCPKG_OK false)

if(LIBPRGE_IS_USING_VCPKG)
    if(NOT VCPKG_OK)
        message(NOTICE "-- ${PROJECT_NAME}:\n   you are using \"vcpkg\" of VCPKG_ROOT env variable as \"$ENV{VCPKG_ROOT}\", using the \"vcpkg\" toolchain")
        if("$ENV{VCPKG_ROOT}" STREQUAL "")
            message(NOTICE "-- ${PROJECT_NAME}:\n   VCPKG_ROOT env variable is empty")
        else()
            include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
            set(VCPKG_OK true)
        endif()
    endif()

    if(NOT VCPKG_OK)
        message(NOTICE "-- ${PROJECT_NAME}:\n   you are using \"vcpkg\" of VCPKG_DIR env variable as \"$ENV{VCPKG_DIR}\", using the \"vcpkg\" toolchain")
        if("$ENV{VCPKG_DIR}" STREQUAL "")
            message(NOTICE "-- ${PROJECT_NAME}:\n   VCPKG_DIR env variable is empty")
        else()
            include("$ENV{VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake")
        endif()
    endif()
endif()
# end: vcpkg

# start: godot-cpp
if(LIBPRGE_GODOT_VERSION_MAJOR GREATER_EQUAL 4)
    if(LIBPRGE_GODOT_VERSION_MINOR GREATER_EQUAL 4)
        add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendors/godot-cpp)
    else()
        message(FATAL_ERROR "${PROJECT_NAME}:\n   LIBPRGE_GODOT_VERSION_MINOR of ${LIBPRGE_GODOT_VERSION_MINOR} is not supported")
    endif()
else()
    message(FATAL_ERROR "${PROJECT_NAME}:\n   LIBPRGE_GODOT_VERSION_MAJOR of ${LIBPRGE_GODOT_VERSION_MAJOR} is not supported")
endif()

set(LIBPRGE_GODOTCPP_BUILD_PROPS "template_debug" CACHE STRING "which godot-cpp::target to link against")
set_property(CACHE LIBPRGE_GODOTCPP_BUILD_PROPS PROPERTY STRINGS "template_debug;template_release;editor")
# end: godot-cpp

# start: jsoncpp
set(LIBPRGE_USING_JSONCPP false)

find_package(jsoncpp CONFIG REQUIRED)

if(jsoncpp_FOUND)
    set(LIBPRGE_USING_JSONCPP true)
    message(NOTICE "-- ${PROJECT_NAME}:\n   using jsoncpp")
else()
    message(FATAL_ERROR "-- ${PROJECT_NAME}:\n   can't found jsoncpp library, this library is required")
endif()
# end: jsoncpp

# start: openssl
set(LIBPRGE_USING_OPENSSL false)

find_package(OpenSSL CONFIG REQUIRED)

if(OpenSSL_FOUND)
    set(LIBPRGE_USING_OPENSSL true)
    message(NOTICE "-- ${PROJECT_NAME}:\n   using openssl")
else()
    message(FATAL_ERROR "-- ${PROJECT_NAME}:\n   can't found openssl library, this library is required")
endif()
# end: openssl

# start: sdl
set(LIBPRGE_USING_SDL3 false)

find_package(SDL3 CONFIG)

if(SDL3_FOUND)
    set(LIBPRGE_USING_SDL3 true)
    message(NOTICE "-- ${PROJECT_NAME}:\n   using sdl3")
endif()
# end: sdl

# start: opencv
set(LIBPRGE_USING_OPENCV false)

find_package(opencv CONFIG)

if(opencv_FOUND)
    set(LIBPRGE_USING_OPENCV true)
    message(NOTICE "-- ${PROJECT_NAME}:\n   using opencv")
endif()
# end: opencv

# start: cryptopp
set(LIBPRGE_USING_CRYPTOPP false)

find_package(cryptopp CONFIG)

if(cryptopp_FOUND)
    set(LIBPRGE_USING_CRYPTOPP true)
    message(NOTICE "-- ${PROJECT_NAME}:\n   using cryptopp")
endif()
# end: cryptopp

# start: steamworks-sdk
set(LIBPRGE_USING_STEAMSDK true)

set(LIBPRGE_STEAMWORKS_SDK_DIR_BIN ${CMAKE_CURRENT_SOURCE_DIR}/vendors/steamworks-sdk/redistributable_bin)

if(LIBPRGE_STEAMWORKS_SDK_DIR_BIN)
    set(LIBPRGE_STEAMWORKS_SDK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendors/steamworks-sdk)

    message(NOTICE "-- ${PROJECT_NAME}:\n   STEAMWORKS_SDK_DIR: ${LIBPRGE_STEAMWORKS_SDK_DIR}")

    if(LIBPRGE_SYSTEM_NAME STREQUAL "linux") 
        file(REMOVE ${LIBPRGE_OUTPUT_DIR}/libsteam_api.so)

        file(COPY
            ${LIBPRGE_STEAMWORKS_SDK_DIR}/redistributable_bin/linux64/libsteam_api.so
            DESTINATION
            ${LIBPRGE_OUTPUT_DIR}
        )
    elseif(LIBPRGE_SYSTEM_NAME STREQUAL "windows")
        file(REMOVE ${LIBPRGE_OUTPUT_DIR}/steam_api64.dll)
        file(REMOVE ${LIBPRGE_OUTPUT_DIR}/steam_api64.lib)

        file(COPY
            ${LIBPRGE_STEAMWORKS_SDK_DIR}/redistributable_bin/win64/steam_api64.dll
            ${LIBPRGE_STEAMWORKS_SDK_DIR}/redistributable_bin/win64/steam_api64.lib
            DESTINATION
            ${LIBPRGE_OUTPUT_DIR}
        )
    elseif(LIBPRGE_SYSTEM_NAME STREQUAL "macos")
        file(REMOVE ${LIBPRGE_OUTPUT_DIR}/libsteam_api.dylib)

        file(COPY
            ${LIBPRGE_STEAMWORKS_SDK_DIR}/redistributable_bin/osx/libsteam_api.dylib
            DESTINATION
            ${LIBPRGE_OUTPUT_DIR}
        )
    else()
        message(NOTICE "-- ${PROJECT_NAME}:\n   steamworks-sdk is not implemented for \"${LIBPRGE_SYSTEM_NAME}\" system")

        set(LIBPRGE_USING_STEAMSDK false)
    endif()
else()
    message(NOTICE "-- ${PROJECT_NAME}:\n   couldn't find LIBPRGE_STEAMWORKS_SDK_DIR_BIN, skipping steamworks-sdk")
endif()

if(NOT ${LIBPRGE_STEAMWORKS_SDK_DIR} STREQUAL "")
    set(LIBPRGE_STEAMWORKS_SDK_LIB_FILE)

    include_directories(${LIBPRGE_STEAMWORKS_SDK_DIR}/public)
    include_directories(${LIBPRGE_STEAMWORKS_SDK_DIR}/public/lib)

    if(LIBPRGE_SYSTEM_NAME STREQUAL "linux") 
        include_directories(${LIBPRGE_STEAMWORKS_SDK_DIR}/redistributable_bin/linux64)
        set(LIBPRGE_STEAMWORKS_SDK_LIB_FILE "${LIBPRGE_STEAMWORKS_SDK_DIR}/redistributable_bin/linux64/libsteam_api.so")
    elseif(LIBPRGE_SYSTEM_NAME STREQUAL "windows")
        include_directories(${LIBPRGE_STEAMWORKS_SDK_DIR}/redistributable_bin/win64)
        set(LIBPRGE_STEAMWORKS_SDK_LIB_FILE "${LIBPRGE_STEAMWORKS_SDK_DIR}/redistributable_bin/win64/steam_api64.lib")
    elseif(LIBPRGE_SYSTEM_NAME STREQUAL "macos")
        include_directories(${LIBPRGE_STEAMWORKS_SDK_DIR}/redistributable_bin/osx)
        set(LIBPRGE_STEAMWORKS_SDK_LIB_FILE "${LIBPRGE_STEAMWORKS_SDK_DIR}/redistributable_bin/osx/libsteam_api.dylib")
    else()
        message(NOTICE "-- ${PROJECT_NAME}:\n   project build target not accepting steamworks-sdk as included directories")

        set(LIBPRGE_USING_STEAMSDK false)
    endif()
endif()
# end: steamworks-sdk
