#pragma once
#include "Robot.hpp"

class AutonomousRobot : public Robot {
 public:
  using Robot::Robot;

  void move() override;

  void turnLeft() override;
  void turnRight() override;
};
