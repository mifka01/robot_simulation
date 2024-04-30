#include "GUI/Widget/VisualizationWidget.hpp"
#include "Settings.hpp"
#include <QPainter>
#include <cmath>
#include <QMouseEvent>

void VisualizationWidget::drawBorder(QPainter &painter) {
  painter.setBrush(Qt::white);
  painter.drawRect(0, 0, width() - 1, Settings::BORDER_SIZE);
  painter.drawRect(0, 0 + Settings::BORDER_SIZE, Settings::BORDER_SIZE,
                   height() - 1);
  painter.drawRect(width() - Settings::BORDER_SIZE, 0 + Settings::BORDER_SIZE,
                   Settings::BORDER_SIZE, height() - 1);
  painter.drawRect(0 + Settings::BORDER_SIZE, height() - Settings::BORDER_SIZE,
                   width() - 1, Settings::BORDER_SIZE);
}

void VisualizationWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  drawBorder(painter);

  // Draw robots as circles
  for (const auto &robot : map->getRobots()) {
    if (robot->getType() == 0) {
      painter.setBrush(Qt::green);
    } else {
      painter.setBrush(Qt::blue);
    }

    painter.drawEllipse(robot->getX(), robot->getY(), robot->getDiameter(),
                        robot->getDiameter());
    painter.drawLine(robot->getX() + robot->getDiameter() / 2,
                     robot->getY() + robot->getDiameter() / 2,
                     robot->getX() + robot->getDiameter() / 2 +
                         robot->getDiameter() / 2 * cos(robot->getAngle()),
                     robot->getY() + robot->getDiameter() / 2 +
                         robot->getDiameter() / 2 * sin(robot->getAngle()));

    auto box = robot->getViewBox();
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::yellow);
    auto points = box.getPoints();
    QPolygonF polygon;
    for (int i = 0; i < 4; i++) {
      polygon << QPointF(points[i].x, points[i].y);
    }
    painter.drawPolygon(polygon);
  }

  // Draw obstacles as rectangles
  for (const auto &obstacle : map->getObstacles()) {
    painter.setBrush(Qt::red);
    painter.drawRect(obstacle->getX(), obstacle->getY(), obstacle->getWidth(),
                     obstacle->getHeight());
  }
}

void VisualizationWidget::resizeEvent(QResizeEvent *event) {
  QWidget::resizeEvent(event);
  map->setWidth(width());
  map->setHeight(height());
}

void VisualizationWidget::mousePressEvent(QMouseEvent* event) {
    double x = event->pos().x();
    double y = event->pos().y();

     for (auto& obstacle : map->getObstacles()) {
        if (obstacle->getBoundingBox().contains({x, y})) {
            selectedObstacle = obstacle;
            return;
        }
    }
    for (auto& robot : map->getRobots()) {
        if (robot->getBoundingBox().contains({x, y})) {
            selectedRobot = robot;
            return;
        }
    }

}

void VisualizationWidget::mouseMoveEvent(QMouseEvent* event) {
    if (selectedObstacle) {
        selectedObstacle->setX(event->pos().x() - selectedObstacle->getWidth() / 2);
        selectedObstacle->setY(event->pos().y() - selectedObstacle->getHeight() / 2);
        update();
    }

    if (selectedRobot) {
        selectedRobot->setX(event->pos().x() - selectedRobot->getDiameter() / 2);
        selectedRobot->setY(event->pos().y() - selectedRobot->getDiameter() / 2);
        update();
    }
}

void VisualizationWidget::mouseReleaseEvent(QMouseEvent* event) {
    if(selectedObstacle){
        selectedObstacle = nullptr;
    }
    if(selectedRobot){
        selectedRobot = nullptr;
    }
}

