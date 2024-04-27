#include "Model/Map.hpp"
#include "Model/Robot/AutonomousRobot.hpp"
#include "Model/Robot/ManualRobot.hpp"

void Map::setMap(
    const std::map<std::string, std::vector<std::map<std::string, int>>>& map,
    int width,
    int height) {
  this->width = width;
  this->height = height;
  for (const auto& robot : map.at("robots")) {
    int type = robot.at("type");
    //
    if (type == 0) {
      ManualRobot manualRobot(robot.at("x"), robot.at("y"),
                              robot.at("diameter"), robot.at("angle"),
                              robot.at("speed"));
      robots.push_back(std::make_shared<ManualRobot>(manualRobot));
    } else {
      AutonomousRobot autoRobot(robot.at("x"), robot.at("y"),
                                robot.at("diameter"), robot.at("angle"),
                                robot.at("speed"));
      robots.push_back(std::make_shared<AutonomousRobot>(autoRobot));
    }
  }
  for (const auto& obstacle : map.at("obstacles")) {
    Obstacle obs(obstacle.at("x"), obstacle.at("y"), obstacle.at("width"),
                 obstacle.at("height"));
    obstacles.push_back(std::make_shared<Obstacle>(obs));
  }
}
