#include "GUI/Widget/ManualRobotControlsWidget.hpp"
#include "GUI/Button.hpp"
#include "GUI/Frame.hpp"
#include "GUI/Label.hpp"
#include <QVBoxLayout>

ManualRobotControlsWidget::ManualRobotControlsWidget(QWidget* parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    Frame *frame = new Frame(this);
    frame->setObjectName("frame");
    QVBoxLayout *frameLayout = new QVBoxLayout(frame);

    Label *label = new Label("Manual controls");
    frameLayout->addWidget(label, 0, Qt::AlignCenter);

    auto bottom = new QHBoxLayout(this);
    auto moveButton = new Button("Move", this);
    auto stopButton = new Button("Stop", this);
    auto turnLeftButton = new Button("Turn Left", this);
    auto turnRightButton = new Button("Turn Right", this);

    frameLayout->addWidget(moveButton);

    bottom->addWidget(turnLeftButton);
    bottom->addWidget(stopButton);
    bottom->addWidget(turnRightButton);


    frameLayout->addLayout(bottom);

    layout->addWidget(frame);

    connect(moveButton, &Button::clicked, this, &ManualRobotControlsWidget::onMoveClicked);
    connect(stopButton, &Button::clicked, this, &ManualRobotControlsWidget::onStopClicked);
    connect(turnLeftButton, &Button::clicked, this, &ManualRobotControlsWidget::onTurnLeftClicked);
    connect(turnRightButton, &Button::clicked, this, &ManualRobotControlsWidget::onTurnRightClicked);
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
