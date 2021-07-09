#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <QPainter>

class ResourceManager
{
public:
    std::map<std::string, QPixmap> tiles;
    std::map<std::string, QPixmap> entities;
    std::map<std::string, QPixmap> player;
public:
    ResourceManager();
    ~ResourceManager();
    void AddSprite(std::string key, QPixmap pixmap, std::map<std::string, QPixmap> storage);
    QPixmap GetSprite(std::string key, std::map<std::string, QPixmap> storage);
    bool IsExist(std::string key, std::map<std::string, QPixmap> storage);
    std::map<std::string, QPixmap>& TilesStorage() { return tiles; }
};

#endif // RESOURCEMANAGER_H
