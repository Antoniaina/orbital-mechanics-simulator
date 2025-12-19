#pragma once
#include "../physics/Body.hpp"
#include <GLFW/glfw3.h>

class Renderer2D {
public:
  void draw(const Body &body) {
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glPointSize(0.5f);
    glBegin(GL_POINTS);
    glVertex2f(static_cast<float>(body.position.x),
               static_cast<float>(body.position.y));
    glEnd();
  }
};
