#pragma once
#include "Robot.hpp"

class ManualRobot : public Robot {

public:
    enum class State {
        MOVE,
        STOP,
        TURN_LEFT,
        TURN_RIGHT
    };

 private:
  State state = State::STOP;
 public:
  using Robot::Robot;

  Type getType() const override { return Robot::Type::MANUAL; }
  void run() override;
  void onCollision() override;

  void setState(State state) { this->state = state; }
  State getState() { return state; }
};
