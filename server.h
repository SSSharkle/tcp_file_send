#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QTimer>
#include <QMessageBox>




QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void senddate();

private slots:
    void on_selectbutton_clicked();

    void on_sendbutton_clicked();

private:
    Ui::Widget *ui;
    QTcpServer* tcpserver;
    QTcpSocket* tcpsoket;

    QString filename;
    qint64 filesize;
    qint64 sendsize;

    QFile file;

    QTimer timer;
};
#endif // SERVER_H
