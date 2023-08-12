#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //ui->tea1->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
}

void Widget::remainMoney(int diff){
    money -= diff;
    ui->lcdNumber->display(money);
}

void Widget::initialMoney(){
    money = 0;
    ui->lcdNumber->display(money);
}

void Widget::on_pushButton_2_clicked()
{
    changeMoney(10);
    ui->lcdNumber->display(money);
}

void Widget::on_pushButton_3_clicked()
{
    changeMoney(50);

}

void Widget::on_pushButton_4_clicked()
{
    changeMoney(100);

}

void Widget::on_pushButton_5_clicked()
{
    changeMoney(500);

}

void Widget::on_tea1_clicked()
{
    if(money < 100)
        return;
    remainMoney(100);
}


void Widget::on_tea2_clicked()
{
    if(money < 150)
        return;
    remainMoney(150);
}


void Widget::on_tea3_clicked()
{
    if(money < 200)
        return;
    remainMoney(200);
}


void Widget::on_pushButton_6_clicked()
{
    QMessageBox mb;
    //mb.information(this, "Changes", "text");
    QString moneyStr = QString::number(money);

    int won500 = money/500;
    int re500 = money%500;

    int won100 = re500/100;
    int re100 = re500%100;

    int won50 = re100/50;
    int re50 = re100%50;

    int won10 = re50/10;



    QString moneyStr1 = QString::number(won500);
    QString moneyStr2 = QString::number(won100);
    QString moneyStr3 = QString::number(won50);
    QString moneyStr4 = QString::number(won10);


    mb.setText("500원: " + moneyStr1 + "개, 100원: " + moneyStr2 + "개, 50원: " + moneyStr3 + "개, 10원: " + moneyStr4 + "개");
    mb.exec();
    initialMoney();
}

