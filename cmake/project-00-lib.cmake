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
set(VCPKG_ERROR 0)

if(LIBPRGE_USE_VCPKG)
    if(NOT VCPKG_OK)
        message(NOTICE "-- ${PROJECT_NAME}:\n   you are using \"vcpkg\" of VCPKG_ROOT env variable as \"$ENV{VCPKG_ROOT}\", using the \"vcpkg\" toolchain")
        if("$ENV{VCPKG_ROOT}" STREQUAL "")
            message(NOTICE "-- ${PROJECT_NAME}:\n   VCPKG_ROOT env variable is empty")
            set(VCPKG_ERROR 1)
        else()
            include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
            set(VCPKG_OK true)
        endif()
    endif()

    if(NOT VCPKG_OK)
        message(NOTICE "-- ${PROJECT_NAME}:\n   you are using \"vcpkg\" of VCPKG_DIR env variable as \"$ENV{VCPKG_DIR}\", using the \"vcpkg\" toolchain")
        if("$ENV{VCPKG_DIR}" STREQUAL "")
            message(NOTICE "-- ${PROJECT_NAME}:\n   VCPKG_DIR env variable is empty")
            set(VCPKG_ERROR 2)
        else()
            include("$ENV{VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake")
            set(VCPKG_OK true)
        endif()
    endif()

    if(NOT VCPKG_ERROR EQUAL 0)
        message(FATAL_ERROR "-- ${PROJECT_NAME}:\n   you are attempting using vcpkg, but \"VCPKG_DIR\" or \"VCPKG_ROOT\" is not set as environment variable")
    endif()
endif()
# end: vcpkg

# start: REQUIRED
# start: godot-cpp
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendors/godot-cpp)
# end: godot-cpp

# start: python3
set(LIBPRGE_USING_PYTHON3 false)

find_package(Python3)
if(Python3_FOUND)
    set(LIBPRGE_USING_PYTHON3 true)
    message(NOTICE "-- ${PROJECT_NAME}:\n   found python3 as ${Python3_EXECUTABLE}")
else()
    message(WARNING "-- ${PROJECT_NAME}:\n   python3 is not found, attempting to check Python3_EXECUTABLE")
    if(Python3_EXECUTABLE STREQUAL "")
        message(FATAL_ERROR "-- ${PROJECT_NAME}:\n   fail to attempt check Python3_EXECUTABLE, you need to set it mannualy as \"-DPython3_EXECUTABLE=/path/to/python\" executeable")
    else()
        message(NOTICE "-- ${PROJECT_NAME}:\n   python3 found as manual implementation of Python3_EXECUTABLE as ${Python3_EXECUTABLE}")
    endif()
endif()
# end: python3
# end: REQUIRED

# start: steamworks-sdk
set(LIBPRGE_USING_STEAMWORKS_SDK false)

if(NOT ${LIBPRGE_STEAMWORKS_SDK_DIR} STREQUAL "")
    message(NOTICE "-- ${PROJECT_NAME}:\n   LIBPRGE_STEAMWORKS_SDK_DIR found as ${LIBPRGE_STEAMWORKS_SDK_DIR}")
endif()
# end: steamworks-sdk
