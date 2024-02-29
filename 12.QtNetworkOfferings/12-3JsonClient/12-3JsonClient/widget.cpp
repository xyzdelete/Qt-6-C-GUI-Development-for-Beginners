#include "widget.hpp"
#include "./ui_widget.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , net_manager{ new QNetworkAccessManager(this) }
    , net_reply{ nullptr }
    , m_data_buffer{ new QByteArray{} }
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete m_data_buffer;
    delete ui;
}

void Widget::dataReadyToRead()
{
    qDebug()<< "Some data available";
    m_data_buffer->append(net_reply->readAll());
}

void Widget::dataReadFinished()
{
    if( net_reply->error())
    {
        qDebug() << " Error : " << QString(*m_data_buffer) ;
    }else
    {
        qDebug() << "Data fetch finished: " << QString{ *m_data_buffer };

        QJsonDocument doc = QJsonDocument::fromJson(*m_data_buffer);

        QJsonArray array = doc.array();

        for (int i{}; i < array.size(); i++)
        {
            QJsonObject object{ array.at(i).toObject() };
            QVariantMap map{ object.toVariantMap() };
            QString title{ map["title"].toString() };
            ui->listWidget->addItem("[" + QString::number(i + 1) + "] " + title);
        }
    }
}

void Widget::on_pushButtonFetch_clicked()
{
    //Initialization

    //Send out the request
    const QUrl API_ENDPOINT{ "https://jsonplaceholder.typicode.com/posts" };
    QNetworkRequest request{};
    //request.setUrl(QUrl("https://www.qt.io"));
    request.setUrl(API_ENDPOINT);

    net_reply = net_manager->get(request);

    connect(net_reply, &QIODevice::readyRead, this, &Widget::dataReadyToRead);
    connect(net_reply, &QNetworkReply::finished, this, &Widget::dataReadFinished);
}
