#pragma once
#include "Model/BoundingBox.hpp"

class Obstacle {
 protected:
  double x;
  double y;
  double width;
  double height;
  BoundingBox boundingBox;

 public:
  Obstacle(double x, double y, double width, int height)
      : x(x), y(y), width(width), height(height) ,
        boundingBox({x,y}, {x + width, y + height}, {x, y + height}, {x +  width,y}){}

  void setX(double x) { this->x = x; this->boundingBox.update(x, y, width, height);}
  void setY(double y) { this->y = y; this->boundingBox.update(x, y, width, height);}
  void setWidth(double width) { this->width = width; this->boundingBox.update(x, y, width, height);}
  void setHeight(double height) { this->height = height; this->boundingBox.update(x, y, width, height);}

  double getX() const { return x; }
  double getY() const { return y; }
  double getWidth() const { return width; }
  double getHeight() const { return height; }

  BoundingBox getBoundingBox() const { return boundingBox; }
};
