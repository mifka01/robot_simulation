#include "GUI/MapLoader.hpp"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

const std::map<std::string, std::vector<std::map<std::string, int>>>
MapLoader::loadMap(QString path) {
  QFile file(path);
  if (!file.open(QIODevice::ReadOnly)) {
    throw std::runtime_error("Cannot open file");
  }

  QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
  QJsonObject obj = doc.object();

  std::map<std::string, std::vector<std::map<std::string, int>>> map;

  for (const auto& key : obj.keys()) {
    QJsonValue value = obj.value(key);
    if (value.isArray()) {
      std::vector<std::map<std::string, int>> vec;
      for (const auto& item : value.toArray()) {
        std::map<std::string, int> m;
        for (const auto& k : item.toObject().keys()) {
          m[k.toStdString()] = item.toObject().value(k).toInt();
        }
        vec.push_back(m);
      }
      map[key.toStdString()] = vec;
    }
  }

  return map;
}
