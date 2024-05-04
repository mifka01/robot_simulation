/**
 * @file Frame.hpp
 * @brief This file contains implementation of Frame class which is custom
 * QFrame
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "GUI/Frame.hpp"
#include <QGraphicsDropShadowEffect>
#include "Settings.hpp"

Frame::Frame(QWidget* parent) : QFrame(parent) {
  this->setFrameShape(QFrame::Panel);
  this->setStyleSheet(
      "QFrame#frame{"
      "background-color: " +
      QString(Settings::FRAME_BACKGROUND_COLOR) +
      ";"
      "border: " +
      QString::number(Settings::FRAME_BORDER_WIDTH) + "px solid " +
      QString(Settings::FRAME_BORDER_COLOR) +
      ";"
      "border-radius: " +
      QString::number(Settings::FRAME_BORDER_RADIUS) +
      "px;"
      "padding: 10px;"
      "}");
}
