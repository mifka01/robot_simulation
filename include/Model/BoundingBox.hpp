/**
 * @file BoundingBox.hpp
 * @brief This file contains declaration of BoundingBox class
 * which is used for collision detection in the simulation
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include <vector>

/**
 * @struct Vector
 * @brief This struct represents a 2D vector
 */
struct Vector {
  double x, y;

  Vector operator-(const Vector& other) const {
    return {x - other.x, y - other.y};
  }
};

/**
 * @struct Point
 * @brief This struct represents a 2D point
 */
struct Point {
  double x;
  double y;

  operator Vector() const { return {x, y}; }
};

/**
 * @class BoundingBox
 * @brief This class is used for collision detection in the simulation
 */
class BoundingBox {
 private:
  std::vector<Point> points;

  /**
   * @brief Construct a new Bounding Box object
   *
   * @param Point topLeft
   * @param Point topRight
   * @param Point bottomRight
   * @param Point bottomLeft
   */
 public:
  BoundingBox(Point topLeft,
              Point topRight,
              Point bottomRight,
              Point bottomLeft) {
    points.push_back(topLeft);
    points.push_back(topRight);
    points.push_back(bottomRight);
    points.push_back(bottomLeft);
  }

  /**
   * @brief Rotate the bounding box around the center
   *
   * @param angle
   * @param centerX
   * @param centerY
   */
  void rotate(double angle, double centerX, double centerY);
  /**
   * @brief Update the bounding box
   *
   * It sets the new position, width, height and angle of the bounding box
   * recalculates the points
   *
   * @param x
   * @param y
   * @param width
   * @param height
   * @param angle
   */
  void update(double x,
              double y,
              double width,
              double height,
              double angle = 0);
  /**
   * @brief Move the bounding box
   *
   * It moves the bounding box by dx and dy
   *
   * @param dx
   * @param dy
   */
  void move(double dx, double dy);

  /**
   * @brief Check if the bounding box intersects with other bounding box
   *
   * @param BoundingBox other
   *
   * @return bool
   */
  bool intersects(const BoundingBox& other) const;

  /**
   * @brief Check if the bounding box contains a point
   *
   * @param Point point
   *
   * @return bool
   */
  bool contains(const Point& point) const;

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
    points[0] = topLeft;
    points[1] = topRight;
    points[2] = bottomRight;
    points[3] = bottomLeft;
  }

  /**
   * @brief Get the points of the bounding box
   *
   * @return std::vector<Point>
   */
  std::vector<Point>& getPoints() { return points; }

 private:
  /**
   * @brief Get the axes of the bounding box
   *
   * @return std::vector<Vector>
   */
  std::vector<Vector> getAxes() const;

  /**
   * @brief Calculate the dot product of two vectors
   *
   * @param Vector a
   * @param Vector b
   *
   * @return double
   */
  double dotProduct(const Vector& a, const Vector& b) const;
};
