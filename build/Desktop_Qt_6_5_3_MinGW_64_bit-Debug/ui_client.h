/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *IP;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *port;
    QProgressBar *progressBar;
    QPushButton *connect;

    void setupUi(QWidget *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName("client");
        client->resize(400, 300);
        widget_4 = new QWidget(client);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(50, 50, 261, 171));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName("widget_3");
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(widget_3);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        IP = new QLineEdit(widget);
        IP->setObjectName("IP");

        horizontalLayout->addWidget(IP);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        port = new QLineEdit(widget_2);
        port->setObjectName("port");

        horizontalLayout_2->addWidget(port);


        verticalLayout->addWidget(widget_2);

        progressBar = new QProgressBar(widget_3);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);


        horizontalLayout_3->addWidget(widget_3);

        connect = new QPushButton(widget_4);
        connect->setObjectName("connect");

        horizontalLayout_3->addWidget(connect);


        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QWidget *client)
    {
        client->setWindowTitle(QCoreApplication::translate("client", "Form", nullptr));
        label->setText(QCoreApplication::translate("client", "\345\257\271\346\226\271IP", nullptr));
        label_2->setText(QCoreApplication::translate("client", "\345\257\271\346\226\271\347\253\257\345\217\243", nullptr));
        connect->setText(QCoreApplication::translate("client", "connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
