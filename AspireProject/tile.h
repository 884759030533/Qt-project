#ifndef TILE_H
#define TILE_H

#include <string>
#include <QPainter>
#include <QMovie>

struct tPosition //tile position in grid
{
    long x;
    long y;
    long z;
    short layer;
    tPosition(): x(0), y(0), z(0) {};
    tPosition(long X, long Y): x(X), y(Y), z(0), layer(1) {};
    tPosition(long X, long Y, long Z): x(X), y(Y), z(Z), layer(1) {};
    tPosition(long X, long Y, long Z, short Layer): x(X), y(Y), z(Z), layer(Layer) {};

};
struct tSize //size of a tile (for proper texture positioning)
{
    unsigned int height;
    unsigned int width;
    tSize(): height(40), width(10) {};
    tSize(unsigned int Height, unsigned int Width): height(Height), width(Width) {};
};
struct ImageType {}; //need image type
struct GifType {}; //need gif-image type
typedef int (*moveFunction)(tPosition, int);

class Tile
{
private:
    tPosition pos;
    tSize size;
    //QPixmap img;
    int ID;
protected:
    bool solid; // can player collide with current tile
    bool dealDamage;
    int damage;
public:
    Tile(long x, long y, long z); //quick spawn tile
    Tile(tPosition pos); //quick spawn tile
    Tile(long x, long y, long z, unsigned int height, unsigned int width, bool isSolid/*, QPixmap &image*/); //spawns regular tile
    Tile(tPosition pos, tSize size, int ID); //spawns regular tile
    ~Tile();
    virtual void Draw();
    void Move(tPosition destination, int speed); //simple tile move
    void Move(tPosition destination, moveFunction moveFunction); //moving tile with different move animation
    tPosition getPos() { return pos; }
    tSize getSize() { return size; }
    int getID() { return ID; }

};

class AnimatedTile : public Tile
{
private:
    QMovie gif;
public:
    AnimatedTile(tPosition pos, tSize size, int id) : Tile(pos, size, id)
    {
        //this->gif = gif;
    }
    AnimatedTile(tPosition pos, tSize size,  bool isSolid, int id) : Tile(pos, size, id)
    {
        //this->gif = gif;
        this->solid = isSolid;
    }
    void Draw();

};

class Slope : public Tile
{
private:
    short slopeType;
public:
    Slope(tPosition pos, tSize size, short slopeType, int id) : Tile(pos, size, id)
    {
        this->slopeType = slopeType;
    }
    void Draw();

};

#endif // TILE_H
