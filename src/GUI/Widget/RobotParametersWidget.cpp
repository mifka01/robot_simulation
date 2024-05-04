/**
 * @file RobotParametersWidget.cpp
 * @brief This file contains implementation of RobotParametersWidget class
 * which is responsible for handling user interactions with the robot
 * parameters in the GUI
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "GUI/Widget/RobotParametersWidget.hpp"
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QShortcut>
#include <QVBoxLayout>
#include <QWidget>
#include "GUI/Button.hpp"
#include "GUI/Frame.hpp"
#include "GUI/Label.hpp"

RobotParametersWidget::RobotParametersWidget(QWidget* parent)
    : QWidget(parent) {
  setObjectName("RobotParametersWidget");
  QVBoxLayout* layout = new QVBoxLayout(this);

  Frame* frame = new Frame(this);
  frame->setObjectName("frame");
  QVBoxLayout* frameLayout = new QVBoxLayout(frame);

  Label* label = new Label("Robot parameters");

  QHBoxLayout* positionLayout = new QHBoxLayout();

  x = createParameterControl("Position X:", -2000, 2000, positionLayout);
  y = createParameterControl("Position Y:", -2000, 2000, positionLayout);

  connect(x, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &RobotParametersWidget::onXChanged);
  connect(y, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &RobotParametersWidget::onYChanged);

  QHBoxLayout* dimensionLayout = new QHBoxLayout();

  diameter = createParameterControl("Diameter:", 1, 100, dimensionLayout);
  viewDistance =
      createParameterControl("View distance:", 1, 100, dimensionLayout);

  connect(diameter, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &RobotParametersWidget::onDiameterChanged);
  connect(viewDistance, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
          this, &RobotParametersWidget::onViewDistanceChanged);

  QHBoxLayout* angleLayout = new QHBoxLayout();

  viewAngle = createParameterControl("View angle:", -360, 360, angleLayout);
  rotateAngle = createParameterControl("Rotate angle:", -360, 360, angleLayout);

  connect(viewAngle, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &RobotParametersWidget::onViewAngleChanged);
  connect(rotateAngle, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
          this, &RobotParametersWidget::onRotateAngleChanged);

  QVBoxLayout* miscLayout = new QVBoxLayout();
  Label* speedLabel = new Label("Speed:");
  speedLabel->setStyleSheet("font-size: 12px;");

  Label* rotateClockwiseLabel = new Label("Rotate clockwise:");
  rotateClockwiseLabel->setStyleSheet("font-size: 12px;");

  QHBoxLayout* miscLabels = new QHBoxLayout();
  miscLabels->addWidget(speedLabel);
  miscLabels->addWidget(rotateClockwiseLabel);

  miscLayout->addLayout(miscLabels);

  QHBoxLayout* miscWidgets = new QHBoxLayout();

  speed = new QSpinBox();
  speed->setRange(1, 100);
  speed->setSingleStep(1);
  miscWidgets->addWidget(speed);

  rotateClockwise = new QCheckBox();
  miscWidgets->addWidget(rotateClockwise);

  miscLayout->addLayout(miscWidgets);

  connect(speed, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &RobotParametersWidget::onSpeedChanged);
  connect(rotateClockwise, &QCheckBox::stateChanged, this,
          &RobotParametersWidget::onRotateClockwiseChanged);

  Button* remove = new Button("Remove");
  QShortcut* shortcut = new QShortcut(QKeySequence(Qt::Key_Delete), remove);

  connect(shortcut, &QShortcut::activated, remove, &Button::click);
  connect(remove, &Button::clicked, [this]() { emit removeRobot(robot); });

  frameLayout->addWidget(label, 0, Qt::AlignCenter);
  frameLayout->addLayout(positionLayout);
  frameLayout->addLayout(dimensionLayout);
  frameLayout->addLayout(angleLayout);
  frameLayout->addLayout(miscLayout);
  frameLayout->addWidget(remove);

  layout->addWidget(frame);

  setLayout(layout);
}

QDoubleSpinBox* RobotParametersWidget::createParameterControl(
    const QString& labelText,
    double minRange,
    double maxRange,
    QHBoxLayout* parentLayout) {
  QVBoxLayout* layout = new QVBoxLayout();

  QLabel* label = new QLabel(labelText);
  label->setStyleSheet("font-size: 12px;");
  layout->addWidget(label);

  QDoubleSpinBox* spinBox = new QDoubleSpinBox();
  spinBox->setRange(minRange, maxRange);
  spinBox->setSingleStep(1);
  layout->addWidget(spinBox);

  parentLayout->addLayout(layout);

  return spinBox;
}

void RobotParametersWidget::setRobot(std::shared_ptr<Robot> robot) {
  this->robot = robot;
  x->setValue(robot->getX());
  y->setValue(robot->getY());
  diameter->setValue(robot->getDiameter());
  viewDistance->setValue(robot->getViewDistance());
  viewAngle->setValue(robot->getViewAngle());
  rotateAngle->setValue(robot->getRotateAngle());
  speed->setValue(robot->getSpeed());
  rotateClockwise->setChecked(robot->getRotateClockwise());
}

void RobotParametersWidget::onXChanged(double value) {
  if (robot && robot->getX() != value) {
    robot->setX(value);
    emit updateMap();
  }
}

void RobotParametersWidget::onYChanged(double value) {
  if (robot && robot->getY() != value) {
    robot->setY(value);
    emit updateMap();
  }
}

void RobotParametersWidget::onDiameterChanged(double value) {
  if (robot && robot->getDiameter() != value) {
    robot->setDiameter(value);
    emit updateMap();
  }
}

void RobotParametersWidget::onViewDistanceChanged(double value) {
  if (robot && robot->getViewDistance() != value) {
    robot->setViewDistance(value);
    emit updateMap();
  }
}

void RobotParametersWidget::onViewAngleChanged(double value) {
  if (robot && robot->getViewAngle() != value) {
    robot->setViewAngle(value);
    emit updateMap();
  }
}

void RobotParametersWidget::onRotateAngleChanged(double value) {
  if (robot && robot->getRotateAngle() != value) {
    robot->setRotateAngle(value);
    emit updateMap();
  }
}

void RobotParametersWidget::onSpeedChanged(int value) {
  if (robot && robot->getSpeed() != value) {
    robot->setSpeed(value);
    emit updateMap();
  }
}
void RobotParametersWidget::onRotateClockwiseChanged(bool value) {
  if (robot && robot->getRotateClockwise() != value) {
    robot->setRotateClockwise(value);
    emit updateMap();
  }
}
