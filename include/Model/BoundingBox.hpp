#pragma once
#include <vector>

struct Vector {
    double x, y;

    Vector operator-(const Vector& other) const {
        return {x - other.x, y - other.y};
    }
};


struct Point {
    double x;
    double y;

    operator Vector() const {
        return {x, y};
    }
};


class BoundingBox {
private:
    std::vector<Point> points;
    // Point topLeft;
    // Point topRight;
    // Point bottomRight;
    // Point bottomLeft;

public:
    BoundingBox(Point topLeft, Point topRight, Point bottomRight, Point bottomLeft){
        points.push_back(topLeft);
        points.push_back(topRight);
        points.push_back(bottomRight);
        points.push_back(bottomLeft);
    }


    void rotate(double angle, double centerX, double centerY);

    void update(double x, double y, double width, double height, double angle = 0);

    bool intersects(const BoundingBox &other) const;
    std::vector<Vector> getAxes() const;
    double dotProduct(const Vector &a, const Vector &b) const;

    bool contains(const Point &point) const;

    void move(double dx, double dy);

    void setPoints(Point topLeft, Point topRight, Point bottomRight, Point bottomLeft) {
        points[0] = topLeft;
        points[1] = topRight;
        points[2] = bottomRight;
        points[3] = bottomLeft;
    }

    std::vector<Point> &getPoints() {
        return points;
    }
};

