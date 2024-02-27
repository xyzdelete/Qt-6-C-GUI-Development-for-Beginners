#include "widget.hpp"
#include "./ui_widget.h"
#include <QColor>
#include <QColorDialog>
#include <QSettings>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    for (int i{}; i < 9; ++i)
    {
        m_color_list.append(Qt::black);
    }
    on_loadButton_clicked();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonOne_clicked()
{
    QColor color{
        QColorDialog::getColor(m_color_list[0], ui->pushButtonOne, "Choose BackGroundColor")
    };
    if (color.isValid())
    {
        m_color_list[0] = color;

        QString css{ QString{ "background-color: %1" }.arg(color.name()) };
        ui->pushButtonOne->setStyleSheet(css);
    }
}

void Widget::on_pushButtonTwo_clicked()
{
    QColor color{
        QColorDialog::getColor(m_color_list[1], ui->pushButtonTwo, "Choose BackGroundColor")
    };
    if (color.isValid())
    {
        m_color_list[1] = color;

        QString css{ QString{ "background-color: %1" }.arg(color.name()) };
        ui->pushButtonTwo->setStyleSheet(css);
    }
}

void Widget::on_pushButtonThree_clicked()
{
    QColor color{
        QColorDialog::getColor(m_color_list[2], ui->pushButtonThree, "Choose BackGroundColor")
    };
    if (color.isValid())
    {
        m_color_list[2] = color;

        QString css{ QString{ "background-color: %1" }.arg(color.name()) };
        ui->pushButtonThree->setStyleSheet(css);
    }
}

void Widget::on_pushButtonFour_clicked()
{
    QColor color{
        QColorDialog::getColor(m_color_list[3], ui->pushButtonFour, "Choose BackGroundColor")
    };
    if (color.isValid())
    {
        m_color_list[3] = color;

        QString css{ QString{ "background-color: %1" }.arg(color.name()) };
        ui->pushButtonFour->setStyleSheet(css);
    }
}

void Widget::on_pushButtonFive_clicked()
{
    QColor color{
        QColorDialog::getColor(m_color_list[4], ui->pushButtonFive, "Choose BackGroundColor")
    };
    if (color.isValid())
    {
        m_color_list[4] = color;

        QString css{ QString{ "background-color: %1" }.arg(color.name()) };
        ui->pushButtonFive->setStyleSheet(css);
    }
}

void Widget::on_pushButtonSix_clicked()
{
    QColor color{
        QColorDialog::getColor(m_color_list[5], ui->pushButtonSix, "Choose BackGroundColor")
    };
    if (color.isValid())
    {
        m_color_list[5] = color;

        QString css{ QString{ "background-color: %1" }.arg(color.name()) };
        ui->pushButtonSix->setStyleSheet(css);
    }
}

void Widget::on_pushButtonSeven_clicked()
{
    QColor color{
        QColorDialog::getColor(m_color_list[6], ui->pushButtonSeven, "Choose BackGroundColor")
    };
    if (color.isValid())
    {
        m_color_list[6] = color;

        QString css{ QString{ "background-color: %1" }.arg(color.name()) };
        ui->pushButtonSeven->setStyleSheet(css);
    }
}

void Widget::on_pushButtonEight_clicked()
{
    QColor color{
        QColorDialog::getColor(m_color_list[7], ui->pushButtonEight, "Choose BackGroundColor")
    };
    if (color.isValid())
    {
        m_color_list[7] = color;

        QString css{ QString{ "background-color: %1" }.arg(color.name()) };
        ui->pushButtonEight->setStyleSheet(css);
    }
}

void Widget::on_pushButtonNine_clicked()
{
    QColor color{
        QColorDialog::getColor(m_color_list[8], ui->pushButtonNine, "Choose BackGroundColor")
    };
    if (color.isValid())
    {
        m_color_list[8] = color;

        QString css{ QString{ "background-color: %1" }.arg(color.name()) };
        ui->pushButtonNine->setStyleSheet(css);
    }
}

void Widget::on_saveButton_clicked()
{
    save_color("button1", m_color_list[0]);
    save_color("button2", m_color_list[1]);
    save_color("button3", m_color_list[2]);
    save_color("button4", m_color_list[3]);
    save_color("button5", m_color_list[4]);
    save_color("button6", m_color_list[5]);
    save_color("button7", m_color_list[6]);
    save_color("button8", m_color_list[7]);
    save_color("button9", m_color_list[8]);
}

void Widget::on_loadButton_clicked()
{
    set_loaded_color("button1", 0, ui->pushButtonOne);
    set_loaded_color("button2", 1, ui->pushButtonTwo);
    set_loaded_color("button3", 2, ui->pushButtonThree);
    set_loaded_color("button4", 3, ui->pushButtonFour);
    set_loaded_color("button5", 4, ui->pushButtonFive);
    set_loaded_color("button6", 5, ui->pushButtonSix);
    set_loaded_color("button7", 6, ui->pushButtonSeven);
    set_loaded_color("button8", 7, ui->pushButtonEight);
    set_loaded_color("button9", 8, ui->pushButtonNine);
}

void Widget::save_color(QString key, QColor color)
{
    int red{ color.red() };
    int green{ color.green() };
    int blue{ color.blue() };

    QSettings settings{ "Arturs", "SettingsDemo" };
    settings.beginGroup("ButtonColor");
    settings.setValue(key + "r", red);
    settings.setValue(key + "g", green);
    settings.setValue(key + "b", blue);
    settings.endGroup();
}

QColor Widget::load_color(QString key)
{
    int red{};
    int green{};
    int blue{};

    QSettings settings{ "Arturs", "SettingsDemo" };
    settings.beginGroup("ButtonColor");
    red = settings.value(key + "r", QVariant{ 0 }).toInt();
    green = settings.value(key + "g", QVariant{ 0 }).toInt();
    blue = settings.value(key + "b", QVariant{ 0 }).toInt();
    settings.endGroup();

    return QColor{ red, green, blue };
}

void Widget::set_loaded_color(QString key, int index, QPushButton* button)
{
    QColor color{ load_color(key) };
    m_color_list[index] = color;
    QString css = QString{ "background-color: %1" }.arg(color.name());
    button->setStyleSheet(css);
}
