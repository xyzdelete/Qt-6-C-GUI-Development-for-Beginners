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

void Widget::on_pushButtonChooseDir_clicked()
{
    QString fileName{ QFileDialog::getExistingDirectory(ui->pushButtonChooseDir, "Choose Dir") };
    if (!fileName.isEmpty())
    {
        ui->lineEdit->setText(fileName);
    }
    return;
}

void Widget::on_pushButtonCreateDir_clicked()
{
    QString dirPath{ ui->lineEdit->text() };
    if (!dirPath.isEmpty())
    {
        QDir dir{ dirPath };
        if (dir.exists())
        {
            QMessageBox::information(ui->pushButtonCreateDir, "Message", "Directory already exists");
        }
        else
        {
            if (dir.mkdir(dirPath))
            {
                QMessageBox::information(ui->pushButtonCreateDir, "Message", "Directory created");
            }
        }
    }
    return;
}

void Widget::on_pushButtonDirExists_clicked()
{
    QString dirPath{ ui->lineEdit->text() };
    if (!dirPath.isEmpty())
    {
        QDir dir{ dirPath };
        if (dir.exists())
        {
            QMessageBox::information(ui->pushButtonDirExists, "Message", "Directory already exists");
        }
        else
        {
            QMessageBox::information(ui->pushButtonDirExists, "Message", "Directory doesn't exist");
        }
    }
    return;
}

void Widget::on_pushButtonDirOrFile_clicked()
{
    QFileInfo fileInfo{ ui->listWidget->currentItem()->text() };
    if (fileInfo.isDir())
    {
        QMessageBox::information(ui->pushButtonDirOrFile, "Message", "This is a dir");
    }
    else if (fileInfo.isFile())
    {
        QMessageBox::information(ui->pushButtonDirOrFile, "Message", "This is a file");
    }
    else
    {
        QMessageBox::information(ui->pushButtonDirOrFile, "Message", "This is not a file or dir");
    }
}

void Widget::on_pushButtonFolderContent_clicked()
{
    ui->listWidget->clear();

    QString dirPath{ ui->lineEdit->text() };
    if (!dirPath.isEmpty())
    {
        QDir dir{ dirPath };
        if (dir.exists())
        {
            QList<QFileInfo> fileList{ dir.entryInfoList() };

            for (std::size_t i{}; i < static_cast<std::size_t>(fileList.size()); ++i)
            {
                ui->listWidget->addItem(fileList.at(i).absoluteFilePath());
            }
        }
    }
    else
    {
        QMessageBox::information(ui->pushButtonFolderContent, "Message", "Directory doesn't exist");
    }
    return;
}
