#include <cmath>
#include <QMouseEvent>
#include <QPainter>
#include "GUI/Widget/VisualizationWidget.hpp"
#include "Settings.hpp"

void VisualizationWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(Qt::NoPen);


  for (const auto &obstacle : map->getObstacles()) {
        drawObstacle(painter, obstacle);
  }

  for (const auto &robot : map->getRobots()) {
        drawRobot(painter, robot);
  }

}

void VisualizationWidget::resizeEvent(QResizeEvent *event) {
  QWidget::resizeEvent(event);
  map->setWidth(width());
  map->setHeight(height());
}

void VisualizationWidget::drawObstacle(QPainter &painter, std::shared_ptr<Obstacle> obstacle) {

    QColor color;
    color.setNamedColor(Settings::OBSTACLE_COLOR);
    
    QBrush brush(color);
    
    painter.setBrush(brush);

    QPen pen;
    pen.setWidth(Settings::OBSTACLE_BORDER_WIDTH);
    if (obstacle == selectedObstacle) {
        QColor color;
        color.setNamedColor(Settings::SELECTED_COLOR);
        pen.setColor(color);
    } else {
        QColor color;
        color.setNamedColor(Settings::OBSTACLE_BORDER_COLOR);
        pen.setColor(color);
    }

    color.setNamedColor(Settings::OBSTACLE_COLOR);
    auto points = obstacle->getPoints();
    QPolygonF polygon;
    painter.setPen(pen);
    painter.setBrush(color);
    for (int i = 0; i < 4; i++) {
      polygon << QPointF(points[i].x, points[i].y);
    }
    painter.drawPolygon(polygon);
}

void VisualizationWidget::drawRobot(QPainter &painter, std::shared_ptr<Robot> robot){

      QColor color;
    if (robot->getType() == Robot::Type::MANUAL) {
      color.setNamedColor(Settings::MANUAL_ROBOT_COLOR);
      painter.setBrush(color);
    } else {
      color.setNamedColor(Settings::AUTONOMOUS_ROBOT_COLOR);
      painter.setBrush(color);
    }

    QPen pen;
    pen.setWidth(Settings::OBSTACLE_BORDER_WIDTH);
    if (robot == selectedRobot) {
        QColor color;
        color.setNamedColor(Settings::SELECTED_COLOR);
        pen.setColor(color);
    } else {
        QColor color;
        color.setNamedColor(Settings::ROBOT_BORDER_COLOR);
        pen.setColor(color);
    }
    pen.setWidth(Settings::ROBOT_BORDER_WIDTH);
    painter.setPen(pen);
    painter.drawEllipse(robot->getX(), robot->getY(), robot->getDiameter(),
                        robot->getDiameter());


    painter.drawLine(robot->getX() + robot->getDiameter() / 2,
                     robot->getY() + robot->getDiameter() / 2,
                     robot->getX() + robot->getDiameter() / 2 +
                         robot->getDiameter() / 2 * cos(robot->getViewAngleRad()),
                     robot->getY() + robot->getDiameter() / 2 +
                         robot->getDiameter() / 2 * sin(robot->getViewAngleRad()));

    int eyeDiameter = robot->getDiameter() / 10;
    int eyeDistance = robot->getDiameter() / 3;


    double eyeAngle = robot->getViewAngleRad() - M_PI / 6 ; // Adjust eye angle as needed
    double eyeX1 = robot->getX() + robot->getDiameter() / 2 + eyeDistance * cos(eyeAngle);
    double eyeY1 = robot->getY() + robot->getDiameter() / 2 + eyeDistance * sin(eyeAngle);
    eyeAngle = robot->getViewAngleRad() + M_PI / 6; // Adjust eye angle as needed
    double eyeX2 = robot->getX() + robot->getDiameter() / 2 + eyeDistance * cos(eyeAngle);
    double eyeY2 = robot->getY() + robot->getDiameter() / 2 + eyeDistance * sin(eyeAngle);

    painter.setBrush(pen.color());

    painter.drawEllipse(QPointF(eyeX1, eyeY1), eyeDiameter, eyeDiameter);
    painter.drawEllipse(QPointF(eyeX2, eyeY2), eyeDiameter, eyeDiameter);

    auto box = robot->getViewBox();
    color.setNamedColor(Settings::ROBOT_VIEW_COLOR);
    auto points = box.getPoints();
    QPolygonF polygon;
    QPen dashpen(color);
    dashpen.setStyle(Qt::DashLine);
    painter.setPen(dashpen);
    painter.setBrush(Qt::NoBrush);
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

    auto robots = map->getRobots();
    std::reverse(robots.begin(), robots.end());
    for (auto& robot : robots) {
        if (robot->getBoundingBox().contains({x, y})) {
            grabbedRobot = robot;
            selectedRobot = robot;
            update();
            emit robotSelected(robot);
            return;
        }
    }

    auto obstacles = map->getObstacles();
    std::reverse(obstacles.begin(), obstacles.end());
    
    for (auto& obstacle : obstacles) {
        if (obstacle->getBoundingBox().contains({x, y})) {
            grabbedObstacle = obstacle;
            selectedObstacle = obstacle;
            update();
            emit obstacleSelected(obstacle);
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
