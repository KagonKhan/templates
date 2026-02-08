
# Add source to this project's executable.
add_executable(vulkan_guide
    main.cpp
    vk_engine.cpp
    vk_engine.h
    vk_types.h
    vk_initializers.cpp
    vk_initializers.h)



set_property(TARGET vulkan_guide PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:vulkan_guide>")

target_include_directories(vulkan_guide PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(vulkan_guide vkbootstrap vma glm tinyobjloader imgui stb_image)
target_link_libraries(vulkan_guide Vulkan::Vulkan sdl2)

add_dependencies(vulkan_guide Shaders)



if(POLICY CMP0079 )
  cmake_policy(SET CMP0079 NEW)
endif()


find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)

target_link_libraries(vulkan_guide 
                        spdlog::spdlog 
                        fmt::fmt)