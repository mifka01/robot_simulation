#pragma once
#include "Robot.hpp"

class ManualRobot : public Robot {
 public:
  using Robot::Robot;

  int getType() const override { return 0; }
};
