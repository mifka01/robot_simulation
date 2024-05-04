/**
 * @file Frame.hpp
 * @brief This file contains declaration of Frame class which is custom
 * QFrame
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once
#include <QFrame>

/**
 * @class Frame
 * @brief This class is custom QFrame
 */
class Frame : public QFrame {
  Q_OBJECT
 public:
  /**
   * @brief Construct a new Frame object
   *
   * @param parent
   */
  Frame(QWidget* parent = nullptr);
};
