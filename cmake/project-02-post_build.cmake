# check & copy static library of godot-cpp
if(LIBPRGE_COPY_GODOTCPP_STATICLIBS)
    if(LIBPRGE_IS_DEBUG)
        file(COPY "${CMAKE_BINARY_DIR}/bin/" DESTINATION "${LIBPRGE_OUTPUT_DIR}" FILES_MATCHING PATTERN "*.editor.*")
        file(COPY "${CMAKE_BINARY_DIR}/bin/" DESTINATION "${LIBPRGE_OUTPUT_DIR}" FILES_MATCHING PATTERN "*.template_debug.*")
    else()
        file(COPY "${CMAKE_BINARY_DIR}/bin/" DESTINATION "${LIBPRGE_OUTPUT_DIR}" FILES_MATCHING PATTERN "*.template_release.*")
    endif()
endif()
