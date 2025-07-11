file(GLOB_RECURSE HELLO_COBALT_SRC CONFIGURE_DEPENDS src/*.cpp)

add_executable(HelloCobalt ${HELLO_COBALT_SRC})

target_include_directories(HelloCobalt PRIVATE
        ${CMAKE_SOURCE_DIR}/CobaltEngine/src
)

target_link_libraries(HelloCobalt PRIVATE CobaltEngine)