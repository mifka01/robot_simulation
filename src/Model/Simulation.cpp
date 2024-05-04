/**
 * @file Simulation.cpp
 * @brief This file contains implementation of Simulation class
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "Model/Simulation.hpp"

void Simulation::setMap(
    const std::map<std::string, std::vector<std::map<std::string, double>>>&
        map,
    int width,
    int height) {
  this->map->setMap(map, width, height);
}

void Simulation::run() {
  auto obstacles = map->getObstacles();
  auto robots = map->getRobots();

  for (auto& robot : robots) {
    if (checkCollisions(robot, obstacles, robots)) {
      robot->onCollision();
    } else {
      robot->run();
    }
  }
}

bool Simulation::checkCollisions(
    const std::shared_ptr<Robot>& robot,
    const std::vector<std::shared_ptr<Obstacle>>& obstacles,
    const std::vector<std::shared_ptr<Robot>>& robots) {
  auto points = robot->getViewBox().getPoints();
  for (const auto& point : points) {
    if (map->isOutOfBounds(point)) {
      return true;
    }
  }

  for (const auto& obstacle : obstacles) {
    if (robot->getViewBox().intersects(obstacle->getBoundingBox())) {
      return true;
    }
  }

  for (const auto& otherRobot : robots) {
    if (robot != otherRobot &&
        robot->getViewBox().intersects(otherRobot->getBoundingBox())) {
      return true;
    }
  }

  return false;
}
