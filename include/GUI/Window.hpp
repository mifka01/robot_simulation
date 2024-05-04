/**
 * @file Window.hpp
 * @brief This file contains declaration of Window class which is custom
 * QMainWindow
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include <QMainWindow>
#include <QTimer>
#include <QWidget>
#include "GUI/Widget/ControlsWidget.hpp"
#include "GUI/Widget/VisualizationWidget.hpp"
#include "Model/Simulation.hpp"

/**
 * @class Window
 * @brief This class is custom QMainWindow
 *
 * This class is main window of application
 * It contains VisualizationWidget and ControlsWidget
 * It also contains Simulation object and timer for updating simulation
 */
class Window : public QMainWindow {
  Q_OBJECT
  QTimer updateTimer;
  Simulation simulation;
  VisualizationWidget visualizationWidget;
  ControlsWidget controls;

 public:
  /**
   * @brief Construct a new Window object
   *
   * @param QWidget* parent
   */
  Window(QWidget* parent = nullptr);

 private slots:
  /**
   * @brief Method called when load map button is clicked
   *
   * It calls loadMap method of MapManager and sets map to other widgets
   */
  void onLoadMap();

  /**
   * @brief Method called when save map button is clicked
   *
   * It calls saveMap method of MapManager
   */
  void onSaveMap();

  /**
   * @brief Method called when start button is clicked
   * It starts the simulation by starting the timer
   */
  void onStart();

  /**
   * @brief Method called when stop button is clicked
   * It stops the simulation by stopping the timer
   */
  void onStop();

  /**
   * @brief Method called on timer tick
   * It updates the simulation and visualizes it in the visualization widget
   */
  void onTick();

  /**
   * @brief Method called when visualizeWidged needs to be updated
   *
   */
  void visualize();
};
