#ifndef YARR_APP_APP_HPP
#define YARR_APP_APP_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

class App {
public:
  App(std::string const &title);
  ~App();
  void run(int fps = -1);

private:
  GLFWwindow *window;

};

#endif