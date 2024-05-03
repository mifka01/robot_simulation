#pragma once
#include "Model/BoundingBox.hpp"
#include <cmath>

class Obstacle {
 protected:
  double x;
  double y;
  double width;
  double height;
  double rotation;
  std::vector<Point> points;
  BoundingBox boundingBox;

 public:
  Obstacle(double x, double y, double width, double height, double rotation);


  void setX(double x) { this->x = x; update(); }
  void setY(double y) { this->y = y; update();}
  void setWidth(double width) { this->width = width; update();}
  void setHeight(double height) { this->height = height; update();}
  void setRotation(double rotation) { this->rotation = rotation * M_PI / 180 ; update();}
  void setPoints(Point topLeft, Point topRight, Point bottomRight, Point bottomLeft) {
    points = {topLeft, topRight, bottomRight, bottomLeft};
  }

  double getX() const { return x; }
  double getY() const { return y; }
  double getWidth() const { return width; }
  double getHeight() const { return height; }
  double getRotation() const { return rotation * 180 / M_PI; }
     
  void rotate(double angle, double centerX, double centerY);

  void update();

  std::vector<Point> &getPoints() { return points; }
  BoundingBox getBoundingBox() const { return boundingBox; }
};
