#pragma once

#include <QWidget>
#include <QObject>
#include <QDoubleSpinBox>
#include "Model/Obstacle.hpp"

class ObstacleParametersWidget: public QWidget {
  Q_OBJECT

  std::shared_ptr<Obstacle> obstacle;

  QDoubleSpinBox* x;
  QDoubleSpinBox* y;

  QDoubleSpinBox* width;
  QDoubleSpinBox* height;

 public:
    ObstacleParametersWidget(QWidget* parent = nullptr);

    void setObstacle(std::shared_ptr<Obstacle> obstacle);

    signals:
        void updateMap();

 private:
    void onXChanged(double value);
    void onYChanged(double value);
    void onWidthChanged(double value);
    void onHeightChanged(double value);
};

