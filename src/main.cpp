#include "Vec3.hpp"
#include "physics/Body.hpp"
#include "physics/Physics.hpp"
#include "render/Renderer2d.hpp"
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

int main() {
  if (!glfwInit()) {
    return -1;
  }

  GLFWwindow *window = glfwCreateWindow(800, 600, "Orbital Mechanics Simulator",
                                        nullptr, nullptr);

  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  float t = 0.0f;

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    float x = 0.5f * cos(t);
    float y = 0.5f * sin(t);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
    t += 0.01f;
  }

  glfwTerminate();
  return 0;
}
