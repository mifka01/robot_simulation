#include "GUI/Frame.hpp"

Frame::Frame(QWidget* parent) : QFrame(parent) {
    setStyleSheet(
                  "QFrame#frame {"
                  "border: 1px solid #111111;"
                  "padding: 5px 10px;"
                  "border-radius: 3px;"
                  "}");
}
