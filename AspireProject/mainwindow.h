#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QMovie>
#include "resourcemanager.h"
//#include <windows.h>

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

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    ResourceManager *resourceManager;
};
#endif // MAINWINDOW_H
