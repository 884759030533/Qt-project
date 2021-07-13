#include "gamerender.h"

GameRender* GameRender::GR = nullptr;

GameRender::GameRender(QWidget *parent) : QLabel(parent)
{
    resources = ResourceManager::CreateManager();
    tileSize = 40;
    cPos = CamPosition(0, 0);
    cMoveState = CamMoveState();
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
    if (GR != nullptr)
    {
        delete GR;
        GR = nullptr;
    }
}

void GameRender::ScreenUpdate(QPixmap &canvas)
{
    //resources = ResourceManager::CreateManager();
    QPainter p;
    QPixmap rotatePixmap(40, 40);
    p.begin(&canvas);
    canvas.fill(Qt::white);
    for (int layer = -1; layer <= 1; layer++) // background/middle/foreground layer
    {
        for (int sublayer = -2; sublayer <= 2; sublayer++) //
        {
            for (unsigned long long tile = 0; tile < resources->GetWorldMap().size(); tile++)
            {
                if (resources->GetWorldMap()[tile].getProperties().isVisible)
                {
                    switch (resources->GetWorldMap()[tile].getPos().layer)
                    {
                    case -1: //bottom layer // parallax < 1
                        if (resources->GetWorldMap()[tile].getPos().layer == layer && resources->GetWorldMap()[tile].getPos().z == sublayer)
                        {
                            p.drawPixmap(resources->GetWorldMap()[tile].getPos().x * tileSize + cPos.x+5,
                                         resources->GetWorldMap()[tile].getPos().y * tileSize + cPos.y+5,
                                         resources->GetSprite(resources->GetWorldMap()[tile].getID(), resources->TilesStorage()) );
                        }
                        break;
                    case 0: //mid layer // parallax = 1
                        if (resources->GetWorldMap()[tile].getPos().layer == layer && resources->GetWorldMap()[tile].getPos().z == sublayer)
                        {                          


                            p.drawPixmap(resources->GetWorldMap()[tile].getPos().x * tileSize + cPos.x,
                                         resources->GetWorldMap()[tile].getPos().y * tileSize + cPos.y,
                                         resources->GetSprite(resources->GetWorldMap()[tile].getID(), resources->TilesStorage()) );
                        }
                        break;
                    case 1: //top layer // parallax > 1
                        if (resources->GetWorldMap()[tile].getPos().layer == layer && resources->GetWorldMap()[tile].getPos().z == sublayer)
                        {
                            if (resources->GetWorldMap()[tile].getProperties().rotation)
                            {
                                rotatePixmap = QPixmap(resources->GetSprite(resources->GetWorldMap()[tile].getID(), resources->TilesStorage()));
                                //p.rotate(45);
                                p.begin(&rotatePixmap);
                                //p.translate(rotatePixmap.size().width() / 2, rotatePixmap.size().height() / 2);
                                //p.rotate(resources->GetWorldMap()[tile].getProperties().rotation*90);
                                //p.translate(-rotatePixmap.size().width() / 2, -rotatePixmap.size().height() / 2);
                                p.begin(&canvas);
                                p.drawPixmap(resources->GetWorldMap()[tile].getPos().x * tileSize + cPos.x,
                                             resources->GetWorldMap()[tile].getPos().y * tileSize + cPos.y,
                                             rotatePixmap );

                            }
                            else
                            p.drawPixmap(resources->GetWorldMap()[tile].getPos().x * tileSize + cPos.x-5,
                                         resources->GetWorldMap()[tile].getPos().y * tileSize + cPos.y-5,
                                         resources->GetSprite(resources->GetWorldMap()[tile].getID(), resources->TilesStorage()) );
                        }
                        break;

                    }
                }
            }
        }
    }//*/
    //p.drawPixmap(canvas.width()/2, canvas.height()/2, resources->GetSprite(0, resources->TilesStorage()));

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
