#include "widget.hpp"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QStringListModel{ this };

    QStringList list{};
    list << "Cow"
         << "Rooster"
         << "Lion"
         << "Hyena"
         << "Buffalo";

    model->setStringList(list);

    ui->listView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonShowData_clicked()
{
    // QStringList list{ model->stringList() };
    // qDebug() << "The current data is: " << list;

    for (std::size_t i{}; i < static_cast<std::size_t>(model->rowCount(QModelIndex())); ++i)
    {
        const auto index{ model->index(static_cast<int>(i), 0, QModelIndex()) };
        //const auto data{ model->data(index) };
        const auto data{ index.data() };
        qDebug() << data.toString();
    }
}
