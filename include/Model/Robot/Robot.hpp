#pragma once

class Robot {
 protected:
  int x;
  int y;
  int diameter;
  int angle;
  int speed;
  int type;

 public:
  Robot(int x, int y, int diameter, int angle, int speed)
      : x(x), y(y), diameter(diameter), angle(angle), speed(speed) {}

  virtual void move() = 0;
  virtual void stop() = 0;
  virtual void turnLeft() = 0;
  virtual void turnRight() = 0;

  virtual void setDiameter(int diameter) { this->diameter = diameter; }
  virtual void setSpeed(int speed) { this->speed = speed; }
  virtual void setAngle(int angle) { this->angle = angle; }

  int getX() const { return x; }
  int getY() const { return y; }
  int getDiameter() const { return diameter; }
  int getAngle() const { return angle; }
  int getSpeed() const { return speed; }
  int getType() const { return type; }

  virtual ~Robot() {}  // Virtual destructor
};
