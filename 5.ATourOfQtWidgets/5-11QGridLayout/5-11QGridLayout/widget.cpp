#include "widget.hpp"
#include "./ui_widget.h"
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGridLayout* layout{ new QGridLayout{ this } };

    layout->addWidget(ui->pushButtonOne, 0, 0, 1, 1);
    layout->addWidget(ui->pushButtonTwo, 0, 1, 1, 1);
    layout->addWidget(ui->pushButtonThree, 0, 2, 2, 1);

    layout->addWidget(ui->pushButtonFour, 1, 0, 1, 1);
    layout->addWidget(ui->pushButtonFive, 1, 1, 1, 1);

    layout->addWidget(ui->pushButtonSeven, 2, 0, 1, 2);

    layout->addWidget(ui->pushButtonNine, 2, 2, 1, 1);
}

Widget::~Widget()
{
    delete ui;
}
