#include "resourcemanager.h"

ResourceManager* ResourceManager::RM = nullptr;

ResourceManager::ResourceManager()
{
    this->tiles.resize(256);
    this->map.resize(2048);
    /* Loading an entire library of sprites with a lots of code ... */

    /* Loading map from file to memory */
    //for (int i =0; i<10; i++) for (int j =0; j<10; j++) map[i+j*10] = Tile(tPosition(i, j, 1),tSize(40, 40), 1);
    for (int i = 0; i<40; i++) map[i+1000] = Tile(tPosition(i,16,0), tSize(), i, tProperties(true));

    map[1045] = Tile(tPosition(2, 18, 0),tSize(40, 40), 1, tProperties(true));
    map[1046] = Tile(tPosition(5, 18, 0),tSize(40, 40), 1, tProperties(true));
    map[1047] = Tile(tPosition(3, 20, 0),tSize(40, 40), 1, tProperties(true));
    map[1048] = Tile(tPosition(4, 20, 0),tSize(40, 40), 1, tProperties(true));
    map[1049] = Tile(tPosition(4, 21, 0),tSize(40, 40), 1, tProperties(true));
    map[1050] = Tile(tPosition(5, 20, 0),tSize(40, 40), 1, tProperties(true));
    map[1051] = Tile(tPosition(5, 21, 1, 1),tSize(40, 40), 12, tProperties(true, true, 1));
    map[1052] = Tile(tPosition(5, 21, -2, 0),tSize(40, 40), 2, tProperties(true));

    //Tile tempTile(tPosition(0,0,0,0),tSize(0,0),1,tProperties());

    tPosition tempTilePos;
    tSize tempTileSize;
    int ID = 1;
    tProperties tempTileProp;
    std::string saveFilename = ":/Level Data/Files/levels/testlevel.level";
    std::fstream afile("F:\\Qt projects\\Qt-project\\AspireProject\\Files\\levels\\testlevel.level"); // file do not open
    if(!afile) qDebug() << "file do not open";
    else qDebug() << "file open succesfull";

    QFile file(":/Level Data/Files/levels/testlevel.level");
    if (file.isOpen()) qDebug() << "qfile open succesfull";
    else qDebug() << "qfile do not open";

    // cannot read data from file


    for (int levelTile = 0; levelTile < 1/*file.eof()*/; levelTile++)
    {
//        file >> tempTilePos.x;
//        qDebug() << tempTilePos.x;
//        file >> tempTilePos.y;
//        qDebug() << tempTilePos.y;
//        file >> tempTilePos.z;
//        qDebug() << tempTilePos.z;
//        file >> tempTilePos.layer;
//        qDebug() << tempTilePos.layer;
//        file >> tempTileSize.height;
//        qDebug() <<  tempTileSize.height;
//        file >> tempTileSize.width;
//        qDebug() << tempTileSize.width;
//        file >> ID;
//        qDebug() << ID;
//        file >> tempTileProp.isVisible;
//        qDebug() << tempTileProp.isVisible;
//        file >> tempTileProp.solid;
//        qDebug() << tempTileProp.solid;
//        file >> tempTileProp.dealDamage;
//        qDebug() << tempTileProp.dealDamage;
//        if (tempTileProp.dealDamage) file >> tempTileProp.damage;

        map[levelTile] = Tile(tempTilePos, tempTileSize, ID, tempTileProp);
    }

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
    QString tileType[] = {"air",
                          "z_missing_texture",
                          "void",
                          "blue_stone",
                          "blue_stone_moss",
                          "dark_blue_stone",
                          "blackstone"};
    QString tileMod[]  = {"",
                          "_transfer",
                          "_inner_corner",
                          "_outer_corner"};


    tiles[0] = QPixmap(":/Tiles/Textures/tiles/air.png"); // air
    tiles[1] = QPixmap(":/Tiles/Textures/tiles/z_missing_texture.png"); // missing texture
    tiles[2] = QPixmap(":/Tiles/Textures/tiles/z_clouds.png"); // blue missing texture
    int _tileCount = 0;
    for (int _tileType = 0; _tileType < 7; _tileType++)
    {
        for(int _tileMod = 0; _tileMod < 4; _tileMod++)
        {
            for (int _tileVar = 0; _tileVar <=4; _tileVar++)
            {
                QString filepath = QString(":/Tiles/Textures/tiles/")+tileType[_tileType]+tileMod[_tileMod];
                if (_tileVar) filepath += QString("_%1").arg(_tileVar);
                filepath += ".png";
                //qDebug() << filepath;
                tiles[_tileCount] = QPixmap(filepath); // program terminate after "std::bad_alloc"
                if (tiles[_tileCount].isNull()) continue;
                else
                {
                    qDebug() << "ID" << _tileCount << filepath;
                    _tileCount++;
                }
            }
        }
        if (tiles[_tileCount].isNull()) continue;
        else _tileCount++;
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
