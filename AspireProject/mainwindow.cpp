#include "mainwindow.h"
#include "ui_mainwindow.h"

QRect lableCoord;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::on_Timer);
    timer->start(1000/30);

    connect(ui->LableCanvas,SIGNAL(KeyPress(QKeyEvent*)),this,SLOT(onKeyPress(QKeyEvent*)));
    connect(ui->LableCanvas,SIGNAL(KeyRelease(QKeyEvent*)),this,SLOT(onKeyRelease(QKeyEvent*)));

    lableCoord = ui->LableCanvas->geometry();

    resourceManager = ResourceManager::CreateManager(); // singletone!
    gameRender = GameRender::CreateGameRender();

    player = new Player(pPosition(400, 300));

    gameRender->MoveCamera(400,300);
    //for (int l = 0; l<2; l++) gameRender->cMoveState = CamMoveState(!l,!l,!l,!l);
}

MainWindow::~MainWindow()
{
    ResourceManager::DeleteManager();
    GameRender::DeleteGameRender();
    delete player;
    delete ui;

}
void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    switch (ev->key())
    {
    case Qt::Key_A:
        gameRender->cMoveState.moveLeft = false;
        player->state.moveLeft = false;
        break;
    case Qt::Key_D:
        gameRender->cMoveState.moveRight = false;
        player->state.moveRight = false;
        break;
    case Qt::Key_W:
        gameRender->cMoveState.moveUp = false;
        break;
    case Qt::Key_S:
        gameRender->cMoveState.moveDown = false;
        player->state.isCrouch = false;
        break;
    }

}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key())
    {
    case Qt::Key_A:
        if (!player->state.moveLeft)
        {
            gameRender->cMoveState.moveLeft = true;
            player->state.moveLeft = true;
        }
        break;
    case Qt::Key_D:
        if (!player->state.moveRight)
        {
            gameRender->cMoveState.moveRight = true;
            player->state.moveRight = true;
        }
        break;
    case Qt::Key_W:
        gameRender->cMoveState.moveUp = true;
        //player->Jump();
        break;
    case Qt::Key_S:
        gameRender->cMoveState.moveDown = true;
        player->state.isCrouch = true;
        break;
    case Qt::Key_Space:
        player->Jump();
        break;
    case Qt::Key_Escape:
        close();
    }

}

void MainWindow::onKeyPress(QKeyEvent *ev)
{
//    switch (ev->key())
//    {
//    case Qt::Key_A:
//        gameRender->cMoveState.moveLeft = true;
//        player->state.moveLeft = true;
//        break;
//    case Qt::Key_D:
//        gameRender->cMoveState.moveRight = true;
//        player->state.moveRight = true;
//        break;
//    case Qt::Key_W:
//        gameRender->cMoveState.moveUp = true;
//        player->Jump();
//        break;
//    case Qt::Key_S:
//        gameRender->cMoveState.moveDown = true;
//        player->state.isCrouch = true;
//        break;
//    case Qt::Key_Escape:
//        close();
//    }
}

void MainWindow::onKeyRelease(QKeyEvent *ev)
{
//    switch (ev->key())
//    {
//    case Qt::Key_A:
//        gameRender->cMoveState.moveLeft = false;
//        player->state.moveLeft = false;
//        break;
//    case Qt::Key_D:
//        gameRender->cMoveState.moveRight = false;
//        player->state.moveRight = false;
//        break;
//    case Qt::Key_W:
//        gameRender->cMoveState.moveUp = false;
//        break;
//    case Qt::Key_S:
//        gameRender->cMoveState.moveDown = false;
//        player->state.isCrouch = false;
//        break;
//    }
}

void CamMove(GameRender *&Camera)
{
    if (Camera->cMoveState.moveLeft) Camera->MoveCamera(Camera->GetCamPos().x+10, Camera->GetCamPos().y);
    if (Camera->cMoveState.moveRight) Camera->MoveCamera(Camera->GetCamPos().x-10, Camera->GetCamPos().y);
    if (Camera->cMoveState.moveUp) Camera->MoveCamera(Camera->GetCamPos().x, Camera->GetCamPos().y+10);
    if (Camera->cMoveState.moveDown) Camera->MoveCamera(Camera->GetCamPos().x, Camera->GetCamPos().y-10);
}
void PlayerCamMove(GameRender *&Camera, Player *&player)
{
    if (Camera->cMoveState.moveLeft || Camera->cMoveState.moveRight)
        Camera->MoveCamera(player->getPos().x - lableCoord.width()/2, Camera->GetCamPos().y);
    if (Camera->cMoveState.moveUp)
        Camera->MoveCamera(Camera->GetCamPos().x - lableCoord.width()/2, Camera->GetCamPos().y-10);
    if (Camera->cMoveState.moveDown)
        Camera->MoveCamera(Camera->GetCamPos().x - lableCoord.width()/2, Camera->GetCamPos().y+10);
    else
        Camera->MoveCamera(player->getPos().x - lableCoord.width()/2, Camera->GetCamPos().y);
}

void MainWindow::on_Timer()
{
    lableCoord = ui->LableCanvas->geometry();
    QPixmap canvas(ui->LableCanvas->geometry().size());
    QPainter p;


    player->Move();
    //CamMove(gameRender);
    PlayerCamMove(gameRender, player);
    gameRender->ScreenUpdate(canvas);
    p.begin(&canvas);

    p.drawRect(player->getPos().x - player->getWidth()/2 - gameRender->GetCamPos().x,
               player->getPos().y - player->getHeight() - gameRender->GetCamPos().y,
               player->getWidth(), player->getHeight() );
    p.end();

   ////debug
    ui->LableCanvas->setPixmap(canvas);
    ui->debugLabel1->setText(QString("Camera Position ") + QString::number(gameRender->GetCamPos().x) +
                             " " + QString::number(gameRender->GetCamPos().y));
    ui->debugLabel2->setText(QString("Player Position ") + QString::number(player->getPos().x) +
                             " " + QString::number(player->getPos().y) + " velocityH " + QString::number(player->getVelocityHorizontal()) +
                             " velocityV " + QString::number(player->getVelocityVertical()) );
    ui->label->setText(QString("Camera States ") +
                       QString::number(gameRender->cMoveState.moveUp) +
                       QString::number(gameRender->cMoveState.moveDown) +
                       QString::number(gameRender->cMoveState.moveLeft) +
                       QString::number(gameRender->cMoveState.moveRight) );
    ui->label_2->setText(QString("Player States ") +
                       QString::number(player->state.moveLeft) +
                       QString::number(player->state.moveRight) + "onGR - " +
                       QString::number(player->state.onGround) +
                       QString::number(player->state.moveUp) +
                       QString::number(player->state.moveDown)  );


}


