#include "tile.h"


Tile::Tile(tPosition pos, tSize size, int ID)
{
    this->pos = pos;
    this->size = size;
    this->ID = ID;
    this->properties.damage = 0;
    this->properties.dealDamage = false;
    this->properties.isVisible = false;
    this->properties.solid = true;
}

Tile::Tile(tPosition pos, tSize size, int ID, tProperties properties)
{
    this->pos = pos;
    this->size = size;
    this->ID = ID;
    this->properties = properties;
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
