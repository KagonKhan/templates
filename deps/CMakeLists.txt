cmake_minimum_required(VERSION 3.23)

find_package(imgui REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)

add_library(imgui_bindings
    ${CMAKE_CURRENT_SOURCE_DIR}/bindings/imgui_impl_glfw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bindings/imgui_impl_opengl3.cpp
)

target_link_libraries(imgui_bindings
    PUBLIC imgui::imgui
    PUBLIC glfw
)

target_include_directories(imgui_bindings PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/
)
