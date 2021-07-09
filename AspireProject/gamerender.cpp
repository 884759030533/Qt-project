#include "gamerender.h"

GameRender::GameRender(QWidget *parent) : QLabel(parent)
{

}

GameRender::~GameRender()
{

}

void GameRender::Initialize(ResourceManager *&resourceManager)
{

}

void GameRender::ScreenUpdate()
{
    //this->resources->
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
