#include "somedialog.hpp"
#include "ui_somedialog.h"

SomeDialog::SomeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SomeDialog)
{
    ui->setupUi(this);
}

SomeDialog::~SomeDialog()
{
    delete ui;
}
