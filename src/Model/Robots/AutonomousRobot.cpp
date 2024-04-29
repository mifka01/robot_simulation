#include "Model/Robot/AutonomousRobot.hpp"
#include <cmath>

void AutonomousRobot::move() {
  double dx = speed * cos(angle);
  double dy = speed * sin(angle);
  x += dx;
  y += dy;

  boundingBox.move(dx, dy);
  viewBox.move(dx, dy);
}

void AutonomousRobot::turnLeft() {
    angle -= rotateAngle;
    viewBox.rotate(-rotateAngle, x + diameter / 2 , y + diameter / 2);
}

void AutonomousRobot::turnRight() {
    angle += rotateAngle;
    viewBox.rotate(rotateAngle, x + diameter / 2 , y + diameter / 2);
}
