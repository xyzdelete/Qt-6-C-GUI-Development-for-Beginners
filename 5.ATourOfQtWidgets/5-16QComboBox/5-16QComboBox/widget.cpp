#include "widget.hpp"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Earh");
    ui->comboBox->addItem("Venus");
    ui->comboBox->addItem("Mars");
    ui->comboBox->addItem("Pluton");
    ui->comboBox->addItem("Saturn");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_captureButton_clicked()
{
    qDebug() << "The currently selected item in the combo is: " << ui->comboBox->currentText()
             << " and the index is: " << QString::number(ui->comboBox->currentIndex());
}

void Widget::on_setButton_clicked()
{
    ui->comboBox->setCurrentIndex(3);
}

void Widget::on_listValuesButton_clicked()
{
    qDebug() << "The combo box currently has " << QString::number(ui->comboBox->count())
             << " items. They are: ";
    for (int i{}; i < ui->comboBox->count(); i++)
    {
        qDebug() << "Index" << QString::number(i) << ": " << ui->comboBox->itemText(i);
    }
}
