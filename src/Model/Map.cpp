#include "Model/Map.hpp"
#include "Model/Robot/AutonomousRobot.hpp"
#include "Model/Robot/ManualRobot.hpp"
#include <cmath>
#include "Settings.hpp"

bool Map::isOutOfBounds(double x, double y, int w, int h) const {
    return x < Settings::BORDER_SIZE|| x + w > width - Settings::BORDER_SIZE || y < Settings::BORDER_SIZE || y + h > height - Settings::BORDER_SIZE;
}

void Map::adjustPosition(double& x, double& y, int w, int h) {
    if (x < Settings::BORDER_SIZE) {
        x = Settings::BORDER_SIZE;
    } else if (x + w > width - Settings::BORDER_SIZE) {
        x = width - w - Settings::BORDER_SIZE;
    }
    if (y < Settings::BORDER_SIZE) {
        y = Settings::BORDER_SIZE;
    } else if (y + h > height - Settings::BORDER_SIZE) {
        y = height - h - Settings::BORDER_SIZE;
    }
}

void Map::setMap(
    const std::map<std::string, std::vector<std::map<std::string, double>>>& map,
    int width,
    int height) {
  this->width = width;
  this->height = height;
  this->robots.clear();
  this->obstacles.clear();
  for (const auto& robot : map.at("robots")) {
    int type = robot.at("type");
    double x = robot.at("x");
    double y = robot.at("y");
    double angle = robot.at("angle") * M_PI / 180;
    double diameter = robot.at("diameter");
    int speed = robot.at("speed");

    if (isOutOfBounds(x, y, diameter, diameter)){
        adjustPosition(x, y, diameter, diameter);
    }

    if (type == 0) {
      ManualRobot manualRobot(x, y, diameter, angle, speed);
      robots.push_back(std::make_shared<ManualRobot>(manualRobot));
    } else {
      AutonomousRobot autoRobot(x, y, diameter,angle, speed);
      robots.push_back(std::make_shared<AutonomousRobot>(autoRobot));
    }
  }
  for (const auto& obstacle : map.at("obstacles")) {
    double x = obstacle.at("x");
    double y = obstacle.at("y");
    int w = obstacle.at("width");
    int h = obstacle.at("height");

    if (isOutOfBounds(x, y, w, h)) {
        adjustPosition(x, y, w,h);
    }

    addObstacle(x, y, w, h);
  }
}

void Map::addObstacle(double x, double y, double width, double height) {
  Obstacle obs(x, y, width, height);
  obstacles.push_back(std::make_shared<Obstacle>(obs));
}

void Map::addRobot(double x, double y, double diameter, double angle, int speed, int type) {
  if (isOutOfBounds(x, y, diameter, diameter)) {
    adjustPosition(x, y, diameter, diameter);
  }
  if (type == 0) {
    ManualRobot manualRobot(x, y, diameter, angle, speed);
    robots.push_back(std::make_shared<ManualRobot>(manualRobot));
  } else {
    AutonomousRobot autoRobot(x, y, diameter, angle, speed);
    robots.push_back(std::make_shared<AutonomousRobot>(autoRobot));
  }
}
