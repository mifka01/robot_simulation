#pragma once
#include <Qstring>
#include <map>
#include <vector>

class MapLoader {
 public:
  static const std::map<std::string, std::vector<std::map<std::string, int>>>
  loadMap(QString path);
};
