#pragma once
#include <map>
#include <string>
#include <vector>
#include "Obstacle.hpp"
#include "Robot/Robot.hpp"
#include <memory>

class IMap {
public:
    virtual ~IMap() = default;

    virtual void setMap(
        const std::map<std::string, std::vector<std::map<std::string, double>>>& map,
        int width,
        int height) = 0;

    virtual Robot& getRobot(int index) = 0;
    virtual Obstacle& getObstacle(int index) = 0;
    virtual std::vector<std::shared_ptr<Robot>>& getRobots() = 0;
    virtual std::vector<std::shared_ptr<Obstacle>>& getObstacles() = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;

    virtual void setWidth(int width) = 0;
    virtual void setHeight(int height) = 0;

    virtual void addObstacle(double x, double y, double width, double height) = 0;
    virtual void addRobot(double x, double y, double diameter, double viewAngle, double rotateAngle, double viewDistance, bool rotateClockwise, int speed, int type) = 0;
};

