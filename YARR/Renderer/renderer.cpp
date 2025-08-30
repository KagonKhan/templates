#include "renderer.hpp"

#include "imgui.h"
#include <GLFW/glfw3.h>
#include <cstdint>


Renderer::Renderer() {

}

void Renderer::render() {
  ImGui::Begin("OpenGL Texture Text");
  ImGui::Text("pointer = %x", image.id());
  ImGui::Text("size = %d x %d", image.size().x, image.size().y);
  ImGui::Image((ImTextureID)(intptr_t)image.id(), image.size());
  ImGui::End();
}