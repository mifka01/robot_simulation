#include "Model/Robot/ManualRobot.hpp"
#include <cmath>
#include <iostream>

void ManualRobot::move() {
  double dx = speed * cos(angle);
  double dy = speed * sin(angle);
  x += dx;
  y += dy;

  boundingBox.move(dx, dy);
  viewBox.move(dx, dy);
}

void ManualRobot::turnLeft() {
    angle -= rotateAngle;
    viewBox.rotate(-rotateAngle, x + diameter / 2 , y + diameter / 2);
}

void ManualRobot::turnRight() {
    angle += rotateAngle;
    viewBox.rotate(rotateAngle, x + diameter / 2 , y + diameter / 2);
}
