#include "GUI/Label.hpp"

Label::Label(const QString &text, QWidget *parent)
    : QLabel(text, parent) {
    setStyleSheet("QLabel {"
                  "color: #333333;"
                  "font-size: 15px;"
                  "font-weight: bold;"
                  "}");
}
