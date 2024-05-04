/**
 * @file Robot.hpp
 * @brief This file contains declaration of Robot class
 * which represents a robot in the simulation
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include <cmath>
#include "Model/BoundingBox.hpp"
#include "Model/ViewBox.hpp"

class Robot {
 public:
  enum class Type { MANUAL = 0, AUTONOMOUS };

 private:
  double x;
  double y;

  double diameter;

  double viewAngle;
  double rotateAngle;

  double viewDistance;
  bool rotateClockwise;

  int speed;
  BoundingBox boundingBox;
  ViewBox viewBox;

 public:
  /**
   * @brief Construct a new Robot object
   *
   * @param double x
   * @param double y
   * @param double diameter
   * @param double viewAngle
   * @param double rotateAngle
   * @param double viewDistance
   * @param bool rotateClockwise
   * @param int speed
   */
  Robot(double x,
        double y,
        double diameter,
        double viewAngle,
        double rotateAngle,
        double viewDistance,
        bool rotateClockwise,
        int speed)
      : x(x),
        y(y),
        diameter(diameter),
        viewAngle(viewAngle),
        rotateAngle(rotateAngle),
        viewDistance(viewDistance),
        rotateClockwise(rotateClockwise),
        speed(speed),
        boundingBox({x, y},
                    {x + diameter, y},
                    {x + diameter, y + diameter},
                    {x, y + diameter}),
        viewBox({x + diameter, y},
                {x + diameter + viewDistance, y},
                {x + diameter + viewDistance, y + diameter},
                {x + diameter, y + diameter}) {
    viewBox.rotate(viewAngle, x + diameter / 2, y + diameter / 2);
  }

  /**
   * @brief Move the robot
   *
   * It moves the robot by speed in the direction of the rotateAngle
   * It also updates the bounding box and view box
   */
  virtual void move();

  /**
   * @brief Turn the robot
   *
   * It turns the robot by rotateAngle based on the rotateClockwise
   */
  virtual void turn();

  /**
   * @brief Turn the robot left
   *
   * It turns the robot left by rotateAngle
   */
  virtual void turnLeft();

  /**
   * @brief Turn the robot right
   *
   * It turns the robot right by rotateAngle
   */
  virtual void turnRight();

  /**
   * @brief Run the robot logic for one step
   */
  virtual void run() = 0;

  /**
   * @brief Method called when robot collides with an obstacle
   */
  virtual void onCollision() = 0;

  /**
   * @brief Set the x position of the robot
   *
   * It sets the x position of the robot and updates the bounding box and view
   * box
   * @param double x
   */
  void setX(double x) {
    this->x = x;
    this->boundingBox.update(x, y, diameter, diameter);
    this->viewBox.update(x, y, diameter, diameter, viewDistance, viewAngle);
  }

  /**
   * @brief Set the y position of the robot
   *
   * It sets the y position of the robot and updates the bounding box and view
   * box
   * @param double y
   */
  void setY(double y) {
    this->y = y;
    this->boundingBox.update(x, y, diameter, diameter);
    this->viewBox.update(x, y, diameter, diameter, viewDistance, viewAngle);
    ;
  }

  /**
   * @brief Set the diameter of the robot
   *
   * It sets the diameter of the robot and updates the bounding box and view
   * box
   * @param double diameter
   */
  virtual void setDiameter(double diameter) {
    this->diameter = diameter;
    this->boundingBox.update(x, y, diameter, diameter);
    this->viewBox.update(x, y, diameter, diameter, viewDistance, viewAngle);
  }

  /**
   * @brief Set the speed of the robot
   *
   * @param int speed
   */
  virtual void setSpeed(int speed) { this->speed = speed; }

  /**
   * @brief Set the rotate angle of the robot
   *
   * It also converts the input angle from degrees to radians
   *
   * @param double angle in degrees
   */
  virtual void setRotateAngle(double angle) {
    this->rotateAngle = angle * M_PI / 180;
  }
  /**
   * @brief Set the view angle of the robot
   *
   * It also converts the input angle from degrees to radians
   *
   * @param double angle in degrees
   */
  virtual void setViewAngle(double angle) {
    this->viewAngle = angle * M_PI / 180;
    this->viewBox.update(x, y, diameter, diameter, viewDistance, viewAngle);
  }

  /**
   * @brief Set the view distance of the robot
   *
   * It updates the view box dimensions
   *
   * @param double distance
   */
  virtual void setViewDistance(double distance) {
    this->viewDistance = distance;
    this->viewBox.update(x, y, diameter, diameter, viewDistance, viewAngle);
  }

  /**
   * @brief Set the rotate direction of the robot
   *
   * @param bool clockwise
   */
  virtual void setRotateClockwise(bool clockwise) {
    this->rotateClockwise = clockwise;
  }

  /**
   * @brief Get the x position of the robot
   *
   * @return double
   */
  double getX() const { return x; }

  /**
   * @brief Get the y position of the robot
   *
   * @return double
   */
  double getY() const { return y; }

  /**
   * @brief Get the diameter of the robot
   *
   * @return double
   */
  double getDiameter() const { return diameter; }

  /**
   * @brief Get the rotate angle of the robot in degrees
   *
   * It converts the angle from radians to degrees
   *
   * @return double angle in degrees
   */
  double getRotateAngle() const { return rotateAngle / M_PI * 180; }

  /**
   * @brief Get the view angle of the robot in degrees
   *
   * It converts the angle from radians to degrees
   *
   * @return double angle in degrees
   */
  double getViewAngle() const { return std::fmod(viewAngle / M_PI * 180, 360); }

  /**
   * @brief Get the rotate angle of the robot in radians
   *
   * @return double angle in radians
   */
  double getRotateAngleRad() const { return rotateAngle; }

  /**
   * @brief Get the view angle of the robot in radians
   *
   * @return double angle in radians
   */
  double getViewAngleRad() const { return viewAngle; }

  /**
   * @brief Get the view distance of the robot
   *
   * @return double
   */
  double getViewDistance() const { return viewDistance; }

  /**
   * @brief Get the rotate direction of the robot
   *
   * @return bool
   */
  bool getRotateClockwise() const { return rotateClockwise; }

  /**
   * @brief Get the speed of the robot
   *
   * @return int
   */
  int getSpeed() const { return speed; }

  /**
   * @brief Get the type of the robot
   *
   * @return Robot::Type
   */
  virtual Type getType() const = 0;

  /**
   * @brief Get the bounding box of the robot
   *
   * @return BoundingBox
   */
  BoundingBox getBoundingBox() const { return boundingBox; }

  /**
   * @brief Get the view box of the robot
   *
   * @return ViewBox
   */
  ViewBox getViewBox() const { return viewBox; }

  virtual ~Robot() {}
};
