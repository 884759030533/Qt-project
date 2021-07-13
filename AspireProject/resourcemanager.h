#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>
#include <QPainter>
#include <string>
#include <iostream>
#include <fstream>
#include <QDebug>
#include <QRandomGenerator>
#include <QFile>
#include "tile.h"


class ResourceManager
{
private:
    ResourceManager();
    ResourceManager(const ResourceManager& );
    ResourceManager& operator=( ResourceManager& );
    ~ResourceManager();
    static ResourceManager * RM;

    std::vector<QPixmap> tiles; // textures
    std::vector<QPixmap> entities;
    std::vector<QPixmap> player;

    std::vector<Tile> map; // world map

public:
    static ResourceManager * CreateManager();
    static void DeleteManager();

    std::vector<Tile>* MM[3];
    void AddSprite(int id, QPixmap &pixmap, std::vector<QPixmap> &storage);
    QPixmap GetSprite(int id, std::vector<QPixmap> &storage);
    bool IsExist(int id, std::vector<QPixmap> &storage);
    std::vector<QPixmap>& TilesStorage() { return tiles; }
    std::vector<Tile>& GetWorldMap() { return map; }

};

#endif // RESOURCEMANAGER_H
