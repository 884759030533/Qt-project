#ifndef GAMERENDER_H
#define GAMERENDER_H

#include <QLabel>
#include <QPainter>
#include <QMovie>
#include "resourcemanager.h"

class GameRender : public QLabel
{
    Q_OBJECT // ???
private:
    GameRender(QWidget *parent = 0);
    GameRender(const GameRender& );
    GameRender& operator=( GameRender& );
    ~GameRender();
    static GameRender * GR;

    ResourceManager *resources;

public:
    static GameRender * CreateGameRender();
    static void DeleteGameRender();

    void Initialize(ResourceManager *&resourceManager);
    void ScreenUpdate(QPixmap &canvas);

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
signals:
    void MouseMove(QMouseEvent *ev);
    void MousePress(QMouseEvent *ev);
    void MouseRelease(QMouseEvent *ev);
};

#endif // GAMERENDER_H
