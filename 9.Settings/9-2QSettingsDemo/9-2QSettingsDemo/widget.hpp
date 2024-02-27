#pragma once

#include <QPushButton>
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
    void on_pushButtonOne_clicked();

    void on_pushButtonTwo_clicked();

    void on_pushButtonThree_clicked();

    void on_pushButtonFour_clicked();

    void on_pushButtonFive_clicked();

    void on_pushButtonSix_clicked();

    void on_pushButtonSeven_clicked();

    void on_pushButtonEight_clicked();

    void on_pushButtonNine_clicked();

    void on_saveButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::Widget *ui;
    QList<QColor> m_color_list{};

    void save_color(QString key, QColor color);
    QColor load_color(QString key);

    void set_loaded_color(QString key, int index, QPushButton *button);
};
