#pragma once

#include <QStringListModel>
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

private slots:
    void on_pushButtonShowData_clicked();

private:
    Ui::Widget *ui;
    QStringListModel *model;
};
