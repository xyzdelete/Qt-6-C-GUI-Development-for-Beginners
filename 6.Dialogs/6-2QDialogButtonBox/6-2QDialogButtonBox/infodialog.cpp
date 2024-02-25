#include "infodialog.hpp"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

QString InfoDialog::position() const
{
    return m_position;
}

QString InfoDialog::favorite_os() const
{
    return m_favorite_os;
}

void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton = ui->buttonBox->standardButton(button);

    if (stdButton == QDialogButtonBox::Ok)
    {
        accept();
        qDebug() << "Ok button Clicked";
    }
    else if (stdButton == QDialogButtonBox::Save)
    {
        qDebug() << "Save button Clicked";
    }
    else if (stdButton == QDialogButtonBox::Open)
    {
        qDebug() << "Open button Clicked";
    }
    else if (stdButton == QDialogButtonBox::SaveAll)
    {
        qDebug() << "SaveAll button Clicked";
    }
    else if (stdButton == QDialogButtonBox::Cancel)
    {
        reject();
        qDebug() << "Cancel button Clicked";
    }
}
