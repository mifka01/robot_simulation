#include "GUI/Button.hpp"
Button::Button(const QString &text, QWidget *parent)
    : QPushButton(text, parent) {
    setStyleSheet("QPushButton {"
            "background-color: #333333;"
            "border: 1px solid #222222;"
            "color: #FFFFFF;"
            "padding: 5px 10px;"
            "border-radius: 3px;"
        "}"
        "QPushButton:hover {"
            "background-color: #444444;"
        "}"
        "QPushButton:pressed {"
            "background-color: #555555;"
        "}");
}
