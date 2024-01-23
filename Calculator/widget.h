#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onNumClicked();
    void onMulClicked();
    void onDivClicked();
    void onAddClicked();
    void onSubClicked();
    void onEquClicked();
    void onNegClicked();

private:
    enum Operation {None, Add, Sub, Mul, Div};

    QPushButton *numbers[10] = {};
    QPushButton *mul_but_;
    QPushButton *div_but_;
    QPushButton *add_but_;
    QPushButton *sub_but_;
    QPushButton *equ_but_;
    QPushButton *neg_but_;
    QLineEdit *display_;

    Operation op = None;
    double result_ = 0;
};
#endif // WIDGET_H
