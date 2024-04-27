#pragma once
#include <QPainter>
#include <QWidget>
#include <memory>
#include "Model/Map.hpp"

class VisualizationWidget : public QWidget {
  Q_OBJECT
  std::shared_ptr<Map> map;

  // bool isWithinBounds(int x, int y) {
  //   return x >= 0 && x < width() && y >= 0 && y < height();
  // }
  //
  // std::pair<int, int> adjustCoordinates(int x, int y, int w, int h);

 public:
  explicit VisualizationWidget(QWidget* parent = nullptr)
      : QWidget(parent), map(std::make_shared<Map>()) {}

  void setMap(std::shared_ptr<Map> map) { this->map = map; }

 protected:
  void paintEvent(QPaintEvent* event) override;

  void resizeEvent(QResizeEvent* event) override;

  void drawBorder(QPainter& painter);
};
