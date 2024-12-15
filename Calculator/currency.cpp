#include "currency.h"
#include "ui_currency.h"

Currency::Currency(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Currency)
{
    ui->setupUi(this);
}

Currency::~Currency()
{
    delete ui;
}
