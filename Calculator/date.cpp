#include "date.h"
#include "ui_date.h"

Date::Date(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Date)
{
    ui->setupUi(this);
}

Date::~Date()
{
    delete ui;
}
