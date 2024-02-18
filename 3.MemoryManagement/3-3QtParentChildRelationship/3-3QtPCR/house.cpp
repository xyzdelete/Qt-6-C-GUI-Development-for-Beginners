#include "house.hpp"
#include <QDebug>

House::House(QObject* parent, const QString& descr) noexcept
    : QObject{ parent }
    , m_descr{ descr }
{
    qDebug() << "House object is constructed";
}

House::~House() noexcept
{
    qDebug() << "House object: " << m_descr << " is dying...";
}

void House::print_info() const noexcept
{
    qDebug() << "House: " << m_descr;
}
