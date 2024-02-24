#include "widget.hpp"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* button = new QPushButton{ this };
    button->setText("ClickMe");
    button->move(200, 200);

    connect(button,
            &QPushButton::clicked,
            [=]()
            {
                QMessageBox message{ this };
                message.setMinimumSize(700, 200);
                message.setWindowTitle("Message title");
                message.setText("Something happened");
                message.setInformativeText("Do you want to do something about it?");
                message.setIcon(QMessageBox::Critical);
                message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

                // int ret{ message.exec() };

                // int ret{ QMessageBox::critical(
                //     this,
                //     "Message title",
                //     "Something happened. Do you want to do something about it?",
                //     QMessageBox::Ok | QMessageBox::Cancel) };

                // int ret{ QMessageBox::information(
                //     this,
                //     "Message title",
                //     "Something happened. Do you want to do something about it?",
                //     QMessageBox::Ok | QMessageBox::Cancel) };

                // int ret{ QMessageBox::question(
                //     this,
                //     "Message title",
                //     "Something happened. Do you want to do something about it?",
                //     QMessageBox::Ok | QMessageBox::Cancel) };

                int ret{ QMessageBox::warning(
                    this,
                    "Message title",
                    "Something happened. Do you want to do something about it?",
                    QMessageBox::Ok | QMessageBox::Cancel) };

                if (ret == QMessageBox::Ok)
                {
                    qDebug() << "User clicked on Ok";
                }
                else if (ret == QMessageBox::Cancel)
                {
                    qDebug() << "User clicked on Cancel";
                }
            });
}

Widget::~Widget() {}
