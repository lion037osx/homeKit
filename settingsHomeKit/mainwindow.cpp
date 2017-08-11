#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qextserialenumerator.h"
#include <QDebug>
#include <QDateTime>
#include <QTimer>
#include <QTime>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow),port(NULL)
{
    ui->setupUi(this);
    QDateTime systemTime;
    systemTime=QDateTime::currentDateTime();
QString txtSystemTime;
txtSystemTime=systemTime.toString();



    ui->label_view_time->setText(txtSystemTime);
    qDebug()<<"string:"<<txtSystemTime;
    qDebug()<<systemTime;


    timeEvent();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_exit_clicked()
{
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

            //m_port->setPortName("/dev/cu.SLAB_USBtoUART");
           port->setPortName("/dev/ttyUSB0");

           if(port->open(QIODevice::ReadWrite)==true)
           {
                qDebug()<<"Open Port success!!!";
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
char str[64];

sprintf(str,"@date %d%d%d%d%d%d%d%d%d%c",month/10,month-((month/10)*10), day/10 ,day-((day/10)*10) ,(hour/10),hour-((hour/10)*10),min/10,(min-((min/10)*10)),(year),127);

        qDebug()<<str;
        port->write("@");
        port->write(str);

}
