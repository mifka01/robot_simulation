/**
 * @file AutonomousRobot.hpp
 * @brief This file contains declaration of AutonomousRobot class which is
 * derived from Robot class and represents autonomous robot in the simulation
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include "Robot.hpp"

/**
 * @class AutonomousRobot
 * @brief This class is derived from Robot class and represents autonomous robot
 * in the simulation
 */
class AutonomousRobot : public Robot {
 public:
  using Robot::Robot;

  /**
   * @brief Get the Type of the robot
   *
   * @return Robot::Type
   */
  Type getType() const override { return Robot::Type::AUTONOMOUS; }

  /**
   * @brief Run the robot logic for one step
   *
   */
  void run() override;

  /**
   * @brief Method called when robot collides with an obstacle
   */
  void onCollision() override;
};
