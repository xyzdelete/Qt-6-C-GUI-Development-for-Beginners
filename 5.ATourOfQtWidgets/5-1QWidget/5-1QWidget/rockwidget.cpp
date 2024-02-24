#include "rockwidget.hpp"
#include <QDebug>
#include <QMessageBox>
#include <QPalette>
#include <QPushButton>
#include <memory>

RockWidget::RockWidget(QWidget* parent)
    : QWidget{ parent }
    , label{ new QLabel{ this } }
{
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("first line\nsecond line");
    label->show();
    label->move(50, 50);
    qDebug() << "Label: " << label.get();

    // Add a styled widget and move it around
    QPalette label1Palette;
    label1Palette.setColor(QPalette::Window, Qt::yellow);
    label1Palette.setColor(QPalette::WindowText, Qt::blue);

    QFont label1Font{ "Times", 20, QFont::Bold };

    QLabel* label1 = new QLabel{ this };
    label1->setAutoFillBackground(true);
    label1->setText("My colored label");
    label1->setFont(label1Font);
    label1->setPalette(label1Palette);
    label1->move(150, 50);

    // Add a styled widget and move it around
    QPalette label2Palette;
    label2Palette.setColor(QPalette::Window, Qt::green);
    label2Palette.setColor(QPalette::WindowText, Qt::black);

    QFont seriFont{ "Times", 20, QFont::Bold };

    QLabel* label2 = new QLabel{ this };
    label2->setAutoFillBackground(true);
    label2->setText("This is label 2");
    label2->setFont(seriFont);
    label2->setPalette(label2Palette);
    label2->move(70, 170);

    // Add a button and connect to slot
    QFont buttonFont{ "Times", 30, QFont::Bold };
    QPushButton* button = new QPushButton{ this };
    button->setText("Click me");
    button->setFont(buttonFont);
    button->move(100, 250);
    connect(button, SIGNAL(clicked()), this, SLOT(button_clicked()));
}

RockWidget::~RockWidget()
{
    qDebug() << "Destructing: " << label.get();
    qDebug() << "Destructing: " << this;
}

void RockWidget::button_clicked()
{
    QMessageBox::information(this, "Message", "You clicked on my button");
}

QSize RockWidget::sizeHint() const
{
    return QSize{ 500, 500 };
}
