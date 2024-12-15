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

private:
    Ui::Currency *ui;
};

#endif // CURRENCY_H
