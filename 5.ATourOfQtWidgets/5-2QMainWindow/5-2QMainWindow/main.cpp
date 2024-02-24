#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window{};
    window.setWindowTitle("Our very own main window");
    window.show();

    return a.exec();
}
