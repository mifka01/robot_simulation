#pragma once
#include "Model/BoundingBox.hpp"
#include "Model/ViewBox.hpp"
#include <cmath>


class Robot {

public:

enum class Type{
    MANUAL = 0,
    AUTONOMOUS
};

private:
  double x;
  double y;
  double diameter;
  double viewAngle;
  double rotateAngle;
  double viewDistance;
  bool rotateClockwise;
  int speed;
  Type type;
  BoundingBox boundingBox;
  ViewBox viewBox;

public:
  Robot(double x, double y, double diameter, double viewAngle, double rotateAngle, double viewDistance, bool rotateClockwise, int speed)
      : x(x), y(y), diameter(diameter), viewAngle(viewAngle), rotateAngle(rotateAngle), viewDistance(viewDistance), rotateClockwise(rotateClockwise), speed(speed),
        boundingBox({x, y}, {x + diameter, y }, {x +  diameter, y + diameter}, {x, y + diameter}), 
        viewBox({x + diameter, y}, {x + diameter + viewDistance , y }, {x + diameter + viewDistance, y + diameter }, {x + diameter , y + diameter }) {
            viewBox.rotate(viewAngle, x + diameter / 2 , y + diameter / 2);
        }

  virtual void move();
  virtual void turn();
  virtual void turnLeft();
  virtual void turnRight();
  virtual void run() = 0;
  virtual void onCollision()  = 0;

  void setX(double x) { 
        this->x = x; 
        this->boundingBox.update(x, y, diameter, diameter);
        this->viewBox.update(x, y, diameter, diameter,viewDistance, viewAngle);
    }
  void setY(double y) { 
        this->y = y; 
        this->boundingBox.update(x, y, diameter, diameter);
        this->viewBox.update(x, y, diameter, diameter, viewDistance, viewAngle);
        ;}

  virtual void setDiameter(double diameter) { this->diameter = diameter; 
    this->boundingBox.update(x, y, diameter, diameter);
    this->viewBox.update(x, y, diameter, diameter, viewDistance, viewAngle);
  }

  virtual void setSpeed(int speed) { this->speed = speed; }
  // rad 
  virtual void setRotateAngle(double angle) { this->rotateAngle = angle * M_PI / 180; 
  }
  // rad
  virtual void setViewAngle(double angle) { this->viewAngle = angle * M_PI / 180; 
    this->viewBox.update(x, y, diameter, diameter, viewDistance, viewAngle);
  }

  virtual void setViewDistance(double distance) { 
    this->viewDistance = distance; 
    this->viewBox.update(x, y, diameter, diameter, viewDistance, viewAngle);
  }

  virtual void setRotateClockwise(bool clockwise) { this->rotateClockwise = clockwise; }

  double getX() const { return x; }
  double getY() const { return y; }
  double getDiameter() const { return diameter; }

  double getRotateAngle() const { return rotateAngle / M_PI * 180; }
  double getViewAngle() const { return std::fmod(viewAngle / M_PI * 180, 360); }

  double getRotateAngleRad() const { return rotateAngle; }
  double getViewAngleRad() const { return viewAngle; }
 
  double getViewDistance() const { return viewDistance; }

  bool getRotateClockwise() const { return rotateClockwise; }

  int getSpeed() const { return speed; }
  virtual Type getType() const = 0;

  BoundingBox getBoundingBox() const { return boundingBox; }
  ViewBox getViewBox() const { return viewBox; }

  virtual ~Robot() {} // Virtual destructor
};
