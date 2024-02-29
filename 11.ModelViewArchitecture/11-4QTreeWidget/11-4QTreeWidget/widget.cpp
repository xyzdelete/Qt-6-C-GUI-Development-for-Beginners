#include "widget.hpp"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);

    // Set header data
    ui->treeWidget->setHeaderLabels(QStringList{} << "ID"
                                                  << "Name");

    // Add data
    QTreeWidgetItem* treeItem1{ new QTreeWidgetItem{ ui->treeWidget } };
    treeItem1->setText(0, "11");
    treeItem1->setText(1, "Snow");

    QTreeWidgetItem* treeItem2{ new QTreeWidgetItem{ ui->treeWidget } };
    treeItem2->setText(0, "22");
    treeItem2->setText(1, "David");

    QTreeWidgetItem* treeItem3{ new QTreeWidgetItem{} };
    treeItem3->setText(0, "33");
    treeItem3->setText(1, "Steve");

    treeItem2->addChild(treeItem3);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonListItems_clicked()
{
    for (std::size_t i{}; i < static_cast<std::size_t>(ui->treeWidget->topLevelItemCount()); ++i)
    {
        auto* const item{ ui->treeWidget->topLevelItem(i) };
        if (item)
        {
            qDebug() << item->data(0, Qt::DisplayRole).toString() << ", "
                     << item->data(1, Qt::DisplayRole).toString();

            if (item->childCount() != 0)
            {
                for (std::size_t j{};
                     j < static_cast<std::size_t>(ui->treeWidget->topLevelItemCount());
                     ++j)
                {
                    auto* const child{ item->child(j) };
                    if (child)
                    {
                        qDebug() << "----" << child->data(0, Qt::DisplayRole).toString() << ", "
                                 << child->data(1, Qt::DisplayRole).toString();
                    }
                }
            }
        }
    }
}
