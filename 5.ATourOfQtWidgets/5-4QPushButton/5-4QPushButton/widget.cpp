#include "widget.hpp"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont button_font{ "Times", 20, QFont::Bold };
    QPushButton* button{ new QPushButton{ "Button", this } };
    button->setMinimumSize(200, 100);
    button->setFont(button_font);

    connect(button, &QPushButton::clicked, [=]() { qDebug() << "Button clicked"; });

    QPushButton* button2{ new QPushButton{ "Button", this } };
    button2->setMinimumSize(200, 100);
    button2->move(205, 0);
    button2->setFont(button_font);
    connect(button2, &QPushButton::pressed, [=]() { qDebug() << "Button pressed"; });
    connect(button2, &QPushButton::released, [=]() { qDebug() << "Button released"; });
}

Widget::~Widget() {}
