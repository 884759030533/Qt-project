#include "tile.h"

Tile::Tile(long X, long Y, long Z)
{

}

Tile::Tile(tPosition Pos)
{

}

Tile::Tile(long X, long Y, long Z, unsigned int Height, unsigned int Width, bool Solid, QPixmap &Image)
{

}

Tile::Tile(tPosition Pos, tSize Size, int ID)
{
    this->pos = Pos;
    this->size = Size;
    this->ID = ID;
}

Tile::~Tile()
{

}

void Tile::Draw()
{

}

void Tile::Move(tPosition destination, int speed)
{

}

void Tile::Move(tPosition destination, moveFunction moveFunction)
{

}


void AnimatedTile::Draw()
{

}

void Slope::Draw()
{

}
