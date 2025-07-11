file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS src/*.cpp src/*.h)

add_library(CobaltEngine STATIC ${ENGINE_SRC})

target_compile_definitions(CobaltEngine PRIVATE
        UNICODE
)

target_compile_options(CobaltEngine PUBLIC
        /utf-8
)

target_include_directories(CobaltEngine
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${CMAKE_SOURCE_DIR}/external/spdlog/include
)