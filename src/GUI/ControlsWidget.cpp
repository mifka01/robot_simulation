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

QHBoxLayout* spawnButtons = new QHBoxLayout(this);
Button* addObstacle = new Button("obstacle", this);
spawnButtons->addWidget(addObstacle);
QSpinBox* obstacleWidth = new QSpinBox(this);
QSpinBox* obstacleHeight= new QSpinBox(this);
obstacleWidth->setValue(40);
obstacleHeight->setValue(40);
obstacleWidth->setRange(10, 1000);
obstacleHeight->setRange(10, 1000);
spawnButtons->addWidget(obstacleWidth);
spawnButtons->addWidget(obstacleHeight);

connect(addObstacle, &Button::clicked, this, [this, obstacleWidth, obstacleHeight]() {
    this->onAddObstacle(obstacleWidth->value(), obstacleHeight->value());
});


layout->addLayout(spawnButtons);

}

void ControlsWidget::onLoadMapClicked() {
  emit loadMapClicked();
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
