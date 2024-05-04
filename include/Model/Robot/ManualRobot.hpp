/**
 * @file ManualRobot.hpp
 * @brief This file contains declaration of ManualRobot class
 * which is derived from Robot class and represents manual robot in the
 * simulation
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include "Robot.hpp"

/**
 * @class ManualRobot
 * @brief This class is derived from Robot class and represents manual robot in
 * the simulation
 */
class ManualRobot : public Robot {
 public:
  enum class State { MOVE, STOP, TURN_LEFT, TURN_RIGHT };

 private:
  State state = State::STOP;

 public:
  using Robot::Robot;

  /**
   * @brief Get the Type of the robot
   *
   * @return Robot::Type
   */
  Type getType() const override { return Robot::Type::MANUAL; }

  /**
   * @brief Get the State of the robot
   *
   * @return ManualRobot::State
   */
  State getState() { return state; }

  /**
   * @brief Set the State of the robot
   *
   * @param ManualRobot::State state
   */
  void setState(State state) { this->state = state; }

  /**
   * @brief Run the robot logic for one step
   */
  void run() override;

  /**
   * @brief Method called when robot collides with an obstacle
   */
  void onCollision() override;
};
