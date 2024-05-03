#include "Model/Map.hpp"
#include "Model/Robot/AutonomousRobot.hpp"
#include "Model/Robot/ManualRobot.hpp"
#include <cmath>
#include "Settings.hpp"

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
    addRobot(robot.at("x"), robot.at("y"), robot.at("diameter"), robot.at("view-angle"), robot.at("rotate-angle"), robot.at("view-distance"), robot.at("rotate-clockwise"), robot.at("speed"), Robot::Type(robot.at("type")));
  }
  for (const auto& obstacle : map.at("obstacles")) {
    addObstacle(obstacle.at("x"), obstacle.at("y"), obstacle.at("width"), obstacle.at("height"));
  }
}

void Map::addObstacle(double x, double y, double width, double height) {
  if (isOutOfBounds(x, y, width, height)) {
    adjustPosition(x, y, width,height);
  }
  Obstacle obs(x, y, width, height);
  obstacles.push_back(std::make_shared<Obstacle>(obs));
}

void Map::addRobot(double x, double y, double diameter, double viewAngle, double rotateAngle, double viewDistance, bool rotateClockwise, int speed, Robot::Type type) {
  if (isOutOfBounds(x, y, diameter, diameter)) {
    adjustPosition(x, y, diameter, diameter);
  }

  double viewAngleRad = viewAngle * M_PI / 180;
  double rotateAngleRad = rotateAngle * M_PI / 180;
  if (type == Robot::Type::MANUAL) {
    ManualRobot manualRobot(x, y, diameter, viewAngleRad, rotateAngleRad, viewDistance, rotateClockwise, speed);
    robots.push_back(std::make_shared<ManualRobot>(manualRobot));
  } else {
    AutonomousRobot autoRobot(x, y, diameter, viewAngleRad, rotateAngleRad, viewDistance, rotateClockwise, speed);
    robots.push_back(std::make_shared<AutonomousRobot>(autoRobot));
  }
}

void Map::removeObstacle(std::shared_ptr<Obstacle> obstacle) {
    for (auto it = obstacles.begin(); it != obstacles.end(); ++it) {
        if (*it == obstacle) {
            obstacles.erase(it);
            break;
        }
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
