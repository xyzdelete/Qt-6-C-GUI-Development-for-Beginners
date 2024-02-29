#include "widget.hpp"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonListItems_clicked()
{
    for (std::size_t i{}; i < static_cast<std::size_t>(ui->tableWidget->rowCount()); ++i)
    {
        for (std::size_t j{}; j < static_cast<std::size_t>(ui->tableWidget->columnCount()); ++j)
        {
            auto* const item_ptr{ ui->tableWidget->item(i, j) };
            if (item_ptr)
            {
                QVariant data{ item_ptr->data(Qt::DisplayRole) };
                qDebug() << data.toString();
            }
            else
            {
                qDebug() << "No data";
            }
        }
    }
}

void Widget::on_pushButtonSetItem_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->insertColumn(ui->tableWidget->columnCount());

    QTableWidgetItem* newItem{ new QTableWidgetItem{ "Hello" } };
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1,
                             ui->tableWidget->columnCount() - 1,
                             newItem);
}
