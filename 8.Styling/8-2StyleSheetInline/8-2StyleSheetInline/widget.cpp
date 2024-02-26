#include "widget.hpp"
#include "./ui_widget.h"
#include "somedialog.hpp"

Widget::Widget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //ui->clickButton->setStyleSheet("QPushButton{background-color: yellow; color: blue;}");
    ui->clickButton->setStyleSheet("background-color: yellow; color: blue;");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_clickButton_clicked()
{
    SomeDialog* dialog{ new SomeDialog{ this } };

    //Set the stylesheet to parent widget
    dialog->setStyleSheet("QPushButton{background-color: yellow; color: blue;}");

    dialog->exec();
}
