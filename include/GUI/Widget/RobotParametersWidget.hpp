#pragma once

#include <QWidget>
#include <QObject>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QHBoxLayout>
#include "Model/Robot/Robot.hpp"

class RobotParametersWidget: public QWidget {
  Q_OBJECT

  std::shared_ptr<Robot> robot;

  QDoubleSpinBox* x;
  QDoubleSpinBox* y;

  QDoubleSpinBox* diameter;
  QDoubleSpinBox* viewAngle;
  QDoubleSpinBox* rotateAngle;
  QDoubleSpinBox* viewDistance;
  QCheckBox* rotateClockwise;
  QSpinBox* speed;

 public:
    RobotParametersWidget(QWidget* parent = nullptr);

    void setRobot(std::shared_ptr<Robot> obstacle);
    QDoubleSpinBox *createParameterControl(const QString &labelText,
                                       double minRange, double maxRange,
                                       QHBoxLayout *parentLayout);

    template <typename T, typename Getter, typename Setter>
    void updateRobotParameter(Getter getter, Setter setter, T newValue);

    signals:
        void updateMap();

 private:
    void onXChanged(double value);
    void onYChanged(double value);
    void onDiameterChanged(double value);
    void onViewAngleChanged(double value);
    void onRotateAngleChanged(double value);
    void onViewDistanceChanged(double value);
    void onRotateClockwiseChanged(bool value);
    void onSpeedChanged(int value);
};

