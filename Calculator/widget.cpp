#include "widget.h"
#include <QIntValidator>
#include <QDoubleValidator>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    auto const Layout = new QGridLayout(this);
    this->setLayout(Layout);
    Layout->setSizeConstraint(QLayout::SetFixedSize);
    Layout->setSpacing(1);

    for (std::size_t i=0; i<10; ++i)
    {
        numbers[i] = new QPushButton(QString::number(i), this);
        numbers[i]->setProperty("number", i);

        if (i==0) Layout->addWidget(numbers[i], 4, 1);
        else Layout->addWidget(numbers[i], (3 - ((i - 1)/3)), ((i - 1)%3));
    }
}

Widget::~Widget() {}
