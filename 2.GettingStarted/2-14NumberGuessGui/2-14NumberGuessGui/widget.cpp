#include "widget.hpp"
#include "./ui_widget.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Set up the seed
    std::srand(std::time(nullptr));
    // Generate number [1; 10]
    secret_number = std::rand() % 10 + 1;
    qDebug() << "Secret number generated: " << QString::number(secret_number);

    // Disable start over button
    ui->startOverButton->setDisabled(true);

    ui->messageLabel->setText("");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_guessButton_clicked()
{
    qDebug() << "on_guessButton_clicked";
    guess_number = ui->numberSpinbox->value();
    qDebug() << "User guessed: " << QString::number(guess_number);

    // Check if the user guessed right
    if (guess_number == secret_number)
    {
        // Show the congratulations message
        ui->messageLabel->setText("Congratulations, the number is " + QString::number(guess_number));

        // Button housekeeping
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    }
    else
    {
        if (secret_number < guess_number)
        {
            ui->messageLabel->setText("Number is lower than that");
        }
        else if (secret_number > guess_number)
        {
            ui->messageLabel->setText("Number is higher than that");
        }
    }
}

void Widget::on_startOverButton_clicked()
{
    qDebug() << "on_startOverButton_clicked";

    // Enable the Guess button
    ui->guessButton->setDisabled(false);

    // Disable the Start Over button
    ui->startOverButton->setDisabled(true);

    // Put the spinbox back to 1
    ui->numberSpinbox->setValue(1);

    // Regenerate the random number
    secret_number = std::rand() % 10 + 1;

    // Clear the message label
    ui->messageLabel->setText("");
}
