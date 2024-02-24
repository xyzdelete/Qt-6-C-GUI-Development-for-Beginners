#include <QCoreApplication>
#include <QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> list{};
    QList<QString> stringList{};

    // Put data in the list
    stringList << "I am "
               << " loving "
               << " Qt"; // ["I am", " loving", " Qt"];
    stringList.append(" a ");
    stringList.append(" lot!");

    // Get the data from the list
    qDebug() << "The first element is " << stringList.at(0);
    qDebug() << "The second element is " << stringList.at(1);
    qDebug() << "The third element is " << stringList.at(2);

    // Get the number of elements
    qDebug() << "The number of elements in my list is: " << stringList.count();

    for (int i{}; i < stringList.count(); ++i)
    {
        qDebug() << "The element at index " << QString::number(i) << " is " << stringList.at(i);
    }

    return a.exec();
}
