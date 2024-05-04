/**
 * @file AutonomousRobot.cpp
 * @brief This file contains implementation of AutonomousRobot class
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "Model/Robot/AutonomousRobot.hpp"

void AutonomousRobot::run() {
  this->move();
}

void AutonomousRobot::onCollision() {
  this->turn();
}
