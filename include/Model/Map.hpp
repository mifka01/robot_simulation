#pragma once
#include <map>
#include <string>
#include <vector>
#include "Obstacle.hpp"
#include "Robot/Robot.hpp"

class Map {
 private:
  std::vector<std::shared_ptr<Robot>> robots;
  std::vector<std::shared_ptr<Obstacle>> obstacles;

 public:
  // map
  //  robots: [{type: 0, x: 0, y: 0, diameter: 0, angle: 0, speed: 0}]
  //  obstacles: [{x: 0, y: 0, width: 0, height: 0}]
  Map(const std::map<std::string, std::vector<std::map<std::string, int>>>&
          map);
};
