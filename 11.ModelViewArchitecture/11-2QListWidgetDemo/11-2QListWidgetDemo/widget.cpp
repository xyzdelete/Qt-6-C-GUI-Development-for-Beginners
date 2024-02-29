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
    // qDebug() << "count: " << ui->listWidget->count();

    for (std::size_t i{}; i < static_cast<std::size_t>(ui->listWidget->count()); ++i)
    {
        auto* const item_ptr{ ui->listWidget->item(static_cast<int>(i)) };
        item_ptr->setToolTip("Tooltip" + QString::number(i));
        QVariant data{ item_ptr->data(Qt::DisplayRole) };
        qDebug() << data.toString();
    }
}

void Widget::on_pushButtonAddItem_clicked()
{
    ui->listWidget->addItem("Hello World");
}
