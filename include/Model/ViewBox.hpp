#pragma once
#include "BoundingBox.hpp"

class ViewBox: public BoundingBox{

public:
    ViewBox(Point topLeft, Point topRight, Point bottomRight, Point bottomLeft)
        : BoundingBox(topLeft, topRight, bottomRight, bottomLeft) {
    }

    void rotate(double angle, double centerX, double centerY);

    void update(double x, double y, double width, double height, double distance, double angle);
};
