set(LIBPRGE_PROJECT_NAME ${PROJECT_NAME})

# libprge build compiler id
set(LIBPRGE_BUILD_COMPILER_ID)

# libprge is in debug
set(LIBPRGE_IS_DEBUG)

# libprge is using vcpkg
set(LIBPRGE_IS_USING_VCPKG)

# godot engine major compatibility
set(LIBPRGE_GODOT_VERSION_MAJOR)
# godot engine minor compatibility
set(LIBPRGE_GODOT_VERSION_MINOR)

# extend 1 add dir of include
set(LIBPRGE_ADD_DIR_INCLUDE)
# extend 1 add dir of lib
set(LIBPRGE_ADD_DIR_LIB)
# extend 1 add dir of share
set(LIBPRGE_ADD_DIR_SHARE)

# libprge compiler is gnu
set(LIBPRGE_COMPILER_IS_GNU)
# libprge compiler is msvc
set(LIBPRGE_COMPILER_IS_MSVC)
# libprge compiler is clang
set(LIBPRGE_COMPILER_IS_CLANG)

# libprge version
set(LIBPRGE_VERSION_MAJOR 0)
set(LIBPRGE_VERSION_MINOR 1)
set(LIBPRGE_VERSION_PATCH 0)
set(LIBPRGE_VERSION_DATES 20241216)
set(LIBPRGE_VERSION_STRING "${LIBPRGE_VERSION_MAJOR}.${LIBPRGE_VERSION_MINOR}.${LIBPRGE_VERSION_PATCH}.${LIBPRGE_VERSION_DATES}")

string(TOLOWER ${CMAKE_SYSTEM_NAME} LIBPRGE_SYSTEM_NAME)
string(TOLOWER ${CMAKE_SYSTEM_PROCESSOR} LIBPRGE_SYSTEM_PROCESSOR)
string(TOLOWER ${CMAKE_BUILD_TYPE} LIBPRGE_SYSTEM_BUILD_TYPE)

if(LIBPRGE_SYSTEM_BUILD_TYPE STREQUAL "release")
    set(LIBPRGE_IS_DEBUG false)
else()
    set(LIBPRGE_IS_DEBUG true)
endif()

if(LIBPRGE_ADD_DIR_INCLUDE)
    message(NOTICE "-- NOTICE for '${PROJECT_NAME}':\n   LIBPRGE_ADD_DIR_INCLUDE is not empty: ${LIBPRGE_ADD_DIR_INCLUDE}")
    set(CMAKE_PREFIX_PATH ${PROJECT_ADD_DIR_INCLUDE} ${CMAKE_PREFIX_PATH})
else()
    message(NOTICE "-- NOTICE for '${PROJECT_NAME}':\n   LIBPRGE_ADD_DIR_INCLUDE is empty")
endif()

if(LIBPRGE_ADD_DIR_LIB)
    message(NOTICE "-- NOTICE for '${PROJECT_NAME}':\n   LIBPRGE_ADD_DIR_LIB is not empty: ${LIBPRGE_ADD_DIR_LIB}")
    set(CMAKE_PREFIX_PATH ${LIBPRGE_ADD_DIR_LIB} ${CMAKE_PREFIX_PATH})
else()
    message(NOTICE "-- NOTICE for '${PROJECT_NAME}':\n   PROJECT_ADD_DIR_LIB is empty")
endif()

if(LIBPRGE_ADD_DIR_SHARE)
    message(NOTICE "-- NOTICE for '${PROJECT_NAME}':\n   LIBPRGE_ADD_DIR_SHARE is not empty: ${LIBPRGE_ADD_DIR_SHARE}")
    set(CMAKE_PREFIX_PATH ${LIBPRGE_ADD_DIR_SHARE} ${CMAKE_PREFIX_PATH})
else()
    message(NOTICE "-- NOTICE for '${PROJECT_NAME}':\n   LIBPRGE_ADD_DIR_SHARE is empty")
endif()

# overwrite
if(${LIBPRGE_SYSTEM_NAME} STREQUAL "darwin")
    set(LIBPRGE_SYSTEM_NAME "macos")
endif()

set(LIBPRGE_OUTPUT "${LIBPRGE_SYSTEM_NAME}_${LIBPRGE_SYSTEM_PROCESSOR}/${LIBPRGE_SYSTEM_BUILD_TYPE}")

message(NOTICE "-- ${PROJECT_NAME}:\n   configuring ${PROJECT_NAME} v${LIBPRGE_VERSION_STRING} for ${LIBPRGE_OUTPUT}")

set(LIBPRGE_OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin/${LIBPRGE_SYSTEM_NAME}_${LIBPRGE_SYSTEM_PROCESSOR}/${LIBPRGE_SYSTEM_BUILD_TYPE}")

set(EXECUTABLE_OUTPUT_PATH         "${LIBPRGE_OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${LIBPRGE_OUTPUT_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${LIBPRGE_OUTPUT_DIR}")
set(CMAKE_PDB_OUTPUT_DIRECTORY     "${LIBPRGE_OUTPUT_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${LIBPRGE_OUTPUT_DIR}")

# # https://github.com/godotengine/godot-cpp/pull/1499
# FUNCTION( GENERATE_GODOT_DOCUMENTATION )
#     # Grab all documentation XML files
#     FILE(GLOB XML_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/libprge_doc/*.xml")
#     STRING(JOIN "," XML_FILES_STR ${XML_FILES})
#     # Generate the target file
#     SET(DOC_DATA_CPP_FILE "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/libprge/doc_data.cc")
#     STRING(JOIN "," DOC_DATA_CPP_STR ${DOC_DATA_CPP_FILE})
#     # Run python to generate the doc_data.cpp file
#     EXECUTE_PROCESS(
#             COMMAND cmd /c py ${CMAKE_CURRENT_SOURCE_DIR}/cmake/generate_godot_docs.py ${DOC_DATA_CPP_STR} ${XML_FILES_STR}
#             WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#     )
# ENDFUNCTION()

# FILE(GLOB_RECURSE gdext_sources
#         CONFIGURE_DEPENDS
#         "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hh"
#         # Includes the generated doc data from /doc_classes
#         "${CMAKE_CURRENT_SOURCE_DIR}/src/cpp/libprge/*.cc"
# )

# GENERATE_GODOT_DOCUMENTATION()
