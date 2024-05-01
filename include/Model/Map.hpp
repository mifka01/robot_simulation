#pragma once
#include <map>
#include <string>
#include <vector>
#include "Obstacle.hpp"
#include "Robot/Robot.hpp"
#include <memory>
#include "IMap.hpp"

class Map : public IMap{
 private:
  int width = 0;
  int height = 0;
  std::vector<std::shared_ptr<Robot>> robots = {};
  std::vector<std::shared_ptr<Obstacle>> obstacles = {};

  bool isOutOfBounds(double x, double y, int w, int h) const;
  void adjustPosition(double& x, double& y, int w, int h);


 public:
    Map() = default;

  void setMap(
      const std::map<std::string, std::vector<std::map<std::string, double>>>& map,
      int width,
      int height) override;

  Robot& getRobot(int index) override { return *robots.at(index); } 
  Obstacle& getObstacle(int index) override { return *obstacles.at(index); }
  std::vector<std::shared_ptr<Robot>>& getRobots() override { return robots; }
  std::vector<std::shared_ptr<Obstacle>>& getObstacles() override { return obstacles; }
  int getWidth() override { return width; }
  int getHeight() override { return height; }

  void setWidth(int width) override { this->width = width; }
  void setHeight(int height) override { this->height = height; }

  void addObstacle(double x, double y, double width, double height) override;
  void addRobot(double x, double y, double diameter, double viewAngle, double rotateAngle, double collisionDistance, bool rotateClockwise, int speed, int type) override;
};

