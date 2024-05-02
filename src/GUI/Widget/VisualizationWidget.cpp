#include <cmath>
#include <QMouseEvent>
#include <QPainter>
#include "GUI/Widget/VisualizationWidget.hpp"

void VisualizationWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(Qt::NoPen);

  for (const auto &robot : map->getRobots()) {
        drawRobot(painter, robot);
  }

  for (const auto &obstacle : map->getObstacles()) {
        drawObstacle(painter, obstacle);
  }

}

void VisualizationWidget::resizeEvent(QResizeEvent *event) {
  QWidget::resizeEvent(event);
  map->setWidth(width());
  map->setHeight(height());
}

void VisualizationWidget::drawObstacle(QPainter &painter,
                                       std::shared_ptr<Obstacle> obstacle) {

    if(obstacle == selectedObstacle){
        painter.setBrush(Qt::blue);
        painter.drawRect(obstacle->getX() - 5, obstacle->getY() - 5, obstacle->getWidth() + 10, obstacle->getHeight() + 10);
    }
    painter.setBrush(Qt::red);
    painter.drawRect(obstacle->getX(), obstacle->getY(), obstacle->getWidth(),
                     obstacle->getHeight());
}

void VisualizationWidget::drawRobot(QPainter &painter, std::shared_ptr<Robot> robot){
    if(robot == selectedRobot){
        painter.setBrush(Qt::red);
        painter.drawEllipse(robot->getX() - 5, robot->getY() - 5, robot->getDiameter() + 10, robot->getDiameter() + 10);
    }

    if (robot->getType() == 0) {
      painter.setBrush(Qt::green);
    } else {
      painter.setBrush(Qt::blue);
    }

    painter.drawEllipse(robot->getX(), robot->getY(), robot->getDiameter(),
                        robot->getDiameter());

    painter.setPen(Qt::black);
    painter.drawLine(robot->getX() + robot->getDiameter() / 2,
                     robot->getY() + robot->getDiameter() / 2,
                     robot->getX() + robot->getDiameter() / 2 +
                         robot->getDiameter() / 2 * cos(robot->getViewAngleRad()),
                     robot->getY() + robot->getDiameter() / 2 +
                         robot->getDiameter() / 2 * sin(robot->getViewAngleRad()));
    painter.setPen(Qt::NoPen);

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

void VisualizationWidget::mousePressEvent(QMouseEvent* event) {
    double x = event->pos().x();
    double y = event->pos().y();

    emit obstacleDeselected();
    if (selectedObstacle) {
        selectedObstacle = nullptr;
        update();
    }

    emit robotDeselected();
    if (selectedRobot) {
        selectedRobot = nullptr;
        update();
    }

     for (auto& obstacle : map->getObstacles()) {
        if (obstacle->getBoundingBox().contains({x, y})) {
            grabbedObstacle = obstacle;
            selectedObstacle = obstacle;
            update();
            emit obstacleSelected(obstacle);
            return;
        }
    }
    for (auto& robot : map->getRobots()) {
        if (robot->getBoundingBox().contains({x, y})) {
            grabbedRobot = robot;
            selectedRobot = robot;
            update();
            emit robotSelected(robot);
            return;
        }
    }


}

void VisualizationWidget::mouseMoveEvent(QMouseEvent* event) {
    if (grabbedObstacle) {
        grabbedObstacle->setX(event->pos().x() - grabbedObstacle->getWidth() / 2);
        grabbedObstacle->setY(event->pos().y() - grabbedObstacle->getHeight() / 2);
        selectedObstacle = grabbedObstacle;
        emit obstacleSelected(grabbedObstacle);
        update();
    }

    if (grabbedRobot) {
        grabbedRobot->setX(event->pos().x() - grabbedRobot->getDiameter() / 2);
        grabbedRobot->setY(event->pos().y() - grabbedRobot->getDiameter() / 2);
        selectedRobot = grabbedRobot;
        emit robotSelected(grabbedRobot);
        update();
    }
}

void VisualizationWidget::mouseReleaseEvent(QMouseEvent* event) {
    if(grabbedObstacle){
        grabbedObstacle = nullptr;
    }
    if(grabbedRobot){
        grabbedRobot = nullptr;
    }
}
