#include "rockwidget.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RockWidget widget{};
    widget.setWindowTitle("Rock Widget");
    widget.show();

    return a.exec();
}
