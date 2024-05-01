#include <QVBoxLayout>
#include "GUI/Widget/ControlsWidget.hpp"
#include "GUI/Widget/SimulationControlsWidget.hpp"
#include "GUI/Widget/SpawnControlsWidget.hpp"
#include "Settings.hpp"
#include "Model/Map.hpp"

ControlsWidget::ControlsWidget(QWidget* parent) : QWidget(parent) {
  // load empty map
map = std::make_shared<Map>();

QVBoxLayout* layout = new QVBoxLayout(this);

SimulationControlsWidget* simulationControls = new SimulationControlsWidget(this);
layout->addWidget(simulationControls);

connect(simulationControls, &SimulationControlsWidget::loadMapClicked, this, &ControlsWidget::onLoadMapClicked);
connect(simulationControls, &SimulationControlsWidget::saveMapClicked, this, &ControlsWidget::onSaveMapClicked);
connect(simulationControls, &SimulationControlsWidget::startClicked, this, &ControlsWidget::onStartClicked);
connect(simulationControls, &SimulationControlsWidget::stopClicked, this, &ControlsWidget::onStopClicked);

SpawnControlsWidget* spawnControls = new SpawnControlsWidget(this);
layout->addWidget(spawnControls);

connect(spawnControls, &SpawnControlsWidget::addObstacleClicked, this, &ControlsWidget::onAddObstacle);
connect(spawnControls, &SpawnControlsWidget::addManualRobotClicked, this, [this]() {
    this->onAddRobot(0);
});
connect(spawnControls, &SpawnControlsWidget::addAutoRobotClicked, this, [this]() {
    this->onAddRobot(1);
});

layout->addStretch();
setLayout(layout);

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
  map->addObstacle(map->getWidth() / 2, map->getHeight() / 2, Settings::OBSTACLE_BASE_WIDTH, Settings::OBSTACLE_BASE_HEIGHT);
  emit updateMap();
}

void ControlsWidget::onAddRobot(int type) {
  emit stopClicked();
  map->addRobot(map->getWidth() / 2, map->getHeight() / 2, Settings::ROBOT_BASE_DIAMETER, Settings::ROBOT_BASE_VIEW_ANGLE, Settings::ROBOT_BASE_ROTATE_ANGLE, Settings::ROBOT_BASE_COLISION_DISTANCE, Settings::ROBOT_BASE_ROTATE_CLOCKWISE, Settings::ROBOT_BASE_SPEED, type);
  emit updateMap();
}

