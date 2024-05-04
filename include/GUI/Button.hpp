/**
 * @file Button.hpp
 * @brief This file contains declaration of Button class which is custom
 * QPushButton
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include <QPushButton>

/**
 * @class Button
 * @brief This class is custom QPushButton
 */
class Button : public QPushButton {
  Q_OBJECT
 public:
  /**
   * @brief Construct a new Button object
   *
   * @param text
   * @param parent
   */
  Button(const QString& text, QWidget* parent = nullptr);
};
