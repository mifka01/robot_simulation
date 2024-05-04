/**
 * @file MapManager.hpp
 * @brief This file contains declaration of MapManager class which is used for
 * loading and saving maps from and to json files
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include <QString>
#include <map>
#include <vector>
#include "Model/IMap.hpp"

/**
 * @class MapManager
 * @brief This class is used for loading and saving maps from and to json files
 */
class MapManager {
 public:
  /**
   * @brief Load map from json file
   *
   * @param QString path
   * @return const std::map<std::string, std::vector<std::map<std::string,
   * double>>>
   */
  static const std::map<std::string, std::vector<std::map<std::string, double>>>
  loadMap(QString path);

  /**
   * @brief Save map to json file
   *
   * @param QString path
   * @param IMap& map
   */
  static void saveMap(QString path, IMap& map);

  /**
   * @brief Get empty map
   *
   * @return const std::map<std::string, std::vector<std::map<std::string,
   * double>>>
   */
  static const std::map<std::string, std::vector<std::map<std::string, double>>>
  getEmptyMap();
};
