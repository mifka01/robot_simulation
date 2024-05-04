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
   * @param map
   *
   * @param width
   * @param height
   */
  virtual void setMap(
      const std::map<std::string, std::vector<std::map<std::string, double>>>&
          map,
      int width,
      int height) = 0;

  /**
   * @brief Set the width of the map
   *
   * @param width
   */
  virtual void setWidth(int width) = 0;

  /**
   * @brief Set the height of the map
   *
   * @param height
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
   * @param x
   * @param y
   * @param width
   * @param height
   * @param rotation
   */
  virtual void addObstacle(double x,
                           double y,
                           double width,
                           double height,
                           double rotation) = 0;

  /**
   * @brief Remove obstacle from the map
   *
   * @param obstacle
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
   * @param x
   * @param y
   * @param diameter
   * @param viewAngle
   * @param rotateAngle
   * @param viewDistance
   * @param bool rotateClockwise
   * @param speed
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
   * @param robot
   */
  virtual void removeRobot(std::shared_ptr<Robot> robot) = 0;

  /**
   * @brief Check if the point is out of map bounds
   *
   * @param x
   * @param y
   * @param w
   * @param h
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
