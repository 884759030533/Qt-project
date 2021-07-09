#ifndef GAMERENDER_H
#define GAMERENDER_H

#include <QLabel>
#include "resourcemanager.h"

class GameRender : public QLabel
{
    Q_OBJECT // ???
private:
    ResourceManager *resources;
public:
    GameRender(QWidget *parent = 0);
    ~GameRender();
    void Initialize(ResourceManager *&resourceManager);
    void ScreenUpdate();

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
signals:
    void MouseMove(QMouseEvent *ev);
    void MousePress(QMouseEvent *ev);
    void MouseRelease(QMouseEvent *ev);
};

#endif // GAMERENDER_H
