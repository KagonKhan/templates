#pragma once
#include "imgui.h"
#include <GLFW/glfw3.h>
#include <gl/GL.h>

#include "image.hpp"

struct Vector {
  double x, y, z;
};

struct Point {
  double x, y, z;

  Vector operator-(Point const &other) {
    return Vector{x - other.x, y - other.y, z - other.z};
  }
};

struct Ray {
  Point origin;
  Vector direction;
};

class Renderer {
public:
  Renderer();

  Image image{{800,600}};
  unsigned char *data;

  void render();
};
