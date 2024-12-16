#include "science.h"
#include "ui_science.h"
#include"programmer.h"
#include"date.h"
#include"currency.h"
#include"capacity.h"
#include"mainwindow.h"

Science::Science(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Science)
{
    ui->setupUi(this);
}

Science::~Science()
{
    delete ui;
}

void Science::on_Standard_triggered()
{
    MainWindow *mainwindow=new MainWindow();
    this->hide();
    mainwindow->show();
}


void Science::on_Programmer_triggered()
{
    Programmer *programmer=new Programmer();
    this->hide();
    programmer->show();
}


void Science::on_Date_triggered()
{
    Date *date=new Date();
    this->hide();
    date->show();
}


void Science::on_Currency_triggered()
{
    Currency *currency=new Currency();
    this->hide();
    currency->show();
}


void Science::on_Capacity_triggered()
{
    Capacity *capacity=new Capacity();
    this->hide();
    capacity->show();
}

