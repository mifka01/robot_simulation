#include <QMainWindow>
#include <QTimer>
#include <QWidget>
#include "GUI/Widget/ControlsWidget.hpp"
#include "GUI/Widget/VisualizationWidget.hpp"
#include "Model/Simulation.hpp"

class Window : public QMainWindow {
  Q_OBJECT
  QTimer updateTimer;
  Simulation simulation;
  VisualizationWidget visualizationWidget;
  ControlsWidget controls;

 public:
  Window(QWidget* parent = nullptr);

 signals:
  void loadMap();
  void start();
  void stop();
  void tick();

 private slots:
  void onLoadMap();
  void onStart();
  void onStop();
  void onTick();
};
