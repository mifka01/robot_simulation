/**
 * @file Map.cpp
 * @brief This file contains implementation of Map class which is used for
 * managing the map in the simulation
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "Model/Map.hpp"
#include <cmath>
#include "Model/Robot/AutonomousRobot.hpp"
#include "Model/Robot/ManualRobot.hpp"

void Map::setMap(
    const std::map<std::string, std::vector<std::map<std::string, double>>>&
        map,
    int width,
    int height) {
  this->width = width;
  this->height = height;
  this->robots.clear();
  this->obstacles.clear();
  for (const auto& robot : map.at("robots")) {
    addRobot(robot.at("x"), robot.at("y"), robot.at("diameter"),
             robot.at("view-angle"), robot.at("rotate-angle"),
             robot.at("view-distance"), robot.at("rotate-clockwise"),
             robot.at("speed"), Robot::Type(robot.at("type")));
  }
  for (const auto& obstacle : map.at("obstacles")) {
    addObstacle(obstacle.at("x"), obstacle.at("y"), obstacle.at("width"),
                obstacle.at("height"), obstacle.at("rotation"));
  }
}

void Map::addObstacle(double x,
                      double y,
                      double width,
                      double height,
                      double rotation) {
  if (isOutOfBounds(x, y, width, height)) {
    adjustPosition(x, y, width, height);
  }
  double rotationRad = rotation * M_PI / 180;
  Obstacle obs(x, y, width, height, rotationRad);
  obstacles.push_back(std::make_shared<Obstacle>(obs));
}

void Map::removeObstacle(std::shared_ptr<Obstacle> obstacle) {
  for (auto it = obstacles.begin(); it != obstacles.end(); ++it) {
    if (*it == obstacle) {
      obstacles.erase(it);
      break;
    }
  }
}

void Map::addRobot(double x,
                   double y,
                   double diameter,
                   double viewAngle,
                   double rotateAngle,
                   double viewDistance,
                   bool rotateClockwise,
                   int speed,
                   Robot::Type type) {
  if (isOutOfBounds(x, y, diameter, diameter)) {
    adjustPosition(x, y, diameter, diameter);
  }

  double viewAngleRad = viewAngle * M_PI / 180;
  double rotateAngleRad = rotateAngle * M_PI / 180;
  if (type == Robot::Type::MANUAL) {
    ManualRobot manualRobot(x, y, diameter, viewAngleRad, rotateAngleRad,
                            viewDistance, rotateClockwise, speed);
    robots.push_back(std::make_shared<ManualRobot>(manualRobot));
  } else {
    AutonomousRobot autoRobot(x, y, diameter, viewAngleRad, rotateAngleRad,
                              viewDistance, rotateClockwise, speed);
    robots.push_back(std::make_shared<AutonomousRobot>(autoRobot));
  }
}

void Map::removeRobot(std::shared_ptr<Robot> robot) {
  for (auto it = robots.begin(); it != robots.end(); ++it) {
    if (*it == robot) {
      robots.erase(it);
      break;
    }
  }
}

void Map::adjustPosition(double& x, double& y, int w, int h) {
  if (x < 0) {
    x = 0;
  } else if (x + w > width) {
    x = width - w;
  }
  if (y < 0) {
    y = 0;
  } else if (y + h > height) {
    y = height - h;
  }
}
