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

}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{

    /*

    switch ()
    {
    case Qt::Key_Left:

        break;
    case Qt::Key_Right:

        break;
    case Qt::Key_Up:

        break;
    case Qt::Key_Down:

        break;
    }
    */

}

void MainWindow::on_Timer()
{
    //ResourceManager resources;

    //QPixmap pixmap(":/resources/Textures/tiles/z_no_texture.bmp");
    QPixmap pixmap(":/Tiles/Textures/tiles/missing_texture.png");

    // resources.GetSprite("no_texture",resources.TilesStorage())
    QPixmap canvas(ui->LableCanvas->geometry().size());
    //canvas.fill(Qt::transparent);
    //QPainter p;
    //p.begin(&canvas);
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
    //p.end();
    ui->LableCanvas->setPixmap(canvas);





    //ui->label->grabKeyboard();
    //if (GetAsyncKeyState(VK_DOWN))
}
