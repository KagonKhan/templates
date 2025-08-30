find_package(imgui REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(spdlog REQUIRED)


    find_package(stb REQUIRED)

add_executable (YARR
    YARR.cpp
    App/app.cpp
    Renderer/renderer.hpp
 "Renderer/renderer.cpp" "Renderer/image.cpp")

target_link_libraries(YARR
    PRIVATE imgui_bindings
    PRIVATE stb::stb
)

target_include_directories(YARR
  PUBLIC  YARR/
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET YARR PROPERTY CXX_STANDARD 20)
endif()


