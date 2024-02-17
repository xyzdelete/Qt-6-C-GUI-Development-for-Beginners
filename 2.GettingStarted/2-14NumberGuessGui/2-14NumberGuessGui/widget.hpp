#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_guessButton_clicked();
    void on_startOverButton_clicked();

private:
    Ui::Widget *ui;

    std::size_t secret_number{};
    std::size_t guess_number{};
};
