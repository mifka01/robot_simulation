#include "Model/BoundingBox.hpp"

bool BoundingBox::intersects(const BoundingBox &other) const {
    for (const auto &point : other.points) {
        if (contains(point)) {
            return true;
        }
    }

    for (const auto &point : points) {
        if (other.contains(point)) {
            return true;
        }
    }
    return false;
}

bool BoundingBox::contains(const Point &point) const {
    return point.x >= points[0].x && point.x <= points[1].x &&
           point.y >= points[0].y && point.y <= points[2].y;
}

void BoundingBox::move(double dx, double dy) {
    for (auto &point : points) {
        point.x += dx;
        point.y += dy;
    }
}

void BoundingBox::update(double x, double y, double width, double height) {
    setPoints({x, y}, {x + width, y}, {x + width, y + height}, {x, y + height});
}
