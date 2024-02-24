#pragma once

#include <QLabel>
#include <QWidget>

class RockWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RockWidget(QWidget *parent = nullptr);
    ~RockWidget();

private slots:
    void button_clicked();

private:
    QSize sizeHint() const;
    std::unique_ptr<QLabel> label{ nullptr };
};
