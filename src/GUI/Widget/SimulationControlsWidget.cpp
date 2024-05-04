/**
 * @file SimulationControlsWidget.cpp
 * @brief This file contains declaration of SimulationControlsWidget class
 * which is responsible for handling user interactions with the simulation
 * controls in the GUI
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "GUI/Widget/SimulationControlsWidget.hpp"
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include "GUI/Button.hpp"
#include "GUI/Frame.hpp"
#include "GUI/Label.hpp"

SimulationControlsWidget::SimulationControlsWidget(QWidget* parent)
    : QWidget(parent) {
  setObjectName("SimulationControlsWidget");
  QVBoxLayout* layout = new QVBoxLayout();

  Frame* frame = new Frame(this);
  frame->setObjectName("frame");
  QVBoxLayout* frameLayout = new QVBoxLayout();

  Label* label = new Label("Simulation");

  QHBoxLayout* buttons = new QHBoxLayout();
  Button* start = new Button("Start");
  buttons->addWidget(start);

  Button* stop = new Button("Stop");
  buttons->addWidget(stop);

  Button* load = new Button("Load");
  buttons->addWidget(load);

  Button* save = new Button("Save");
  buttons->addWidget(save);

  frameLayout->addWidget(label, 0, Qt::AlignCenter);
  frameLayout->addLayout(buttons);

  frame->setLayout(frameLayout);

  layout->addWidget(frame);

  setLayout(layout);

  setStyleSheet(
      "QWidget#SimulationControlsWidget {"
      "background-color: transparent;"
      "}");

  connect(load, &Button::clicked, this,
          &SimulationControlsWidget::onLoadMapClicked);
  connect(save, &Button::clicked, this,
          &SimulationControlsWidget::onSaveMapClicked);
  connect(start, &Button::clicked, this,
          &SimulationControlsWidget::onStartClicked);
  connect(stop, &Button::clicked, this,
          &SimulationControlsWidget::onStopClicked);
}

void SimulationControlsWidget::onStartClicked() {
  emit startClicked();
}

void SimulationControlsWidget::onStopClicked() {
  emit stopClicked();
}

void SimulationControlsWidget::onLoadMapClicked() {
  emit loadMapClicked();
}

void SimulationControlsWidget::onSaveMapClicked() {
  emit saveMapClicked();
}
