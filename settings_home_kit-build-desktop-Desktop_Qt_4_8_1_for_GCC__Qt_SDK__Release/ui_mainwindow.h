/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Aug 11 21:33:16 2017
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_connex_to_uart;
    QPushButton *pushButton_send;
    QLabel *label_view_time;
    QLabel *label_background;
    QLabel *label_get_clock;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(683, 407);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_exit = new QPushButton(centralWidget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(590, 290, 61, 61));
        pushButton_connex_to_uart = new QPushButton(centralWidget);
        pushButton_connex_to_uart->setObjectName(QString::fromUtf8("pushButton_connex_to_uart"));
        pushButton_connex_to_uart->setGeometry(QRect(10, 290, 101, 61));
        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(300, 290, 101, 61));
        label_view_time = new QLabel(centralWidget);
        label_view_time->setObjectName(QString::fromUtf8("label_view_time"));
        label_view_time->setGeometry(QRect(10, 10, 301, 31));
        QFont font;
        font.setPointSize(10);
        label_view_time->setFont(font);
        label_background = new QLabel(centralWidget);
        label_background->setObjectName(QString::fromUtf8("label_background"));
        label_background->setGeometry(QRect(0, -20, 681, 391));
        label_background->setFont(font);
        label_get_clock = new QLabel(centralWidget);
        label_get_clock->setObjectName(QString::fromUtf8("label_get_clock"));
        label_get_clock->setGeometry(QRect(10, 60, 301, 31));
        MainWindow->setCentralWidget(centralWidget);
        label_background->raise();
        label_view_time->raise();
        pushButton_exit->raise();
        pushButton_send->raise();
        pushButton_connex_to_uart->raise();
        label_get_clock->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 683, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Smart Home Kit", 0, QApplication::UnicodeUTF8));
        pushButton_exit->setText(QString());
        pushButton_connex_to_uart->setText(QApplication::translate("MainWindow", "connect", 0, QApplication::UnicodeUTF8));
        pushButton_send->setText(QApplication::translate("MainWindow", "Update", 0, QApplication::UnicodeUTF8));
        label_view_time->setText(QString());
        label_background->setText(QString());
        label_get_clock->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
