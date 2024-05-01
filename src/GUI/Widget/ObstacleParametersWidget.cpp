#include "GUI/Widget/ObstacleParametersWidget.hpp"
#include "GUI/Button.hpp"
#include "GUI/Frame.hpp"
#include "GUI/Label.hpp"
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>

ObstacleParametersWidget::ObstacleParametersWidget(QWidget *parent)
    : QWidget(parent) {
  setObjectName("ObstacleParametersWidget");
  QVBoxLayout *layout = new QVBoxLayout(this);

  Frame *frame = new Frame(this);
  frame->setObjectName("frame");
  QVBoxLayout *frameLayout = new QVBoxLayout(frame);

  Label *label = new Label("Obstacle parameters", frame);

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
          &ObstacleParametersWidget::onXChanged);
  connect(y, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &ObstacleParametersWidget::onYChanged);

  QVBoxLayout *dimensionLayout = new QVBoxLayout(frame);

  QHBoxLayout *dimensionLabels = new QHBoxLayout(frame);

  Label *widthLabel= new Label("Width:", frame);
  widthLabel->setStyleSheet("font-size: 12px;");

  Label *heightLabel= new Label("Height:", frame);
  heightLabel->setStyleSheet("font-size: 12px;");

  dimensionLabels->addWidget(widthLabel);
  dimensionLabels->addWidget(heightLabel);
  dimensionLayout->addLayout(dimensionLabels);

  QHBoxLayout *spinboxes = new QHBoxLayout(frame);

  width = new QDoubleSpinBox(frame);
  width->setRange(0, 2000);
  width->setSingleStep(1);
  spinboxes->addWidget(width);

  height = new QDoubleSpinBox(frame);
  height->setRange(0, 2000);
  height->setSingleStep(1);
  spinboxes->addWidget(height);

  dimensionLayout->addLayout(spinboxes);

  connect(width, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &ObstacleParametersWidget::onWidthChanged);
  connect(height, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &ObstacleParametersWidget::onHeightChanged);

  frameLayout->addWidget(label, 0, Qt::AlignCenter);
  frameLayout->addLayout(positionLayout);
  frameLayout->addLayout(dimensionLayout);

  layout->addWidget(frame);

  setLayout(layout);
}

void ObstacleParametersWidget::setObstacle(std::shared_ptr<Obstacle> obstacle) {
  this->obstacle = obstacle;
  x->setValue(obstacle->getX());
  y->setValue(obstacle->getY());
  width->setValue(obstacle->getWidth());
  height->setValue(obstacle->getHeight());
}

void ObstacleParametersWidget::onXChanged(double value) {
  if (obstacle && obstacle->getX() != value) {
    obstacle->setX(value);
    emit updateMap();
  }
}

void ObstacleParametersWidget::onYChanged(double value) {
  if (obstacle && obstacle->getY() != value) {
    obstacle->setY(value);
    emit updateMap();
  }
}

void ObstacleParametersWidget::onWidthChanged(double value) {
  if (obstacle && obstacle->getWidth() != value) {
    obstacle->setWidth(value);
    emit updateMap();
  }
}

void ObstacleParametersWidget::onHeightChanged(double value) {
  if (obstacle && obstacle->getHeight() != value) {
    obstacle->setHeight(value);
    emit updateMap();
  }
}
