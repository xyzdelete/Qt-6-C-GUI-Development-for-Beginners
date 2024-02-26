#include "widget.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setStyleSheet("QPushButton{background-color: yellow; color: blue;}");
    Widget w;
    w.show();
    return a.exec();
}
