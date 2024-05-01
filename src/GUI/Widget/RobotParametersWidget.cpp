#include "GUI/Widget/RobotParametersWidget.hpp"
#include "GUI/Frame.hpp"
#include "GUI/Label.hpp"
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

RobotParametersWidget::RobotParametersWidget(QWidget *parent)
    : QWidget(parent) {
  setObjectName("RobotParametersWidget");
  QVBoxLayout *layout = new QVBoxLayout(this);

  Frame *frame = new Frame(this);
  frame->setObjectName("frame");
  QVBoxLayout *frameLayout = new QVBoxLayout(frame);

  Label *label = new Label("Robot parameters", frame);

  QVBoxLayout *positionLayout = new QVBoxLayout(frame);

  QHBoxLayout *positionLabels = new QHBoxLayout(frame);

  Label *positionXLabel = new Label("Position X:", frame);
  positionXLabel->setStyleSheet("font-size: 12px;");

  Label *positionYLabel = new Label("Position Y:", frame);
  positionYLabel->setStyleSheet("font-size: 12px;");

  positionLabels->addWidget(positionXLabel);
  positionLabels->addWidget(positionYLabel);
  positionLayout->addLayout(positionLabels);

  QHBoxLayout *posSpinboxes = new QHBoxLayout(frame);

  x = new QDoubleSpinBox(frame);
  x->setRange(-2000, 2000);
  x->setSingleStep(1);
  posSpinboxes->addWidget(x);

  y = new QDoubleSpinBox(frame);
  y->setRange(-2000, 2000);
  y->setSingleStep(1);
  posSpinboxes->addWidget(y);

  positionLayout->addLayout(posSpinboxes);

  connect(x, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &RobotParametersWidget::onXChanged);
  connect(y, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &RobotParametersWidget::onYChanged);

  QVBoxLayout *dimensionLayout = new QVBoxLayout(frame);
  Label *diameterLabel = new Label("Diameter:", frame);
  diameterLabel->setStyleSheet("font-size: 12px;");

  Label *viewDistanceLabel = new Label("View distance:", frame);
  viewDistanceLabel->setStyleSheet("font-size: 12px;");

  QHBoxLayout *dimensionLabels = new QHBoxLayout(frame);
  dimensionLabels->addWidget(diameterLabel);
  dimensionLabels->addWidget(viewDistanceLabel);

  dimensionLayout->addLayout(dimensionLabels);

  QHBoxLayout *dimensionSpinboxes = new QHBoxLayout(frame);

  diameter = new QDoubleSpinBox(frame);
  diameter->setRange(1, 200);
  diameter->setSingleStep(1);
  dimensionSpinboxes->addWidget(diameter);

  viewDistance = new QDoubleSpinBox(frame);
  viewDistance->setRange(1, 2000);
  viewDistance->setSingleStep(1);
  dimensionSpinboxes->addWidget(viewDistance);

  dimensionLayout->addLayout(dimensionSpinboxes);

  connect(diameter, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &RobotParametersWidget::onDiameterChanged);
  connect(viewDistance, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
          this, &RobotParametersWidget::onViewDistanceChanged);

  QVBoxLayout *angleLayout = new QVBoxLayout(frame);
  Label *viewAngleLabel = new Label("View angle:", frame);
  viewAngleLabel->setStyleSheet("font-size: 12px;");

  Label *rotateAngleLabel = new Label("Rotate angle:", frame);
  rotateAngleLabel->setStyleSheet("font-size: 12px;");

  QHBoxLayout *angleLabels = new QHBoxLayout(frame);
  angleLabels->addWidget(viewAngleLabel);
  angleLabels->addWidget(rotateAngleLabel);

  angleLayout->addLayout(angleLabels);

  QHBoxLayout *angleSpinboxes = new QHBoxLayout(frame);

  viewAngle = new QDoubleSpinBox(frame);
  viewAngle->setRange(-360, 360);
  viewAngle->setSingleStep(1);
  angleSpinboxes->addWidget(viewAngle);

  rotateAngle = new QDoubleSpinBox(frame);
  rotateAngle->setRange(-359, 359);
  rotateAngle->setSingleStep(1);
  angleSpinboxes->addWidget(rotateAngle);

  angleLayout->addLayout(angleSpinboxes);

  connect(viewAngle, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &RobotParametersWidget::onViewAngleChanged);
  connect(rotateAngle, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
          this, &RobotParametersWidget::onRotateAngleChanged);

  QVBoxLayout *miscLayout = new QVBoxLayout(frame);
  Label *speedLabel = new Label("Speed:", frame);
  speedLabel->setStyleSheet("font-size: 12px;");

  Label *rotateClockwiseLabel = new Label("Rotate clockwise:", frame);
  rotateClockwiseLabel->setStyleSheet("font-size: 12px;");

  QHBoxLayout *miscLabels = new QHBoxLayout(frame);
  miscLabels->addWidget(speedLabel);
  miscLabels->addWidget(rotateClockwiseLabel);

  miscLayout->addLayout(miscLabels);

  QHBoxLayout *miscWidgets = new QHBoxLayout(frame);

  speed = new QSpinBox(frame);
  speed->setRange(1, 100);
  speed->setSingleStep(1);
  miscWidgets->addWidget(speed);

  rotateClockwise = new QCheckBox(frame);
  miscWidgets->addWidget(rotateClockwise);

  miscLayout->addLayout(miscWidgets);

  connect(speed, QOverload<int>::of(&QSpinBox::valueChanged), this,
          &RobotParametersWidget::onSpeedChanged);
  connect(rotateClockwise, &QCheckBox::stateChanged, this,
          &RobotParametersWidget::onRotateClockwiseChanged);

  frameLayout->addWidget(label, 0, Qt::AlignCenter);
  frameLayout->addLayout(positionLayout);
  frameLayout->addLayout(dimensionLayout);
  frameLayout->addLayout(angleLayout);
  frameLayout->addLayout(miscLayout);

  layout->addWidget(frame);

  setLayout(layout);
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
