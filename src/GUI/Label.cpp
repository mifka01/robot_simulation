/**
 * @file Label.cpp
 * @brief This file contains implementation of Label class which is custom
 * QLabel
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "GUI/Label.hpp"
#include "Settings.hpp"

Label::Label(const QString& text, QWidget* parent) : QLabel(text, parent) {
  setStyleSheet(
      "QLabel {"
      "color: " +
      QString(Settings::LABEL_TEXT_COLOR) +
      ";"
      "font-size: 15px;"
      "font-weight: bold;"
      "}"
      "QLabel#stopped {"
      "color: red;"
      "}");
}
