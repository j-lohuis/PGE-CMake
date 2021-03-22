
set(CMAKE_EXECUTABLE_SUFFIX .html)
set(CMAKE_CXX_STANDARD 17)

function(set_emscripten_options project_name)

    if (UNIX)
        target_link_libraries(${project_name} PRIVATE -lX11 -lGL -lpthread -lpng)
    endif (UNIX)

    option(PGE_INCLUDE_ASSETS "Include the 'assets' folder" TRUE)
    if (PGE_INCLUDE_ASSETS)
        file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
    endif()

    if (${CMAKE_CXX_COMPILER} MATCHES ".*em[+][+]")
        set(PGE_LINKER_OPTIONS -sALLOW_MEMORY_GROWTH=1 -sMAX_WEBGL_VERSION=2 -sMIN_WEBGL_VERSION=2 -sUSE_LIBPNG=1)
        if (PGE_INCLUDE_ASSETS)
            target_link_options(${project_name} PRIVATE ${PGE_LINKER_OPTIONS} --preload-file "./assets")
        else()
            target_link_options(${project_name} PRIVATE ${PGE_LINKER_OPTIONS})
        endif()
    endif()
endfunction()
