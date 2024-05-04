/**
 * @file ObstacleParametersWidget.cpp
 * @brief This file contains implementation of ObstacleParametersWidget class
 * which is responsible for handling user interactions with the obstacle
 * parameters in the GUI
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "GUI/Widget/ObstacleParametersWidget.hpp"
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QShortcut>
#include <QVBoxLayout>
#include <QWidget>
#include "GUI/Button.hpp"
#include "GUI/Frame.hpp"
#include "GUI/Label.hpp"

ObstacleParametersWidget::ObstacleParametersWidget(QWidget* parent)
    : QWidget(parent) {
  setObjectName("ObstacleParametersWidget");
  QVBoxLayout* layout = new QVBoxLayout(this);

  Frame* frame = new Frame(this);
  frame->setObjectName("frame");

  QVBoxLayout* frameLayout = new QVBoxLayout(frame);

  Label* label = new Label("Obstacle parameters");

  QHBoxLayout* positionLayout = new QHBoxLayout();

  x = createParameterControl("Position X:", -2000, 2000, positionLayout);
  y = createParameterControl("Position Y:", -2000, 2000, positionLayout);

  connect(x, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &ObstacleParametersWidget::onXChanged);
  connect(y, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &ObstacleParametersWidget::onYChanged);

  QHBoxLayout* dimensionLayout = new QHBoxLayout();
  width = createParameterControl("Width:", 1, 2000, dimensionLayout);
  height = createParameterControl("Height:", 1, 2000, dimensionLayout);

  connect(width, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &ObstacleParametersWidget::onWidthChanged);
  connect(height, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &ObstacleParametersWidget::onHeightChanged);

  QHBoxLayout* rotationLayout = new QHBoxLayout();
  rotation = createParameterControl("Rotation:", -360, 360, rotationLayout);
  connect(rotation, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this,
          &ObstacleParametersWidget::onRotationChanged);

  Button* remove = new Button("Remove");
  QShortcut* shortcut = new QShortcut(QKeySequence(Qt::Key_Delete), remove);

  connect(shortcut, &QShortcut::activated, remove, &Button::click);
  connect(remove, &Button::clicked,
          [this]() { emit removeObstacle(obstacle); });

  frameLayout->addWidget(label, 0, Qt::AlignCenter);
  frameLayout->addLayout(positionLayout);
  frameLayout->addLayout(dimensionLayout);
  frameLayout->addLayout(rotationLayout);
  frameLayout->addWidget(remove);

  layout->addWidget(frame);

  setLayout(layout);
}

void ObstacleParametersWidget::setObstacle(std::shared_ptr<Obstacle> obstacle) {
  this->obstacle = obstacle;
  x->setValue(obstacle->getX());
  y->setValue(obstacle->getY());
  width->setValue(obstacle->getWidth());
  height->setValue(obstacle->getHeight());
  rotation->setValue(obstacle->getRotation());
}

QDoubleSpinBox* ObstacleParametersWidget::createParameterControl(
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

void ObstacleParametersWidget::onRotationChanged(double value) {
  if (obstacle && obstacle->getRotation() != value) {
    obstacle->setRotation(value);
    emit updateMap();
  }
}
