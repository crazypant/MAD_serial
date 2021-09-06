#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //查找可用的串口
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->PortBox->addItem(serial.portName());
            serial.close();
        }
    }

    //设置波特率下拉菜单默认显示第0项
    ui->BaudBox->setCurrentIndex(0);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OpenSerialButton_clicked()
{
    thread_serial = new Serial_thread();
    if(ui->OpenSerialButton->text() == tr("打开串口"))
    {

        //serial = new QSerialPort;
        //设置串口名
        //serial->setPortName(ui->PortBox->currentText());
        thread_serial->set_Com(ui->PortBox->currentText());
        //打开串口
        //serial->open(QIODevice::ReadWrite);
        //设置波特率
        //serial->setBaudRate(QSerialPort::Baud115200);//设置波特率为115200
        //设置数据位数
        switch (ui->BitBox->currentIndex())
        {
        case 8:
            //serial->setDataBits(QSerialPort::Data8);//设置数据位8
            thread_serial->set_databits(QSerialPort::Data8);
            break;
        default:
            break;
        }
        //设置校验位
        switch (ui->ParityBox->currentIndex())
        {
        case 0:
            //serial->setParity(QSerialPort::NoParity);
            thread_serial->set_parity(QSerialPort::NoParity);
            break;
        default:
            break;
        }
        //设置停止位
        switch (ui->BitBox->currentIndex())
        {
        case 1:
            //serial->setStopBits(QSerialPort::OneStop);//停止位设置为1
            thread_serial->set_stop(QSerialPort::OneStop);
            break;
        case 2:
            //serial->setStopBits(QSerialPort::TwoStop);
            thread_serial->set_parity(QSerialPort::TwoStop);
        default:
            break;
        }
        //设置流控制
        //serial->setFlowControl(QSerialPort::NoFlowControl);//设置为无流控制\

        //关闭设置菜单使能
        ui->PortBox->setEnabled(false);
        ui->BaudBox->setEnabled(false);
        ui->BitBox->setEnabled(false);
        ui->ParityBox->setEnabled(false);
        ui->StopBox->setEnabled(false);
        ui->OpenSerialButton->setText(tr("关闭串口"));

        //连接信号槽
        //QObject::connect(thread_serial,&Serial_thread::readyRead,this,&MainWindow::ReadData);
    }
    else
    {
        //关闭串口
        //serial->clear();
        //serial->close();
        //serial->deleteLater();

        //恢复设置使能
        ui->PortBox->setEnabled(true);
        ui->BaudBox->setEnabled(true);
        ui->BitBox->setEnabled(true);
        ui->ParityBox->setEnabled(true);
        ui->StopBox->setEnabled(true);
        ui->OpenSerialButton->setText(tr("打开串口"));

    }

    // 串口线程

    p = new QThread;
    thread_serial->moveToThread(p);
    connect(p,&QThread::started,thread_serial,&Serial_thread::ReadyRead);
    connect(thread_serial,&Serial_thread::SendData,this,&MainWindow::ShowData);
    connect(this,&MainWindow::Sent2Serial,thread_serial,&Serial_thread::Send);
    connect(this,&MainWindow::SendFileSignal,thread_serial,&Serial_thread::SendFile);
    //connect(this,&MainWindow::on_SendButton_2_clicked,thread_serial,&Serial_thread::SendFile);
    p->start();
    qDebug()<<"串口线程开始";


}
//读取接收到的信息
void MainWindow::ReadData()
{
    QByteArray buf;
    buf = serial->readAll();
    if(!buf.isEmpty())
    {
        QString str = ui->textEdit->toPlainText();
        str+=tr(buf);
        ui->textEdit->clear();
        ui->textEdit->append(str);

    }
    buf.clear();
}

void MainWindow::ShowData(QByteArray ba)
{
    QString str = ui->textEdit->toPlainText();
    str+=tr(ba);
    ui->textEdit->clear();
    ui->textEdit->append(str);

}

//发送按钮槽函数
void MainWindow::on_SendButton_clicked()
{
    //QString s1 = "t0.txt=\"111ss44s\"";
    QByteArray ba = ui->textEdit_2->toPlainText().toLatin1();
    ba.append('\xff');
    ba.append('\xff');
    ba.append('\xff');
    //serial->write(ui->textEdit_2->toPlainText().toLatin1());
    emit Sent2Serial(ba);
}
//发送数据文件
void MainWindow::on_SendButton_2_clicked()
{
    qDebug()<<"发送文件";
    //QString s1 = "t0.txt=\"111ss44s\"";
    QByteArray ba = ui->textEdit_2->toPlainText().toLatin1();
    ba.append('\xff');
    ba.append('\xff');
    ba.append('\xff');
    //serial->write(ui->textEdit_2->toPlainText().toLatin1());
    emit SendFileSignal();
}
