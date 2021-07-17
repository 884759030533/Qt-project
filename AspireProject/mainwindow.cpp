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
    timer->start(1000/60);

    //connect(ui->LableCanvas,SIGNAL(KeyPress(QKeyEvent*)),this,SLOT(onKeyPress(QKeyEvent*)));
    //connect(ui->LableCanvas,SIGNAL(KeyRelease(QKeyEvent*)),this,SLOT(onKeyRelease(QKeyEvent*)));

    lableCoord = ui->LableCanvas->geometry();

    resourceManager = ResourceManager::CreateManager(); // singletone!
    gameRender = GameRender::CreateGameRender();

    long spawnX = 17;
    long spawnY = 10;


    player = new Player(pPosition(spawnX * 40 - 20, spawnY * 40));

    gameRender->MoveCamera(spawnX * 40, spawnY * 40);
    //for (int l = 0; l<2; l++) gameRender->cMoveState = CamMoveState(!l,!l,!l,!l);

    ui->debugLabel1->setStyleSheet("QLabel {color: rgb(255, 255, 255); background-color: rgba(0, 0, 0, 50);}");
    ui->debugLabel2->setStyleSheet("QLabel {color: rgb(255, 255, 255); background-color: rgba(0, 0, 0, 50);}");
    ui->label->setStyleSheet("QLabel {color: rgb(255, 255, 255); background-color: rgba(0, 0, 0, 50);}");
    ui->label_2->setStyleSheet("QLabel {color: rgb(255, 255, 255); background-color: rgba(0, 0, 0, 50);}");
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
        if (!player->state.canMove)
        {
            player->state.canMove = true;
            player->state.moveLeft = false;
            player->state.moveRight = true;
        }

        else player->state.moveLeft = false;
        break;
    case Qt::Key_D:
        if (!player->state.canMove)
        {
            player->state.canMove = true;
            player->state.moveLeft = true;
            player->state.moveRight = false;
        }

        else player->state.moveRight = false;
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
        if (player->state.moveRight)
        {
            //gameRender->cMoveState.moveLeft = true;
            player->state.moveLeft = false;
            player->state.moveRight = false;
            player->state.canMove = false;
        }
        else
        {
            player->state.moveLeft = true;
        }
        break;
    case Qt::Key_D:
        if (player->state.moveLeft)
        {
            //gameRender->cMoveState.moveRight = true;
            player->state.moveLeft = false;
            player->state.moveRight = false;
            player->state.canMove = false;
        }
        else
        {
            player->state.moveRight = true;
        }
        if (player->state.moveRight)
        {
            player->state.moveRight = true;
        }

        break;
    case Qt::Key_W:
        //gameRender->cMoveState.moveUp = true;
        //player->Jump();
        break;
    case Qt::Key_S:
        //gameRender->cMoveState.moveDown = true;
        player->state.isCrouch = true;
        break;
    case Qt::Key_Space:
        if (player->state.onGround) player->Jump();
        break;
    case Qt::Key_Escape:
        close();
    }

}

//void MainWindow::onKeyPress(QKeyEvent *ev)
//{
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
//}

//void MainWindow::onKeyRelease(QKeyEvent *ev)
//{
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
//}

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
        Camera->MoveCamera(player->getPos().x - lableCoord.width()/2, player->getPos().y - lableCoord.height()/2 - player->getHeight()/2);
    if (Camera->cMoveState.moveUp)
        Camera->MoveCamera(player->getPos().x - lableCoord.width()/2, Camera->GetCamPos().y-10);
    if (Camera->cMoveState.moveDown)
        Camera->MoveCamera(player->getPos().x - lableCoord.width()/2, Camera->GetCamPos().y+10);
    else
        Camera->MoveCamera(player->getPos().x - lableCoord.width()/2, player->getPos().y - lableCoord.height()/2 - player->getHeight()/2);
}

void MainWindow::on_Timer()
{
    ui->LableCanvas->resize(this->geometry().width(), this->geometry().height());


    lableCoord = ui->LableCanvas->geometry();
    QPixmap canvas(ui->LableCanvas->geometry().size());
    QPainter p;
    //QPixmap debugCanvas(ui->LableCanvas->geometry().size());

//    player->Move(&debugCanvas);
    //CamMove(gameRender);
    PlayerCamMove(gameRender, player);
    gameRender->ScreenUpdate(canvas);
    player->Move(&canvas);
    p.begin(&canvas);
    QBrush brush;
    QPen pen;
    brush.setColor(QColor(0,255,0,80));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    pen.setColor(QColor(0,255,0,180));
    p.setBrush(brush);
    p.setPen(pen);

    p.drawRect(player->getPos().x - player->getWidth()/2 - gameRender->GetCamPos().x,
               player->getPos().y - player->getHeight() - gameRender->GetCamPos().y,
               player->getWidth(), player->getHeight() );

    p.end();

    ///debug
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
                       QString::number(player->state.canMove) +
                       QString::number(player->state.moveRight) + "onGR - " +
                       QString::number(player->state.onGround) +
                       QString::number(player->state.moveUp) +
                       QString::number(player->state.moveDown) + " - " +
                       QString::number(player->state.canJump) );


}


