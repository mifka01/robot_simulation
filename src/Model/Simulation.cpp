#include "Model/Simulation.hpp"
#include <iostream>

void Simulation::setMap(
    const std::map<std::string, std::vector<std::map<std::string, int>>>& map,
    int width,
    int height) {
  this->map->setMap(map, width, height);
}

void Simulation::run() {
  std::cout << map->getWidth() << " " << map->getHeight() << std::endl;
  for (auto& robot : map->getRobots()) {
    robot->move();
  }
}
