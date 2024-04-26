/**
 * @file src/main.cpp
 * @author Radim Mifka (xmifka00)
 * @date April 2024
 */
#include <QApplication>
#include "GUI/Window.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Window window;
  window.show();
  return app.exec();
}
