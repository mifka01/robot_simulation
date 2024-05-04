/**
 * @file SpawnControlsWidget.hpp
 * @brief This file contains declaration of SpawnControlsWidget class
 * which is responsible for handling user interactions with the spawn controls
 * in the GUI
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once

#include <QObject>
#include <QWidget>

/**
 * @class SpawnControlsWidget
 * @brief This class is responsible for handling user interactions with the
 * spawn controls in the GUI
 */
class SpawnControlsWidget : public QWidget {
  Q_OBJECT

 public:
  /**
   * @brief Construct a new SpawnControlsWidget object
   *
   * @param QWidget* parent
   */
  SpawnControlsWidget(QWidget* parent = nullptr);

 signals:
  /**
   * @brief Signal emitted when add obstacle button is clicked
   */
  void addObstacleClicked();

  /**
   * @brief Signal emitted when add auto robot button is clicked
   */
  void addAutoRobotClicked();

  /**
   * @brief Signal emitted when add manual robot button is clicked
   */
  void addManualRobotClicked();

 private:
  /**
   * @brief Method called when add obstacle button is clicked
   *
   * It emits addObstacleClicked signal
   */
  void onAddObstacle();

  /**
   * @brief Method called when add auto robot button is clicked
   *
   * It emits addAutoRobotClicked signal
   */
  void onAddAutoRobot();

  /**
   * @brief Method called when add manual robot button is clicked
   *
   * It emits addManualRobotClicked signal
   */
  void onAddManualRobot();
};
