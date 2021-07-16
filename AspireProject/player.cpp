#include "player.h"

double velocityHorizontalIncrease = 1.15;
double velocityVerticalIncrease = 1.20;
double velocityWalkLim = 10.0;
double velocityFallLim = 30.0;

int checkboxRadius = 240;
//Tile tempTile;


Player::Player(pPosition pos, int maxHealth, int height, int width)
{
    this->pos = pos;
    this->velocityH = 0.0;
    this->velocityV = 0.0;
    this->maxHealth = maxHealth;
    this->health = maxHealth;
    this->height = height;
    this->width = width;
    this->state = pMoveState();

    manager = ResourceManager::CreateManager();
    map = &manager->GetWorldMap();
}

void Player::Move()
{
    long currentTileX = 0;
    long currentTileY = 0;
    // take each tile
    for (unsigned long long tile = 0; tile < manager->GetWorldMap().size(); tile++)
    {
        currentTileX = manager->GetWorldMap()[tile].getPos().x * 40;
        currentTileY = manager->GetWorldMap()[tile].getPos().y * 40;

        // is current tile in check square distance from player
        if ((currentTileX - pos.x < checkboxRadius) && (currentTileY - pos.y < checkboxRadius))
        {
            // is current tile is solid
            if (manager->GetWorldMap()[tile].getProperties().solid)
            {
                // is current tile is under the player
                if (pos.x - currentTileX < manager->GetWorldMap()[tile].getSize().width)
                {
                    // is player above current tile
                    if (pos.y >= currentTileY)
                    {
                        // if player gonna go through tile
                        if (pos.y + velocityV > currentTileY)
                        {
                            /// player touch the ground
                            state.moveDown = false;
                            state.onGround = true;
                            state.canJump = true;
                            //pos.y = currentTileY;
                            velocityV = 0.0;
                        }

                        // is height from player to tile less than tile height
                        if (pos.y - currentTileY < manager->GetWorldMap()[tile].getSize().height)
                        {
                            // is player falling
                            if (state.moveDown)
                            {

                            }
                        }
                    }
//                    else if (pos.y - height < currentTileY + manager->GetWorldMap()[tile].getSize().height)
//                    {

//                    }

//                    else if ((pos.y - height > currentTileY + manager->GetWorldMap()[tile].getSize().height) || pos.y < currentTileY)
//                    {
//                        if (pos.x + width/2 + velocityH > currentTileX)
//                        {
//                            state.moveRight = false;
//                            velocityH = 0.0;
//                            //pos.x = currentTileX - width/2;
//                        }
//                        else if (pos.x - width/2 + velocityH < currentTileX + manager->GetWorldMap()[tile].getSize().width)
//                        {
//                            state.moveLeft = false;
//                            velocityH = 0.0;
//                            //pos.x = currentTileX + width/2 + manager->GetWorldMap()[tile].getSize().width;
//                        }
//                        else
//                        {
//                        }
//                    }

//                    if (pos.x + width/2 < currentTileX + velocityH || pos.x - width/2 + velocityH > currentTileX + manager->GetWorldMap()[tile].getSize().width)
//                    {

//                    }



                }
                // is current tile on the same height as player
                if (pos.y > currentTileY && pos.y < currentTileY + manager->GetWorldMap()[tile].getSize().height)
                {
                    if (pos.x + velocityH > currentTileX)
                    {
                        state.moveRight = false;
                        velocityH = 0.0;
                        pos.x = currentTileX - width/2;
                    }
                    if (pos.x + velocityH < currentTileX + manager->GetWorldMap()[tile].getSize().width)
                    {
                        state.moveLeft = false;
                        velocityH = 0.0;
                        pos.x = currentTileX + width/2 + manager->GetWorldMap()[tile].getSize().width;
                    }
                }
//                if (pos.y - currentTileY < manager->GetWorldMap()[tile].getSize().height)
//                {
//                    if (pos.x + velocityH > currentTileX)
//                    {
//                        state.moveRight = false;
//                        velocityH = 0.0;
//                        //pos.x = currentTileX - width/2;
//                    }
//                    if (pos.x + velocityH < currentTileX + manager->GetWorldMap()[tile].getSize().width)
//                    {
//                        state.moveLeft = false;
//                        velocityH = 0.0;
//                        //pos.x = currentTileX + width/2 + manager->GetWorldMap()[tile].getSize().width;
//                    }
//                }


                ////// ========================
//                if (pos.y < currentTileY)
//                {
//                    if (pos.x + width/2 + velocityH > currentTileX)
//                    {
//                        state.moveRight = false;
//                        velocityH = 0.0;
//                        //pos.x = currentTileX - width/2;
//                    }
//                    else if (pos.x - width/2 + velocityH < currentTileX + manager->GetWorldMap()[tile].getSize().width)
//                    {
//                        state.moveLeft = false;
//                        velocityH = 0.0;
//                        //pos.x = currentTileX + width/2 + manager->GetWorldMap()[tile].getSize().width;
//                    }
//                    else
//                    {
//                    }
//                }


//                if (pos.y >= manager->GetWorldMap()[tile].getPos().y*40)
//                {
//                    state.onGround = false;
//                }
//                else if (pos.y <= manager->GetWorldMap()[tile].getPos().y*40 + manager->GetWorldMap()[tile].getSize().height)
//                {
//                    state.moveUp = false;
//                }
//                else
//                {
//                    if (!state.onGround)
//                    {
//                        state.onGround = true;
//                        pos.y = manager->GetWorldMap()[tile].getPos().y;
//                        velocityV = 0.0;
//                    }
//                    state.onGround = true;
//                }
//                // if hit wall to the left
//                if ((pos.x - width/2) + velocityH < manager->GetWorldMap()[tile].getPos().x*40 + manager->GetWorldMap()[tile].getSize().width)
//                {
//                    //state.moveLeft = false;
//                }
//                // if hit the wall to the right
//                if ((pos.x + width/2) + velocityH > manager->GetWorldMap()[tile].getPos().x*40)
//                {
//                    //state.moveRight = false;
//                }
//                if (pos.y <= manager->GetWorldMap()[tile].getPos().y*40)
//                {
//                    //state.onGround = false;
//                }
            }
//            if ((pos.y - height > currentTileY + manager->GetWorldMap()[tile].getSize().height) || pos.y < currentTileY)
//            {
//                if (pos.x + width/2 + velocityH > currentTileX)
//                {
//                    state.moveRight = false;
//                    velocityH = 0.0;
//                    //pos.x = currentTileX - width/2;
//                }
//                else if (pos.x - width/2 + velocityH < currentTileX + manager->GetWorldMap()[tile].getSize().width)
//                {
//                    state.moveLeft = false;
//                    velocityH = 0.0;
//                    //pos.x = currentTileX + width/2 + manager->GetWorldMap()[tile].getSize().width;
//                }
//                else
//                {
//                }
//            }
        }
    }
    //// Jump state
    if (!state.onGround)
    {
        if (state.moveUp || state.moveDown)
        {
            if (state.moveUp)
            {
                decreaseVelocityUp();
            }
            else if (state.moveDown)
            {
                increaseVelocityDown();
            }
            pos.y += velocityV;
        }
        else
        {
            pos.y += velocityV;
            //decreaseVelocityHorizontalToZero();
        }
    }
    else
    {
        state.moveDown = false;
        velocityV = 0.0;
    }

    //// Walking state
    if (state.moveLeft || state.moveRight)
    {
        if (state.moveRight)
        {
            increaseVelocityRight();
        }
        else if (state.moveLeft)
        {
            increaseVelocityLeft();
        }
        pos.x += velocityH;
    }
    else
    {
        pos.x += velocityH;
        decreaseVelocityHorizontalToZero();
    }
}

