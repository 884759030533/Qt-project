#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QMovie>
#include <QKeyEvent>
#include "resourcemanager.h"
#include "gamerender.h"
#include "player.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Timer();

    void onKeyPress(QKeyEvent*ev);
    void onKeyRelease(QKeyEvent*ev);

private:
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    Ui::MainWindow *ui;
    QTimer *timer;
    ResourceManager *resourceManager;
    GameRender *gameRender;
    Player *player;

};
#endif // MAINWINDOW_H
