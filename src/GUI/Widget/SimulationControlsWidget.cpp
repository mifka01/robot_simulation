#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QWidget>
#include "GUI/Widget/SimulationControlsWidget.hpp"
#include "GUI/Button.hpp"
#include "GUI/Label.hpp"
#include "GUI/Frame.hpp"


SimulationControlsWidget::SimulationControlsWidget(QWidget* parent) : QWidget(parent) {
    setObjectName("SimulationControlsWidget");
    QVBoxLayout* layout = new QVBoxLayout(this);

    Frame* frame = new Frame(this);
    frame->setObjectName("frame");
    QVBoxLayout* frameLayout = new QVBoxLayout(frame);


    Label* label = new Label("Simulation", frame);

    QHBoxLayout* buttons = new QHBoxLayout(frame);
    Button* start = new Button("Start", frame);
    buttons->addWidget(start);

    Button* stop = new Button("Stop", frame);
    buttons->addWidget(stop);

    Button* load = new Button("Load", frame);
    buttons->addWidget(load);

    Button* save = new Button("Save", frame);
    buttons->addWidget(save);

    frameLayout->addWidget(label, 0, Qt::AlignCenter);
    frameLayout->addLayout(buttons);

    layout->addWidget(frame);

    setLayout(layout);

    setStyleSheet("QWidget#SimulationControlsWidget {"
                  "background-color: transparent;" // make the background transparent
                  "}");


    connect(load, &Button::clicked, this, &SimulationControlsWidget::onLoadMapClicked);
    connect(save, &Button::clicked, this, &SimulationControlsWidget::onSaveMapClicked);
    connect(start, &Button::clicked, this, &SimulationControlsWidget::onStartClicked);
    connect(stop, &Button::clicked, this, &SimulationControlsWidget::onStopClicked);
}

void SimulationControlsWidget::onStartClicked() {
    emit startClicked();
}

void SimulationControlsWidget::onStopClicked() {
    emit stopClicked();
}

void SimulationControlsWidget::onLoadMapClicked() {
    emit loadMapClicked();
}

void SimulationControlsWidget::onSaveMapClicked() {
    emit saveMapClicked();
}


