/**
 * @file ViewBox.cpp
 * @brief This file contains implementation of ViewBox class
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "Model/ViewBox.hpp"
#include <cmath>

void ViewBox::rotate(double angle, double centerX, double centerY) {
  for (auto& point : getPoints()) {
    double x = point.x - centerX;
    double y = point.y - centerY;
    point.x = x * cos(angle) - y * sin(angle) + centerX;
    point.y = x * sin(angle) + y * cos(angle) + centerY;
  }
}

void ViewBox::update(double x,
                     double y,
                     double width,
                     double height,
                     double distance,
                     double angle) {
  setPoints({x + width, y}, {x + width + distance, y},
            {x + width + distance, y + height}, {x + width, y + height});
  rotate(angle, x + width / 2, y + height / 2);
}
