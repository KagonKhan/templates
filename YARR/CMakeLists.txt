find_package(imgui REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(spdlog REQUIRED)


add_executable (YARR
    YARR.cpp
    YARR.h
 "App/app.cpp")

target_link_libraries(YARR
    PRIVATE imgui_bindings
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET YARR PROPERTY CXX_STANDARD 20)
endif()


