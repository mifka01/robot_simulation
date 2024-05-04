/**
 * @file Label.hpp
 * @brief This file contains declaration of Label class which is custom
 * QLabel
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include <QLabel>

/**
 * @class Label
 * @brief This class is custom QLabel
 */
class Label : public QLabel {
  Q_OBJECT
 public:
  /**
   * @brief Construct a new Label object
   *
   * @param const QString& text
   * @param QWidget* parent
   */
  Label(const QString& text, QWidget* parent = nullptr);
};
