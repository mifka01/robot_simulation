/**
 * @file ViewBox.hpp
 * @brief This file contains declaration of ViewBox class
 * which represents a Robot's view box in the simulation
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include "BoundingBox.hpp"

/**
 * @class ViewBox
 * @brief This class represents a Robot's view box in the simulation
 *
 * This class is used for collision detection in the simulation
 * and is derived from BoundingBox class
 */
class ViewBox : public BoundingBox {
 public:
  /**
   * @brief Construct a new View Box object
   *
   * @param Point topLeft
   * @param Point topRight
   * @param Point bottomRight
   * @param Point bottomLeft
   */
  ViewBox(Point topLeft, Point topRight, Point bottomRight, Point bottomLeft)
      : BoundingBox(topLeft, topRight, bottomRight, bottomLeft) {}

  /**
   * @brief Rotate the view box around the center
   *
   * @param double angle
   * @param double centerX
   * @param double centerY
   */
  void rotate(double angle, double centerX, double centerY);

  /**
   * @brief Update the view box
   *
   * This method updates the view box based on the given parameters
   * and rotates it around the center
   *
   * @param double x
   * @param double y
   * @param double width
   * @param double height
   * @param double distance
   * @param double angle
   */
  void update(double x,
              double y,
              double width,
              double height,
              double distance,
              double angle);
};
