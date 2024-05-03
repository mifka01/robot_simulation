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
    virtual void addRobot(double x, double y, double diameter, double viewAngle, double rotateAngle, double viewDistance, bool rotateClockwise, int speed, Robot::Type type) = 0;

    virtual void removeObstacle(std::shared_ptr<Obstacle> obstacle) = 0;
    virtual void removeRobot(std::shared_ptr<Robot> robot) = 0;

    bool isOutOfBounds(double x, double y, int w, int h) {
        return x < 0 || x + w > getWidth() || y < 0 || y + h > getHeight();
    }

    bool isOutOfBounds(Point point) {
        return isOutOfBounds(point.x, point.y, 0, 0);
    }
};

