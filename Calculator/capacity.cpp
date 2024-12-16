#include "capacity.h"
#include "ui_capacity.h"
#include"programmer.h"
#include"science.h"
#include"date.h"
#include"currency.h"
#include"mainwindow.h"

Capacity::Capacity(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Capacity)
{
    ui->setupUi(this);
}

Capacity::~Capacity()
{
    delete ui;
}



void Capacity::on_Currency_triggered()
{
    Currency *currency=new Currency();
    this->hide();
    currency->show();
}


void Capacity::on_Standard_triggered()
{
    MainWindow *mainwinodw=new MainWindow();
    this->hide();
    mainwinodw->show();
}


void Capacity::on_Science_triggered()
{
    Science *science=new Science();
    this->hide();
    science->show();
}


void Capacity::on_Programmer_triggered()
{
    Programmer *programmer=new Programmer();
    this->hide();
    programmer->show();
}


void Capacity::on_Date_triggered()
{
    Date *date=new Date();
    this->hide();
    date->show();
}

