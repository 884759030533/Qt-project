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
    //ResourceManager resources;

    //QPixmap pixmap(":/resources/Textures/tiles/z_no_texture.bmp");
    //QPixmap pixmap(":/Tiles/Textures/tiles/missing_texture.png");

    // resources.GetSprite("no_texture",resources.TilesStorage())
    QPixmap canvas(ui->LableCanvas->geometry().size());
    //canvas.fill(Qt::transparent);
    QPainter p;
    ////p.begin(&canvas);
    //p.setRenderHint(QPainter::SmoothPixmapTransform);
    //p.setRenderHint(QPainter::Antialiasing);
    //p.setRenderHint(QPainter::LosslessImageRendering);

    //p.translate(canvas.size().width() / 2, canvas.size().height() / 2); // rotate each image
    //p.rotate(55); // degrees
    //p.translate(-canvas.size().width() / 2, -canvas.size().height() / 2);

    //p.drawPixmap(100, 100, resources.GetSprite("no_texture",resources.TilesStorage()));
    //p.drawPixmap(100, 100, resourceManager->tiles["no_texture"]);
    //p.drawPixmap(ui->LableCanvas->geometry().x() + ui->LableCanvas->geometry().width()/2, ui->LableCanvas->geometry().y() + ui->LableCanvas->geometry().height()/2, pixmap);
    /*p.drawPixmap(ui->LableCanvas->geometry().x() + ui->LableCanvas->geometry().width()/2,
                 ui->LableCanvas->geometry().y() + ui->LableCanvas->geometry().height()/2,
                 resourceManager->GetSprite(0, resourceManager->TilesStorage()));
    */
    CamMove(gameRender);
//    if (gameRender->cMoveState.moveLeft) gameRender->MoveCamera(gameRender->GetCamPos().x-10, gameRender->GetCamPos().y);
//    if (gameRender->cMoveState.moveRight) gameRender->MoveCamera(gameRender->GetCamPos().x+10, gameRender->GetCamPos().y);
//    if (gameRender->cMoveState.moveUp) gameRender->MoveCamera(gameRender->GetCamPos().x, gameRender->GetCamPos().y-10);
//    if (gameRender->cMoveState.moveDown) gameRender->MoveCamera(gameRender->GetCamPos().x, gameRender->GetCamPos().y+10);
    gameRender->ScreenUpdate(canvas);
    ////p.end();
    ui->LableCanvas->setPixmap(canvas);





    //ui->label->grabKeyboard();
    //if (GetAsyncKeyState(VK_DOWN))
}
