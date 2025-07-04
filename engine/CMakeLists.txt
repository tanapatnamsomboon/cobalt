add_library(cobalt_engine STATIC)

target_sources(cobalt_engine
    PRIVATE
        src/core.cpp
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/cobalt/core.h
)

target_include_directories(cobalt_engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(cobalt_engine PUBLIC cxx_std_23)