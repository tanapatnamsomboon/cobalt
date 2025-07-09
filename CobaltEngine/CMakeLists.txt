file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS src/*.cpp src/*.h)

add_library(CobaltEngine STATIC ${ENGINE_SRC})

target_include_directories(CobaltEngine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)