#include "GUI/Window.hpp"
#include <QHBoxLayout>
#include "GUI/Settings.hpp"
#include "GUI/Widget/ControlsWidget.hpp"
#include "GUI/Widget/VisualizationWidget.hpp"

Window::Window(QWidget* parent) : QMainWindow(parent) {
  setWindowTitle(Settings::TITLE);
  setMinimumSize(Settings::WINDOW_MIN_W, Settings::WINDOW_MIN_H);

  QWidget* centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  QHBoxLayout* layout = new QHBoxLayout(centralWidget);
  layout->setContentsMargins(0, 0, 0, 0);

  // Create visualization widget
  VisualizationWidget* visualizationWidget =
      new VisualizationWidget(centralWidget);
  visualizationWidget->setSizePolicy(QSizePolicy::Expanding,
                                     QSizePolicy::Preferred);
  layout->addWidget(visualizationWidget, 3);

  // Create controls widget
  ControlsWidget* controls = new ControlsWidget(centralWidget);
  controls->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
  layout->addWidget(controls, 1);
}
