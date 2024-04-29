#include "Model/Simulation.hpp"
#include <iostream>

void Simulation::setMap(
    const std::map<std::string, std::vector<std::map<std::string, double>>>
        &map,
    int width, int height) {
  this->map->setMap(map, width, height);
}

void Simulation::run() {
  auto obstacles = map->getObstacles();

  for (auto &robot : map->getRobots()) {
    bool blocked = false;

    for (const auto &obstacle : obstacles) {
      if (robot->getViewBox().intersects(obstacle->getBoundingBox())) {
        std::cout << "Robot collided with obstacle" << std::endl;
        robot->turnLeft();
        blocked = true;
        break;
      }
    }
    if (!blocked)
      robot->move();
  }
}
