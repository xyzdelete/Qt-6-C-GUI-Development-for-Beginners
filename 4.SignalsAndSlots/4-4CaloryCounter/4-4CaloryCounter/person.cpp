#include "person.hpp"

Person::Person(QObject *parent)
    : QObject{ parent }
{
}

double Person::weight() const
{
    return m_weight;
}

void Person::setWeight(double weight)
{
    if (m_weight != weight)
    {
        m_weight = weight;
        emit weightChanged();
    }
}
