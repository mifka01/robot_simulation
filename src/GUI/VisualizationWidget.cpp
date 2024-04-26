#include "GUI/Widget/VisualizationWidget.hpp"
#include <QPainter>

VisualizationWidget::VisualizationWidget(QWidget* parent) : QWidget(parent) {
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
  setStyleSheet("background-color: white;");
  paintEvent(nullptr);
}

void VisualizationWidget::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setBrush(QBrush(Qt::green));
  painter.drawRect(10, 10, 100, 100);
}
