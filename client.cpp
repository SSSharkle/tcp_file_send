#include "client.h"
#include "ui_client.h"
#include <QDebug>
#include <QMessageBox>

client::client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
    tcpsoket=new QTcpSocket(this);

    isok=true;

    ui->progressBar->setValue(0);

    connect(tcpsoket,&QTcpSocket::readyRead,[=](){
        QByteArray s=tcpsoket->readAll();
        if(true==isok)
        {
            isok=false;


            //接受文件信息并拆包
            filename=QString(s).section("##",0,0);
            filesize=QString(s).section("##",1,1).toInt();
            receivesize=0;


            //创建文件为只写
            file.setFileName(filename);

            bool isfine = file.open(QIODevice::WriteOnly);
            if(isfine==false)
            {
                qDebug()<<"文件打开失败";

                tcpsoket->disconnectFromHost();
                tcpsoket->close();
            }
            ui->progressBar->setMinimum(0);
            ui->progressBar->setMaximum(filesize/1024);
            ui->progressBar->setValue(0);

        }
        else
            {
            qint64 len= file.write(s);
            receivesize+=len;

            //更新进度条
            ui->progressBar->setValue(receivesize/1024);

            if(receivesize==filesize)
            {
                QMessageBox::information(this,"完成","文件已全部接收");
                tcpsoket->write("file done");
                file.close();

                tcpsoket->disconnectFromHost();
                tcpsoket->close();
            }
        }
    });
}

client::~client()
{
    delete ui;
}

void client::on_connect_clicked()
{
    QString ip=ui->IP->text();
    qint16 port=ui->port->text().toInt();

    tcpsoket->connectToHost(ip,port);
}

