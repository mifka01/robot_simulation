#pragma once

#include <QWidget>
#include <QObject>
#include <memory>
#include "GUI/Widget/ManualRobotControlsWidget.hpp"
#include "GUI/Widget/ObstacleParametersWidget.hpp"
#include "GUI/Widget/RobotParametersWidget.hpp"
#include "GUI/Widget/SpawnControlsWidget.hpp"
#include "Model/IMap.hpp"
#include <memory>

class ControlsWidget : public QWidget {
  Q_OBJECT
  std::shared_ptr<IMap> map;
  SpawnControlsWidget* spawnControls;
  ObstacleParametersWidget* obstacleParameters;
  RobotParametersWidget* robotParameters;
  ManualRobotControlsWidget* manualRobotControls;
  

 public:
  explicit ControlsWidget(QWidget* parent = nullptr);

  void setMap(std::shared_ptr<IMap> map) { this->map = map; }

  void onObstacleSelected(std::shared_ptr<Obstacle> obstacle);
  void onObstacleDeselected();
  void onRobotSelected(std::shared_ptr<Robot> robot);
  void onRobotDeselected();
  void onRemoveObstacle(std::shared_ptr<Obstacle> obstacle);
  void onRemoveRobot(std::shared_ptr<Robot> robot);

 signals:
  void loadMapClicked();
  void saveMapClicked();
  void startClicked();
  void stopClicked();
  void addObstacleClicked();
  void addRobotClicked();
  void updateMap();

 private:
  void onLoadMapClicked();
  void onSaveMapClicked();
  void onStartClicked();
  void onStopClicked();
  void onAddObstacle();
  void onAddRobot(Robot::Type type);
};
