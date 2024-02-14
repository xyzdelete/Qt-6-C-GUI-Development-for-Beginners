#include <QChar>
#include <QCoreApplication>
#include <QDate>
#include <QDebug>
#include <QRect>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Date:" << QDate::currentDate();
    qDebug() << "Types:" << QString("String") << QChar('x') << QRect(0, 10, 50, 40);

    return a.exec();
}
