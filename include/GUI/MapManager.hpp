#pragma once
#include <QString>
#include <map>
#include <vector>
#include "Model/IMap.hpp"

class MapManager{
 public:
  static const std::map<std::string, std::vector<std::map<std::string, double>>>
  loadMap(QString path);
  static void saveMap(QString path, IMap &map);
  
  static const std::map<std::string, std::vector<std::map<std::string, double>>> getEmptyMap();
};
