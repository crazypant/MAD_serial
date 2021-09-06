#include "serial_thread.h"

Serial_thread::Serial_thread(QObject *parent) : QObject(parent)
{
    count = 0;
}



void Serial_thread::ReadyRead()
{
    serial = new QSerialPort;
    serial->setPortName(Com_name);
    serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(baud);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    connect(serial,&QSerialPort::readyRead,this,&Serial_thread::DealData);

}



void Serial_thread::DealData()
{
    QByteArray ba = serial->readAll();
    emit SendData(ba);
}
void Serial_thread::set_baud(int num)
{
    baud = num;
}
void Serial_thread::set_Com(QString name)
{
    Com_name = name;
}
void Serial_thread::set_parity(int num)
{
    parity = num;
}
void Serial_thread::set_stop(int num)
{
    stop = num;
}

void Serial_thread::set_databits(int num)
{
    databits = num;
}

void Serial_thread::Send(QByteArray ba)
{
    serial->write(ba);
}

void Serial_thread::EndSerial()
{
    serial->clear();
    serial->close();
    serial->deleteLater();
}

void Serial_thread::SendFile()
{
    int h=0;
    QByteArray line_data;
    qDebug()<<"发送文件串口";
    QString filepath = "ddd";
    QFile file(filepath);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug()<<" 文件打开失败！";
        return;
    }
    int len =1;

    while(!file.atEnd())
    {
        //Sleep(10);


        len = 0;
        line_data = file.readLine();
        qDebug()<<line_data.size();

        len = serial->write(line_data);
        h = h+1;

    }
}
