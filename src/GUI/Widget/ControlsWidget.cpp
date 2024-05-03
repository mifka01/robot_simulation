/**
 * @file ControlsWidget.cpp
 * @brief This file contains declaration of ControlsWidget class
 * which is responsible for handling user interactions with the controls
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "GUI/Widget/ControlsWidget.hpp"
#include <QVBoxLayout>
#include "GUI/Widget/SimulationControlsWidget.hpp"
#include "GUI/Widget/SpawnControlsWidget.hpp"
#include "Model/Map.hpp"
#include "Settings.hpp"

ControlsWidget::ControlsWidget(QWidget* parent) : QWidget(parent) {
  // load empty map
  map = std::make_shared<Map>();

  QVBoxLayout* layout = new QVBoxLayout(this);

  SimulationControlsWidget* simulationControls =
      new SimulationControlsWidget(this);
  layout->addWidget(simulationControls);

  connect(simulationControls, &SimulationControlsWidget::loadMapClicked, this,
          &ControlsWidget::onLoadMapClicked);
  connect(simulationControls, &SimulationControlsWidget::saveMapClicked, this,
          &ControlsWidget::onSaveMapClicked);
  connect(simulationControls, &SimulationControlsWidget::startClicked, this,
          &ControlsWidget::onStartClicked);
  connect(simulationControls, &SimulationControlsWidget::stopClicked, this,
          &ControlsWidget::onStopClicked);

  spawnControls = new SpawnControlsWidget(this);
  layout->addWidget(spawnControls);

  connect(spawnControls, &SpawnControlsWidget::addObstacleClicked, this,
          &ControlsWidget::onAddObstacle);
  connect(spawnControls, &SpawnControlsWidget::addManualRobotClicked, this,
          [this]() { this->onAddRobot(Robot::Robot::Type::MANUAL); });
  connect(spawnControls, &SpawnControlsWidget::addAutoRobotClicked, this,
          [this]() { this->onAddRobot(Robot::Robot::Type::AUTONOMOUS); });

  obstacleParameters = new ObstacleParametersWidget(this);
  layout->addWidget(obstacleParameters);
  obstacleParameters->hide();

  connect(obstacleParameters, &ObstacleParametersWidget::updateMap, this,
          &ControlsWidget::updateMap);
  connect(obstacleParameters, &ObstacleParametersWidget::removeObstacle, this,
          &ControlsWidget::removeObstacle);

  robotParameters = new RobotParametersWidget(this);
  layout->addWidget(robotParameters);
  robotParameters->hide();

  connect(robotParameters, &RobotParametersWidget::updateMap, this,
          &ControlsWidget::updateMap);
  connect(robotParameters, &RobotParametersWidget::removeRobot, this,
          &ControlsWidget::removeRobot);

  manualRobotControls = new ManualRobotControlsWidget(this);
  layout->addWidget(manualRobotControls);
  manualRobotControls->hide();

  layout->addStretch();
  setLayout(layout);
}

void ControlsWidget::onObstacleSelected(std::shared_ptr<Obstacle> obstacle) {
  obstacleParameters->setObstacle(obstacle);
  obstacleParameters->show();
  spawnControls->hide();
}

void ControlsWidget::onObstacleDeselected() {
  this->obstacleParameters->hide();
  spawnControls->show();
}

void ControlsWidget::onRobotSelected(std::shared_ptr<Robot> robot) {
  robotParameters->setRobot(robot);
  robotParameters->show();
  spawnControls->hide();
  if (robot->getType() == Robot::Type::MANUAL) {
    manualRobotControls->setRobot(std::static_pointer_cast<ManualRobot>(robot));
    manualRobotControls->show();
  };
}

void ControlsWidget::onRobotDeselected() {
  robotParameters->hide();
  manualRobotControls->hide();
  spawnControls->show();
}

void ControlsWidget::onLoadMapClicked() {
  emit loadMapClicked();
}

void ControlsWidget::onSaveMapClicked() {
  emit saveMapClicked();
}

void ControlsWidget::onStartClicked() {
  emit startClicked();
}

void ControlsWidget::onStopClicked() {
  emit stopClicked();
}

void ControlsWidget::onAddObstacle() {
  emit stopClicked();
  map->addObstacle(
      map->getWidth() / 2, map->getHeight() / 2, Settings::OBSTACLE_BASE_WIDTH,
      Settings::OBSTACLE_BASE_HEIGHT, Settings::OBSTACLE_BASE_ROTATION);
  emit updateMap();
}

void ControlsWidget::onAddRobot(Robot::Type type) {
  emit stopClicked();
  map->addRobot(
      map->getWidth() / 2, map->getHeight() / 2, Settings::ROBOT_BASE_DIAMETER,
      Settings::ROBOT_BASE_VIEW_ANGLE, Settings::ROBOT_BASE_ROTATE_ANGLE,
      Settings::ROBOT_BASE_COLISION_DISTANCE,
      Settings::ROBOT_BASE_ROTATE_CLOCKWISE, Settings::ROBOT_BASE_SPEED, type);
  emit updateMap();
}

void ControlsWidget::removeObstacle(std::shared_ptr<Obstacle> obstacle) {
  map->removeObstacle(obstacle);
  this->obstacleParameters->hide();
  this->spawnControls->show();
  emit updateMap();
}

void ControlsWidget::removeRobot(std::shared_ptr<Robot> robot) {
  map->removeRobot(robot);
  this->robotParameters->hide();
  this->manualRobotControls->hide();
  this->spawnControls->show();
  emit updateMap();
}
