/**
 * @file IMap.hpp
 * @brief This file contains declaration of IMap interface which is used for
 * managing the map in the simulation
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "Obstacle.hpp"
#include "Robot/Robot.hpp"

/**
 * @class IMap
 * @brief This class is used for managing the map in the simulation
 */
class IMap {
 public:
  virtual ~IMap() = default;

  /**
   * @brief Set the map
   *
   * @param const std::map<std::string, std::vector<std::map<std::string,
   * double>>>& map
   * @param int width
   * @param int height
   */
  virtual void setMap(
      const std::map<std::string, std::vector<std::map<std::string, double>>>&
          map,
      int width,
      int height) = 0;

  /**
   * @brief Set the width of the map
   *
   * @param int width
   */
  virtual void setWidth(int width) = 0;

  /**
   * @brief Set the height of the map
   *
   * @param int height
   */
  virtual void setHeight(int height) = 0;

  /**
   * @brief Get the width of the map
   *
   * @return int
   */
  virtual int getWidth() = 0;

  /**
   * @brief Get the height of the map
   *
   * @return int
   */
  virtual int getHeight() = 0;

  /**
   * @brief Get the obstacles
   *
   * @return std::vector<std::shared_ptr<Obstacle>>&
   */
  virtual std::vector<std::shared_ptr<Obstacle>>& getObstacles() = 0;

  /**
   * @brief Add obstacle to the map
   *
   * @param double x
   * @param double y
   * @param double width
   * @param double height
   * @param double rotation
   */
  virtual void addObstacle(double x,
                           double y,
                           double width,
                           double height,
                           double rotation) = 0;

  /**
   * @brief Remove obstacle from the map
   *
   * @param std::shared_ptr<Obstacle> obstacle
   */
  virtual void removeObstacle(std::shared_ptr<Obstacle> obstacle) = 0;

  /**
   * @brief Get the robots
   *
   * @return std::vector<std::shared_ptr<Robot>>&
   */
  virtual std::vector<std::shared_ptr<Robot>>& getRobots() = 0;

  /**
   * @brief Add robot to the map
   *
   * @param double x
   * @param double y
   * @param double diameter
   * @param double viewAngle
   * @param double rotateAngle
   * @param double viewDistance
   * @param bool rotateClockwise
   * @param int speed
   * @param Robot::Type type
   */
  virtual void addRobot(double x,
                        double y,
                        double diameter,
                        double viewAngle,
                        double rotateAngle,
                        double viewDistance,
                        bool rotateClockwise,
                        int speed,
                        Robot::Type type) = 0;

  /**
   * @brief Remove robot from the map
   *
   * @param std::shared_ptr<Robot> robot
   */
  virtual void removeRobot(std::shared_ptr<Robot> robot) = 0;

  /**
   * @brief Check if the point is out of map bounds
   *
   * @param double x
   * @param double y
   * @param int w
   * @param int h
   *
   * @return bool
   */
  bool isOutOfBounds(double x, double y, int w, int h) {
    return x < 0 || x + w > getWidth() || y < 0 || y + h > getHeight();
  }

  /**
   * @brief Check if the point is out of map bounds
   *
   * @param Point point
   *
   * @return bool
   */
  bool isOutOfBounds(Point point) {
    return isOutOfBounds(point.x, point.y, 0, 0);
  }
};
