#include "widget.hpp"
#include "./ui_widget.h"

#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_writePushButton_clicked()
{
    QString fileName{ QFileDialog::getSaveFileName(ui->readPushButton, "Save As") };
    if (!fileName.isEmpty())
    {
        QFile file{ fileName };

        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        {
            QTextStream out{ &file };
            out << ui->textEdit->toPlainText() << "\n";

            file.close();
        }
    }
    return;
}

void Widget::on_readPushButton_clicked()
{
    QString fileContent{};

    QString fileName{ QFileDialog::getOpenFileName(ui->readPushButton, "Open File") };

    if (!fileName.isEmpty())
    {
        QFile file{ fileName };

        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in{ &file };

            QString line = in.readLine();

            while (!line.isNull())
            {
                fileContent.append(line);
                line = in.readLine();
            }
            file.close();
        }

        ui->textEdit->clear();
        ui->textEdit->setPlainText(fileContent);
    }
    return;
}

void Widget::on_copyPushButton_clicked()
{
    QString src_file_name{ ui->sourceFileLineEdit->text() };
    QString dest_file_name{ ui->destinationFileLineEdit->text() };

    if (!src_file_name.isEmpty() && !dest_file_name.isEmpty())
    {
        QFile file{ src_file_name };
        if (file.copy(dest_file_name))
        {
            QMessageBox::information(ui->copyPushButton, "Success", "Copy successfull");
        }
        else
        {
            QMessageBox::information(ui->copyPushButton, "Failure", "Copy failed");
        }
    }
    return;
}

void Widget::on_selectFilePushButton_clicked()
{
    QString fileName{ QFileDialog::getOpenFileName(ui->selectFilePushButton, "Choose File") };
    if (!fileName.isEmpty())
    {
        ui->sourceFileLineEdit->setText(fileName);
    }
    return;
}
