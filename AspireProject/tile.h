#ifndef TILE_H
#define TILE_H

struct tPosition //tile position in grid
{
    long x;
    long y;
    long z;
    tPosition(): x(0), y(0), z(0) {};
    tPosition(long X, long Y, long Z): x(X), y(Y), z(Z) {};
};
struct tileSize //size of a tile (for proper texture positioning)
{
    unsigned int height;
    unsigned int width;
    tileSize(): height(10), width(10) {};
    tileSize(unsigned int Height, unsigned int Width): height(Height), width(Width) {};
};
struct ImageType {};

class Tile
{
private:
    tPosition pos;
    int layer;
    bool solid; // can player collide with current tile
    tileSize size;
    ImageType img;

public:
    Tile(long X, long Y, long Z); //quick spawn tile
    Tile(tPosition Pos); //quick spawn tile
    Tile(long X, long Y, long Z, unsigned int Height, unsigned int Width, bool Solid, ImageType Image); //spawns regular tile
    Tile(tPosition Pos, tileSize Size); //spawns regular tile
    ~Tile();

};

#endif // TILE_H
