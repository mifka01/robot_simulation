/**
 * @file Obstacle.hpp
 * @brief This file contains declaration of Obstacle class
 * which represents an obstacle in the simulation
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include <cmath>
#include "Model/BoundingBox.hpp"

/**
 * @class Obstacle
 * @brief This class represents an obstacle in the simulation
 */
class Obstacle {
 protected:
  double x;
  double y;
  double width;
  double height;
  double rotation;
  std::vector<Point> points;
  BoundingBox boundingBox;

 public:
  /**
   * @brief Construct a new Obstacle object
   *
   * @param x
   * @param y
   * @param width
   * @param height
   * @param rotation
   */
  Obstacle(double x, double y, double width, double height, double rotation);

  /**
   * @brief Set the x position of the object
   *
   * @param x
   */
  void setX(double x) {
    this->x = x;
    update();
  }

  /**
   * @brief Set the y position of the object
   *
   * @param y
   */
  void setY(double y) {
    this->y = y;
    update();
  }
  /**
   * @brief Set the width of the object
   *
   * @param width
   */
  void setWidth(double width) {
    this->width = width;
    update();
  }

  /**
   * @brief Set the height of the object
   *
   * @param height
   */
  void setHeight(double height) {
    this->height = height;
    update();
  }

  /**
   *
   * @brief Set the rotation of the object
   *
   * @param rotation
   */
  void setRotation(double rotation) {
    this->rotation = rotation * M_PI / 180;
    update();
  }

  /**
   * @brief Set the points of the bounding box
   *
   * @param Point topLeft
   * @param Point topRight
   * @param Point bottomRight
   * @param Point bottomLeft
   */
  void setPoints(Point topLeft,
                 Point topRight,
                 Point bottomRight,
                 Point bottomLeft) {
    points = {topLeft, topRight, bottomRight, bottomLeft};
  }

  /**
   * @brief Get the x position of the obstacle
   *
   * @return double
   */
  double getX() const { return x; }

  /**
   * @brief Get the y position of the obstacle
   *
   * @return double
   */
  double getY() const { return y; }

  /**
   * @brief Get the width of the obstacle
   *
   * @return double
   */
  double getWidth() const { return width; }

  /**
   * @brief Get the height of the obstacle
   *
   * @return double
   */
  double getHeight() const { return height; }

  /**
   * @brief Get the rotation of the obstacle
   *
   * @return double
   */
  double getRotation() const { return rotation * 180 / M_PI; }

  /**
   * @brief Get the points of the obstacle
   *
   * @return std::vector<Point>&
   */
  std::vector<Point>& getPoints() { return points; }

  /**
   * @brief Get the bounding box of the obstacle
   *
   * @return BoundingBox
   */
  BoundingBox getBoundingBox() const { return boundingBox; }

  /**
   * @brief Rotate the obstacle around the center
   *
   * @param angle
   * @param centerX
   * @param centerY
   */
  void rotate(double angle, double centerX, double centerY);

  /**
   * @brief Update the obstacle
   *
   * It sets the new position, width, height and angle of the obstacle
   * recalculates the points
   */
  void update();
};
