#include "GUI/Widget/ControlsWidget.hpp"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

ControlsWidget::ControlsWidget(QWidget* parent) : QWidget(parent) {
  QVBoxLayout* layout = new QVBoxLayout(this);

  QHBoxLayout* buttons = new QHBoxLayout(this);

  QPushButton* loadMap = new QPushButton("load", this);
  buttons->addWidget(loadMap);
  connect(loadMap, &QPushButton::clicked, this,
          &ControlsWidget::onLoadMapClicked);

  QPushButton* start = new QPushButton("start", this);
  buttons->addWidget(start);
  connect(start, &QPushButton::clicked, this, &ControlsWidget::onStartClicked);

  QPushButton* stop = new QPushButton("stop", this);
  buttons->addWidget(stop);
  connect(stop, &QPushButton::clicked, this, &ControlsWidget::onStopClicked);

  layout->addLayout(buttons);
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
