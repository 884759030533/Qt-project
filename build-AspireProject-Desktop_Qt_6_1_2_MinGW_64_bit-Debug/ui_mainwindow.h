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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *LableCanvas;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *debugLabel2;
    QLabel *label_2;
    QLabel *debugLabel1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1100, 600);
        MainWindow->setMinimumSize(QSize(1100, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Textures/icons/small_icon_x2.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(128, 128));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LableCanvas = new QLabel(centralwidget);
        LableCanvas->setObjectName(QString::fromUtf8("LableCanvas"));
        LableCanvas->setPixmap(QPixmap(QString::fromUtf8(":/Tiles/Textures/tiles/z_missing_texture.png")));
        LableCanvas->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LableCanvas);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        debugLabel2 = new QLabel(centralwidget);
        debugLabel2->setObjectName(QString::fromUtf8("debugLabel2"));

        horizontalLayout->addWidget(debugLabel2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        debugLabel1 = new QLabel(centralwidget);
        debugLabel1->setObjectName(QString::fromUtf8("debugLabel1"));

        horizontalLayout->addWidget(debugLabel1);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Aspire Project", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        debugLabel2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        debugLabel1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
