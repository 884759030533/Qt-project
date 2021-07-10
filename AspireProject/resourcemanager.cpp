#include "resourcemanager.h"

ResourceManager* ResourceManager::RM = nullptr;

ResourceManager::ResourceManager()
{
    this->tiles.resize(100);
    this->map.resize(256);
    /* Loading an entire library of sprites with a lots of code ... */

    map[0] = Tile(tPosition(1, 1, 1),tSize(40, 40), 0);
    //AddSprite("no_texture", QPixmap(":/resources/Textures/tiles/z_no_texture.bmp"), this->tiles); // do not work
    this->tiles[0] = QPixmap(":/Tiles/Textures/tiles/missing_texture.png"); // do not work too
}

ResourceManager *ResourceManager::CreateManager()
{
     if (RM == nullptr) RM = new ResourceManager();
     return RM;
}

void ResourceManager::DeleteManager()
{
    if (RM == nullptr)
    {
        delete RM;
        RM = nullptr;
    }
}

void ResourceManager::AddSprite(int id, QPixmap &pixmap, std::vector<QPixmap> &storage)
{
    storage[id] = pixmap;
}

QPixmap ResourceManager::GetSprite(int id, std::vector<QPixmap> &storage)
{
    return storage[id];
}

bool ResourceManager::IsExist(int id, std::vector<QPixmap> &storage)
{
    //if(storage[id] == )
    return 0;
}

ResourceManager::~ResourceManager()
{
    this->tiles.clear();
}

/*void ResourceManager::AddSprite(std::string key, QPixmap &pixmap, std::map<std::string, QPixmap> &storage)
{
    if(!IsExist(key, storage)) storage[key] = pixmap;
}

QPixmap ResourceManager::GetSprite(std::string key, std::map<std::string, QPixmap> &storage)
{
    if(IsExist(key, storage)) return storage[key];
    else throw 1;
}

bool ResourceManager::IsExist(std::string key, std::map<std::string, QPixmap> &storage)
{
    auto exist = storage.find(key);
    return exist != storage.end();
}// */
