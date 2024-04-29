#include "Model/ViewBox.hpp"
#include <cmath>


void ViewBox::rotate(double angle, double centerX, double centerY) {
    for (auto &point : getPoints()) {
        double x = point.x - centerX;
        double y = point.y - centerY;
        point.x = x * cos(angle) - y * sin(angle) + centerX;
        point.y = x * sin(angle) + y * cos(angle) + centerY;
    }
}
