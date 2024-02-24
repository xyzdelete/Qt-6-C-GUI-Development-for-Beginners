#include "widget.hpp"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QWidget* widget{ new QWidget{ this } };

    QVBoxLayout* layout{ new QVBoxLayout{} };

    layout->addWidget(new QPushButton{ "Button1", this });
    layout->addWidget(new QPushButton{ "Button2", this });
    layout->addWidget(new QPushButton{ "Button3", this });

    QPushButton* button4{ new QPushButton{ "Button4", this } };
    connect(button4,
            &QPushButton::clicked,
            [=]() { qDebug() << "Button4 from custom tab clicked"; });
    layout->addWidget(button4);
    layout->addSpacerItem(new QSpacerItem{ 100, 200 });

    widget->setLayout(layout);

    ui->tabWidget->insertTab(0, widget, "My custom tab");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_3_clicked()
{
    qDebug() << "Clicked on the button in the tab 3";
}
