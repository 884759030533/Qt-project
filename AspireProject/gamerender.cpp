#include "gamerender.h"

GameRender::GameRender(QWidget *parent) : QLabel(parent)
{
    resources = ResourceManager::CreateManager();
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
    QPainter p;
    for (int i = 0; i < 3; i++)
    {

        p.begin(&canvas);

        p.drawPixmap(resources->GetWorldMap()[i].getPos().x, resources->GetWorldMap()[i].getPos().y,
                     resources->GetSprite(resources->GetWorldMap()[i].getID(), resources->TilesStorage()));

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
