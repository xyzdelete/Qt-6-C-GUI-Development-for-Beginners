#include "widget.hpp"
#include "./ui_widget.h"
#include "infodialog.hpp"

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

void Widget::on_showInfoButton_clicked()
{
    InfoDialog* dialog{ new InfoDialog{ this } };
    dialog->exec();
}
