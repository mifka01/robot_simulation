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

  QPushButton* start = new QPushButton("start", this);
  buttons->addWidget(start);

  QPushButton* stop = new QPushButton("stop", this);
  buttons->addWidget(stop);

  layout->addLayout(buttons);
}
