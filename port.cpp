#include "port.h"



PortData::PortData(QObject*parent)

{
    serial_port_ = nullptr;
    //p = zeros(serialK,serialL);
}

void PortData::Init()
{
    //connect(this->serial_port_,SIGNAL(readyRead()),this,SLOT(resolveDataFromSerialport()));
    qDebug()<<"  init...";
    serial_port_ = new QSerialPort;
    serial_port_->setPortName(this->Port_name);
    if(serial_port_->open(QIODevice::ReadWrite))
    {
        qDebug()<<"打开成功！";
    }

    serial_port_->setBaudRate(QSerialPort::Baud115200);
    serial_port_->setStopBits(QSerialPort::OneStop);
    serial_port_->setDataBits(QSerialPort::Data8);
    serial_port_->setParity(QSerialPort::NoParity);
    serial_port_->setFlowControl(QSerialPort::NoFlowControl);
    connect(this->serial_port_,SIGNAL(readyRead()),this,SLOT(resolveDataFromSerialport()));
    qDebug()<<Port_name<<" has init";

}

void PortData::SendData()
{
    QString sendstr0 = "ddd";
    QString sendstr1 = "2";
    QString sendstr2 = "3";
    QString sendstr3 = "4";
    QString sendstr4 = "5";

    int n = qrand()%5;

    switch (n) {
    case 1:
        serial_port_->write(sendstr1.toUtf8());
        break;
    case 2:
        serial_port_->write(sendstr2.toUtf8());
        break;

    case 3:
        serial_port_->write(sendstr3.toUtf8());

        break;
    case 4:
        serial_port_->write(sendstr4.toUtf8());
        break;
    case 5:
        serial_port_->write(sendstr0.toUtf8());
        break;
    }
}
void PortData::resolveDataFromSerialport()
{
    QByteArray tmp_data = serial_port_->readAll();
    qDebug()<<tmp_data;
}

