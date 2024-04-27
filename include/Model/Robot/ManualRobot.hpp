#pragma once
#include "Robot.hpp"

class ManualRobot : public Robot {
 public:
  using Robot::Robot;

  void move() override;
  void stop() override;

  void turnLeft() override;
  void turnRight() override;
};
