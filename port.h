#ifndef PORT_H
#define PORT_H
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QFile>
#include <QDebug>
#include <QThread>
#include <QTime>

class PortData : public QObject
{
    Q_OBJECT
public:
    PortData(QObject *parent = 0);
    virtual ~PortData() {

    }
    void setPortName(QString str){
        Port_name = str;
    }

    void setBaudRate(QString baud){
        Baud_rate = baud;
    }
    void Init();
    void SendData();
private:
    QString Port_name;
    QSerialPort* serial_port_;
    bool isInit;
    QString Baud_rate;
public slots:
    void resolveDataFromSerialport();
};


#endif // PORT_H


