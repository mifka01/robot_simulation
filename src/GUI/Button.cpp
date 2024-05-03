#include "GUI/Button.hpp"
#include "Settings.hpp"

Button::Button(const QString &text, QWidget *parent)
    : QPushButton(text, parent) {
    setStyleSheet("QPushButton {"
            "background-color: " + QString(Settings::BUTTON_COLOR) + ";"
            "border: 1px solid " + QString(Settings::BUTTON_BORDER_COLOR) + ";"
            "color: " + QString(Settings::BUTTON_TEXT_COLOR) + ";"
            "padding: 5px 10px;"
            "border-radius: 3px;"
        "}"
        "QPushButton:hover {"
            "background-color: " + QString(Settings::BUTTON_HOVER_COLOR) + ";"
        "}"
        "QPushButton:pressed {"
            "background-color: " + QString(Settings::BUTTON_PRESSED_COLOR) + ";"
        "}");
}
