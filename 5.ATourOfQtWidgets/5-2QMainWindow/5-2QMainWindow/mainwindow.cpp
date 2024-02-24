#include "mainwindow.hpp"
#include "QApplication"
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow{ parent }
{
    QPushButton* button = new QPushButton{ "Hello", this };
    setCentralWidget(button);

    quitAction = new QAction{ "Quit" };

    connect(quitAction, &QAction::triggered, [=]() { QApplication::quit(); });

    QMenu* fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    statusBar()->showMessage("Uploading file ... ", 3000);
}

QSize MainWindow::sizeHint() const
{
    return QSize{ 1920, 1080 };
}
