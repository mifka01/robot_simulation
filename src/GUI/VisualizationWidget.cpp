#include "GUI/Widget/VisualizationWidget.hpp"
#include <QPainter>
#include <iostream>
#include "GUI/Settings.hpp"

// std::pair<int, int> VisualizationWidget::adjustCoordinates(int x,
//                                                            int y,
//                                                            int w,
//                                                            int h) {
//   if (x < 0)
//     x = 0;
//   if (y < 0)
//     y = 0;
//   if (x >= width())
//     x = width() - w - Settings::BORDER_SIZE;
//   if (y >= height())
//     y = height() - h - Settings::BORDER_SIZE;
//
//   return {x, y};
// }
//
void VisualizationWidget::drawBorder(QPainter& painter) {
  painter.setBrush(Qt::white);
  painter.drawRect(0, 0, width() - 1, Settings::BORDER_SIZE);
  painter.drawRect(0, 0 + Settings::BORDER_SIZE, Settings::BORDER_SIZE,
                   height() - 1);
  painter.drawRect(width() - Settings::BORDER_SIZE, 0 + Settings::BORDER_SIZE,
                   Settings::BORDER_SIZE, height() - 1);
  painter.drawRect(0 + Settings::BORDER_SIZE, height() - Settings::BORDER_SIZE,
                   width() - 1, Settings::BORDER_SIZE);
}

void VisualizationWidget::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  drawBorder(painter);

  // Draw robots as circles
  for (const auto& robot : map->getRobots()) {
    if (robot->getType() == 0) {
      painter.setBrush(Qt::green);
    } else {
      painter.setBrush(Qt::blue);
    }

    painter.drawEllipse(robot->getX(), robot->getY(), robot->getDiameter(),
                        robot->getDiameter());
  }

  // Draw obstacles as rectangles
  for (const auto& obstacle : map->getObstacles()) {
    painter.setBrush(Qt::red);
    painter.drawRect(obstacle->getX(), obstacle->getY(), obstacle->getWidth(),
                     obstacle->getHeight());
  }
}

void VisualizationWidget::resizeEvent(QResizeEvent* event) {
  QWidget::resizeEvent(event);
  map->setWidth(width());
  map->setHeight(height());
}
