#include "resourcemanager.h"

ResourceManager* ResourceManager::RM = nullptr;

ResourceManager::ResourceManager()
{
    this->tiles.resize(32767);
    this->map.resize(32767);
    MM[0] = &mapBot;
    MM[1] = &mapMid;
    MM[2] = &mapTop;
    /* Loading an entire library of sprites with a lots of code ... */

    /* Loading map from file to memory */
    for (int i =0; i<10; i++) for (int j =0; j<10; j++) map[i+j*10] = Tile(tPosition(i, j, 1),tSize(40, 40), 1);


    map[32] = Tile(tPosition(2, 3, 1),tSize(40, 40), 1, tProperties(true));
    map[35] = Tile(tPosition(5, 3, 1),tSize(40, 40), 1, tProperties(true));
    map[53] = Tile(tPosition(3, 5, 1),tSize(40, 40), 1, tProperties(true));
    map[54] = Tile(tPosition(4, 5, 1),tSize(40, 40), 1, tProperties(true));
    map[55] = Tile(tPosition(4, 6, 1),tSize(40, 40), 1, tProperties(true));
    map[64] = Tile(tPosition(5, 5, 1),tSize(40, 40), 1, tProperties(true));
    map[65] = Tile(tPosition(5, 6, 1, 1),tSize(40, 40), 1, tProperties(true));
    map[66] = Tile(tPosition(5, 6, 1, -1),tSize(40, 40), 2, tProperties(true));



    /* Sorting for better use */
    for (int tile = 0; tile < map.size(); tile++)
    {
        switch (map[tile].getPos().layer)
        {
        case -1: //bottom layer
            mapBot.push_back(map[tile]);
            break;
        case 0: //middle layer
            mapMid.push_back(map[tile]);
            break;
        case 1: //top layer
            mapTop.push_back(map[tile]);
            break;
        }

    }



    //AddSprite("no_texture", QPixmap(":/resources/Textures/tiles/z_no_texture.bmp"), this->tiles);
    this->tiles[0] = QPixmap(":/Tiles/Textures/tiles/Air_0.png"); // air
    this->tiles[1] = QPixmap(":/Tiles/Textures/tiles/missing_texture.png"); // missing texture
    this->tiles[2] = QPixmap(":/Tiles/Textures/tiles/clouds.png"); // blue missing texture
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
