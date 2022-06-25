#include "qtelepathy.hpp"
#include <QTest>
#include <iostream>


class TestIPC : public QObject
{
    Q_OBJECT
public Q_SLOTS:
    void t1()
    {
        
        qtelepathy::Server srv;
        QString srv_name = "testsrv2";
        bool wait = true;

        connect(&srv, &qtelepathy::Server::newConnection, [](auto ptr){
            QJsonObject payload;
            payload.insert("bar", "baz");
            ptr->transmit("foo", payload);
            connect(ptr, &qtelepathy::Socket::disconnected, ptr, &qtelepathy::Socket::deleteLater);
        });
        srv.listen(srv_name);

        qtelepathy::Socket sock;
        QJsonObject payload;
        payload.insert("bar", "baz");

        

        connect(&sock, &qtelepathy::Socket::received, [&](QString t, QJsonObject p){
            QVERIFY(t == "foo");
            QVERIFY(p["bar"].toString() == "baz");
            wait = false;
        });
        sock.connectToServer(srv_name);
        
        while(wait) srv.wait();

    }
};

QTEST_MAIN(TestIPC);

#include "test1.moc"