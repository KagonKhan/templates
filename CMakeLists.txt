cmake_minimum_required (VERSION 3.23)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (ImguiProject CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(bindings)

find_package(stb REQUIRED)
find_package(spdlog REQUIRED)

# =======================    PROJECT    ==========================


add_executable(dear-imgui-conan
    src/main.cpp

    src/app/app.cpp

    src/renderer/image.cpp
    src/renderer/renderer.cpp

    src/utils/logger.cpp
)

target_include_directories(dear-imgui-conan PUBLIC src)

target_link_libraries(dear-imgui-conan PUBLIC
    ImguiBindings
    
    stb::stb
    spdlog::spdlog

)

target_compile_definitions(dear-imgui-conan PUBLIC RESOURCE_DIR=${PROJECT_SOURCE_DIR}/resources)

# todo: expand (maybe cmake starter template from jason turner?)