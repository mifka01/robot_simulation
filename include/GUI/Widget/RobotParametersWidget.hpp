/**
 * @file RobotParametersWidget.hpp
 * @brief This file contains declaration of RobotParametersWidget class
 * which is responsible for handling user interactions with the robot
 * parameters in the GUI
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once

#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QObject>
#include <QSpinBox>
#include <QWidget>
#include <memory>
#include "Model/Robot/Robot.hpp"

/**
 * @class RobotParametersWidget
 * @brief This class is responsible for handling user interactions with the
 * robot parameters in the GUI
 */
class RobotParametersWidget : public QWidget {
  Q_OBJECT

  std::shared_ptr<Robot> robot;

  QDoubleSpinBox* x;
  QDoubleSpinBox* y;

  QDoubleSpinBox* diameter;

  QDoubleSpinBox* viewAngle;
  QDoubleSpinBox* viewDistance;

  QDoubleSpinBox* rotateAngle;
  QCheckBox* rotateClockwise;

  QSpinBox* speed;

 public:
  /**
   * @brief Construct a new RobotParametersWidget object
   *
   * @param parent
   */
  RobotParametersWidget(QWidget* parent = nullptr);

  /**
   * @brief Set the Robot object
   *
   * @param robot
   */
  void setRobot(std::shared_ptr<Robot> robot);

  /**
   * @brief Creates a parameter control
   * in the form of a QDoubleSpinBox plus Label and adds it to the parent layout
   *
   * @param labelText
   * @param minRange
   * @param maxRange
   * @param QHBoxLayout* parentLayout
   *
   * @return QDoubleSpinBox*
   */
  QDoubleSpinBox* createParameterControl(const QString& labelText,
                                         double minRange,
                                         double maxRange,
                                         QHBoxLayout* parentLayout);

 signals:
  /**
   * @brief Signal emitted when map needs to be updated
   *
   */
  void updateMap();

  /**
   * @brief Signal emitted when remove robot button is clicked
   * and robot should be removed
   *
   * @param robot
   */
  void removeRobot(std::shared_ptr<Robot> robot);

 private:
  /**
   * @brief Method called when x value is changed
   *
   * It sets the robot x value and emits updateMap signal
   *
   * @param value
   */
  void onXChanged(double value);

  /**
   * @brief Method called when y value is changed
   *
   * It sets the robot y value and emits updateMap signal
   *
   * @param value
   */
  void onYChanged(double value);

  /**
   * @brief Method called when diameter value is changed
   *
   * It sets the robot diameter value and emits updateMap signal
   *
   * @param value
   */
  void onDiameterChanged(double value);

  /**
   * @brief Method called when view angle value is changed
   *
   * It sets the robot view angle value and emits updateMap signal
   *
   * @param value
   */
  void onViewAngleChanged(double value);

  /**
   * @brief Method called when view distance value is changed
   *
   * It sets the robot view distance value and emits updateMap signal
   *
   * @param value
   */
  void onViewDistanceChanged(double value);

  /**
   * @brief Method called when rotate angle value is changed
   *
   * It sets the robot rotate angle value and emits updateMap signal
   *
   * @param value
   */
  void onRotateAngleChanged(double value);

  /**
   * @brief Method called when rotate clockwise value is changed
   *
   * It sets the robot rotate clockwise value and emits updateMap signal
   *
   * @param bool value
   */
  void onRotateClockwiseChanged(bool value);

  /**
   * @brief Method called when speed value is changed
   *
   * It sets the robot speed value and emits updateMap signal
   *
   * @param value
   */
  void onSpeedChanged(int value);
};
