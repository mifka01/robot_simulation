/**
 * @file Window.cpp
 * @brief This file contains implementation of Window class which is custom
 * QMainWindow
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "GUI/Window.hpp"
#include <QFileDialog>
#include <QHBoxLayout>
#include <QString>
#include <iostream>
#include "GUI/MapManager.hpp"
#include "Settings.hpp"

Window::Window(QWidget* parent) : QMainWindow(parent) {
  setWindowTitle(Settings::TITLE);
  setMinimumSize(Settings::WINDOW_MIN_W, Settings::WINDOW_MIN_H);
  setStyleSheet("QMainWindow {background-color: " +
                QString(Settings::BACKGROUND_COLOR) + ";}");

  QWidget* centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QHBoxLayout* layout = new QHBoxLayout(centralWidget);
  layout->setContentsMargins(0, 0, 0, 0);

  visualizationWidget.setSizePolicy(QSizePolicy::Expanding,
                                    QSizePolicy::Preferred);
  layout->addWidget(&visualizationWidget, 3);

  // Create controls widget
  controls.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
  layout->addWidget(&controls, 1);

  updateTimer.setInterval(1000 / Settings::FPS);

  // Create empty map
  simulation.setMap(MapManager::getEmptyMap(), visualizationWidget.width(),
                    visualizationWidget.height());
  controls.setMap(simulation.getMap());
  visualizationWidget.setMap(simulation.getMap());

  connect(&updateTimer, &QTimer::timeout, this, &Window::onTick);
  connect(&controls, &ControlsWidget::loadMapClicked, this, &Window::onLoadMap);
  connect(&controls, &ControlsWidget::saveMapClicked, this, &Window::onSaveMap);
  connect(&controls, &ControlsWidget::startClicked, this, &Window::onStart);
  connect(&controls, &ControlsWidget::startClicked, &visualizationWidget,
          &VisualizationWidget::onStart);
  connect(&controls, &ControlsWidget::stopClicked, this, &Window::onStop);
  connect(&controls, &ControlsWidget::stopClicked, &visualizationWidget,
          &VisualizationWidget::onStop);
  connect(&controls, &ControlsWidget::updateMap, this, &Window::visualize);
  connect(&visualizationWidget, &VisualizationWidget::obstacleSelected,
          &controls, &ControlsWidget::onObstacleSelected);
  connect(&visualizationWidget, &VisualizationWidget::obstacleDeselected,
          &controls, &ControlsWidget::onObstacleDeselected);
  connect(&visualizationWidget, &VisualizationWidget::robotSelected, &controls,
          &ControlsWidget::onRobotSelected);
  connect(&visualizationWidget, &VisualizationWidget::robotDeselected,
          &controls, &ControlsWidget::onRobotDeselected);
}

void Window::onLoadMap() {
  QString filePath = QFileDialog::getOpenFileName(this, tr("Open Map"), "",
                                                  tr("JSON Files (*.json)"));
  if (filePath.isEmpty()) {
    return;
  }

  try {
    auto map = MapManager::loadMap(filePath);
    simulation.setMap(map, visualizationWidget.width(),
                      visualizationWidget.height());
  } catch (std::exception e) {
    std::cerr << "error: failed to load map" << std::endl;
    simulation.setMap(MapManager::getEmptyMap(), visualizationWidget.width(),
                      visualizationWidget.height());
  }
  controls.setMap(simulation.getMap());
  visualizationWidget.setMap(simulation.getMap());
  controls.onObstacleDeselected();
  controls.onRobotDeselected();
  emit visualize();
}

void Window::onSaveMap() {
  updateTimer.stop();
  QString filePath = QFileDialog::getSaveFileName(this, tr("Save Map"), "",
                                                  tr("JSON Files (*.json)"));
  if (filePath.isEmpty()) {
    return;
  }
  MapManager::saveMap(filePath, *simulation.getMap());
}

void Window::onStart() {
  updateTimer.start();
}

void Window::onStop() {
  updateTimer.stop();
}

void Window::onTick() {
  simulation.run();
  emit visualize();
}

void Window::visualize() {
  visualizationWidget.update();
}
