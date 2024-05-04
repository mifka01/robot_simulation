/**
 * @file Simulation.hpp
 * @brief This file contains declaration of Simulation class which is
 * responsible for running the simulation and checking for collisions between
 * robots and obstacles
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include <map>
#include <string>
#include <vector>
#include "Model/IMap.hpp"
#include "Model/Map.hpp"

/**
 * @class Simulation
 * @brief This class is responsible for running the simulation and checking for
 * collisions between robots and obstacles
 */
class Simulation {
  std::shared_ptr<IMap> map;

 public:
  /**
   * @brief Construct a new Simulation object
   */
  Simulation() : map(std::make_shared<Map>()) {}

  /**
   * @brief Run the simulation
   */
  void run();

  /**
   *
   * @brief Check for collisions between robots and obstacles
   * @param Robot robot current robot
   * @param std::vector<Obstacle> obstacles vector of obstacles
   * @param std::vector<Robot> robots vector of robots
   * @return true if there is a collision, false otherwise
   */
  bool checkCollisions(const std::shared_ptr<Robot>& robot,
                       const std::vector<std::shared_ptr<Obstacle>>& obstacles,
                       const std::vector<std::shared_ptr<Robot>>& robots);

  /**
   * @brief Set the map
   *
   * @param const std::map<std::string, std::vector<std::map<std::string,
   * double>>>& map
   * @param int width
   * @param int height
   */
  void setMap(const std::map<std::string,
                             std::vector<std::map<std::string, double>>>& map,
              int width,
              int height);

  /**
   * @brief Get the map
   *
   * @return std::shared_ptr<IMap>
   */
  std::shared_ptr<IMap> getMap() { return map; }
};
