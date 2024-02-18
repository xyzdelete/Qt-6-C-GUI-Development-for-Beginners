#include <QCoreApplication>
#include <QDebug>

#include <memory>

#include "house.hpp"

void do_stuff()
{
    std::unique_ptr<House> p_parent{ new House{ nullptr, "parent" } };

    House* p_house1{ new House{ p_parent.get(), "House1" } };
    House* p_house2{ new House{ p_parent.get(), "House2" } };
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Starting...";

    do_stuff();

    qDebug() << "Ending...";

    return a.exec();
}
