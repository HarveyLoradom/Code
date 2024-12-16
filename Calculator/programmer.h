#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <QMainWindow>

namespace Ui {
class Programmer;
}

class Programmer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Programmer(QWidget *parent = nullptr);
    ~Programmer();

private slots:
    void on_Science_triggered();

    void on_Date_triggered();

    void on_Currency_triggered();

    void on_Capacity_triggered();

    void on_Standard_triggered();

private:
    Ui::Programmer *ui;
};

#endif // PROGRAMMER_H
