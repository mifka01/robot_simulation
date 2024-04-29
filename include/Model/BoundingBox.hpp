#pragma once
#include <vector>

struct Point {
    double x;
    double y;
};


class BoundingBox {
private:
    std::vector<Point> points;

public:
    BoundingBox(Point p1, Point p2, Point p3, Point p4) {
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
    }

    bool intersects(const BoundingBox &other) const;

    void move(double dx, double dy);

    std::vector<Point>& getPoints() { return points; }
};

