#include "player.h"

double velocityHorizontalIncrease = 1.15;
double velocityWalkUpLim = 10.0;


Player::Player(pPosition pos, int maxHealth, int height, int width)
{
    this->pos = pos;
    this->velocityH = 0.0;
    //this->velocityV = 0.0;
    this->maxHealth = maxHealth;
    this->health = maxHealth;
    this->height = height;
    this->width = width;
    this->State = pMoveState();

    manager = ResourceManager::CreateManager();
    map = &manager->GetWorldMap();
}

void Player::Move()
{


    //int i = 0;
    for (unsigned long long tile = 0; tile < manager->GetWorldMap().size(); tile++)
    {
        if (manager->GetWorldMap()[tile].getProperties().solid)
        {
            if (pos.y >= manager->GetWorldMap()[tile].getPos().y*40)
            {
                //pos.y += 1;
            }
            else
            {
                //pos.y = manager->GetWorldMap()[tile].getPos().y;
                State.onGround = true;
            }
            // if hit wall to the left
            if ((pos.x - width/2) + velocityH < manager->GetWorldMap()[tile].getPos().x*40 + manager->GetWorldMap()[tile].getSize().width)
            {
                //State.moveLeft = false;
            }
            // if hit the wall to the right
            if ((pos.x + width/2) + velocityH > manager->GetWorldMap()[tile].getPos().x*40)
            {
                //State.moveRight = false;
            }
            if (State.onGround && pos.y <= manager->GetWorldMap()[tile].getPos().y*40)
            {
                State.onGround = false;
            }
        }
    }

    if (State.moveLeft || State.moveRight)
    {
        if (State.moveRight)
        {
            increaseVelocityRight();
        }
        else if (State.moveLeft)
        {
            increaseVelocityLeft();
        }
        pos.x += velocityH;
    }
    else
    {
        pos.x += velocityH;
        decreaseVelocityToZero();
    }




//    if (!State.onGround)
//    {
//        pos.y -= 10;
//    }



//        for (unsigned long long tile = 0; tile < manager->GetWorldMap().size(); tile++)
//        {
//            if (manager->GetWorldMap()[tile].getProperties().solid)
//            {
//                if (pos.y >= manager->GetWorldMap()[tile].getPos().y)
//                {
//                    if ((pos.x + width/2) + velocity < manager->GetWorldMap()[tile].getPos().x)
//                    {
//                        pos.x += velocity;
//                    }
//                    else
//                    {
//                        pos.x = manager->GetWorldMap()[tile].getPos().x;
//                        State.moveRight = false;
//                    }
//                    if ((pos.x - width/2) - velocity > manager->GetWorldMap()[tile].getPos().x + manager->GetWorldMap()[tile].getSize().width)
//                    {
//                        pos.x -= velocity;
//                    }
//                    else
//                    {
//                        pos.x = manager->GetWorldMap()[tile].getPos().x;
//                        State.moveLeft = false;
//                    }

//                }
//                if ((pos.y - height < pos.y) >= manager->GetWorldMap()[tile].getPos().y - manager->GetWorldMap()[tile].getSize().height)
//                {

//                }

//            }
//        }




}

void Player::Jump()
{
//    if (pos.y >= manager->GetWorldMap()[tile].getPos().y)
//    {

//    }
//    if (pos.y - height < pos.y >= manager->GetWorldMap()[tile].getPos().y - manager->GetWorldMap()[tile].getSize().height)
//    {

//    }

}

void Player::increaseVelocity()
{
    if (velocityH < 1) velocityH = 2.5;
    if (velocityH < 20.0)
    {
        velocityH = velocityH * velocityHorizontalIncrease;
    }
}

void Player::decreaseVelocity()
{
    if (velocityH < 1) velocityH = 0.0;
    else velocityH /= velocityHorizontalIncrease;
}
////==========================
void Player::increaseVelocityLeft()
{
    if (velocityH > -1) velocityH = -1.5;
    else if (velocityH > -velocityWalkUpLim)
    {
        velocityH = velocityH * velocityHorizontalIncrease;
    }
}
void Player::increaseVelocityRight()
{
    if (velocityH < 1) velocityH = 1.5;
    else if (velocityH < velocityWalkUpLim)
    {
        velocityH = velocityH * velocityHorizontalIncrease;
    }
}
void Player::decreaseVelocityToZero()
{
    if (velocityH*velocityH > 0.125) velocityH /= velocityHorizontalIncrease+0.05;
    else velocityH = 0;
}

