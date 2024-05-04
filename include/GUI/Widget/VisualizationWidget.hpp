/**
 * @file VisualizationWidget.hpp
 * @brief This file contains declaration of VisualizationWidget class
 * which is responsible for visualizing the map in the GUI
 * and handling user interactions with the map visualization
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include <QPainter>
#include <QWidget>
#include <memory>
#include "GUI/Label.hpp"
#include "Model/IMap.hpp"

/**
 * @class VisualizationWidget
 * @brief This class is responsible for visualizing the map in the GUI
 * and handling user interactions with the map visualization
 */
class VisualizationWidget : public QWidget {
  Q_OBJECT
  std::shared_ptr<IMap> map;
  Label* simulationStateLabel;

  std::shared_ptr<Obstacle> grabbedObstacle;
  std::shared_ptr<Obstacle> selectedObstacle;

  std::shared_ptr<Robot> grabbedRobot;
  std::shared_ptr<Robot> selectedRobot;

 public:
  /**
   * @brief Construct a new VisualizationWidget object
   *
   * @param QWidget* parent
   */
  VisualizationWidget(QWidget* parent = nullptr);

  /**
   * @brief Set the Map object
   *
   * @param std::shared_ptr<IMap> map
   */
  void setMap(std::shared_ptr<IMap> map) { this->map = map; }

  /**
   * @brief Shows the simulation state label
   */
  void onStop();

  /**
   * @brief Hides the simulation state label
   */
  void onStart();

 signals:
  /**
   * @brief Signal emitted when obstacle is selected
   *
   * @param std::shared_ptr<Obstacle> obstacle
   */
  void obstacleSelected(std::shared_ptr<Obstacle> obstacle);

  /**
   * @brief Signal emitted when obstacle is deselected
   */
  void obstacleDeselected();

  /**
   * @brief Signal emitted when robot is selected
   *
   * @param std::shared_ptr<Robot> robot
   */
  void robotSelected(std::shared_ptr<Robot> robot);

  /**
   * @brief Signal emitted when robot is deselected
   */
  void robotDeselected();

 protected:
  /**
   * @brief Method called when paint event is triggered
   * It draws the map and all its elements
   *
   * @param QPaintEvent* event
   */
  void paintEvent(QPaintEvent* event) override;

  /**
   * @brief Method called when resize event is triggered
   * It resizes the map
   *
   * @param QResizeEvent* event
   */
  void resizeEvent(QResizeEvent* event) override;

  /**
   * @brief Method to draw obstacle
   * It draws the obstacle on the map
   * It is called from paintEvent
   *
   * @param QPainter& painter
   * @param std::shared_ptr<Obstacle> obstacle
   */
  void drawObstacle(QPainter& painter, std::shared_ptr<Obstacle> obstacle);
  /**
   * @brief Method to draw robot
   * It draws the robot on the map
   * It is called from paintEvent
   *
   * @param QPainter& painter
   * @param std::shared_ptr<Robot> robot
   */
  void drawRobot(QPainter& painter, std::shared_ptr<Robot> robot);

  /**
   * @brief Method called when mouse is pressed
   * It handles the mouse press event
   * and selects the obstacle or robot
   * or deselects the selected obstacle or robot
   *
   * @param QMouseEvent* event
   */
  void mousePressEvent(QMouseEvent* event) override;

  /**
   * @brief Method called when mouse is moved
   * It handles the mouse move event and moves the obstacle or robot
   *
   * @param QMouseEvent* event
   */
  void mouseMoveEvent(QMouseEvent* event) override;

  /**
   * @brief Method called when mouse is released
   * It handles the mouse release event
   * and stops moving the obstacle or robot
   *
   * @param QMouseEvent* event
   */
  void mouseReleaseEvent(QMouseEvent* event) override;
};
