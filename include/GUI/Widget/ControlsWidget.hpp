#pragma once

#include <QWidget>
#include <QObject>

class ControlsWidget : public QWidget {
  Q_OBJECT
 public:
  ControlsWidget(QWidget* parent = nullptr);

 signals:
  void loadMapClicked();
  void startClicked();
  void stopClicked();

 private:
  void onLoadMapClicked();
  void onStartClicked();
  void onStopClicked();
};
