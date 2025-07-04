add_library(cobalt_engine STATIC)

target_precompile_headers(cobalt_engine PRIVATE include/cobalt.pch)

target_sources(cobalt_engine
        PRIVATE
        src/core/core.cpp
            src/core/log.cpp
        PUBLIC
        include/cobalt/core/core.h
            ${CMAKE_CURRENT_SOURCE_DIR}/include/cobalt/core/base.h
            ${CMAKE_CURRENT_SOURCE_DIR}/include/cobalt/core/log.h
)

target_include_directories(cobalt_engine
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(cobalt_engine PUBLIC CB_DEBUG)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(cobalt_engine PUBLIC CB_RELEASE)
elseif (CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    target_compile_definitions(cobalt_engine PUBLIC CB_RELEASE)
elseif (CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    target_compile_definitions(cobalt_engine PUBLIC CB_DIST)
endif ()

add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/spdlog
                 ${CMAKE_BINARY_DIR}/thirdparty/spdlog)

target_link_libraries(cobalt_engine PUBLIC spdlog::spdlog_header_only)

target_compile_features(cobalt_engine PUBLIC cxx_std_23)