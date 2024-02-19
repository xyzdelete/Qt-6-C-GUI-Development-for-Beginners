#include "widget.hpp"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // String notation
    //connect(ui->myButton, SIGNAL(clicked()), this, SLOT(change_text()));

    // Functor notation with regular slots
    // connect(ui->myButton, &QPushButton::clicked, this, &Widget::change_text);

    // Lambda
    connect(ui->myButton,
            &QPushButton::clicked,
            [=]() { ui->label->setText("Some other text from Lambda"); });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_text()
{
    ui->label->setText("Some other text");
}
