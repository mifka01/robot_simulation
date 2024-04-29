#pragma once
#include "BoundingBox.hpp"

class ViewBox: public BoundingBox{

public:
    ViewBox(Point p1, Point p2, Point p3, Point p4): BoundingBox(p1, p2, p3, p4) {}

    void rotate(double angle, double centerX, double centerY);
};
