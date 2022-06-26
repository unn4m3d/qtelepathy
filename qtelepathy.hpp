#include <QtNetwork/QLocalServer>
#include <QtNetwork/QLocalSocket>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <QtCore/QByteArray>
#include <QtCore/QString>
#include <memory>


namespace qtelepathy
{

    using packet_size_t = quint32;

    class Socket : public QObject
    {
        Q_OBJECT
    public:
        Socket(QLocalServer*);
        Socket();
        Socket(const Socket&) = delete;
        
        Socket& operator=(const Socket&) = delete;

        Q_SIGNAL void received(QString topic, QJsonObject payload);
        Q_SIGNAL void disconnected();
        Q_SLOT void transmit(QString topic, QJsonObject payload);
        Q_SLOT void transmitData(QByteArray arr);
        Q_SLOT void connectToServer(QString serverName);

        void wait();
        void waitWritten();

        Q_SLOT void waitForever();
    private:
        Q_SLOT void read();
        QByteArray m_buffer;
        QLocalSocket* m_socket;
        packet_size_t m_blockSize, m_received;
    };

    class Server : public QObject
    {
        Q_OBJECT
    public:
        Server();
        Server(const Server&) = delete;

        Server& operator=(const Server&) = delete;

        Q_SIGNAL void newConnection(Socket*);
        void listen(QString name);
        ~Server() { qDebug() << "~Server()"; }
        void wait();
        Q_SLOT void waitForever();
    private:
        Q_SLOT void connection();
        
        QLocalServer* m_server;
    };
}