#include "widget.hpp"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Init members with UI values
    m_person.setWeight(ui->weightSpinBox->value());
    m_time = ui->timeSpinBox->value();
    m_speed = ui->speedSpinBox->value();

    // Connect spinboxes
    connect(ui->weightSpinBox, &QDoubleSpinBox::valueChanged, this, &Widget::weight_changed);
    connect(ui->timeSpinBox, &QDoubleSpinBox::valueChanged, this, &Widget::time_changed);
    connect(ui->speedSpinBox, &QDoubleSpinBox::valueChanged, this, &Widget::speed_changed);

    // Update the calory count
    connect(this,
            &Widget::calory_count_changed,
            [=]() { ui->caloryCountLabel->setText(QString::number(m_calory_count)); });

    calculate_calories();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::calculate_calories()
{
    // CB = [0.0215 *  KPH^3 - 0.1765 * KPH^2 + 0.8710 * KPH + 1.4577] * WKG * T
    m_calory_count = ((0.0215 * (m_speed * m_speed * m_speed)) - (0.1765 * (m_speed * m_speed))
                      + (0.8710 * m_speed) + 1.4577)
                     * m_person.weight() * m_time;
    emit calory_count_changed();
}

void Widget::weight_changed(double weight)
{
    m_person.setWeight(weight);
    calculate_calories();
}

void Widget::time_changed(double time)
{
    m_time = time;
    calculate_calories();
}

void Widget::speed_changed(double speed)
{
    m_speed = speed;
    calculate_calories();
}
