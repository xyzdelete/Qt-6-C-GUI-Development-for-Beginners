#pragma once

#include <QNetworkAccessManager>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void dataReadyToRead();
    void dataReadFinished();

private:
    Ui::Widget *ui;
    QNetworkAccessManager* net_manager{};
    QNetworkReply* net_reply{};
    QByteArray* m_data_buffer{};
};
