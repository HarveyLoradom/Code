#include "currency.h"
#include "ui_currency.h"
#include"programmer.h"
#include"science.h"
#include"date.h"
#include"capacity.h"
#include"mainwindow.h"

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

void Currency::on_Science_triggered()
{
    Science *science=new Science();
    this->hide();
    science->show();
}


void Currency::on_Standard_triggered()
{
    MainWindow *mainwinodw=new MainWindow();
    this->hide();
    mainwinodw->show();
}


void Currency::on_Programmer_triggered()
{
    Programmer *programmer=new Programmer();
    this->hide();
    programmer->show();
}


void Currency::on_Date_triggered()
{
    Date *date=new Date();
    this->hide();
    date->show();
}


void Currency::on_Capacity_triggered()
{
    Capacity *capacity=new Capacity();
    this->hide();
    capacity->show();
}

