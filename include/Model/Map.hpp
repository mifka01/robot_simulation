#pragma once
#include <map>
#include <string>
#include <vector>
#include "Obstacle.hpp"
#include "Robot/Robot.hpp"

class Map {
 private:
  int width = 0;
  int height = 0;
  std::vector<std::shared_ptr<Robot>> robots = {};
  std::vector<std::shared_ptr<Obstacle>> obstacles = {};

 public:
  // map
  //  robots: [{type: 0, x: 0, y: 0, diameter: 0, angle: 0, speed: 0}]
  //  obstacles: [{x: 0, y: 0, width: 0, height: 0}]
  void setMap(
      const std::map<std::string, std::vector<std::map<std::string, int>>>& map,
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
