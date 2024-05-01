#pragma once
#include "Robot.hpp"

class AutonomousRobot : public Robot {
 public:
  using Robot::Robot;

  int getType() const override { return 1; }
};
