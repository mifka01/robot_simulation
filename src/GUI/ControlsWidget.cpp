#include <QHBoxLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QSpinBox>
#include "GUI/Button.hpp"
#include "GUI/Label.hpp"

#include "GUI/Widget/ControlsWidget.hpp"
#include "Model/Map.hpp"

ControlsWidget::ControlsWidget(QWidget* parent) : QWidget(parent) {
  // load empty map
map = std::make_shared<Map>();

QVBoxLayout* layout = new QVBoxLayout(this);

QVBoxLayout* mapControls = new QVBoxLayout(layout->widget());
Label* mapLabel = new Label("Map Controls", this);
mapControls->addWidget(mapLabel);

QHBoxLayout* mapButtons = new QHBoxLayout(this);
Button* loadMap = new Button("load", this);
mapButtons->addWidget(loadMap);
connect(loadMap, &Button::clicked, this, &ControlsWidget::onLoadMapClicked);

Button* saveMap = new Button("save", this);
mapButtons->addWidget(saveMap);
connect(saveMap, &Button::clicked, this, &ControlsWidget::onSaveMapClicked);

mapControls->addLayout(mapButtons);
layout->addLayout(mapControls);

Label* simulationLabel = new Label("Simulation Controls", this);
layout->addWidget(simulationLabel);

QHBoxLayout* simulationButtons = new QHBoxLayout(this);
Button* start = new Button("start", this);
simulationButtons->addWidget(start);
connect(start, &Button::clicked, this, &ControlsWidget::onStartClicked);

Button* stop = new Button("stop", this);
simulationButtons->addWidget(stop);
connect(stop, &Button::clicked, this, &ControlsWidget::onStopClicked);
layout->addLayout(simulationButtons);

Label* spawnLabel = new Label("Spawn Controls", this);
layout->addWidget(spawnLabel);

QVBoxLayout* spawnButtons = new QVBoxLayout(this);

QHBoxLayout* obstacleButtons = new QHBoxLayout(this);
Button* addObstacle = new Button("obstacle", this);
obstacleButtons->addWidget(addObstacle);
QSpinBox* obstacleWidth = new QSpinBox(this);
QSpinBox* obstacleHeight= new QSpinBox(this);

obstacleWidth->setValue(40);
obstacleHeight->setValue(40);
obstacleWidth->setRange(10, 1000);
obstacleHeight->setRange(10, 1000);

obstacleButtons->addWidget(obstacleWidth);
obstacleButtons->addWidget(obstacleHeight);

spawnButtons->addLayout(obstacleButtons);

QHBoxLayout* robotButtons = new QHBoxLayout(this);

Button* addManualRobot = new Button("Manual Robot", this);
robotButtons->addWidget(addManualRobot);
Button* addAutoRobot = new Button("Autonomous Robot", this);
robotButtons->addWidget(addAutoRobot);
QSpinBox* diameter = new QSpinBox(this);
robotButtons->addWidget(diameter);


diameter->setValue(20);
diameter->setRange(5, 500);


robotButtons->addWidget(diameter);

QSpinBox* speed = new QSpinBox(this);

speed->setValue(1);
speed->setRange(1, 100);

robotButtons->addWidget(speed);


QSpinBox* angle = new QSpinBox(this);

angle->setValue(1);
angle->setRange(1, 359);

robotButtons->addWidget(angle);


spawnButtons->addLayout(robotButtons);



connect(addObstacle, &Button::clicked, this, [this, obstacleWidth, obstacleHeight]() {
    this->onAddObstacle(obstacleWidth->value(), obstacleHeight->value());
});

connect(addManualRobot, &Button::clicked, this, [this, diameter, angle, speed]() {
    this->onAddRobot(diameter->value(), angle->value(), speed->value(), 0);
});

connect(addAutoRobot, &Button::clicked, this, [this, diameter, angle, speed]() {
    this->onAddRobot(diameter->value(), angle->value(), speed->value(), 1);
});


layout->addLayout(spawnButtons);

}

void ControlsWidget::onLoadMapClicked() {
  emit loadMapClicked();
}

void ControlsWidget::onSaveMapClicked() {
  emit saveMapClicked();
}

void ControlsWidget::onStartClicked() {
  emit startClicked();
}

void ControlsWidget::onStopClicked() {
  emit stopClicked();
}

void ControlsWidget::onAddObstacle(int width, int height) {
  emit stopClicked();
  map->addObstacle(map->getWidth() / 2, map->getHeight() / 2, width, height);
  emit updateMap();
}

void ControlsWidget::onAddRobot(double diameter, int angle, int speed, int type) {
  emit stopClicked();
  map->addRobot(map->getWidth() / 2, map->getHeight() / 2, diameter, angle, speed, type);
  emit updateMap();
}

