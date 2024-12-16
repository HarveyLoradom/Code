#ifndef SCIENCE_H
#define SCIENCE_H

#include <QMainWindow>

namespace Ui {
class Science;
}

class Science : public QMainWindow
{
    Q_OBJECT

public:
    explicit Science(QWidget *parent = nullptr);
    ~Science();

private slots:
    void on_Standard_triggered();

    void on_Programmer_triggered();

    void on_Date_triggered();

    void on_Currency_triggered();

    void on_Capacity_triggered();

private:
    Ui::Science *ui;
};

#endif // SCIENCE_H
