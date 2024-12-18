#include "currency.h"
#include "ui_currency.h"
#include"programmer.h"
#include"science.h"
#include"date.h"
#include"capacity.h"
#include"mainwindow.h"
#include"mylineedit.h"

Currency::Currency(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Currency)
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

    QFont font=ui->StartCurrencyEdit->font();
    font.setBold(true);
    ui->StartCurrencyEdit->setFont(font);

    connect(ui->StartCurrencyEdit, &MyLineEdit::clicked, this, &Currency::on_startEdit_clicked);
    connect(ui->EndCurrencyEdit, &MyLineEdit::clicked, this, &Currency::on_endEdit_clicked);
    ui->StartCurrencyEdit->setReadOnly(false);
    ui->EndCurrencyEdit->setReadOnly(true);

}

Currency::~Currency()
{
    delete ui;
}

double Currency::getExchangeRate(const QString &fromCurrency, const QString &toCurrency)
{
    if (fromCurrency == "美国-美元" && toCurrency == "日本-日元") return 153.77;
    if (fromCurrency == "美国-美元" && toCurrency == "欧洲-欧元") return 0.9526;
    if (fromCurrency == "美国-美元" && toCurrency == "中国-人民币") return 7.2839;
    if (fromCurrency == "美国-美元" && toCurrency == "英国-英镑") return 0.7906;

    if (fromCurrency == "日本-日元" && toCurrency == "美国-美元") return 0.006;
    if (fromCurrency == "日本-日元" && toCurrency == "欧洲-欧元") return 0.006;
    if (fromCurrency == "日本-日元" && toCurrency == "中国-人民币") return 0.4737;
    if (fromCurrency == "日本-日元" && toCurrency == "英国-英镑") return 0.005;

    if (fromCurrency == "欧洲-欧元" && toCurrency == "美国-美元") return 1.0498;
    if (fromCurrency == "欧洲-欧元" && toCurrency == "日本-日元") return 161.421;
    if (fromCurrency == "欧洲-欧元" && toCurrency == "中国-人民币") return 7.646;
    if (fromCurrency == "欧洲-欧元" && toCurrency == "英国-英镑") return 0.8299;

    if (fromCurrency == "中国-人民币" && toCurrency == "美国-美元") return 0.1373;
    if (fromCurrency == "中国-人民币" && toCurrency == "日本-日元") return 21.1109;
    if (fromCurrency == "中国-人民币" && toCurrency == "欧洲-欧元") return 0.1308;
    if (fromCurrency == "中国-人民币" && toCurrency == "英国-英镑") return 0.1085;

    if (fromCurrency == "英国-英镑" && toCurrency == "美国-美元") return 1.2649;
    if (fromCurrency == "英国-英镑" && toCurrency == "日本-日元") return 194.4978;
    if (fromCurrency == "英国-英镑" && toCurrency == "欧洲-欧元") return 1.2049;
    if (fromCurrency == "英国-英镑" && toCurrency == "中国-人民币") return 9.2131;
    return 1.0;
}

void Currency::convertCurrency()
{
    MyLineEdit *FromEdit=new MyLineEdit();
    MyLineEdit *ToEdit=new MyLineEdit();
    if(ui->StartCurrencyEdit->isReadOnly()){
        ToEdit=ui->StartCurrencyEdit;
        FromEdit=ui->EndCurrencyEdit;
    }
    else{
        ToEdit=ui->EndCurrencyEdit;
        FromEdit=ui->StartCurrencyEdit;
    }

    QString currencyFrom=ui->comboxStart->currentText();
    QString currencyTo=ui->comboxEnd->currentText();
    double amount = FromEdit->text().toDouble();

    double exchangeRate = getExchangeRate(currencyFrom, currencyTo);
    double convertedAmount = amount * exchangeRate;
    ToEdit->setText(QString::number(convertedAmount, 'f', 2));
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



void Currency::on_comboxEnd_activated()
{
    convertCurrency();
}

void Currency::on_comboxStart_activated()
{
    convertCurrency();
}

void Currency::btnNumClicked()
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

    if(ui->StartCurrencyEdit->isReadOnly()){
        ui->EndCurrencyEdit->setText(Amount);
    }
    else
        ui->StartCurrencyEdit->setText(Amount);

    convertCurrency();
}

void Currency::on_btnPoint_clicked()
{
    if(!Amount.contains("."))
        Amount +=  qobject_cast<QPushButton*>(sender())->text();
    if(ui->StartCurrencyEdit->isReadOnly())
        ui->EndCurrencyEdit->setText(Amount);
    else
        ui->StartCurrencyEdit->setText(Amount);
}

void Currency::on_btnCE_clicked()
{
    Amount="";
    ui->StartCurrencyEdit->clear();
    ui->EndCurrencyEdit->clear();
}

void Currency::on_btnDelete_clicked()
{
    Amount=Amount.left(Amount.length()-1);
    if(ui->StartCurrencyEdit->isReadOnly())
        ui->EndCurrencyEdit->setText(Amount);
    else
        ui->StartCurrencyEdit->setText(Amount);
}

void Currency::on_startEdit_clicked()
{
    on_btnCE_clicked();
    QFont font = ui->StartCurrencyEdit->font();
    font.setBold(true);
    ui->StartCurrencyEdit->setFont(font);

    font.setBold(false);
    ui->EndCurrencyEdit->setFont(font);
    ui->StartCurrencyEdit->setReadOnly(false);
    ui->EndCurrencyEdit->setReadOnly(true);
}

void Currency::on_endEdit_clicked()
{
    on_btnCE_clicked();
    QFont font = ui->StartCurrencyEdit->font();
    font.setBold(false);
    ui->StartCurrencyEdit->setFont(font);

    font.setBold(true);
    ui->EndCurrencyEdit->setFont(font);
    ui->StartCurrencyEdit->setReadOnly(true);
    ui->EndCurrencyEdit->setReadOnly(false);
}



