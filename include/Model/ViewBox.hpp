#pragma once
#include "BoundingBox.hpp"

class ViewBox: public BoundingBox{

public:
    ViewBox(Point topLeft, Point topRight, Point bottomLeft, Point bottomRight)
        : BoundingBox(topLeft, topRight, bottomLeft, bottomRight) {}

    void rotate(double angle, double centerX, double centerY);

    void update(double x, double y, double width, double height, double angle);
};
