#include "player.h"

Player::Player(pPosition pos, int maxHealth, int height, int width)
{
    this->pos = pos;
    this->velocity = 0.0;
    this->maxHealth = maxHealth;
    this->health = maxHealth;
    this->height = height;
    this->width = width;
    this->pState = pMoveState();
}
