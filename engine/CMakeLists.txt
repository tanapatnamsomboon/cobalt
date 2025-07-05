add_library(cobalt_engine STATIC)

target_precompile_headers(cobalt_engine PRIVATE include/pch.h)

target_sources(cobalt_engine
        PRIVATE
            src/core/log.cpp
            src/core/window.cpp
            src/core/application.cpp
            src/platform/windows/windows_window.cpp
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include/cobalt/core/base.h
            ${CMAKE_CURRENT_SOURCE_DIR}/include/cobalt/core/log.h
            ${CMAKE_CURRENT_SOURCE_DIR}/include/cobalt/core/assert.h
            ${CMAKE_CURRENT_SOURCE_DIR}/include/cobalt/core/window.h
            ${CMAKE_CURRENT_SOURCE_DIR}/include/cobalt/core/application.h
            ${CMAKE_CURRENT_SOURCE_DIR}/include/cobalt/platform/windows/windows_window.h
)

target_include_directories(cobalt_engine
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(cobalt_engine
        PRIVATE
            UNICODE
            CB_INTERNAL
        PUBLIC
            $<$<CONFIG:Debug>:CB_BUILD_DEBUG=1>
            $<$<CONFIG:Release>:CB_BUILD_RELEASE=1>
            $<$<CONFIG:RelWithDebInfo>:CB_BUILD_RELEASE=1>
            $<$<CONFIG:MinSizeRel>:CB_BUILD_DIST=1>
)

add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/spdlog
                 ${CMAKE_BINARY_DIR}/thirdparty/spdlog)

target_link_libraries(cobalt_engine PUBLIC spdlog::spdlog_header_only)

target_compile_features(cobalt_engine PUBLIC cxx_std_23)