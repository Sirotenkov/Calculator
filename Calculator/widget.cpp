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

    QFont const font1("Courrier New", 24, QFont::Medium),
        font2("Courrier New", 20, QFont::Medium),
        font3("Courrier New", 16, QFont::ExtraLight);
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
        connect(numbers[i], &QPushButton::clicked, this, &Widget::onNumClicked);
    }

    equ_but_ = new QPushButton("=", this);
    equ_but_->setFont(font3);
    equ_but_->setFixedSize(but_size);
    Layout->addWidget(equ_but_, 4, 2);
    connect(equ_but_, &QPushButton::clicked, this, &Widget::onEquClicked);

    neg_but_ = new QPushButton("±", this);
    neg_but_->setFont(font3);
    neg_but_->setFixedSize(but_size);
    Layout->addWidget(neg_but_, 4, 0);
    connect(neg_but_, &QPushButton::clicked, this, &Widget::onNegClicked);

    div_but_ = new QPushButton("/", this);
    div_but_->setFont(font3);
    div_but_->setFixedSize(but_size);
    Layout->addWidget(div_but_, 1, 3);
    connect(div_but_, &QPushButton::clicked, this, &Widget::onDivClicked);

    mul_but_ = new QPushButton("×", this);
    mul_but_->setFont(font3);
    mul_but_->setFixedSize(but_size);
    Layout->addWidget(mul_but_, 2, 3);
    connect(mul_but_, &QPushButton::clicked, this, &Widget::onMulClicked);

    sub_but_ = new QPushButton("-", this);
    sub_but_->setFont(font3);
    sub_but_->setFixedSize(but_size);
    Layout->addWidget(sub_but_, 3, 3);
    connect(sub_but_, &QPushButton::clicked, this, &Widget::onSubClicked);

    add_but_ = new QPushButton("+", this);
    add_but_->setFont(font3);
    add_but_->setFixedSize(but_size);
    Layout->addWidget(add_but_, 4, 3);
    connect(add_but_, &QPushButton::clicked, this, &Widget::onAddClicked);

    display_ = new QLineEdit("0", this);
    Layout->addWidget(display_, 0, 0, 1, 4);
    display_->setAlignment(Qt::AlignRight);
    display_->setReadOnly(true);
    display_->setMaxLength(15);
    display_->setFont(font1);

    setLayout(Layout);
    setWindowTitle("Integer Calculator");
}

Widget::~Widget() {}

void Widget::onNumClicked()
{
    auto const number = sender()->property("number");
    auto text = display_->text();
    text.append(QString::number(number.toInt()));
    if (text.front() == '0')
        text.remove(0, 1);
    display_->setText(text);
}

void Widget::onMulClicked()
{
    op = Mul;
    result_ = display_->text().toInt();
    display_->setText("0");
}

void Widget::onDivClicked()
{
    op = Div;
    result_ = display_->text().toDouble();
    display_->setText("0");
}

void Widget::onAddClicked()
{
    op = Add;
    result_ = display_->text().toInt();
    display_->setText("0");
}

void Widget::onSubClicked()
{
    op = Sub;
    result_ = display_->text().toInt();
    display_->setText("0");
}

void Widget::onNegClicked()
{
    auto text = display_->text();
    if (text.front() == '-')
    {
        text.remove(0, 1);
    }
    else
    {
        if (text.front() != '0')
            text.insert(0, '-');
    }
    display_->setText(text);
}

void Widget::onEquClicked()
{
    auto number = display_->text().toDouble();

    switch(op)
    {
        case Add:
            result_ += number;
            break;
        case Div:
            result_ /= number;
            break;
        case Mul:
            result_ *= number;
            break;
        case Sub:
            result_ -= number;
            break;
        default:
            break;
    }
    display_->setText(QString::number(result_));
    op = None;
}
