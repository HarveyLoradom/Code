#ifndef CAPACITY_H
#define CAPACITY_H

#include <QMainWindow>

namespace Ui {
class Capacity;
}

class Capacity : public QMainWindow
{
    Q_OBJECT

public:
    explicit Capacity(QWidget *parent = nullptr);
    ~Capacity();

private slots:


    void on_Currency_triggered();

    void on_Standard_triggered();

    void on_Science_triggered();

    void on_Programmer_triggered();

    void on_Date_triggered();

private:
    Ui::Capacity *ui;
};

#endif // CAPACITY_H
