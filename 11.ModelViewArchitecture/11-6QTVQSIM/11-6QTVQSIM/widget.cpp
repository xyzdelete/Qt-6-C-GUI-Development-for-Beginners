#include "widget.hpp"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QStandardItemModel(4, 4, ui->tableView);
    for (int row = 0; row < model->rowCount(); ++row)
    {
        for (int column = 0; column < model->columnCount(); ++column)
        {
            QStandardItem *item = new QStandardItem(
                QString("row %0, column %1").arg(row).arg(column));
            model->setItem(row, column, item);
        }
    }

    ui->tableView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonReadData_clicked()
{
    for (int row = 0; row < model->rowCount(); ++row)
    {
        for (int column = 0; column < model->columnCount(); ++column)
        {
            const auto index{ model->index(row, column, QModelIndex()) };
            const auto data{ index.data() };
            qDebug() << data.toString();
        }
        qDebug() << "===";
    }
}
