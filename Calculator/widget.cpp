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

    QFont const font1("Courrier New", 24, QFont::Bold);
    QFont font2("Courrier New", 20, QFont::Medium);
    QFont font3("Courrier New", 16, QFont::ExtraLight);
    QFontMetrics const metrics(font2);
    QSize const but_size(metrics.height() * 1.5, metrics.height());

    for (std::size_t i=0; i<10; ++i)
    {
        numbers[i] = new QPushButton(QString::number(i), this);
        numbers[i]->setProperty("number", i);
        numbers[i]->setFont(font2);
        numbers[i]->setFixedSize(but_size);
        if (i==0) Layout->addWidget(numbers[i], 4, 1);
        else Layout->addWidget(numbers[i], (3 - ((i - 1)/3)), ((i - 1)%3));
    }

    equ_but_ = new QPushButton("=", this);
    equ_but_->setFont(font3);
    equ_but_->setFixedSize(but_size);
    Layout->addWidget(equ_but_, 4, 2);

    neg_but_ = new QPushButton("±", this);
    neg_but_->setFont(font3);
    neg_but_->setFixedSize(but_size);
    Layout->addWidget(neg_but_, 4, 0);

}

Widget::~Widget() {}
