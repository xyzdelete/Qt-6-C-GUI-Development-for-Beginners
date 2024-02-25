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

void InfoDialog::on_okButton_clicked()
{
    QString user_position = ui->positionLineEdit->text();

    if (!user_position.isEmpty())
    {
        m_position = user_position;

        if (ui->windowsRadioButton->isChecked())
        {
            m_favorite_os = "Windows";
        }
        else if (ui->linuxRadioButton->isChecked())
        {
            m_favorite_os = "Linux";
        }
        else if (ui->macRadioButton->isChecked())
        {
            m_favorite_os = "Mac";
        }

        accept();
    }
    else
    {
        reject();
    }
}

void InfoDialog::on_cancelButton_clicked()
{
    reject();
}

QString InfoDialog::position() const
{
    return m_position;
}

QString InfoDialog::favorite_os() const
{
    return m_favorite_os;
}
