#pragma once

class Obstacle {
 protected:
  int x;
  int y;
  int width;
  int height;

 public:
  Obstacle(int x, int y, int width, int height)
      : x(x), y(y), width(width), height(height) {}

  void setX(int x) { this->x = x; }
  void setY(int y) { this->y = y; }

  int getX() const { return x; }
  int getY() const { return y; }
  int getWidth() const { return width; }
  int getHeight() const { return height; }
};
