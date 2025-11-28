#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QFile>

namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

private slots:
    void on_connect_clicked();

private:
    Ui::client *ui;

    QTcpSocket* tcpsoket;
    bool isok;

    QString filename;
    qint64 filesize;
    qint64 receivesize;

    QFile file;


};

#endif // CLIENT_H
