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

    QFrame * frame = new Frame(this);
    frame->setObjectName("frame");
    QVBoxLayout* frameLayout = new QVBoxLayout();


    Label* label = new Label("Spawn");
    Button* obstacle = new Button("Obstacle");
    Button* autoRobot = new Button("Autonomous Robot");
    Button* manualRobot = new Button("Manual Robot");

    frameLayout->addWidget(label, 0, Qt::AlignCenter);
    frameLayout->addWidget(obstacle);
    frameLayout->addWidget(autoRobot);
    frameLayout->addWidget(manualRobot);

    frame->setLayout(frameLayout);

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
