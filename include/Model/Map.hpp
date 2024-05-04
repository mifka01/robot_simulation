/**
 * @file Map.hpp
 * @brief This file uses the IMap interface for managing the map in the
 * simulation
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "IMap.hpp"
#include "Obstacle.hpp"
#include "Robot/Robot.hpp"

class Map : public IMap {
 private:
  int width = 0;
  int height = 0;
  std::vector<std::shared_ptr<Robot>> robots = {};
  std::vector<std::shared_ptr<Obstacle>> obstacles = {};

 public:
  Map() = default;

  void setMap(const std::map<std::string,
                             std::vector<std::map<std::string, double>>>& map,
              int width,
              int height) override;
  void setWidth(int width) override { this->width = width; }
  void setHeight(int height) override { this->height = height; }

  int getWidth() override { return width; }
  int getHeight() override { return height; }

  std::vector<std::shared_ptr<Obstacle>>& getObstacles() override {
    return obstacles;
  }
  void addObstacle(double x,
                   double y,
                   double width,
                   double height,
                   double rotation) override;
  void removeObstacle(std::shared_ptr<Obstacle> obstacle) override;

  std::vector<std::shared_ptr<Robot>>& getRobots() override { return robots; }
  void addRobot(double x,
                double y,
                double diameter,
                double viewAngle,
                double rotateAngle,
                double viewDistance,
                bool rotateClockwise,
                int speed,
                Robot::Type type) override;
  void removeRobot(std::shared_ptr<Robot> robot) override;

 private:
  /**
   * @brief Adjusts the position of the object so it fits into the map
   *
   * @param x
   * @param y
   * @param w
   * @param h
   */
  void adjustPosition(double& x, double& y, int w, int h);
};
