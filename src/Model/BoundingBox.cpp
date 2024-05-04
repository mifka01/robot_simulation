/**
 * @file BoundingBox.cpp
 * @brief This file contains implementation of BoundingBox class
 * which is used for collision detection in the simulation
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "Model/BoundingBox.hpp"

#include <algorithm>
#include <cmath>
#include <vector>

bool BoundingBox::intersects(const BoundingBox& other) const {
  std::vector<Vector> axes = getAxes();
  std::vector<Vector> otherAxes = other.getAxes();
  axes.insert(axes.end(), otherAxes.begin(), otherAxes.end());

  for (const auto& axis : axes) {
    double minA = std::numeric_limits<double>::max();
    double maxA = std::numeric_limits<double>::min();
    double minB = std::numeric_limits<double>::max();
    double maxB = std::numeric_limits<double>::min();

    for (const auto& point : points) {
      double projection = dotProduct(axis, point);
      minA = std::min(minA, projection);
      maxA = std::max(maxA, projection);
    }

    for (const auto& point : other.points) {
      double projection = dotProduct(axis, point);
      minB = std::min(minB, projection);
      maxB = std::max(maxB, projection);
    }

    if (maxA < minB || maxB < minA) {
      return false;
    }
  }

  return true;
}

std::vector<Vector> BoundingBox::getAxes() const {
  std::vector<Vector> axes;
  for (size_t i = 0; i < points.size(); i++) {
    Vector p1 = points[i];
    Vector p2 = points[(i + 1) % points.size()];
    Vector edge = p1 - p2;
    Vector normal = {edge.y, -edge.x};
    axes.push_back(normal);
  }
  return axes;
}

double BoundingBox::dotProduct(const Vector& a, const Vector& b) const {
  return a.x * b.x + a.y * b.y;
}

void BoundingBox::rotate(double angle, double centerX, double centerY) {
  for (auto& point : getPoints()) {
    double x = point.x - centerX;
    double y = point.y - centerY;
    point.x = x * cos(angle) - y * sin(angle) + centerX;
    point.y = x * sin(angle) + y * cos(angle) + centerY;
  }
}

bool BoundingBox::contains(const Point& point) const {
  for (size_t i = 0; i < points.size(); i++) {
    Vector p1 = points[i];
    Vector p2 = points[(i + 1) % points.size()];
    Vector edge = p1 - p2;
    Vector normal = {edge.y, -edge.x};
    Vector pointVector = point;
    Vector pointToP1 = p1 - pointVector;
    if (dotProduct(normal, pointToP1) > 0) {
      return false;
    }
  }
  return true;
}

void BoundingBox::move(double dx, double dy) {
  for (auto& point : points) {
    point.x += dx;
    point.y += dy;
  }
}

void BoundingBox::update(double x,
                         double y,
                         double width,
                         double height,
                         double angle) {
  setPoints({x, y}, {x + width, y}, {x + width, y + height}, {x, y + height});
  rotate(angle, x + width / 2, y + height / 2);
}
