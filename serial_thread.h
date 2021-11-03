#ifndef SERIAL_THREAD_H
#define SERIAL_THREAD_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>

class Serial_thread : public QObject
{
    Q_OBJECT
public:
    explicit Serial_thread(QObject *parent = nullptr);
    ~Serial_thread(){}
    void set_baud(int num);
    void set_Com(QString name);
    void set_parity(int num);
    void set_stop(int num);
    void set_databits(int num);
public slots:
    void DealData();
    void ReadyRead();
    void Send(QByteArray ba);
    void EndSerial();
    void SendFile();
    void Send_data(QByteArray ba);
    void Send_peak(QByteArray ba);
signals:
    void SendData(QByteArray);

private:
    int max;
    int min;
    int baud;//波特率
    QString Com_name;//端口名
    int parity;//校验位
    int stop;//停止位
    int databits;//数据位
    QSerialPort *serial;

};

#endif // SERIAL_THREAD_H
