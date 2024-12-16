#ifndef CURRENCY_H
#define CURRENCY_H

#include <QMainWindow>

namespace Ui {
class Currency;
}

class Currency : public QMainWindow
{
    Q_OBJECT

public:
    explicit Currency(QWidget *parent = nullptr);
    ~Currency();

private slots:
    void on_Science_triggered();

    void on_Standard_triggered();

    void on_Programmer_triggered();

    void on_Date_triggered();

    void on_Capacity_triggered();

private:
    Ui::Currency *ui;
};

#endif // CURRENCY_H
