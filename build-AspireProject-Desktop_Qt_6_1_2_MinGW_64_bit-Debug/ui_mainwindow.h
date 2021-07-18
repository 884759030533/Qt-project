/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *label;
    QLabel *debugLabel1;
    QLabel *debugLabel2;
    QLabel *LableCanvas;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Textures/icons/small_icon_x2.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(128, 128));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 400, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Small Fonts")});
        font.setPointSize(14);
        font.setBold(true);
        font.setStyleStrategy(QFont::NoAntialias);
        label_2->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 400, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Small Fonts")});
        font1.setPointSize(12);
        font1.setBold(true);
        label->setFont(font1);
        debugLabel1 = new QLabel(centralwidget);
        debugLabel1->setObjectName(QString::fromUtf8("debugLabel1"));
        debugLabel1->setGeometry(QRect(10, 30, 400, 20));
        debugLabel1->setFont(font1);
        debugLabel2 = new QLabel(centralwidget);
        debugLabel2->setObjectName(QString::fromUtf8("debugLabel2"));
        debugLabel2->setGeometry(QRect(10, 70, 400, 20));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(debugLabel2->sizePolicy().hasHeightForWidth());
        debugLabel2->setSizePolicy(sizePolicy);
        debugLabel2->setFont(font1);
        LableCanvas = new QLabel(centralwidget);
        LableCanvas->setObjectName(QString::fromUtf8("LableCanvas"));
        LableCanvas->setGeometry(QRect(0, 0, 800, 600));
        LableCanvas->setPixmap(QPixmap(QString::fromUtf8(":/Tiles/Textures/tiles/z_missing_texture.png")));
        LableCanvas->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        LableCanvas->raise();
        label_2->raise();
        label->raise();
        debugLabel1->raise();
        debugLabel2->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Aspire Project", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        debugLabel1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        debugLabel2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
