#pragma once
#include "Body.hpp"
#include <cmath>

class PhysicsSystem {
public:
  double G = 1.0;

  void update(Body &body, double dt) {
    double x = body.position.x;
    double y = body.position.y;
    double z = body.position.z;

    double r = std::sqrt(x * x + y * y + z * z);
    if (r < 1e-6)
      return;

    double inv_r3 = 1.0 / (r * r * r);

    body.velocity.x += (-G * x * inv_r3) * dt;
    body.velocity.y += (-G * y * inv_r3) * dt;
    body.velocity.z += (-G * z * inv_r3) * dt;

    body.position.x += body.velocity.x * dt;
    body.position.y += body.velocity.y * dt;
    body.position.z += body.velocity.z * dt;
  }
};
