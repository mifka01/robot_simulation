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
  void saveMap();
  void start();
  void stop();
  void tick();
  void visualize();

 private slots:
  void onLoadMap();
  void onSaveMap();
  void onStart();
  void onStop();
  void onTick();
  void onVisualize();
};
