cmake_minimum_required(VERSION 3.15...3.30)
project(libprge LANGUAGES CXX)

include(CheckIncludeFileCXX)
include(CMakeDependentOption)
include(GenerateExportHeader)
include(FindPackageHandleStandardArgs)
include(cmake/project-00-setup.cmake)
include(cmake/project-01-packages.cmake)

if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

if(NOT ${CMAKE_CXX_STANDARD} STREQUAL "")
    message(NOTICE "-- ${PROJECT_NAME}:\n   using c++${CMAKE_CXX_STANDARD}")
else()
    message(NOTICE "-- ${PROJECT_NAME}:\n   cxx standard is not set")
endif()

set(PREFIX        "")
set(IMPORT_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

# reserved: pre-build

# start: project include
if(LIBPRGE_ADD_DIR_INCLUDE)
    include_directories(${LIBPRGE_ADD_DIR_INCLUDE})
endif()
    
if(LIBPRGE_ADD_DIR_LIB)
    include_directories(${LIBPRGE_ADD_DIR_LIB})
endif()

if(LIBPRGE_ADD_DIR_SHARE)
    include_directories(${LIBPRGE_ADD_DIR_SHARE})
endif()
# end: project include

add_library(${PROJECT_NAME} SHARED
    src/cpp/libprge/libprge.hh src/cpp/libprge/libprge.cc
    src/cpp/libprge/registrar.cc
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(LIBPRGE_COMPILER_IS_GNU true)
    set(LIBPRGE_COMPILER_IS_MSVC false)
    set(LIBPRGE_COMPILER_IS_CLANG false)

    set(LIBPRGE_BUILD_COMPILER_ID 1)

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
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(LIBPRGE_COMPILER_IS_GNU false)
    set(LIBPRGE_COMPILER_IS_MSVC true)
    set(LIBPRGE_COMPILER_IS_CLANG false)

    set(LIBPRGE_BUILD_COMPILER_ID 2)

    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
    )
elseif(CMAKE_CXX_COMPILER_ID MATCHES "[Cc]lang")
    set(LIBPRGE_COMPILER_IS_GNU false)
    set(LIBPRGE_COMPILER_IS_MSVC false)
    set(LIBPRGE_COMPILER_IS_CLANG true)

    set(LIBPRGE_BUILD_COMPILER_ID 3)

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
    )
else()
    set(LIBPRGE_COMPILER_IS_GNU false)
    set(LIBPRGE_COMPILER_IS_MSVC false)
    set(LIBPRGE_COMPILER_IS_CLANG false)

    set(LIBPRGE_BUILD_COMPILER_ID 0)

    message(NOTICE "${PROJECT_NAME}:\n   -DCMAKE_CXX_COMPILER_ID is not implemented for ${CMAKE_CXX_COMPILER_ID}")
endif()

# start: link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE godot-cpp::${LIBPRGE_GODOTCPP_BUILD_PROPS})

if(LIBPRGE_USING_JSONCPP)
    target_link_libraries(${PROJECT_NAME} PRIVATE JsonCpp::JsonCpp)
endif()

if(LIBPRGE_USING_OPENSSL)
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::SSL OpenSSL::Crypto)
endif()

if(LIBPRGE_USING_SDL3)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
endif()

if(LIBPRGE_USING_OPENCV)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})
endif()

if(LIBPRGE_USING_CRYPTOPP)
    target_link_libraries(${PROJECT_NAME} PRIVATE cryptopp::cryptopp)
endif()

if(LIBPRGE_USING_STEAMSDK)
    target_link_libraries(${PROJECT_NAME} PRIVATE "${LIBPRGE_STEAMWORKS_SDK_LIB_FILE}")
endif()
# end: link libraries

generate_export_header(${PROJECT_NAME}
    EXPORT_FILE_NAME
        ${PROJECT_SOURCE_DIR}/src/cpp/libprge/base/export.hh
)

configure_file(
    ${PROJECT_SOURCE_DIR}/src/cpp/libprge/base/config.in.hh
    ${PROJECT_SOURCE_DIR}/src/cpp/libprge/base/config.hh
)

aux_source_directory(src/cpp/libprge LIBPRGE_DIR)
aux_source_directory(src/cpp/libprge/base LIBPRGE_DIR_BASE)
aux_source_directory(src/cpp/libprge/constants LIBPRGE_DIR_CONSTANTS)
aux_source_directory(src/cpp/libprge/enums LIBPRGE_DIR_ENUMS)
aux_source_directory(src/cpp/libprge/functions LIBPRGE_DIR_FUNCTIONS)
aux_source_directory(src/cpp/libprge/interfaces LIBPRGE_DIR_INTERFACES)
aux_source_directory(src/cpp/libprge/nodes LIBPRGE_DIR_NODES)
    aux_source_directory(src/cpp/libprge/nodes/3d LIBPRGE_DIR_NODES_3D)
    aux_source_directory(src/cpp/libprge/nodes/ui LIBPRGE_DIR_NODES_UI)
aux_source_directory(src/cpp/libprge/tools LIBPRGE_DIR_TOOLS)
aux_source_directory(src/cpp/libprge/types LIBPRGE_DIR_TYPES)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${LIBPRGE_DIR}
        ${LIBPRGE_DIR_BASE}
        ${LIBPRGE_DIR_CONSTANTS}
        ${LIBPRGE_DIR_ENUMS}
        ${LIBPRGE_DIR_FUNCTIONS}
        ${LIBPRGE_DIR_INTERFACES}
        ${LIBPRGE_DIR_NODES}
            ${LIBPRGE_DIR_NODES_3D}
            ${LIBPRGE_DIR_NODES_UI}
        ${LIBPRGE_DIR_TOOLS}
        ${LIBPRGE_DIR_TYPES}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/src/cpp
        $<BUILD_INTERFACE:${LIBPRGE_STEAMWORKS_SDK_DIR}>/public
)

include(cmake/project-02-post_build.cmake)
