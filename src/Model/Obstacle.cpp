/**
 * @file Obstacle.cpp
 * @brief This file contains implementation of Obstacle class
 * which represents an obstacle in the simulation
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "Model/Obstacle.hpp"
#include <cmath>

Obstacle::Obstacle(double x,
                   double y,
                   double width,
                   double height,
                   double rotation)
    : x(x),
      y(y),
      width(width),
      height(height),
      rotation(rotation),
      boundingBox({x, y},
                  {x + width, y},
                  {x + width, y + height},
                  {x, y + height}) {
  update();
}

void Obstacle::rotate(double angle, double centerX, double centerY) {
  for (auto& point : getPoints()) {
    double x = point.x - centerX;
    double y = point.y - centerY;
    point.x = x * cos(angle) - y * sin(angle) + centerX;
    point.y = x * sin(angle) + y * cos(angle) + centerY;
  }
}

void Obstacle::update() {
  setPoints({x, y}, {x + width, y}, {x + width, y + height}, {x, y + height});
  rotate(rotation, x + width / 2, y + height / 2);
  boundingBox.update(x, y, width, height, rotation);
}
