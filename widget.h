#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money{0};
    void changeMoney(int diff);
    void remainMoney(int diff);
    void initialMoney();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_tea1_clicked();

    void on_tea2_clicked();

    void on_tea3_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
