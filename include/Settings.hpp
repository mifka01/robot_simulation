#pragma once

namespace Settings {

constexpr const char* TITLE = "ICP - Robots";

constexpr const int WINDOW_MIN_W = 1280;
constexpr const int WINDOW_MIN_H = 720;

constexpr const int FPS = 60;

constexpr const int BORDER_SIZE = 5;

constexpr const int OBSTACLE_BASE_WIDTH = 50;
constexpr const int OBSTACLE_BASE_HEIGHT = 50;
constexpr const int OBSTACLE_BASE_ROTATION = 0;

constexpr const int ROBOT_BASE_DIAMETER = 20;
constexpr const int ROBOT_BASE_SPEED = 2;
constexpr const int ROBOT_BASE_VIEW_ANGLE = -90;
constexpr const int ROBOT_BASE_ROTATE_ANGLE = 45;
constexpr const int ROBOT_BASE_COLISION_DISTANCE = ROBOT_BASE_DIAMETER;
constexpr const int ROBOT_BASE_ROTATE_CLOCKWISE = true;

}  // namespace Settings