void Player::Jump()
{
    velocityV = -40.0;
    state.onGround = false;
    state.moveUp = true;
    state.canJump = false;

}

void Player::increaseVelocityLeft()
{
    if (velocityH > -1) velocityH = -1.5;
    else if (velocityH > -velocityWalkLim)
    {
        velocityH = velocityH * velocityHorizontalIncrease;
    }
}
void Player::increaseVelocityRight()
{
    if (velocityH < 1) velocityH = 1.5;
    else if (velocityH < velocityWalkLim)
    {
        velocityH = velocityH * velocityHorizontalIncrease;
    }
}
void Player::decreaseVelocityHorizontalToZero()
{
    if (velocityH*velocityH > 0.25) velocityH /= velocityHorizontalIncrease + 0.05;
    else velocityH = 0;
}
////==========================
void Player::decreaseVelocityUp()
{
    if (velocityV*velocityV > 1.3)
    {
        velocityV /= velocityVerticalIncrease;
    }
    else
    {
        velocityV = 0;
        state.moveUp = false;
        state.moveDown = true;
    }
}
void Player::increaseVelocityDown()
{
    if (velocityV < 1) velocityV = 1.3;
    if (velocityV < velocityFallLim)
    {
        velocityV = velocityV * velocityVerticalIncrease-0.09;
    }
}

