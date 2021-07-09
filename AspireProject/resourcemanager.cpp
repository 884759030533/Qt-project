#include "resourcemanager.h"

ResourceManager::ResourceManager()
{
    /* Loading an entire library of sprites with a lots of code ... */

    //AddSprite("no_texture", QPixmap(":/resources/Textures/tiles/z_no_texture.bmp"), this->tiles); // do not work
    this->tiles["no_texture"] = QPixmap(":/resources/Textures/tiles/z_no_texture.bmp"); // do not work too
}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::AddSprite(std::string key, QPixmap pixmap, std::map<std::string, QPixmap> storage)
{
    if(!IsExist(key, storage)) storage[key] = pixmap;
}

QPixmap ResourceManager::GetSprite(std::string key, std::map<std::string, QPixmap> storage)
{
    if(IsExist(key, storage)) return storage[key];
    else throw 1;
}

bool ResourceManager::IsExist(std::string key, std::map<std::string, QPixmap> storage)
{
    auto exist = storage.find(key);
    return exist != storage.end();
}
