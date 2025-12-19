#pragma once
#include "Body.hpp"

class PhysicsSystem {
public:
  void update(Body &body, double dt);
};
