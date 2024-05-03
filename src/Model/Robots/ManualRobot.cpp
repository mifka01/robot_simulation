#include "Model/Robot/ManualRobot.hpp"

void ManualRobot::run() {
    switch (this->state) {
    case State::MOVE:
        this->move();
        break;
    case State::STOP:
        break;
    case State::TURN_LEFT:
        this->turnLeft();
        this->setState(State::STOP);
        break;
    case State::TURN_RIGHT:
        this->turnRight();
        this->setState(State::STOP);
        break;
    }
}

void ManualRobot::onCollision() {
    switch (this->state) {
    case State::MOVE:
        this->setState(State::STOP);
        break;
    case State::STOP:
        break;
    case State::TURN_LEFT:
        this->turnLeft();
        this->setState(State::STOP);
        break;
    case State::TURN_RIGHT:
        this->turnRight();
        this->setState(State::STOP);
        break;
    }
}
