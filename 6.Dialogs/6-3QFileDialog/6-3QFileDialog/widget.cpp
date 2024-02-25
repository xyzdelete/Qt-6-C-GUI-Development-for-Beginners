#include "widget.hpp"
#include "./ui_widget.h"
#include <QFileDialog>

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

void Widget::on_chooseButton_clicked()
{
    // Get existing Directory
    // QString dir{ QFileDialog::getExistingDirectory(this,
    //                                                tr("Open Directory"),
    //                                                QString{},
    //                                                QFileDialog::ShowDirsOnly
    //                                                    | QFileDialog::DontResolveSymlinks) };
    // if (!dir.isEmpty())
    // {
    //     qDebug() << "Your chosed dir is: " << dir;
    // }
    // else
    // {
    //     qDebug() << "Your didn't choose anything...";
    // }

    // Get opened file name
    // QString fileName{ QFileDialog::getOpenFileName(this,
    //                                                tr("Open File"),
    //                                                QString{},
    //                                                tr("Images (*.png *.xpm *.jpg)")) };
    // if (!fileName.isEmpty())
    // {
    //     qDebug() << "Your chosed fileName is: " << fileName;
    // }
    // else
    // {
    //     qDebug() << "Your didn't choose anything...";
    // }

    // Get opened file names
    // QStringList fileNameNames{ QFileDialog::getOpenFileNames(this,
    //                                                          tr("Open Files"),
    //                                                          QString{},
    //                                                          tr("Images (*.png *.xpm *.jpg)")) };
    // if (!fileNameNames.isEmpty())
    // {
    //     qDebug() << "Your chosen files is: " << fileNameNames;
    // }
    // else
    // {
    //     qDebug() << "Your didn't choose anything...";
    // }

    // Get saved filename

    QStringList fileName{ QFileDialog::getSaveFileName(this,
                                                       tr("Save File"),
                                                       QString{},
                                                       tr("Images (*.png *.xpm *.jpg)")) };
    if (!fileName.isEmpty())
    {
        qDebug() << "Your chosen file is: " << fileName;
    }
    else
    {
        qDebug() << "Your didn't choose anything...";
    }
}
