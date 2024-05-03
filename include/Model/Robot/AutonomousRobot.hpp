#pragma once
#include "Robot.hpp"

class AutonomousRobot : public Robot {
 public:
  using Robot::Robot;

  Type getType() const override { return Robot::Type::AUTONOMOUS; }
  void run() override;
  void onCollision() override;
};
