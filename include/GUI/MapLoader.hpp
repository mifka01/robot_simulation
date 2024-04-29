#pragma once
#include <QString>
#include <map>
#include <vector>

class MapLoader {
 public:
  static const std::map<std::string, std::vector<std::map<std::string, double>>>
  loadMap(QString path);
};
