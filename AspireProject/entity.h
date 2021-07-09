#ifndef ENTITY_H
#define ENTITY_H

struct ePosition
{
    long x;
    long y;
    ePosition() : x(0), y(0) {};
    ePosition(long X, long Y) : x(X), y(Y) {};
};

class Entity
{
private:
    ePosition pos;
    double velocity;

    int health;
public:
    Entity();
};

#endif // ENTITY_H
