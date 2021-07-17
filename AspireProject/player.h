#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <math.h>
#include "tile.h"
#include "gamerender.h"
#include "resourcemanager.h"

struct pPosition
{
    long x;
    long y;
    pPosition() : x(0), y(0) {};
    pPosition(long X, long Y) : x(X), y(Y) {};
};
struct pMoveState
{
    bool moveLeft;
    bool moveRight;
    bool onGround;
    bool canJump;
    bool moveUp;
    bool moveDown;
    bool isSprint;
    bool isCrouch;
    bool canMove;
    /* ... */
    pMoveState() : moveLeft(false), moveRight(false), onGround(false),
                   canJump(true), moveUp(false), moveDown(true), isSprint(false),
                   isCrouch(false), canMove(true) {};
};
struct pSpriteList
{
    std::string spriteIdle;
    std::string spriteWalk;
    std::string spriteSprint;
    std::string spriteJump;
    std::string sptiteInAir;
    std::string spriteCrouch;
    std::string spriteCrowl;
    /* ... */
};

class Player
{
private:
    pPosition pos;
    double velocityH;
    double velocityV;
    int maxHealth; //player's max health
    int health; //current player's health
    int height; //height of player's hitbox in pixels
    int width; //width of player's hitbox in pixels
    //int baseMeleeDamage;
    pSpriteList sprite; //player sprite list

    ResourceManager *manager;
    std::vector<Tile> *map;


public:
    Player(pPosition pos, int maxHealth = 1000, int height = 70, int width = 26);
    //void Draw();
    void Move(QPixmap *canv);
    void Jump();
    pPosition getPos() { return pos; }
    int getHeight() { return height; }
    int getWidth() { return width; }

    void increaseVelocity();
    void decreaseVelocity();
    void increaseVelocityLeft();
    void increaseVelocityRight();
    void decreaseVelocityHorizontalToZero();
    void decreaseVelocityUp();
    void increaseVelocityDown();
    void decreaseVelocityVerticalToZero();
    double getVelocityHorizontal() { return velocityH; }
    double getVelocityVertical() { return velocityV; }
    pMoveState getMoveState() { return state; }
    pMoveState state;

};

#endif // PLAYER_H
