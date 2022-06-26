#include "qtelepathy.hpp"
#include <QTest>
#include <QThread>
#include <iostream>

QString srv_name = "testsrv2";
class Client : public QObject
{
    Q_OBJECT
public:
    Q_SLOT void process()
    {
        qtelepathy::Socket* sock = new qtelepathy::Socket(this);
        connect(sock, &qtelepathy::Socket::received, this, &Client::received);
        connect(sock, &qtelepathy::Socket::disconnected, sock, &qtelepathy::Socket::deleteLater);
        connect(sock, &qtelepathy::Socket::disconnected, this, &Client::finished);
        sock->connectToServer(srv_name);
        sock->waitForever();
    }

    Q_SIGNAL void received(QString, QJsonObject);
    Q_SIGNAL void finished();
};


class TestIPC : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void t1()
    {
        
        qtelepathy::Server srv;
        
        volatile bool wait = true;

        connect(&srv, &qtelepathy::Server::newConnection, [](auto ptr){
            QJsonObject payload;
            payload.insert("bar", "baz");
            ptr->transmit("foo", payload);
            connect(ptr, &qtelepathy::Socket::disconnected, ptr, &qtelepathy::Socket::deleteLater);
            ptr->waitWritten();
            
        });
        srv.listen(srv_name);

        auto thr = new QThread;
        auto cli = new Client;
        cli->moveToThread(thr);
        connect(thr, &QThread::started, cli, &Client::process);
        connect(thr, &QThread::finished, thr, &QThread::deleteLater);
        connect(cli, &Client::finished, cli, &Client::deleteLater);

        connect(cli, &Client::received, [&](QString t, QJsonObject p){
            QVERIFY(t == "foo");
            QVERIFY(p["bar"].toString() == "baz");
            thr->terminate();
        });
        thr->start();
        
        while(wait){
            srv.wait(100);
        }
        thr->terminate();

    }
};

QTEST_MAIN(TestIPC);

#include "test1.moc"