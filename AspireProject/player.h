#ifndef PLAYER_H
#define PLAYER_H

#include <string>

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
    bool isSprint;
    bool isCrouch;
    /* ... */
    pMoveState() : moveLeft(false), moveRight(false), onGround(true), isSprint(false), isCrouch(false) {};
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
    double velocity;
    int maxHealth; //player's max health
    int health; //current player's health
    int height; //height of player's hitbox in pixels
    int width; //width of player's hitbox in pixels
    //int baseMeleeDamage;
    pMoveState State;
    pSpriteList sprite; //player sprite list


public:
    Player(pPosition pos, int maxHealth, int height = 120, int width = 40);
    void Draw();
    void Move();
    void Jump();

};

#endif // PLAYER_H
