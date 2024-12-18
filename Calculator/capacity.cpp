#include"capacity.h"
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

    digitBTNs={{Qt::Key_0,ui->btnNum0},
                 {Qt::Key_1,ui->btnNum1},
                 {Qt::Key_2,ui->btnNum2},
                 {Qt::Key_3,ui->btnNum3},
                 {Qt::Key_4,ui->btnNum4},
                 {Qt::Key_5,ui->btnNum5},
                 {Qt::Key_6,ui->btnNum6},
                 {Qt::Key_7,ui->btnNum7},
                 {Qt::Key_8,ui->btnNum8},
                 {Qt::Key_9,ui->btnNum9},
                 };
    foreach(auto btn ,digitBTNs)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    digitElse={{Qt::Key_Period,ui->btnPoint},
        {Qt::Key_Escape,ui->btnCE},
        {Qt::Key_Backspace,ui->btnDelete},};

    QFont font=ui->StartCapacityEdit->font();
    font.setBold(true);
    ui->StartCapacityEdit->setFont(font);

    connect(ui->StartCapacityEdit, &MyLineEdit::clicked, this, &Capacity::on_startEdit_clicked);
    connect(ui->EndCapacityEdit, &MyLineEdit::clicked, this, &Capacity::on_endEdit_clicked);
    ui->StartCapacityEdit->setReadOnly(false);
    ui->EndCapacityEdit->setReadOnly(true);
}

Capacity::~Capacity()
{
    delete ui;
}

double Capacity::getExchangeRate(const QString &fromCapacity, const QString &toCapacity)
{
    constexpr double exchangeRates[6][6] = {
        // 立方厘米、立方米、升、毫升、立方英尺、立方英寸
        {1.0, 1e-6, 0.001, 1, 3.53147e-5, 0.0610237},  // 立方厘米
        {1e6, 1.0, 1000, 1e6, 35.3147, 61023.7},       // 立方米
        {1000, 0.001, 1.0, 1000, 0.0353147, 61.0237},   // 升
        {1, 1e-6, 0.001, 1.0, 3.53147e-5, 0.0610237},   // 毫升
        {28316.8, 0.0283168, 28.3168, 28316.8, 1.0, 1728},  // 立方英尺
        {16.3871, 1.63871e-5, 0.0163871, 16.3871, 1.0 / 1728, 1.0}  // 立方英寸
    };
    int fromIndex = -1, toIndex = -1;
    // 确定源单位对应的索引
    if (fromCapacity == "立方厘米") {
        fromIndex = 0;
    } else if (fromCapacity == "立方米") {
        fromIndex = 1;
    } else if (fromCapacity == "升") {
        fromIndex = 2;
    } else if (fromCapacity == "毫升") {
        fromIndex = 3;
    } else if (fromCapacity == "立方英尺") {
        fromIndex = 4;
    } else if (fromCapacity == "立方英寸") {
        fromIndex = 5;
    }
    // 确定目标单位对应的索引
    if (toCapacity == "立方厘米") {
        toIndex = 0;
    } else if (toCapacity == "立方米") {
        toIndex = 1;
    } else if (toCapacity == "升") {
        toIndex = 2;
    } else if (toCapacity == "毫升") {
        toIndex = 3;
    } else if (toCapacity == "立方英尺") {
        toIndex = 4;
    } else if (toCapacity == "立方英寸") {
        toIndex = 5;
    }
    // 根据索引获取并返回换算率，如果索引有不合法情况（即单位不识别）则返回0
    if (fromIndex!= -1 && toIndex!= -1) {
        return exchangeRates[fromIndex][toIndex];
    }
    return 0;
}

void Capacity::convertCapacity()
{
    MyLineEdit *FromEdit=new MyLineEdit();
    MyLineEdit *ToEdit=new MyLineEdit();
    if(ui->StartCapacityEdit->isReadOnly()){
        ToEdit=ui->StartCapacityEdit;
        FromEdit=ui->EndCapacityEdit;
    }
    else{
        ToEdit=ui->EndCapacityEdit;
        FromEdit=ui->StartCapacityEdit;
    }

    QString capacityFrom=ui->comboxStart->currentText();
    QString capacityTo=ui->comboxEnd->currentText();
    double amount = FromEdit->text().toDouble();

    double exchangeRate = getExchangeRate(capacityFrom, capacityTo);
    double convertedAmount = amount * exchangeRate;
    ToEdit->setText(QString::number(convertedAmount, 'f', 2));
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




void Capacity::on_comboxEnd_activated()
{
    convertCapacity();
}

void Capacity::on_comboxStart_activated()
{
    convertCapacity();
}

void Capacity::btnNumClicked()
{
    QString digit = qobject_cast<QPushButton*>(sender())->text();

    // 先处理特殊情况，如果当前输入是"0"且金额显示为"0"，则不添加这个"0"，保持为空
    if (digit == "0" && Amount == "0") {
        digit = "";
    }
    // 如果输入不是"0"但当前金额显示为"0"，则先将金额置为空字符串，准备添加新输入
    else if (digit!= "0" && Amount == "0") {
        Amount = "";
    }

    // 检查添加新输入后是否会超出位数限制
    QString newAmount = Amount + digit;
    int dotIndex = newAmount.indexOf('.');
    if (dotIndex == -1) {
        // 没有小数点，说明是整数部分，检查整数位长度
        if (newAmount.length() > 8) {
            return;  // 超出整数位最大长度限制，不进行输入
        }
    }
    else {
        // 有小数点，分别检查整数部分和小数部分长度
        QString integerPart = newAmount.left(dotIndex);
        QString decimalPart = newAmount.mid(dotIndex + 1);
        if (integerPart.length() > 8 || decimalPart.length() > 2) {
            return;  // 超出位数限制，不进行输入
        }
    }
    Amount += digit;

    if(ui->StartCapacityEdit->isReadOnly()){
        ui->EndCapacityEdit->setText(Amount);
    }
    else
        ui->StartCapacityEdit->setText(Amount);

    convertCapacity();
}

void Capacity::on_btnPoint_clicked()
{
    if(!Amount.contains("."))
        Amount +=  qobject_cast<QPushButton*>(sender())->text();
    if(ui->StartCapacityEdit->isReadOnly())
        ui->EndCapacityEdit->setText(Amount);
    else
        ui->StartCapacityEdit->setText(Amount);
}

void Capacity::on_btnCE_clicked()
{
    Amount="";
    ui->StartCapacityEdit->clear();
    ui->EndCapacityEdit->clear();
}

void Capacity::on_btnDelete_clicked()
{
    Amount=Amount.left(Amount.length()-1);

    if(ui->StartCapacityEdit->isReadOnly())
        ui->EndCapacityEdit->setText(Amount);
    else
        ui->StartCapacityEdit->setText(Amount);
}

void Capacity::on_startEdit_clicked()
{
    on_btnCE_clicked();
    QFont font = ui->StartCapacityEdit->font();
    font.setBold(true);
    ui->StartCapacityEdit->setFont(font);

    font.setBold(false);
    ui->EndCapacityEdit->setFont(font);
    ui->StartCapacityEdit->setReadOnly(false);
    ui->EndCapacityEdit->setReadOnly(true);
}

void Capacity::on_endEdit_clicked()
{
    on_btnCE_clicked();
    QFont font = ui->StartCapacityEdit->font();
    font.setBold(false);
    ui->StartCapacityEdit->setFont(font);

    font.setBold(true);
    ui->EndCapacityEdit->setFont(font);
    ui->StartCapacityEdit->setReadOnly(true);
    ui->EndCapacityEdit->setReadOnly(false);
}

