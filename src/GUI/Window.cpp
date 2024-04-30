#include "GUI/Window.hpp"
#include <QFileDialog>
#include <QHBoxLayout>
#include <QString>
#include "GUI/MapLoader.hpp"
#include "Settings.hpp"

Window::Window(QWidget* parent) : QMainWindow(parent) {
  setWindowTitle(Settings::TITLE);
  setMinimumSize(Settings::WINDOW_MIN_W, Settings::WINDOW_MIN_H);

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
  simulation.setMap(MapLoader::getEmptyMap(), visualizationWidget.width(),
                    visualizationWidget.height());
  controls.setMap(simulation.getMap());
  visualizationWidget.setMap(simulation.getMap());

  connect(&updateTimer, &QTimer::timeout, this, &Window::onTick);
  connect(&controls, &ControlsWidget::loadMapClicked, this, &Window::onLoadMap);
  connect(&controls, &ControlsWidget::startClicked, this, &Window::onStart);
  connect(&controls, &ControlsWidget::stopClicked, this, &Window::onStop);
  connect(&controls, &ControlsWidget::updateMap, this, &Window::onVisualize);

}

void Window::onLoadMap() {
  QString filePath = QFileDialog::getOpenFileName(this, tr("Open Map"), "",
                                                  tr("JSON Files (*.json)"));
  if (filePath.isEmpty()) {
    return;
  }
  auto map = MapLoader::loadMap(filePath);
  simulation.setMap(map, visualizationWidget.width(),
                    visualizationWidget.height());
  controls.setMap(simulation.getMap());
  visualizationWidget.setMap(simulation.getMap());
  emit onVisualize();
}

void Window::onStart() {
  updateTimer.start();
}

void Window::onStop() {
  updateTimer.stop();
}

void Window::onTick() {
  simulation.run();
  emit onVisualize();
}

void Window::onVisualize() {
  visualizationWidget.update();
}
