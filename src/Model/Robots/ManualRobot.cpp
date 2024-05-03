#include "Model/Robot/ManualRobot.hpp"

void ManualRobot::run() {
  switch (this->state) {
  case State::MOVE:
    this->move();
    return;
  case State::STOP:
    return;
  case State::TURN_LEFT:
    this->turnLeft();
    break;
  case State::TURN_RIGHT:
    this->turnRight();
    break;
  }
  this->setState(State::STOP);
}

void ManualRobot::onCollision() {
  switch (this->state) {
  case State::MOVE:
    break;
  case State::STOP:
    return;
  case State::TURN_LEFT:
    this->turnLeft();
    break;
  case State::TURN_RIGHT:
    this->turnRight();
    break;
  }
  this->setState(State::STOP);
}
