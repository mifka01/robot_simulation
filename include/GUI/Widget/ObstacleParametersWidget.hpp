/**
 * @file ObstacleParametersWidget.hpp
 * @brief This file contains declaration of ObstacleParametersWidget class
 * which is responsible for handling user interactions with the obstacle
 * parameters in the GUI
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once

#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QObject>
#include <QWidget>
#include <memory>
#include "Model/Obstacle.hpp"

/**
 * @class ObstacleParametersWidget
 * @brief This class is responsible for handling user interactions with the
 * obstacle parameters in the GUI
 */
class ObstacleParametersWidget : public QWidget {
  Q_OBJECT

  std::shared_ptr<Obstacle> obstacle;

  QDoubleSpinBox* x;
  QDoubleSpinBox* y;

  QDoubleSpinBox* width;
  QDoubleSpinBox* height;

  QDoubleSpinBox* rotation;

 public:
  /**
   * @brief Construct a new ObstacleParametersWidget object
   *
   * @param parent
   */
  ObstacleParametersWidget(QWidget* parent = nullptr);

  /**
   * @brief Set the Obstacle object
   *
   * @param obstacle
   */
  void setObstacle(std::shared_ptr<Obstacle> obstacle);

  /**
   * @brief Creates a parameter control
   * in the form of a QDoubleSpinBox plus Label and adds it to the parent layout
   *
   * @param labelText
   * @param minRange
   * @param maxRange
   * @param QHBoxLayout* parentLayout
   *
   * @return QDoubleSpinBox*
   */
  QDoubleSpinBox* createParameterControl(const QString& labelText,
                                         double minRange,
                                         double maxRange,
                                         QHBoxLayout* parentLayout);

 private:
  /**
   * @brief Method called when x value is changed
   *
   * It sets the obstacle x value and emits updateMap signal
   *
   * @param value
   */
  void onXChanged(double value);

  /**
   * @brief Method called when y value is changed
   *
   * It sets the obstacle y value and emits updateMap signal
   *
   * @param value
   */
  void onYChanged(double value);

  /**
   * @brief Method called when width value is changed
   *
   * It sets the obstacle width value and emits updateMap signal
   *
   * @param value
   */
  void onWidthChanged(double value);

  /**
   * @brief Method called when height value is changed
   *
   * It sets the obstacle height value and emits updateMap signal
   *
   * @param value
   */
  void onHeightChanged(double value);

  /**
   * @brief Method called when rotation value is changed
   *
   * It sets the obstacle rotation value and emits updateMap signal
   *
   * @param value
   */
  void onRotationChanged(double value);

 signals:
  /**
   * @brief Signal emitted when map needs to be updated
   *
   */
  void updateMap();

  /**
   * @brief Signal emitted when remove obstacle button is clicked
   * and obstacle should be removed
   *
   * @param obstacle
   */
  void removeObstacle(std::shared_ptr<Obstacle> obstacle);
};
