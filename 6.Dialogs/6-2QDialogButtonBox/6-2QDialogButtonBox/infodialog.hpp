#pragma once

#include <QAbstractButton>
#include <QDialog>
namespace Ui
{
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT
public:
    explicit InfoDialog(QWidget* parent = nullptr);
    InfoDialog();

    ~InfoDialog();

    QString position() const;
    QString favorite_os() const;

private slots:

    void on_buttonBox_clicked(QAbstractButton* button);

private:
    QString m_position{};
    QString m_favorite_os{};
    Ui::InfoDialog* ui{};
};
