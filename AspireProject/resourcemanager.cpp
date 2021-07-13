#include "resourcemanager.h"

ResourceManager* ResourceManager::RM = nullptr;

ResourceManager::ResourceManager()
{
    this->tiles.resize(32767);
    this->map.resize(32767);
    /* Loading an entire library of sprites with a lots of code ... */

    /* Loading map from file to memory */
    //for (int i =0; i<10; i++) for (int j =0; j<10; j++) map[i+j*10] = Tile(tPosition(i, j, 1),tSize(40, 40), 1);
    for (int i = 0; i<40; i++) map[i] = Tile(tPosition(i,1,0), tSize(), i, tProperties(true));

    map[32] = Tile(tPosition(2, 3, 0),tSize(40, 40), 1, tProperties(true));
    map[35] = Tile(tPosition(5, 3, 0),tSize(40, 40), 1, tProperties(true));
    map[53] = Tile(tPosition(3, 5, 0),tSize(40, 40), 1, tProperties(true));
    map[54] = Tile(tPosition(4, 5, 0),tSize(40, 40), 1, tProperties(true));
    map[55] = Tile(tPosition(4, 6, 0),tSize(40, 40), 1, tProperties(true));
    map[64] = Tile(tPosition(5, 5, 0),tSize(40, 40), 1, tProperties(true));
    map[65] = Tile(tPosition(5, 6, 1, 0),tSize(40, 40), 1, tProperties(true));
    map[66] = Tile(tPosition(5, 6, -2, 0),tSize(40, 40), 2, tProperties(true));



    /* Sorting for better use */
    /*for (unsigned long long tile = 0; tile < map.size(); tile++)
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
    } // */
    std::string tileType[] = {"air",
                              "z_missing_texture",
                              "void",
                              "blue_stone",
                              "dark_blue_stone",
                              "moss"};
    std::string tileMod[]  = {"",
                              "transfer",
                              "inner_corner",
                              "outer_corner"};


    tiles[0] = QPixmap(":/Tiles/Textures/tiles/air.png"); // air
    tiles[1] = QPixmap(":/Tiles/Textures/tiles/z_missing_texture.png"); // missing texture
    tiles[2] = QPixmap(":/Tiles/Textures/tiles/z_clouds.png"); // blue missing texture
    int _tileCount = 0;
    for (int _tileType = 0; _tileType < 30; _tileType++)
    {
        for(int _tileMod = 0; _tileMod < 30; _tileMod++)
        {
            //std::string filepath = ":/Tiles/Textures/tiles/"+tileType[_tileType]+"_"+tileMod[_tileMod]+".png";
            //tiles[_tileCount] = QPixmap(filepath.c_str()); // program terminate after "std::bad_alloc"
            if (tiles[_tileCount].isNull()) continue;
            else _tileCount++;
        }
        _tileCount++;
    }



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
