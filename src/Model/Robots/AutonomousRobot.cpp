#include "Model/Robot/AutonomousRobot.hpp"
#include <iostream>

void AutonomousRobot::move() {
  x += speed;
  y += speed;
}

void AutonomousRobot::stop() {
  std::cout << "Robot is stopped" << std::endl;
}

void AutonomousRobot::turnLeft() {
  // Turn the robot left
  std::cout << "Robot is turning left" << std::endl;
}

void AutonomousRobot::turnRight() {
  // Turn the robot right
  std::cout << "Robot is turning right" << std::endl;
}
