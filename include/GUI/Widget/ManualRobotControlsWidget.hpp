/**
 * @file ManualRobotControlsWidget.hpp
 * @brief This file contains declaration of ManualRobotControlsWidget class
 * which is responsible for handling user interactions with the manual robot
 * controls
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include <QWidget>
#include <memory>
#include "Model/Robot/ManualRobot.hpp"

/**
 * @class ManualRobotControlsWidget
 * @brief This class is responsible for handling user interactions with the
 * manual robot controls in the GUI
 */
class ManualRobotControlsWidget : public QWidget {
  Q_OBJECT
  std::shared_ptr<ManualRobot> robot;

 public:
  /**
   * @brief Construct a new ManualRobotControlsWidget object
   * @param parent
   */
  ManualRobotControlsWidget(QWidget* parent = nullptr);

  /**
   * @brief Set the Robot object
   * @param robot
   */
  void setRobot(std::shared_ptr<ManualRobot> robot);

 private:
  /**
   * @brief Method called when move button is clicked
   * It sets the robot state to move
   */
  void onMoveClicked();

  /**
   * @brief Method called when stop button is clicked
   * It sets the robot state to stop
   */
  void onStopClicked();

  /**
   * @brief Method called when turn left button is clicked
   * It sets the robot state to turn left
   */
  void onTurnLeftClicked();

  /**
   * @brief Method called when turn right button is clicked
   * It sets the robot state to turn right
   */
  void onTurnRightClicked();
};
