/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *PortBox;
    QComboBox *BaudBox;
    QComboBox *BitBox;
    QComboBox *ParityBox;
    QLabel *label_4;
    QLabel *label_6;
    QComboBox *StopBox;
    QPushButton *OpenSerialButton;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *SendButton;
    QPushButton *SendButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(694, 501);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 61, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 90, 61, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 130, 61, 21));
        PortBox = new QComboBox(centralWidget);
        PortBox->setObjectName(QString::fromUtf8("PortBox"));
        PortBox->setGeometry(QRect(100, 50, 101, 22));
        BaudBox = new QComboBox(centralWidget);
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->addItem(QString());
        BaudBox->setObjectName(QString::fromUtf8("BaudBox"));
        BaudBox->setGeometry(QRect(100, 90, 101, 22));
        BitBox = new QComboBox(centralWidget);
        BitBox->addItem(QString());
        BitBox->setObjectName(QString::fromUtf8("BitBox"));
        BitBox->setGeometry(QRect(100, 130, 101, 22));
        ParityBox = new QComboBox(centralWidget);
        ParityBox->addItem(QString());
        ParityBox->setObjectName(QString::fromUtf8("ParityBox"));
        ParityBox->setGeometry(QRect(100, 170, 101, 22));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 170, 71, 31));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 200, 61, 31));
        StopBox = new QComboBox(centralWidget);
        StopBox->addItem(QString());
        StopBox->setObjectName(QString::fromUtf8("StopBox"));
        StopBox->setGeometry(QRect(100, 210, 101, 22));
        OpenSerialButton = new QPushButton(centralWidget);
        OpenSerialButton->setObjectName(QString::fromUtf8("OpenSerialButton"));
        OpenSerialButton->setGeometry(QRect(100, 240, 101, 31));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(320, 10, 221, 291));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(270, 320, 221, 31));
        SendButton = new QPushButton(centralWidget);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));
        SendButton->setGeometry(QRect(500, 320, 111, 31));
        SendButton_2 = new QPushButton(centralWidget);
        SendButton_2->setObjectName(QString::fromUtf8("SendButton_2"));
        SendButton_2->setGeometry(QRect(500, 360, 111, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 694, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        BaudBox->setCurrentIndex(0);
        BitBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        BaudBox->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        BaudBox->setItemText(1, QCoreApplication::translate("MainWindow", "19200", nullptr));
        BaudBox->setItemText(2, QCoreApplication::translate("MainWindow", "38400", nullptr));
        BaudBox->setItemText(3, QCoreApplication::translate("MainWindow", "57600", nullptr));
        BaudBox->setItemText(4, QCoreApplication::translate("MainWindow", "115200", nullptr));

        BitBox->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));

        ParityBox->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        StopBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));

        OpenSerialButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        SendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        SendButton_2->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
