#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

    // QWidget interface
private:
    virtual QSize sizeHint() const override;
    QAction* quitAction{};
};
