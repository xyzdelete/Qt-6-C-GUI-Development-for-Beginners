#include "widget.hpp"

#include <QApplication>
#include <QFile>

namespace
{
QString readTextFile(QString path)
{
    QFile file{ path };
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in{ &file };
        return in.readAll();
    }
    return "";
}
} // namespace

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString css{ readTextFile(":/styles/style.css") };
    a.setStyleSheet(css);
    Widget w;
    w.show();
    return a.exec();
}
