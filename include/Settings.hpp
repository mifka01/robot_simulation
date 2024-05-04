/**
 * @file Settings.hpp
 * @brief This file contains all settings for the application
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#pragma once

namespace Settings {

// App settings
constexpr const char* TITLE = "ICP - Robots";
constexpr const int WINDOW_MIN_W = 1280;
constexpr const int WINDOW_MIN_H = 720;
constexpr const int FPS = 60;

// App colors
constexpr const char* BACKGROUND_COLOR = "#DFE0E2";
constexpr const char* BUTTON_COLOR = "#333333";
constexpr const char* BUTTON_BORDER_COLOR = "#222222";
constexpr const char* BUTTON_HOVER_COLOR = "#444444";
constexpr const char* BUTTON_PRESSED_COLOR = "#555555";

constexpr const char* BUTTON_TEXT_COLOR = "#FFFFFF";
constexpr const char* FRAME_BORDER_COLOR = "#111111";
constexpr const int FRAME_BORDER_WIDTH = 2;
constexpr const char* FRAME_BACKGROUND_COLOR = "#E3E7D3";
constexpr const int FRAME_BORDER_RADIUS = 5;

constexpr const char* LABEL_TEXT_COLOR = "#333333";

// Obstacle settings
constexpr const int OBSTACLE_BASE_WIDTH = 100;
constexpr const int OBSTACLE_BASE_HEIGHT = 50;
constexpr const int OBSTACLE_BASE_ROTATION = 0;

// Obstacle colors
constexpr const char* OBSTACLE_COLOR = "#FB5607";
constexpr const char* OBSTACLE_BORDER_COLOR = "#000000";
constexpr const int OBSTACLE_BORDER_WIDTH = 3;
constexpr const char* SELECTED_COLOR = "#FFBE0B";

// Robot settings
constexpr const int ROBOT_BASE_DIAMETER = 40;
constexpr const int ROBOT_BASE_SPEED = 2;
constexpr const int ROBOT_BASE_VIEW_ANGLE = -90;
constexpr const int ROBOT_BASE_ROTATE_ANGLE = 45;
constexpr const int ROBOT_BASE_COLISION_DISTANCE = ROBOT_BASE_DIAMETER;
constexpr const int ROBOT_BASE_ROTATE_CLOCKWISE = true;

// Robot colors
constexpr const char* MANUAL_ROBOT_COLOR = "#FF006E";
constexpr const char* AUTONOMOUS_ROBOT_COLOR = "#8338EC";
constexpr const char* ROBOT_BORDER_COLOR = "#000000";
constexpr const int ROBOT_BORDER_WIDTH = 2;
constexpr const char* ROBOT_ANGLE_LINE_COLOR = ROBOT_BORDER_COLOR;
constexpr const char* ROBOT_VIEW_COLOR = "#FFBE0B";

}  // namespace Settings
