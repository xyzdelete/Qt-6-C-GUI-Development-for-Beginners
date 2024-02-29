#include "widget.hpp"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QFileSystemModel
    // QString path{ "C:/" };

    // dir_model = new QFileSystemModel{ this };
    // dir_model->setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);
    // dir_model->setRootPath(path);

    // ui->treeView->setModel(dir_model);
    // ui->listView->setModel(dir_model);

    // QStandardItemModel
    standard_item_tree_model = new QStandardItemModel{ this };
    QStandardItem* parentItem{ standard_item_tree_model->invisibleRootItem() };
    for (int i{}; i < 4; ++i)
    {
        QStandardItem* item{ new QStandardItem{ QString{ "item %0" }.arg(i) } };
        parentItem->appendRow(item);
        parentItem = item;
    }
    ui->treeView->setModel(standard_item_tree_model);
    ui->listView->setModel(standard_item_tree_model);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonReadData_clicked()
{
    // qDebug() << "Row count: " << dir_model->rowCount(QModelIndex{});
    // qDebug() << "Column count: " << dir_model->columnCount(QModelIndex{});
    // const auto index{ dir_model->index(0, 0, QModelIndex{}) };
    // const auto data{ index.data() };
    // qDebug() << "data: " << data.toString();

    qDebug() << "Row count: " << standard_item_tree_model->rowCount(QModelIndex{});
    qDebug() << "Column count: " << standard_item_tree_model->columnCount(QModelIndex{});
    const auto index{ standard_item_tree_model->index(0, 0, QModelIndex{}) };
    const auto data{ index.data() };
    qDebug() << "data: " << data.toString();
}
