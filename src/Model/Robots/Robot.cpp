#include "Model/Robot/Robot.hpp"
#include <cmath>

void Robot::move() {
  double dx = speed * cos(viewAngle);
  double dy = speed * sin(viewAngle);
  x += dx;
  y += dy;

  boundingBox.move(dx, dy);
  viewBox.move(dx, dy);
}

void Robot::turn() {
  if (rotateClockwise) {
    turnRight();
  } else {
    turnLeft();
  }
}

void Robot::turnLeft() {
  viewAngle -= rotateAngle;
  viewBox.rotate(-rotateAngle, x + diameter / 2, y + diameter / 2);
}

void Robot::turnRight() {
  viewAngle += rotateAngle;
  viewBox.rotate(rotateAngle, x + diameter / 2, y + diameter / 2);
}
