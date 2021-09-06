#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QThread>
#include <QFile>
#include <QDialog>
#include <QDir>
#include <QTimer>
#include "serial_thread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void Sent2Serial(QByteArray);
    void SendFileSignal();
private slots:
    void on_OpenSerialButton_clicked();

    void ReadData();

    void on_SendButton_clicked();

    void on_SendButton_2_clicked();
private:
    Ui::MainWindow *ui;
    QThread *p,*p1;
    QSerialPort *serial;
    Serial_thread *thread_serial;
    QTimer dataTimer;
private slots:
    void ShowData(QByteArray);

};

#endif // MAINWINDOW_H
