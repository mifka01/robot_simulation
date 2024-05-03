#include "Model/Robot/AutonomousRobot.hpp"

void AutonomousRobot::run() {
    this->move();
}

void AutonomousRobot::onCollision() {
    this->turn();
}
