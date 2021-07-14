#ifndef GAMERENDER_H
#define GAMERENDER_H

#include <QLabel>
#include <QPainter>
#include <QMovie>
#include "resourcemanager.h"
#include "player.h"

struct CamPosition
{
    long x;
    long y;
    CamPosition() : x(0), y(0) {};
    CamPosition(long X, long Y) : x(X), y(Y) {};
};
struct CamMoveState
{
    bool moveLeft;
    bool moveRight;
    bool moveUp;
    bool moveDown;
    CamMoveState(bool MoveLeft = false, bool MoveRight = false, bool MoveUp = false,
                 bool MoveDown = false) : moveLeft(MoveLeft), moveRight(MoveRight), moveUp(MoveUp), moveDown(MoveDown) {};
};

class GameRender : public QLabel // AKA player camera
{
    Q_OBJECT // ???
private:
    GameRender(QWidget *parent = 0);
    GameRender(const GameRender& );
    GameRender& operator=( GameRender& );
    ~GameRender();
    static GameRender * GR;

    ResourceManager *resources;
    int tileSize;
    CamPosition cPos;


public:
    static GameRender * CreateGameRender();
    static void DeleteGameRender();

    void ScreenUpdate(QPixmap &canvas);

    void MoveCamera(long xDest, long yDest) { cPos.x = xDest; cPos.y = yDest; }
    CamPosition GetCamPos() { return cPos; }
    CamMoveState cMoveState;

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
signals:
    void MouseMove(QMouseEvent *ev);
    void MousePress(QMouseEvent *ev);
    void MouseRelease(QMouseEvent *ev);
};

#endif // GAMERENDER_H
