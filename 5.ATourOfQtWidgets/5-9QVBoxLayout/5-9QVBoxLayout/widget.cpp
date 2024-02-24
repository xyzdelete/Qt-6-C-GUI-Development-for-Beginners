#include "widget.hpp"
#include "./ui_widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QVBoxLayout* layout{ new QVBoxLayout{ this } };
    // layout->addWidget(ui->pushButtonOne);
    // layout->addWidget(ui->pushButtonTwo);
    // layout->addWidget(ui->pushButtonThree);
    // layout->addWidget(ui->pushButtonFour);
    // layout->addWidget(ui->pushButtonFive);

    //setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
