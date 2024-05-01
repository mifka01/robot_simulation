#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include "GUI/Widget/SpawnControlsWidget.hpp"
#include "GUI/Button.hpp"
#include "GUI/Label.hpp"
#include "GUI/Frame.hpp"


SpawnControlsWidget::SpawnControlsWidget(QWidget* parent) : QWidget(parent) {
    setObjectName("SpawnControlsWidget");
    QVBoxLayout* layout = new QVBoxLayout(this);

    Frame * frame = new Frame(this);
    frame->setObjectName("frame");
    QVBoxLayout* frameLayout = new QVBoxLayout(frame);


    Label* label = new Label("Spawn", frame);

    QVBoxLayout* buttons = new QVBoxLayout(frame);
    Button* obstacle = new Button("Obstacle", frame);
    buttons->addWidget(obstacle);

    Button* autoRobot = new Button("Autonomous Robot", frame);
    buttons->addWidget(autoRobot);

    Button* manualRobot = new Button("Manual Robot", frame);
    buttons->addWidget(manualRobot);

    frameLayout->addWidget(label, 0, Qt::AlignCenter);
    frameLayout->addLayout(buttons);

    layout->addWidget(frame);

    setLayout(layout);

    connect(obstacle, &Button::clicked, this, &SpawnControlsWidget::onAddObstacle);
    connect(autoRobot, &Button::clicked, this, &SpawnControlsWidget::onAddAutoRobot);
    connect(manualRobot, &Button::clicked, this, &SpawnControlsWidget::onAddManualRobot);

    setStyleSheet("QWidget#SpawnControlsWidget {"
                  "background-color: transparent;"
                  "}");

}

void SpawnControlsWidget::onAddObstacle() {
    emit addObstacleClicked();
}

void SpawnControlsWidget::onAddAutoRobot() {
    emit addAutoRobotClicked();
}

void SpawnControlsWidget::onAddManualRobot() {
    emit addManualRobotClicked();
}
