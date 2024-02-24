#include "widget.hpp"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel* first_name_label = new QLabel{ "First name", this };
    first_name_label->setMinimumSize(70, 50);
    first_name_label->move(10, 10);

    QLineEdit* first_name_line_edit = new QLineEdit{ this };
    first_name_line_edit->setMinimumSize(200, 50);
    first_name_line_edit->move(100, 10);

    QLabel* last_name_label = new QLabel{ "Last name", this };
    last_name_label->setMinimumSize(70, 50);
    last_name_label->move(10, 70);

    QLineEdit* last_name_line_edit = new QLineEdit{ this };
    last_name_line_edit->setMinimumSize(200, 50);
    last_name_line_edit->move(100, 70);

    QLabel* city_label = new QLabel{ "City", this };
    city_label->setMinimumSize(70, 50);
    city_label->move(10, 130);

    QLineEdit* city_line_edit = new QLineEdit{ this };
    city_line_edit->setMinimumSize(200, 50);
    city_line_edit->move(100, 130);

    QFont button_font{ "Times", 20, QFont::Bold };
    QPushButton* button = new QPushButton{ "Grab data", this };
    button->setFont(button_font);
    button->move(80, 190);

    connect(button,
            &QPushButton::clicked,
            [=]()
            {
                QString first_name = first_name_label->text();
                QString last_name = last_name_line_edit->text();
                QString city = city_line_edit->text();

                if (!first_name.isEmpty() && !last_name.isEmpty() && !city.isEmpty())
                {
                    qDebug() << " First name is: " << first_name;
                    qDebug() << " Last name is: " << last_name;
                    qDebug() << " City is: " << city;
                }
                else
                {
                    qDebug() << "One field is empty";
                }
            });

    // connect(first_name_line_edit,
    //         &QLineEdit::cursorPositionChanged,
    //         [=]()
    //         { qDebug() << "The cursor position is: " << first_name_line_edit->cursorPosition(); });

    // connect(first_name_line_edit,
    //         &QLineEdit::editingFinished,
    //         [=]() { qDebug() << "Editing finished: "; });

    // connect(first_name_line_edit,
    //         &QLineEdit::returnPressed,
    //         [=]() { qDebug() << "Return pressed: "; });

    // connect(first_name_line_edit,
    //         &QLineEdit::selectionChanged,
    //         [=]() { qDebug() << "Selection changed: "; });

    // connect(first_name_line_edit,
    //         &QLineEdit::textChanged,
    //         [=]() { qDebug() << "Text changed: " << first_name_line_edit->text(); });

    // connect(first_name_line_edit,
    //         &QLineEdit::textEdited,
    //         [=]() { qDebug() << "Text edited and changed to: " << first_name_line_edit->text(); });

    // last_name_line_edit->setText("Say your last name");

    first_name_line_edit->setPlaceholderText("First name");
    last_name_line_edit->setPlaceholderText("Last name");
    city_line_edit->setPlaceholderText("City");
}

Widget::~Widget() {}
