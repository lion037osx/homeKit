#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qextserialenumerator.h"
#include <QDebug>
#include <QDateTime>
#include <QTimer>
#include <QTime>
#include <QDate>
#include <QPixmap>
#include <QColor>
#include <QPalette>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow),port(NULL)
{
    ui->setupUi(this);
    QDateTime systemTime;
    systemTime=QDateTime::currentDateTime();
QString txtSystemTime;
txtSystemTime=systemTime.toString();
QString linkBackGround;
#ifdef Q_OS_LINUX
linkBackGround = qApp->applicationDirPath() + "/../settingsHomeKit/png/bg_cool.png";
#endif

#ifdef Q_OS_MACOS
linkBackGround = qApp->applicationDirPath() + "/../settingsHomeKit/png/bg_cool.png";
#endif


//QPixmap pixmap("/home/optimus/Documentos/source_code/qt/qt_homeKit/homeKit/settingsHomeKit/png/bg_cool.png");
QPixmap pixmap(linkBackGround);
ui->label_background->setPixmap(pixmap);

    ui->label_view_time->setText(txtSystemTime);
    qDebug()<<"string:"<<txtSystemTime;
    qDebug()<<systemTime;

     //ui->pushButton_connex_to_uart->setStyleSheet("QLabel {color:white;}");
     //ui->pushButton_send->setStyleSheet("QLabel {color:white;}");
     //ui->pushButton_exit->setStyleSheet("QLabel {color:white;}");

    ui->pushButton_connex_to_uart->setStyleSheet("* { background-color: rgba(48,48,48,90) }");
    ui->pushButton_send->setStyleSheet("* { background-color: rgba(48,48,48,90) }");
    ui->pushButton_exit->setStyleSheet("* { background-color: rgba(48,48,48,90) }");

    timeEvent();

    //QIcon icon=QIcon("/home/optimus/Documentos/source_code/qt/qt_homeKit/homeKit/settingsHomeKit/png/exit.png");

    QString linkIcon;

     linkIcon = qApp->applicationDirPath() + "/../settingsHomeKit/png/exit.png";

     QIcon icon=QIcon(linkIcon);

     ui->pushButton_exit->setIcon(icon);

     // icon=QIcon("/home/optimus/Documentos/source_code/qt/qt_homeKit/homeKit/settingsHomeKit/png/usb.png");
     linkIcon = qApp->applicationDirPath() + "/../settingsHomeKit/png/usb.png";


       icon=QIcon(linkIcon);

      ui->pushButton_connex_to_uart->setIcon(icon);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_exit_clicked()
{
    delete port;
    port=0x00;
    this->close();
}

void MainWindow::on_pushButton_connex_to_uart_clicked()
{
       if (!port)
       {
           QString sPort;

           port= new QextSerialPort(sPort, QextSerialPort::EventDriven);

           port->setBaudRate(BAUD115200);
           port->setFlowControl(FLOW_OFF);
           port->setParity(PAR_NONE);
           port->setDataBits(DATA_8);
           port->setStopBits(STOP_1);

#ifdef Q_OS_MACOS
    m_port->setPortName("/dev/cu.SLAB_USBtoUART");
#endif

#ifdef Q_OS_LINUX
    port->setPortName("/dev/ttyUSB0");
#endif


           if(port->open(QIODevice::ReadWrite)==true)
           {
                qDebug()<<"Open Port success!!!";
                connect(port, SIGNAL(readyRead()),this,SLOT (onDatosRecibidos()));
           }
           else
           {
               qDebug()<<"Open Error ";
               delete port;
               port=NULL;
           }
       }
       else
       {
           qDebug()<<"Closed Port";
           delete port;
           port=NULL;
       }
       if (port && port->isOpen())
            ui->pushButton_connex_to_uart->setText("Disconnect");
       else
           ui->pushButton_connex_to_uart->setText("Connect");
}




void MainWindow::timeEvent()
{
QTimer *timer=new QTimer(this);

connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
timer->start();

}

void MainWindow::showTime()
{
QDateTime systemTime;
systemTime =QDateTime::currentDateTime();

ui->label_view_time->setStyleSheet("QLabel {color:white;}");
ui->label_view_time->setText(systemTime.toString());
}


void MainWindow::on_pushButton_send_clicked()
{
QDateTime systemTime;
QTime time;
QDate date;

systemTime = QDateTime::currentDateTime();

int hour,min,sec,year,month,day;

time=QTime::currentTime();
date=QDate::currentDate();

hour=time.hour();
min=time.minute();
day=date.day();
year=date.year();
month=date.month();

sec=time.second();


qDebug()<<"seconds"<<time.second();
char str[64];

sprintf(str,"@date %d%d%d%d%d%d%d%d%d%d%d%c",
month/10,month-((month/10)*10),\
day/10 ,day-((day/10)*10),\
(hour/10),hour-((hour/10)*10),\
min/10,(min-((min/10)*10)),\
(year),\
(sec/10),\
(sec-((sec/10)*10)),\
(0X7F));

        qDebug()<<str;
        port->write(str);

}


void MainWindow::onDatosRecibidos()
{
    QByteArray bytes;
    int cant=port->bytesAvailable();
    //if(bytes.isNull())return;
    bytes.resize(cant);
    port->read(bytes.data(),bytes.size());//cant de datos a leer
    m_cant_bytes_recibidos+=cant;
    ui->label_get_clock->setStyleSheet("QLabel {color:white;}");
    ui->label_get_clock->setText(bytes);
    if(stat==1){
        QTextStream stream( &file );
        stream<<bytes;
    }
    qDebug()<<"dDebug:"<<bytes;
}
