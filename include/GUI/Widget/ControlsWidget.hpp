#pragma once

#include <QWidget>
#include <QObject>
#include <memory>
#include "Model/IMap.hpp"

class ControlsWidget : public QWidget {
  Q_OBJECT
  std::shared_ptr<IMap> map;

 public:
  explicit ControlsWidget(QWidget* parent = nullptr);

  void setMap(std::shared_ptr<IMap> map) { this->map = map; }

 signals:
  void loadMapClicked();
  void startClicked();
  void stopClicked();
  void addObstacleClicked();
  void updateMap();

 private:
  void onLoadMapClicked();
  void onStartClicked();
  void onStopClicked();
  void onAddObstacle(int width, int height);
};
