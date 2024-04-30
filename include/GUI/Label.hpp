#pragma once
#include <QLabel>

class Label: public QLabel{
    Q_OBJECT
public:
    Label(const QString &text, QWidget *parent = nullptr);
};
