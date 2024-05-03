/**
 * @file ManualRobotControlsWidget.cpp
 * @brief This file contains declaration of ManualRobotControlsWidget class
 * which is responsible for handling user interactions with the manual robot
 * controls
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "GUI/Widget/ManualRobotControlsWidget.hpp"
#include <QShortcut>
#include <QVBoxLayout>
#include "GUI/Button.hpp"
#include "GUI/Frame.hpp"
#include "GUI/Label.hpp"

ManualRobotControlsWidget::ManualRobotControlsWidget(QWidget* parent)
    : QWidget(parent) {
  QVBoxLayout* layout = new QVBoxLayout(this);
  Frame* frame = new Frame(this);
  frame->setObjectName("frame");
  QVBoxLayout* frameLayout = new QVBoxLayout(frame);

  Label* label = new Label("Manual controls");
  frameLayout->addWidget(label, 0, Qt::AlignCenter);

  auto bottom = new QHBoxLayout();
  auto moveButton = new Button("Move");
  auto stopButton = new Button("Stop");
  auto turnLeftButton = new Button("Turn Left");
  auto turnRightButton = new Button("Turn Right");

  frameLayout->addWidget(moveButton);

  bottom->addWidget(turnLeftButton);
  bottom->addWidget(stopButton);
  bottom->addWidget(turnRightButton);

  frameLayout->addLayout(bottom);

  layout->addWidget(frame);

  QShortcut* moveShortcut = new QShortcut(QKeySequence(Qt::Key_W), moveButton);
  connect(moveShortcut, &QShortcut::activated, this,
          &ManualRobotControlsWidget::onMoveClicked);

  QShortcut* turnLeftShortcut =
      new QShortcut(QKeySequence(Qt::Key_A), turnLeftButton);
  connect(turnLeftShortcut, &QShortcut::activated, this,
          &ManualRobotControlsWidget::onTurnLeftClicked);

  QShortcut* turnRightShortcut =
      new QShortcut(QKeySequence(Qt::Key_D), turnRightButton);
  connect(turnRightShortcut, &QShortcut::activated, this,
          &ManualRobotControlsWidget::onTurnRightClicked);

  QShortcut* stopShortcut = new QShortcut(QKeySequence(Qt::Key_S), stopButton);
  connect(stopShortcut, &QShortcut::activated, this,
          &ManualRobotControlsWidget::onStopClicked);

  connect(moveButton, &Button::clicked, this,
          &ManualRobotControlsWidget::onMoveClicked);
  connect(turnLeftButton, &Button::clicked, this,
          &ManualRobotControlsWidget::onTurnLeftClicked);
  connect(stopButton, &Button::clicked, this,
          &ManualRobotControlsWidget::onStopClicked);
  connect(turnRightButton, &Button::clicked, this,
          &ManualRobotControlsWidget::onTurnRightClicked);
}

void ManualRobotControlsWidget::setRobot(std::shared_ptr<ManualRobot> robot) {
  this->robot = robot;
}

void ManualRobotControlsWidget::onMoveClicked() {
  if (robot) {
    robot->setState(ManualRobot::State::MOVE);
  }
}

void ManualRobotControlsWidget::onStopClicked() {
  if (robot) {
    robot->setState(ManualRobot::State::STOP);
  }
}

void ManualRobotControlsWidget::onTurnLeftClicked() {
  if (robot) {
    robot->setState(ManualRobot::State::TURN_LEFT);
  }
}

void ManualRobotControlsWidget::onTurnRightClicked() {
  if (robot) {
    robot->setState(ManualRobot::State::TURN_RIGHT);
  }
}
