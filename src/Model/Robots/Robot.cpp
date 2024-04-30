#include "Model/Robot/Robot.hpp"
#include <cmath>

void Robot::move() {
  double dx = speed * cos(angle);
  double dy = speed * sin(angle);
  x += dx;
  y += dy;

  boundingBox.move(dx, dy);
  viewBox.move(dx, dy);
}

void Robot::turnLeft() {
  angle -= rotateAngle;
  viewBox.rotate(-rotateAngle, x + diameter / 2, y + diameter / 2);
}

void Robot::turnRight() {
  angle += rotateAngle;
  viewBox.rotate(rotateAngle, x + diameter / 2, y + diameter / 2);
}
