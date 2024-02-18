#include <QCoreApplication>
#include <QDebug>

#include <memory>

#include "house.hpp"

void do_stuff()
{
    // House h1{ nullptr, "First" };
    // h1.print_info();

    // House* p_h1 = new House{ nullptr, "First" };
    // p_h1->print_info();
    // delete p_h1;

    // std::unique_ptr<House> up_house_1{ new House{ nullptr, "Second" } };
    // up_house_1->print_info();

    std::shared_ptr<House> sp_house_1{ new House{ nullptr, "Second" } };
    sp_house_1->print_info();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Starting...";

    do_stuff();

    qDebug() << "Ending...";

    return a.exec();
}
