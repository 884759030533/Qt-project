#include "gamerender.h"

GameRender::GameRender(QWidget *parent) : QLabel(parent)
{
    resources = ResourceManager::CreateManager();
    tileSize = 40;
    cPos = CamPosition(0, 0);
}

GameRender::~GameRender()
{

}

GameRender *GameRender::CreateGameRender()
{
    if (GR == nullptr) GR = new GameRender();
    return GR;
}

void GameRender::DeleteGameRender()
{
    if (GR == nullptr)
    {
        delete GR;
        GR = nullptr;
    }
}

void GameRender::Initialize(ResourceManager *&resourceManager)
{

}

void GameRender::ScreenUpdate(QPixmap &canvas)
{
    //resources = ResourceManager::CreateManager();
    QPainter p;
    p.begin(&canvas);
    for (int layer = 0; layer < 3; layer++) // background/middle/foreground layer
    {
        for (int sublayer = 0; sublayer < 5; sublayer++) //
        {
            for (int tile = 0; tile < resources->GetWorldMap().size(); tile++)
            {
                if (resources->GetWorldMap()[sublayer].getPos().z == sublayer)
                {
                    p.drawPixmap(resources->GetWorldMap()[tile].getPos().x * tileSize + cPos.x,
                                 resources->GetWorldMap()[tile].getPos().y * tileSize + cPos.y,
                                 resources->GetSprite(resources->GetWorldMap()[tile].getID(), resources->TilesStorage()) );

                }
            }
        }
    }
    p.end();
}

void GameRender::mouseMoveEvent(QMouseEvent *ev)
{
    emit MouseMove(ev);
}

void GameRender::mousePressEvent(QMouseEvent *ev)
{
    emit MousePress(ev);
}

void GameRender::mouseReleaseEvent(QMouseEvent *ev)
{
    emit MouseRelease(ev);
}
