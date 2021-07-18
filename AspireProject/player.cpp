#include "player.h"

double velocityHorizontalIncrease = 1.18;
double velocityVerticalIncrease = 1.13;
double velocityWalkLim = 7.1;
double velocityFallLim = 17.9;
double jumpStartVelocity = 13.5;

int checkboxRadius = 320;

bool debugMode = false;


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
void debugBox(QBrush * br, QPen * pen, QPainter * p, QColor bnd, QColor fill)
{
    br->setColor(fill);
    br->setStyle(Qt::BrushStyle::SolidPattern);
    pen->setColor(bnd);
    p->setBrush(*br);
    p->setPen(*pen);
}

void Player::Move(QPixmap *debugCanvas, bool DebugMode)
{
    debugMode = DebugMode;
    GameRender *g;
    QPainter p;
    QBrush brush;
    QPen pen;
    if (debugMode) { g = GameRender::CreateGameRender(); p.begin(debugCanvas); }

    //canv->fill(Qt::transparent);

    //long currentTileX = 0;
    //long currentTileY = 0;
    // take each tile
    for (unsigned long long tile = 0; tile < manager->GetWorldMap().size(); tile++)
    {
        long currentTileX = manager->GetWorldMap()[tile].getPos().x * 40;
        long currentTileY = manager->GetWorldMap()[tile].getPos().y * 40;
        int currentTileHeight = manager->GetWorldMap()[tile].getSize().height;
        int currentTileWidth = manager->GetWorldMap()[tile].getSize().width;

        // is current tile in check square distance from player
        if ((currentTileX - pos.x < checkboxRadius) && (currentTileY - pos.y < checkboxRadius) && (pos.x - currentTileX-currentTileWidth < checkboxRadius) && (pos.y - currentTileY-currentTileHeight < checkboxRadius))
        {
            // is current tile is solid
            if (manager->GetWorldMap()[tile].getProperties().solid)
            {
                if (debugMode) { debugBox(&brush, &pen, &p, QColor(0, 255, 255, 180), QColor(0, 255, 255, 40)); p.drawRect(currentTileX - g->GetCamPos().x, currentTileY - g->GetCamPos().y, currentTileWidth, currentTileHeight);}

                // searching for tiles has the same Y as player
                if (pos.y - currentTileY > 0 && pos.y - height - currentTileY - currentTileHeight < 0)
                {
                    if (debugMode) {debugBox(&brush, &pen, &p, QColor(180, 255, 0, 180), QColor(180, 255, 0, 40)); p.drawRect(currentTileX - g->GetCamPos().x, currentTileY - g->GetCamPos().y, currentTileWidth, currentTileHeight);}

                    // is player to the left from current tile
                    if (pos.x >= currentTileX + currentTileWidth)
                    {
                        // if player is about to collide with left wall
                        if (pos.x-1 - width/2 + velocityH <= currentTileX + currentTileWidth)
                        {
                            if (debugMode) {debugBox(&brush, &pen, &p, QColor(255, 70, 0, 180), QColor(255, 70, 0, 40)); p.drawRect(currentTileX - g->GetCamPos().x, currentTileY - g->GetCamPos().y, currentTileWidth, currentTileHeight);}

                            state.moveLeft = false;
                            //state.canMove = false;
                            velocityH = 0.0;
                            pos.x = currentTileX + currentTileWidth + width/2 + 1;
                        }
                    }
                    // is player to the right from current tile
                    else if (pos.x <= currentTileX)
                    {

                        // if player about to collide with right wall
                        if (pos.x+1 + width/2 + velocityH >= currentTileX)
                        {
                            if (debugMode) {debugBox(&brush, &pen, &p, QColor(255, 70, 0, 180), QColor(255, 70, 0, 40)); p.drawRect(currentTileX - g->GetCamPos().x, currentTileY - g->GetCamPos().y, currentTileWidth, currentTileHeight);}

                            state.moveRight = false;
                            //state.canMove = false;
                            velocityH = 0.0;
                            pos.x = currentTileX - width/2 - 1;
                        }
                    }
                }
                // searching for tiles has the same X as player
                if (pos.x - width/2 - currentTileX <= currentTileWidth && pos.x + width/2 - currentTileX >= 0)
                {
                    if (debugMode) {debugBox(&brush, &pen, &p, QColor(0, 60, 255, 180), QColor(0, 60, 255, 40)); p.drawRect(currentTileX - g->GetCamPos().x, currentTileY - g->GetCamPos().y, currentTileWidth, currentTileHeight);}


                    // is player above current tile
                    if (pos.y <= currentTileY)
                    {
                        //if (debugMode) {debugBox(&brush, &pen, &p, QColor(0, 60, 255, 180), QColor(0, 60, 255, 40)); p.drawRect(currentTileX - g->GetCamPos().x, currentTileY - g->GetCamPos().y, currentTileWidth, currentTileHeight);}

                        // if player gain altitude
                        if (state.moveUp)
                        {
                            /// player in mid jump
                        }
                        // if player fall
                        else if (state.moveDown)
                        {
                            // prevent player fall through tile
                            if (pos.y+1 + velocityV >= currentTileY)
                            {
                                if (debugMode) {debugBox(&brush, &pen, &p, QColor(255, 0, 255, 180), QColor(255, 0, 255, 40)); p.drawRect(currentTileX - g->GetCamPos().x, currentTileY - g->GetCamPos().y, currentTileWidth, currentTileHeight);}

                                /// player touch the ground
                                state.moveDown = false;
                                state.onGround = true;
                                //state.canJump = true;
                                pos.y = currentTileY-1;
                                velocityV = 0.0;
                            }
                            else
                            {
                                /// player still falls
                            }
                        }
                        // is player actually stays on ground
                        else if (state.onGround)
                        {

                            if (pos.y+1 == currentTileY)
                            {
                                if (debugMode) {debugBox(&brush, &pen, &p, QColor(255, 0, 255, 180), QColor(255, 0, 255, 40)); p.drawRect(currentTileX - g->GetCamPos().x, currentTileY - g->GetCamPos().y, currentTileWidth, currentTileHeight);}

                                /// player definitely on ground
                                state.moveDown = false;
                                state.onGround = true;
                                //state.canJump = true;
                                //pos.y = currentTileY-1;
                                velocityV = 0.0;
                            }else

                            // if somehow player standing in mid air
                            /*if (pos.y < currentTileY)
                            {
                                ///if (debugMode) {debugBox(&brush, &pen, &p, QColor(255, 0, 255, 180), QColor(255, 0, 255, 40)); p.drawRect(currentTileX - g->GetCamPos().x, currentTileY - g->GetCamPos().y, currentTileWidth, currentTileHeight);}

                                /// player supposed to fall
                                state.onGround = false;
                                state.moveUp = true;
                                state.moveDown = false;
                                velocityV = -0.1;
                            }
                            // if tile not direct under the player
                            ///if (pos.x + width - currentTileX)
                            if (pos.x - width/2 - currentTileX + velocityH <= currentTileWidth && pos.x + width/2 - currentTileX + velocityH >= 0)
                            {
                                ///if (debugMode) {debugBox(&brush, &pen, &p, QColor(255, 255, 0, 180), QColor(255, 255, 0, 40)); p.drawRect(currentTileX - g->GetCamPos().x, currentTileY - g->GetCamPos().y, currentTileWidth, currentTileHeight);}

                                /// player is on ground
                                state.moveDown = false;
                                state.moveUp = true;
                                state.onGround = true;
                                //state.canJump = true;
                                //pos.y = currentTileY;
                            }
                            // if player gonna walk of tile to the right
                            else */if (pos.x + width/2 + velocityH - currentTileX > currentTileWidth)
                            {

                                //if (debugMode) {debugBox(&brush, &pen, &p, QColor(0, 180, 180, 180), QColor(255, 0, 0, 40)); p.drawRect(currentTileX+2 - g->GetCamPos().x, currentTileY+2 - g->GetCamPos().y, currentTileWidth-4, currentTileHeight-4);}

                                /// player walk off the tile
                                state.onGround = false;
                                state.moveUp = true;
                                state.moveDown = false;
                                velocityV = -0.1;
                            }
                            // if player gonna walk of tile to the left
                            else if (pos.x - width/2 + velocityH < currentTileX)
                            {
                                //if (debugMode) {debugBox(&brush, &pen, &p, QColor(50, 180, 0, 180), QColor(255, 0, 0, 40)); p.drawRect(currentTileX+2 - g->GetCamPos().x, currentTileY+2 - g->GetCamPos().y, currentTileWidth-4, currentTileHeight-4);}

                                /// player walk off the tile
                                state.onGround = false;
                                state.moveUp = true;
                                state.moveDown = false;
                                velocityV = -0.1;
                            }

                        }
                    }
                    // if player somehow fall through tile
                    else if (pos.y > currentTileY)
                    {
                        // if player fall through top tile
                        if (pos.y - currentTileY < currentTileHeight && pos.y - currentTileY > 0)
                        {

                            /// force player move to upper tile side
//                            state.moveDown = false;
//                            state.onGround = true;
//                            //state.canJump = true;
//                            pos.y = currentTileY-1;
//                            velocityV = 0.0;

                        }

                        //else
                        {

                        }
                    }
                }

            }
        }
    }
    if (debugMode) p.end();
    //if (state.moveUp) state.canJump = false;
    //else if (!state.moveDown) state.canJump = true;
    //// Jump state
    if (!state.onGround || state.moveUp)
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
        state.onGround = true;
        state.moveDown = false;
        velocityV = 0.0;
    }

    //// Walking state
    if (state.moveLeft || state.moveRight)
    {
        if (state.moveRight && state.canMove)
        {
            increaseVelocityRight();
        }
        else if (state.moveLeft && state.canMove)
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
    // prevent player go out of bounds
    if (pos.x*pos.x > 100000000 || pos.y*pos.y > 9000000)
    {
        long x = 66;
        long y = 20;
        pos.x = x*40 + 20;
        pos.y = y*40;
    }


}

