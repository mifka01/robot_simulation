#pragma once
#include <memory>
#include <QPainter>
#include <QWidget>
#include "GUI/Label.hpp"
#include "Model/IMap.hpp"
#include "Model/Map.hpp"

class VisualizationWidget : public QWidget {
  Q_OBJECT
  std::shared_ptr<IMap> map;
  std::shared_ptr<Obstacle> grabbedObstacle;
  std::shared_ptr<Obstacle> selectedObstacle;
  std::shared_ptr<Robot> grabbedRobot;
  std::shared_ptr<Robot> selectedRobot;
  Label *simulationStateLabel;

 public:
  explicit VisualizationWidget(QWidget* parent = nullptr);

  void setMap(std::shared_ptr<IMap> map) { this->map = map; }
  void onStop();
  void onStart();

  signals:
    void obstacleSelected(std::shared_ptr<Obstacle> obstacle);
    void obstacleDeselected();
    void robotSelected(std::shared_ptr<Robot> robot);
    void robotDeselected();

 protected:
  void paintEvent(QPaintEvent* event) override;
  void resizeEvent(QResizeEvent* event) override;

  void drawObstacle(QPainter& painter, std::shared_ptr<Obstacle> obstacle);
  void drawRobot(QPainter& painter, std::shared_ptr<Robot> robot);

  void mousePressEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;

};
