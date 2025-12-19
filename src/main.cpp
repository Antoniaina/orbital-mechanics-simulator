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

  PhysicsSystem physics;

  Body planet;
  planet.position = {0.5, 0.0, 0.0};
  planet.velocity = {0.0, 1.0, 0.0};
  planet.mass = 1.0;

  Renderer2D renderer;

  const double dt = 0.01;

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    physics.update(planet, dt);
    renderer.draw(planet);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
