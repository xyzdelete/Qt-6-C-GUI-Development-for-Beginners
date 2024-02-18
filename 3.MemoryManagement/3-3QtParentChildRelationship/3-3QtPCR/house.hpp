#pragma once

#include <QObject>

class House : public QObject
{
    Q_OBJECT
public:
    explicit House(QObject* parent = nullptr, const QString& descr = "") noexcept;
    ~House() noexcept;
    void print_info() const noexcept;

private:
    QString m_descr{};

signals:
};
