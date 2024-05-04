/**
 * @file SimulationControlsWidget.hpp
 * @brief This file contains declaration of SimulationControlsWidget class
 * which is responsible for handling user interactions with the simulation
 * controls in the GUI
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once

#include <QObject>
#include <QWidget>

/**
 * @class SimulationControlsWidget
 * @brief This class is responsible for handling user interactions with the
 * simulation controls in the GUI
 */
class SimulationControlsWidget : public QWidget {
  Q_OBJECT

 public:
  /**
   * @brief Construct a new SimulationControlsWidget object
   *
   * @param parent
   */
  SimulationControlsWidget(QWidget* parent = nullptr);

 signals:
  /**
   * @brief Signal emitted when load map button is clicked
   */
  void loadMapClicked();

  /**
   * @brief Signal emitted when save map button is clicked
   */
  void saveMapClicked();

  /**
   * @brief Signal emitted when start button is clicked
   */
  void startClicked();

  /**
   * @brief Signal emitted when stop button is clicked
   */

  void stopClicked();

 private:
  /**
   * @brief Method called when load map button is clicked
   * It emits loadMapClicked signal
   */
  void onLoadMapClicked();

  /**
   * @brief Method called when save map button is clicked
   * It emits saveMapClicked signal
   */
  void onSaveMapClicked();

  /**
   * @brief Method called when start button is clicked
   *
   * It emits startClicked signal
   */
  void onStartClicked();

  /**
   * @brief Method called when stop button is clicked
   *
   * It emits stopClicked signal
   */
  void onStopClicked();
};
