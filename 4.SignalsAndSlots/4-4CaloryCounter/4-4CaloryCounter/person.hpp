#pragma once

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);
    double weight() const;
    void setWeight(double weight);
signals:
    void weightChanged();

private:
    double m_weight{ 0.0 };

signals:
};
