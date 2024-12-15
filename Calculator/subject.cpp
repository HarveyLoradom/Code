#include "subject.h"
#include "ui_subject.h"
#include"mainwindow.h"

Subject::Subject(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Subject)
{
    ui->setupUi(this);
}

Subject::~Subject()
{
    delete ui;
}

void Subject::on_Standard_triggered()
{
    MainWindow *mainwindow=new MainWindow();
    this->hide();
    mainwindow->show();

}

