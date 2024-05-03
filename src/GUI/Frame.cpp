#include "GUI/Frame.hpp"
#include "Settings.hpp"

Frame::Frame(QWidget* parent) : QFrame(parent) {
    setStyleSheet(
                  "QFrame#frame {"
                  "border: 1px solid " + QString(Settings::FRAME_BORDER_COLOR) + ";"
                  "padding: 5px 10px;"
                  "border-radius: 3px;"
                  "}");
}
