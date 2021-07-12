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
    tPosition(long X, long Y): x(X), y(Y), z(0), layer(0) {};
    tPosition(long X, long Y, long Z): x(X), y(Y), z(Z), layer(0) {};
    tPosition(long X, long Y, long Z, short Layer): x(X), y(Y), z(Z), layer(Layer) {};

};
struct tSize //size of a tile (for proper texture positioning)
{
    unsigned int height;
    unsigned int width;
    tSize(): height(40), width(40) {};
    tSize(unsigned int Height, unsigned int Width): height(Height), width(Width) {};
};
struct tProperties
{
    bool isVisible; // for render optimization
    bool solid; // can player collide with current tile
    bool dealDamage; // do tile deal damage
    int damage;

    tProperties(bool IsVisible = false,
                bool Solid = true,
                bool DealDamage = false,
                int Damage = 0) : isVisible(IsVisible), solid(Solid), dealDamage(DealDamage), damage(Damage) {}
};

typedef int (*moveFunction)(tPosition, int);

class Tile
{
private:
    tPosition pos;
    tSize size;
    //QPixmap img;
    int ID;
protected:
    tProperties properties;
public:
    Tile(tPosition pos = tPosition(), tSize size = tSize(), int ID = 1); //default spawn tile
    Tile(tPosition pos, tSize size, int ID, tProperties properties); //spawns regular tile
    ~Tile();
    virtual void Draw();
    void Move(tPosition destination, int speed); //simple tile move
    void Move(tPosition destination, moveFunction moveFunction); //moving tile with different move animation
    tPosition getPos() { return pos; }
    tSize getSize() { return size; }
    int getID() { return ID; }
    tProperties getProperties() { return properties; }
    void setVisible(bool isVisible) { this->properties.isVisible = isVisible; }
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
        this->properties.solid = isSolid;
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
