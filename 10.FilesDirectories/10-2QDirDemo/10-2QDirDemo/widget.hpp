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
    void on_pushButtonChooseDir_clicked();

    void on_pushButtonCreateDir_clicked();

    void on_pushButtonDirExists_clicked();

    void on_pushButtonDirOrFile_clicked();

    void on_pushButtonFolderContent_clicked();

private:
    Ui::Widget *ui;
};
