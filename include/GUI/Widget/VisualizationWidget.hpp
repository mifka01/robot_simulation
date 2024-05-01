#pragma once
#include <QPainter>
#include <QWidget>
#include <memory>
#include "Model/IMap.hpp"
#include "Model/Map.hpp"

class VisualizationWidget : public QWidget {
  Q_OBJECT
  std::shared_ptr<IMap> map;
  std::shared_ptr<Obstacle> selectedObstacle;
  std::shared_ptr<Robot> selectedRobot;

 public:
  explicit VisualizationWidget(QWidget* parent = nullptr)
      : QWidget(parent), map(std::make_shared<Map>()) {}

  void setMap(std::shared_ptr<IMap> map) { this->map = map; }

 protected:
  void paintEvent(QPaintEvent* event) override;

  void resizeEvent(QResizeEvent* event) override;

  void mousePressEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;
};
