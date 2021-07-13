#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::on_Timer);
    timer->start(1000/60);

    resourceManager = ResourceManager::CreateManager(); // singletone!
    gameRender = GameRender::CreateGameRender();
}

MainWindow::~MainWindow()
{
    ResourceManager::DeleteManager();
    GameRender::DeleteGameRender();
    delete ui;

}
void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    switch (ev->key())
    {
    case Qt::Key_A:
        gameRender->cMoveState.moveLeft = false;
        break;
    case Qt::Key_D:
        gameRender->cMoveState.moveRight = false;
        break;
    case Qt::Key_W:
        gameRender->cMoveState.moveUp = false;
        break;
    case Qt::Key_S:
        gameRender->cMoveState.moveDown = false;
        break;
    }

}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key())
    {
    case Qt::Key_A:
        gameRender->cMoveState.moveLeft = true;
        break;
    case Qt::Key_D:
        gameRender->cMoveState.moveRight = true;
        break;
    case Qt::Key_W:
        gameRender->cMoveState.moveUp = true;
        break;
    case Qt::Key_S:
        gameRender->cMoveState.moveDown = true;
        break;
    case Qt::Key_Escape:
        close();
    }

}
void CamMove(GameRender *&Camera)
{
    if (Camera->cMoveState.moveLeft) Camera->MoveCamera(Camera->GetCamPos().x-10, Camera->GetCamPos().y);
    if (Camera->cMoveState.moveRight) Camera->MoveCamera(Camera->GetCamPos().x+10, Camera->GetCamPos().y);
    if (Camera->cMoveState.moveUp) Camera->MoveCamera(Camera->GetCamPos().x, Camera->GetCamPos().y-10);
    if (Camera->cMoveState.moveDown) Camera->MoveCamera(Camera->GetCamPos().x, Camera->GetCamPos().y+10);
}

void MainWindow::on_Timer()
{
    QPixmap canvas(ui->LableCanvas->geometry().size());



    CamMove(gameRender);
    gameRender->ScreenUpdate(canvas);

    ui->LableCanvas->setPixmap(canvas);
}
