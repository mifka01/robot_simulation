#include "GUI/Label.hpp"
#include "Settings.hpp"

Label::Label(const QString &text, QWidget *parent)
    : QLabel(text, parent) {
    setStyleSheet("QLabel {"
                  "color: " + QString(Settings::LABEL_TEXT_COLOR) + ";"
                  "font-size: 15px;"
                  "font-weight: bold;"
                  "}");
}
