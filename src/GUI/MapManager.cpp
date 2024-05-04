/**
 * @file MapManager.cpp
 * @brief This file contains implementation of MapManager class which is used for
 * loading and saving maps from and to json files
 * @author Mifka Radim (xmifka00)
 * @date April 2024
 */
#include "GUI/MapManager.hpp"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

const std::map<std::string, std::vector<std::map<std::string, double>>>
MapManager::loadMap(QString path) {
  QFile file(path);
  if (!file.open(QIODevice::ReadOnly)) {
    throw std::runtime_error("Cannot open file");
  }

  QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
  QJsonObject obj = doc.object();

  std::map<std::string, std::vector<std::map<std::string, double>>> map;

  for (const auto& key : obj.keys()) {
    QJsonValue value = obj.value(key);
    if (value.isArray()) {
      std::vector<std::map<std::string, double>> vec;
      for (const auto& item : value.toArray()) {
        std::map<std::string, double> m;
        for (const auto& k : item.toObject().keys()) {
          m[k.toStdString()] = item.toObject().value(k).toDouble();
        }
        vec.push_back(m);
      }
      map[key.toStdString()] = vec;
    }
  }
  return map;
}

void MapManager::saveMap(QString path, IMap& map) {
  QJsonObject obj;
  QJsonArray robots;
  for (auto& robot : map.getRobots()) {
    QJsonObject r;
    r["x"] = robot->getX();
    r["y"] = robot->getY();
    r["diameter"] = robot->getDiameter();
    r["view-angle"] = robot->getViewAngle();
    r["rotate-angle"] = robot->getRotateAngle();
    r["view-distance"] = robot->getViewDistance();
    r["rotate-clockwise"] = robot->getRotateClockwise();
    r["speed"] = robot->getSpeed();
    r["type"] = (int)robot->getType();
    robots.append(r);
  }
  obj["robots"] = robots;

  QJsonArray obstacles;
  for (const auto& obstacle : map.getObstacles()) {
    QJsonObject o;
    o["x"] = obstacle->getX();
    o["y"] = obstacle->getY();
    o["width"] = obstacle->getWidth();
    o["height"] = obstacle->getHeight();
    o["rotation"] = obstacle->getRotation();
    obstacles.append(o);
  }
  obj["obstacles"] = obstacles;

  QJsonDocument doc(obj);
  QFile file(path);
  if (!file.open(QIODevice::WriteOnly)) {
    throw std::runtime_error("Cannot open file");
  }
  file.write(doc.toJson());
}

const std::map<std::string, std::vector<std::map<std::string, double>>>
MapManager::getEmptyMap() {
  return {{"robots", {}}, {"obstacles", {}}};
}
