#pragma once

#include <QWidget>
#include <QObject>

class SpawnControlsWidget : public QWidget {
  Q_OBJECT

 public:
    SpawnControlsWidget(QWidget* parent = nullptr);

 signals:
  void addObstacleClicked();
  void addAutoRobotClicked();
  void addManualRobotClicked();

 private:
    void onAddObstacle();
    void onAddAutoRobot();
    void onAddManualRobot();
};
