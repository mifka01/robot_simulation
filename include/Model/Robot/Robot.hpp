#pragma once
#include "Model/BoundingBox.hpp"
#include "Model/ViewBox.hpp"

class Robot {
protected:
  double x;
  double y;
  double diameter;
  double rotateAngle;
  double angle = 0;
  int speed;
  int type;
  BoundingBox boundingBox;
  ViewBox viewBox;

public:
  Robot(double x, double y, double diameter, double rotateAngle, int speed)
      : x(x), y(y), diameter(diameter), rotateAngle(rotateAngle), speed(speed),
        boundingBox({x,y}, {x + diameter, y + diameter}, {x, y +diameter}, {x +  diameter,y}), viewBox({x + diameter,y}, {x + diameter, y + diameter}, {x + diameter *2, y + diameter}, {x +  diameter *2 ,y}) {}

  virtual void move() = 0;
  virtual void turnLeft() = 0;
  virtual void turnRight() = 0;

  virtual void setDiameter(double diameter) { this->diameter = diameter; }
  virtual void setSpeed(int speed) { this->speed = speed; }
  virtual void setRotateAngle(double angle) { this->rotateAngle = angle; }
  virtual void setAngle(double angle) { this->angle = angle; }

  double getX() const { return x; }
  double getY() const { return y; }
  double getDiameter() const { return diameter; }
  double getRotateAngle() const { return rotateAngle; }
  double getAngle() const { return angle; }
  int getSpeed() const { return speed; }
  int getType() const { return type; }
  BoundingBox getBoundingBox() const { return boundingBox; }
  ViewBox getViewBox() const { return viewBox; }

  virtual ~Robot() {} // Virtual destructor
};
