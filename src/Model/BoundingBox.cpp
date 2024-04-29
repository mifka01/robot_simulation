#include "Model/BoundingBox.hpp"

bool BoundingBox::intersects(const BoundingBox &other) const {
    for (const auto &point : points) {
        if (point.x >= other.points[0].x && point.x <= other.points[1].x &&
            point.y >= other.points[0].y && point.y <= other.points[2].y) {
            return true;
        }
    }
    return false;
}

void BoundingBox::move(double dx, double dy) {
    for (auto &point : points) {
        point.x += dx;
        point.y += dy;
    }
}
