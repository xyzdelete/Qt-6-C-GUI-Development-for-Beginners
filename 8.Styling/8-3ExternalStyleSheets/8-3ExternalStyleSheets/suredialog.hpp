#pragma once

#include <QDialog>

namespace Ui
{
class SureDialog;
}

class SureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SureDialog(QWidget *parent = nullptr);
    ~SureDialog();

private:
    Ui::SureDialog *ui;
};
