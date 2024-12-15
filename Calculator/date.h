#ifndef DATE_H
#define DATE_H

#include <QMainWindow>

namespace Ui {
class Date;
}

class Date : public QMainWindow
{
    Q_OBJECT

public:
    explicit Date(QWidget *parent = nullptr);
    ~Date();

private:
    Ui::Date *ui;
};

#endif // DATE_H
