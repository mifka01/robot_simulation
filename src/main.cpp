/**
 * @file main.cpp
 * @brief This file contains the main function which starts the application
 * @details The main function creates a new QApplication object and a new Window
 * object and shows the window
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include <QApplication>
#include "GUI/Window.hpp"

/**
 * @brief Main function which starts the application
 *
 * @param int argc
 * @param char* argv[]
 * @return int
 */
int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Window window;
  window.show();
  return app.exec();
}
