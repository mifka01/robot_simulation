#pragma once

#include <QWidget>
#include <QObject>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include "Model/Obstacle.hpp"

class ObstacleParametersWidget: public QWidget {
  Q_OBJECT

  std::shared_ptr<Obstacle> obstacle;

  QDoubleSpinBox* x;
  QDoubleSpinBox* y;

  QDoubleSpinBox* width;
  QDoubleSpinBox* height;

  QDoubleSpinBox* rotation;

 public:
    ObstacleParametersWidget(QWidget* parent = nullptr);

    void setObstacle(std::shared_ptr<Obstacle> obstacle);

    QDoubleSpinBox *createParameterControl(const QString &labelText,
                                       double minRange, double maxRange,
                                       QHBoxLayout *parentLayout);

    signals:
        void updateMap();
        void removeObstacle(std::shared_ptr<Obstacle> obstacle);

 private:
    void onXChanged(double value);
    void onYChanged(double value);
    void onWidthChanged(double value);
    void onHeightChanged(double value);
    void onRotationChanged(double value);
};

