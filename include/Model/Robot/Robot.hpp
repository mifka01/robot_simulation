#pragma once
#include "Model/BoundingBox.hpp"
#include "Model/ViewBox.hpp"
#include <cmath>

class Robot {
protected:
  double x;
  double y;
  double diameter;
  double viewAngle;
  double rotateAngle;
  double collisionDistance;
  bool rotateClockwise;
  int speed;
  int type;
  BoundingBox boundingBox;
  ViewBox viewBox;

public:
  Robot(double x, double y, double diameter, double viewAngle, double rotateAngle, double collisionDistance, bool rotateClockwise, int speed)
      : x(x), y(y), diameter(diameter), viewAngle(viewAngle), rotateAngle(rotateAngle), collisionDistance(collisionDistance), rotateClockwise(rotateClockwise), speed(speed),
        boundingBox({x, y}, {x + diameter, y }, {x +  diameter, y + diameter}, {x, y + diameter}), 
        viewBox({x + diameter, y}, {x + diameter + collisionDistance , y }, {x + diameter + collisionDistance, y + diameter }, {x + diameter , y + diameter }) {
            viewBox.rotate(viewAngle, x + diameter / 2 , y + diameter / 2);
        }

  virtual void move();
  virtual void turn();
  virtual void turnLeft();
  virtual void turnRight();

  void setX(double x) { 
        this->x = x; 
        this->boundingBox.update(x, y, diameter, diameter);
        this->viewBox.update(x, y, diameter, diameter,collisionDistance, viewAngle);
    }
  void setY(double y) { 
        this->y = y; 
        this->boundingBox.update(x, y, diameter, diameter);
        this->viewBox.update(x, y, diameter, diameter, collisionDistance, viewAngle);
        ;}

  virtual void setDiameter(double diameter) { this->diameter = diameter; }
  virtual void setSpeed(int speed) { this->speed = speed; }
  // rad 
  virtual void setRotateAngle(double angle) { this->rotateAngle = angle; }
  // rad
  virtual void setViewAngle(double angle) { this->viewAngle= angle; }

  virtual void setCollisionDistance(double distance) { 
    this->collisionDistance = distance; 
    this->viewBox.update(x, y, diameter, diameter, collisionDistance, viewAngle);
  }

  virtual void setRotateClockwise(bool clockwise) { this->rotateClockwise = clockwise; }

  double getX() const { return x; }
  double getY() const { return y; }
  double getDiameter() const { return diameter; }

  double getRotateAngle() const { return rotateAngle / M_PI * 180; }
  double getViewAngle() const { return viewAngle / M_PI * 180; }

  double getRotateAngleRad() const { return rotateAngle; }
  double getViewAngleRad() const { return viewAngle; }
 
  double getCollisionDistance() const { return collisionDistance; }

  bool getRotateClockwise() const { return rotateClockwise; }

  int getSpeed() const { return speed; }
  virtual int getType() const = 0;

  BoundingBox getBoundingBox() const { return boundingBox; }
  ViewBox getViewBox() const { return viewBox; }

  virtual ~Robot() {} // Virtual destructor
};
