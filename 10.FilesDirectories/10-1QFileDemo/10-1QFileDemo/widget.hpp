#pragma once

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
    void on_writePushButton_clicked();

    void on_readPushButton_clicked();

    void on_copyPushButton_clicked();

    void on_selectFilePushButton_clicked();

private:
    Ui::Widget *ui;
};
