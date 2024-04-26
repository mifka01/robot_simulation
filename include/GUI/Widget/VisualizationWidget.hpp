#pragma once
#include <QPainter>
#include <QWidget>

class VisualizationWidget : public QWidget {
 public:
  VisualizationWidget(QWidget* parent = nullptr);

 protected:
  void paintEvent(QPaintEvent* event) override;
};
