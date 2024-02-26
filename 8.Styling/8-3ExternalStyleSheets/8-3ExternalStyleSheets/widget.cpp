#include "widget.hpp"
#include "./ui_widget.h"
#include "suredialog.hpp"

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

void Widget::on_submitButton_clicked()
{
    SureDialog* dialog{ new SureDialog{ this } };

    int ret{ dialog->exec() };
}
