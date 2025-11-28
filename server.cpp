#include "server.h"
#include "ui_server.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpserver= new QTcpServer(this);
    tcpserver->listen(QHostAddress::Any, 7777);

    ui->selectbutton->setEnabled(false);
    ui->sendbutton->setEnabled(false);

    connect(tcpserver, &QTcpServer::newConnection, [=]()
    {
        tcpsoket=tcpserver->nextPendingConnection();
        QString ip=tcpsoket->peerAddress().toString();
        qint16 port = tcpsoket->peerPort();

        QString tp = QString("[%1:%2]").arg(ip).arg(port);

        ui->message->setText(tp);

        ui->selectbutton->setEnabled(true);

        connect(tcpsoket,&QTcpSocket::readyRead,[=]()
        {
            QByteArray arr=tcpsoket->readAll();
            if(QString(arr)=="filedone")
            {
                QMessageBox::information(this,"infomation","all send");

                //断开服务器
                tcpsoket->disconnectFromHost();
                tcpsoket->close();

            }
        });

    });

    connect(&timer, &QTimer::timeout, [=]()
    {
       //关闭定时器
        timer.stop();

        //发送文件
        senddate();
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_selectbutton_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "open","../");

    if(filepath.isEmpty()==false)
    {


    //获取文件信息
        QFileInfo info(filepath);

        filename=info.fileName();
        filesize=info.size();
        sendsize=0;

    //打开文件为只读
        file.setFileName(filepath);

        bool isok=file.open(QIODevice::ReadOnly);
        if(isok==false)
        {
            qDebug()<<"文件打开失败";
        }

        //文件路径显示
        ui->message->append(filepath);
        ui->selectbutton->setEnabled(false);
        ui->sendbutton->setEnabled(true);


    }
    else
    {
        qDebug()<<"文件路径失效";
    }
}


void Widget::on_sendbutton_clicked()
{
    //发送文件信息
    QString str= QString("%1##%2").arg(filename).arg(filesize);
    qint64 len= tcpsoket->write(str.toUtf8().data());

    if(len>0)//成功发送
    {
        //发送真的文件内容
        //但是距离太近会导致粘包
        //所以用定时器延时，解决问题
        timer.start(20);//间隔20ms触发信号


    }
    else
    {
        qDebug()<<"发送失败";
        file.close();
        tcpsoket->disconnectFromHost();
        tcpsoket->close();
    }

}

void Widget::senddate()
{
    qint64 len = 0;
    do
    {
        char buf[4096]={0};        //读文件

        len = file.read(buf,sizeof(buf));//读了多少
        //读了多少发多少
        len=tcpsoket->write(buf,len);//返回发送的值

        sendsize+=len;     //总共发送的文件
    }while(len>0);

//     if(sendsize==filesize)
//     {
//         // ui->message->append(QString("文件发送完毕"));
//         QMessageBox::information(this,"infomation","all send");

//         //断开服务器
//         tcpsoket->disconnectFromHost();
//         tcpsoket->close();

//     }

}
