#include "serial_thread.h"

Serial_thread::Serial_thread(QObject *parent) : QObject(parent)
{

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
    qDebug()<<"文件";
}
