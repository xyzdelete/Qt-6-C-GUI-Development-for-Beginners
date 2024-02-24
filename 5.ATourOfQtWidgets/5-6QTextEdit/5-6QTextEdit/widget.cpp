#include "widget.hpp"
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupUi();
    setFixedSize(400, 400);
}

Widget::~Widget() {}

void Widget::setupUi()
{
    QFont labelFont{ "Times", 10, QFont::Bold };

    QLabel* mLabel{ new QLabel{ "This is my text", this } };
    mLabel->setFont(labelFont);
    mLabel->move(100, 25);

    QTextEdit* textEdit{ new QTextEdit{ this } };
    textEdit->move(70, 55);

    connect(textEdit, &QTextEdit::textChanged, [=]() { qDebug() << "Text Changed"; });

    // Copy, Cut and paste
    QPushButton* copyButton{ new QPushButton{ "Copy", this } };
    copyButton->setMinimumSize(50, 25);
    copyButton->move(10, 250);
    connect(copyButton, &QPushButton::clicked, [=]() { textEdit->copy(); });

    QPushButton* cutButton{ new QPushButton{ "Cut", this } };
    cutButton->setMinimumSize(50, 25);
    cutButton->move(110, 250);
    connect(cutButton, &QPushButton::clicked, [=]() { textEdit->cut(); });

    QPushButton* pasteButton{ new QPushButton{ "Paste", this } };
    pasteButton->setMinimumSize(50, 25);
    pasteButton->move(210, 250);
    connect(pasteButton, &QPushButton::clicked, [=]() { textEdit->paste(); });

    QPushButton* undoButton{ new QPushButton{ "Undo", this } };
    undoButton->setMinimumSize(50, 25);
    undoButton->move(10, 280);
    connect(undoButton, &QPushButton::clicked, [=]() { textEdit->undo(); });

    QPushButton* redoButton{ new QPushButton{ "Redo", this } };
    redoButton->setMinimumSize(50, 25);
    redoButton->move(110, 280);
    connect(redoButton, &QPushButton::clicked, [=]() { textEdit->redo(); });

    QPushButton* plainTextButton{ new QPushButton{ "Plain text", this } };
    plainTextButton->setMinimumSize(100, 25);
    plainTextButton->move(10, 310);
    connect(plainTextButton,
            &QPushButton::clicked,
            [=]() { textEdit->setPlainText("Sed blababalablw eii2 d nfii tgi"); });

    QPushButton* htmlButton{ new QPushButton{ "HTML", this } };
    htmlButton->setMinimumSize(100, 25);
    htmlButton->move(120, 310);
    connect(htmlButton,
            &QPushButton::clicked,
            [=]()
            {
                textEdit->setHtml(R"(<!DOCTYPE html>
                                <html>
                                <head>
                                <title>Page Title</title>
                                </head>
                                <body>
                                
                                <h1>My First Heading</h1>
                                <p>My first paragraph.</p>
                                
                                </body>
                                </html>)");
            });

    QPushButton* grabTextButton{ new QPushButton{ "Grab text", this } };
    grabTextButton->setMinimumSize(100, 24);
    grabTextButton->move(10, 340);
    connect(grabTextButton, &QPushButton::clicked, [=]() { qDebug() << textEdit->toPlainText(); });

    QPushButton* grabHtmlButton{ new QPushButton{ "Grab HTML", this } };
    grabHtmlButton->setMinimumSize(100, 24);
    grabHtmlButton->move(120, 340);
    connect(grabHtmlButton, &QPushButton::clicked, [=]() { qDebug() << textEdit->toHtml(); });
}
