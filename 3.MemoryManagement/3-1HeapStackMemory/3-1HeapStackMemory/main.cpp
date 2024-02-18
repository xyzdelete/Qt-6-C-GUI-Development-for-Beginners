#include <QCoreApplication>
#include <QDebug>

#include "house.hpp"

void do_stuff()
{
    // House h1{ nullptr, "First" };

    // h1.print_info();

    House* p_h1 = new House{ nullptr, "First" };

    p_h1->print_info();

    delete p_h1;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    do_stuff();

    qDebug() << "Done!";

    return a.exec();
}
