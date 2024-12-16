#include "programmer.h"
#include "ui_programmer.h"
#include"mainwindow.h"
#include"date.h"
#include"currency.h"
#include"capacity.h"
#include"science.h"


Programmer::Programmer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Programmer)
{
    ui->setupUi(this);
}

Programmer::~Programmer()
{
    delete ui;
}



void Programmer::on_Date_triggered()
{
    Date *date=new Date();
    this->hide();
    date->show();
}


void Programmer::on_Currency_triggered()
{
    Currency *currency=new Currency();
    this->hide();
    currency->show();
}


void Programmer::on_Capacity_triggered()
{
    Capacity *capacity=new Capacity();
    this->hide();
    capacity->show();
}


void Programmer::on_Standard_triggered()
{
    MainWindow *mainwindow=new MainWindow();
    this->hide();
    mainwindow->show();
}


void Programmer::on_Science_triggered()
{
    Science *science=new Science();
    this->hide();
    science->show();
}

