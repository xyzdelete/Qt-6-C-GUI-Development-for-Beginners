#pragma once

#include <QFileSystemModel>
#include <QStandardItemModel>
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
    void on_pushButtonReadData_clicked();

private:
    Ui::Widget *ui;
    QFileSystemModel *dir_model;
    QStandardItemModel *standard_item_tree_model;
};
