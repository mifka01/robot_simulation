#pragma once
#include <map>
#include <string>
#include <vector>
#include "Obstacle.hpp"
#include "Robot/Robot.hpp"
#include <memory>

class Map {
 private:
  int width = 0;
  int height = 0;
  std::vector<std::shared_ptr<Robot>> robots = {};
  std::vector<std::shared_ptr<Obstacle>> obstacles = {};

  bool isOutOfBounds(double x, double y, int w, int h) const;
  void adjustPosition(double& x, double& y, int w, int h);


 public:
  // map
  //  robots: [{type: 0, x: 0, y: 0, diameter: 0, angle: 0, speed: 0}]
  //  obstacles: [{x: 0, y: 0, width: 0, height: 0}]
  void setMap(
      const std::map<std::string, std::vector<std::map<std::string, double>>>& map,
      int width,
      int height);

  Robot& getRobot(int index) { return *robots.at(index); }
  Obstacle& getObstacle(int index) { return *obstacles.at(index); }
  std::vector<std::shared_ptr<Robot>>& getRobots() { return robots; }
  std::vector<std::shared_ptr<Obstacle>>& getObstacles() { return obstacles; }
  int getWidth() { return width; }
  int getHeight() { return height; }

  void setWidth(int width) { this->width = width; }
  void setHeight(int height) { this->height = height; }
};
