#include "qtelepathy.hpp"
#include <QtCore/QDataStream>
#include <iostream>

using namespace qtelepathy;

Socket::Socket(QLocalServer* server) :
    m_socket(server->nextPendingConnection()),
    m_blockSize(0),
    m_received(0)
{
    connect(m_socket, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(read()));
    connect(m_socket, &QLocalSocket::stateChanged, this, &Socket::stateChanged);
}

Socket::Socket(QObject* parent) :
    QObject(parent),
    m_socket(new QLocalSocket(this)),
    m_blockSize(0),
    m_received(0)
{
    connect(m_socket, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
    connect(m_socket, SIGNAL(disconnected()), m_socket, SLOT(deleteLater()));
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(read()));
    connect(m_socket, &QLocalSocket::stateChanged, this, &Socket::stateChanged);
}

void Socket::connectToServer(QString name)
{
    m_socket->connectToServer(name);
}

void Socket::read()
{
    QLocalSocket* sock = (QLocalSocket*)sender();
    QDataStream in(sock);
    in.setVersion(QDataStream::Qt_5_3);

    while(true)
    {
        if(!m_blockSize)
        {
            if(sock->bytesAvailable() < sizeof(packet_size_t))
                break;

            in >> m_blockSize;
            m_received = 0;
            m_buffer.resize(m_blockSize);
            in.skipRawData(sizeof(packet_size_t));
        }

        if(m_received < m_blockSize)
        {
            int rcvd = in.readRawData(m_buffer.data() + m_received, m_blockSize - m_received);
            if(rcvd < 0)
                throw std::runtime_error("IO Error");
            m_received += rcvd;
        }

        if(m_received == m_blockSize)
        {
            m_blockSize = 0;
            QJsonParseError err;
            auto doc = QJsonDocument::fromJson(m_buffer, &err);

            if(err.error == QJsonParseError::NoError)
            {
                auto obj = doc.object();
                auto topic = obj["topic"].toString();
                auto payload = obj["payload"].toObject();

                Q_EMIT received(topic, payload);
            }
            else
            {
                throw std::runtime_error("Json Parse Error");
            }
        }
    }
}

void Socket::transmitData(QByteArray arr)
{

    QDataStream out(m_socket);
    out.setVersion(QDataStream::Qt_5_3);
    out << packet_size_t(arr.length()) << arr;
}

void Socket::transmit(QString message, QJsonObject payload)
{
    QJsonObject data;
    data.insert("topic", message);
    data.insert("payload", payload);
    QJsonDocument doc;
    doc.setObject(data);
    transmitData(doc.toJson());
    m_socket->flush();
}

void Socket::wait()
{
    m_socket->waitForReadyRead();
}

void Socket::waitForever()
{
    while(true) wait();
}

void Socket::waitWritten()
{
    while(!m_socket->waitForBytesWritten())
    {
        if(m_socket->state() == QLocalSocket::UnconnectedState)
        {
            break;
        }
    }
}

void Socket::connectAndWait()
{
    connectToServer(m_serverName);
    waitForever();
}

void Socket::setServerName(QString str)
{
    m_serverName = str;
}

Server::Server(QObject* parent) :
    QObject(parent),
    m_server(new QLocalServer(this))
{
}

void Server::listen(QString serverName)
{
    QLocalServer::removeServer(serverName);
    if(!m_server->listen(serverName))
        throw std::runtime_error("Cannot launch QLocalServer");
    connect(m_server, &QLocalServer::newConnection, this, &Server::connection);
}

void Server::connection()
{
    Q_EMIT newConnection(new Socket(m_server));
}

void Server::wait()
{
    m_server->waitForNewConnection();
}

void Server::wait(int ms)
{
    m_server->waitForNewConnection(ms);
}

void Server::waitForever()
{
    while(true) wait();
}