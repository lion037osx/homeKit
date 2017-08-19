#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <qextserialport.h>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_pushButton_exit_clicked();

    void on_pushButton_connex_to_uart_clicked();

    void on_pushButton_send_clicked();

    void showTime();

    void timeEvent();

    void onDatosRecibidos();

private:
    Ui::MainWindow *ui;
QextSerialPort *port;
int m_cant_bytes_enviados;
int m_cant_bytes_recibidos;
char * rx_data;
 QString buffer;
 //void EnviarComando_rs232(QString com);

 QFile file;
  bool  stat;

};

#endif // MAINWINDOW_H