void Player::Jump()
{
    velocityV = -jumpStartVelocity;
    state.onGround = false;
    state.moveUp = true;
    state.canJump = false;

}

void Player::respawn()
{
    state = pMoveState();
    pos = spawnPoint;
}

void Player::setRespawnPoint(pPosition spawnPoint)
{
    this->spawnPoint = spawnPoint;
}

void Player::setRespawnPoint()
{
    this->spawnPoint = pos;
}

void Player::increaseVelocityLeft()
{
    if (velocityH > 0.0) decreaseVelocityHorizontalToZero();
    else if (velocityH > -1.0) velocityH = -1.5;
    else if (velocityH > -velocityWalkLim)
    {
        velocityH = velocityH * velocityHorizontalIncrease;
    }
    else velocityH = -velocityWalkLim;
}
void Player::increaseVelocityRight()
{
    if (velocityH < 0.0) decreaseVelocityHorizontalToZero();
    else if (velocityH < 1.0) velocityH = 1.5;
    else if (velocityH < velocityWalkLim)
    {
        velocityH = velocityH * velocityHorizontalIncrease;
    }
    else velocityH = velocityWalkLim;
}
void Player::decreaseVelocityHorizontalToZero()
{
    if (velocityH*velocityH > 0.25) velocityH /= velocityHorizontalIncrease + 0.05;
    else velocityH = 0.0;
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
    else if (velocityV < velocityFallLim)
    {
        velocityV = velocityV * velocityVerticalIncrease-0.09;
    }
    else velocityV = velocityFallLim;
}

