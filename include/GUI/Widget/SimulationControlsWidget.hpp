#pragma once

#include <QWidget>
#include <QObject>

class SimulationControlsWidget : public QWidget {
  Q_OBJECT

 public:
    SimulationControlsWidget(QWidget* parent = nullptr);

 signals:
  void loadMapClicked();
  void saveMapClicked();
  void startClicked();
  void stopClicked();

 private:
  void onLoadMapClicked();
  void onSaveMapClicked();
  void onStartClicked();
  void onStopClicked();
};
