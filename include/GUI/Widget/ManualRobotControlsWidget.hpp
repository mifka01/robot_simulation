#pragma once
#include <QWidget>
#include "Model/Robot/ManualRobot.hpp"

class ManualRobotControlsWidget: public QWidget {
  Q_OBJECT
    std::shared_ptr<ManualRobot> robot;

    public:
        ManualRobotControlsWidget(QWidget* parent = nullptr);
        void setRobot(std::shared_ptr<ManualRobot> robot);

    private:
        void onMoveClicked();
        void onStopClicked();
        void onTurnLeftClicked();
        void onTurnRightClicked();
};
