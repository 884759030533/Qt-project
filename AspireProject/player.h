#ifndef PLAYER_H
#define PLAYER_H

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
    pMoveState pState;



public:
    Player(pPosition pos, int maxHealth, int height = 120, int width = 40);
    void Draw();
    void Move();
    void Jump();

};

#endif // PLAYER_H
