/**
 * @file ControlsWidget.hpp
 * @brief This file contains declaration of ControlsWidget class
 * which is responsible for handling user interactions with the controls
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once

#include <QObject>
#include <QWidget>
#include <memory>
#include "GUI/Widget/ManualRobotControlsWidget.hpp"
#include "GUI/Widget/ObstacleParametersWidget.hpp"
#include "GUI/Widget/RobotParametersWidget.hpp"
#include "GUI/Widget/SpawnControlsWidget.hpp"
#include "Model/IMap.hpp"

/**
 * @class ControlsWidget
 * @brief This class is responsible for handling user interactions with the
 * controls in the GUI
 */
class ControlsWidget : public QWidget {
  Q_OBJECT
  std::shared_ptr<IMap> map;
  SpawnControlsWidget* spawnControls;
  RobotParametersWidget* robotParameters;
  ManualRobotControlsWidget* manualRobotControls;
  ObstacleParametersWidget* obstacleParameters;

 public:
  /**
   * @brief Construct a new ControlsWidget object
   *
   * @param parent
   */
  explicit ControlsWidget(QWidget* parent = nullptr);

  /**
   * @brief Set the Map object
   *
   * @param map
   */
  void setMap(std::shared_ptr<IMap> map) { this->map = map; }

  /**
   * @brief Method called when robot is selected
   *
   * Shows robot parameters and hide spawn controls
   *
   * @param robot
   */
  void onRobotSelected(std::shared_ptr<Robot> robot);

  /**
   * @brief Method called when robot is deselected
   *
   * Shows spawn controls and hides robot parameters
   *
   */
  void onRobotDeselected();

  /**
   * @brief Method called when robot should be removed
   *
   * Removes robot from map
   * Hides robot parameters and shows spawn controls
   *
   * @param robot
   */
  void removeRobot(std::shared_ptr<Robot> robot);

  /**
   * @brief Method called when obstacle is selected
   *
   * Shows obstacle parameters and hide spawn controls
   *
   * @param obstacle
   */
  void onObstacleSelected(std::shared_ptr<Obstacle> obstacle);

  /**
   * @brief Method called when obstacle is deselected
   *
   * Hides obstacle parameters and shows spawn controls
   *
   */
  void onObstacleDeselected();

  /**
   * @brief Method called when obstacle should be removed
   *
   * Removes obstacle from map
   * Hides obstacle parameters and shows spawn controls
   *
   * @param obstacle
   */
  void removeObstacle(std::shared_ptr<Obstacle> obstacle);

 private:
  /**
   * @brief Method called when load map button is clicked
   *
   * emits loadMapClicked signal
   *
   */
  void onLoadMapClicked();

  /**
   * @brief Method called when save map button is clicked
   *
   * emits saveMapClicked signal
   *
   */
  void onSaveMapClicked();

  /**
   * @brief Method called when start button is clicked
   *
   * emits startClicked signal
   */
  void onStartClicked();

  /**
   * @brief Method called when stop button is clicked
   *
   */
  void onStopClicked();

  /**
   * @brief Method called when add obstacle button is clicked
   *
   * emits addObstacleClicked signal
   *
   */
  void onAddObstacle();

  /**
   * @brief Method called when add robot button is clicked
   *
   * Adds robot to map based on type
   *
   * @param Robot::Type type
   */
  void onAddRobot(Robot::Type type);

 signals:
  /**
   * @brief Signal emitted when map should be loaded
   *
   */
  void loadMapClicked();

  /**
   * @brief Signal emitted when map should be saved
   *
   */
  void saveMapClicked();

  /**
   * @brief Signal emitted when start button is clicked
   *
   */
  void startClicked();

  /**
   * @brief Signal emitted when stop button is clicked
   *
   */
  void stopClicked();

  /**
   * @brief Signal emitted when add obstacle button is clicked
   *
   */
  void addObstacleClicked();

  /**
   * @brief Signal emitted when add robot button is clicked
   *
   */
  void addRobotClicked();

  /**
   * @brief Signal emitted when map needs to be updated
   *
   */
  void updateMap();
};
