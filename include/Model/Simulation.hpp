#pragma once
#include <map>
#include <string>
#include <vector>
#include "Model/IMap.hpp"
#include "Model/Map.hpp"

class Simulation {
    std::shared_ptr<IMap> map;

 public:
  Simulation() : map(std::make_shared<Map>()) {}

  void run();

  void setMap(
      const std::map<std::string, std::vector<std::map<std::string, double>>>& map,
      int width,
      int height);

  std::shared_ptr<IMap> getMap() { return map; }
};