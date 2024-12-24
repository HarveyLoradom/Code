#include "science.h"
#include "ui_science.h"
#include"programmer.h"
#include"date.h"
#include"currency.h"
#include"capacity.h"
#include"mainwindow.h"
#include<QtMath>

Science::Science(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Science)
{
    ui->setupUi(this);
    isCheckedState = false;
    hasResult = false;
    operand = "";
    operands.clear();
    opcodes.clear();
    historyRecords.clear();
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
                 {Qt::Key_Bar,ui->btnPai},
                 {Qt::Key_AudioRandomPlay,ui->btnE},
                 };

    foreach(auto btn ,digitBTNs)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

    digitBinarys={{Qt::Key_Asterisk,ui->btnMulti},
                    {Qt::Key_Slash,ui->btnDivide},
                    {Qt::Key_Plus,ui->btnAdd},
                    {Qt::Key_Minus,ui->btnMinus},
                    {Qt::Key_Dead_Caron,ui->btnMod},
                    {Qt::Key_Blue,ui->btnExp},
                    {Qt::Key_Dead_Belowdot,ui->btn10andX},
                    {Qt::Key_Adiaeresis,ui->btnXandY},
                    };

    foreach(auto btn,digitBinarys)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));

    digitUnBinarys={{Qt::Key_Exclam,ui->btnDenominator},  //键盘的！
        {Qt::Key_At,ui->btnSqrt},  //键盘的@
        {Qt::Key_AsciiCircum,ui->btnSquare},        //键盘^ 大写模式按下shift+数字键盘6
                      {Qt::Key_Ocircumflex,ui->btn10andX},
                      {Qt::Key_Ucircumflex,ui->btnAbs},
                      {Qt::Key_Calculator,ui->btnLn},
                      {Qt::Key_Apostrophe,ui->btnN},
    };

    foreach(auto btn,digitUnBinarys)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));

    digitElse={{Qt::Key_Period,ui->btnPoint},
        {Qt::Key_Return,ui->btnC},            //字母键盘的Enter键
        {Qt::Key_Equal,ui->btnAddMinus},     // =键
        {Qt::Key_Enter,ui->btnEqual},        //数字键盘Enter
        {Qt::Key_Backspace,ui->btnDelete}, //Backspace键
    };
}

Science::~Science()
{
    delete ui;
}

QString Science::calculation(bool *ok)
{
    double result = 0;
    QString first = operands.front();
    QString expression;
    if (operands.size() == 2 && opcodes.size() > 0) {
        // 取操作数
        double operand1 = operands.front().toDouble();
        operands.pop_front();
        double operand2 = operands.front().toDouble();
        operands.pop_front();

        // 取操作符
        QString op = opcodes.front();
        opcodes.pop_front();

        if (op == "+") {
            result = operand1 + operand2;
            expression = QString("%1 %2 %3 = %4")
                             .arg(QString::number(operand1))
                             .arg(op)
                             .arg(QString::number(operand2))
                             .arg(QString::number(result));
        }
        else if (op == "-") {
            result = operand1 - operand2;
            expression = QString("%1 %2 %3 = %4")
                             .arg(QString::number(operand1))
                             .arg(op)
                             .arg(QString::number(operand2))
                             .arg(QString::number(result));
        }
        else if (op == "×") {
            result = operand1 * operand2;
            expression = QString("%1 %2 %3 = %4")
                             .arg(QString::number(operand1))
                             .arg(op)
                             .arg(QString::number(operand2))
                             .arg(QString::number(result));
        }
        else if (op == "÷") {
            if (operand2 == 0) {
                // 处理除数为0的情况，这里简单设置错误信息并返回
                if (ok) {
                    *ok = false;
                }
                ui->statusbar->showMessage("除数不能为0");
                return first;
            }
            result = operand1 / operand2;
            expression = QString("%1 %2 %3 = %4")
                             .arg(QString::number(operand1))
                             .arg(op)
                             .arg(QString::number(operand2))
                             .arg(QString::number(result));
        }
        else if(op=="mod"){
            result=std::fmod(operand1, operand2);
            expression = QString("%1 %2 %3 = %4")
                             .arg(QString::number(operand1))
                             .arg("%")
                             .arg(QString::number(operand2))
                             .arg(QString::number(result));
        }
        else if(op=="exp"){
            result=operand1*qPow(10,operand2);
            expression = QString("%1= %2")
                             .arg(QString::number(result))
                             .arg(QString::number(result));
        }
        else if(op=="x^y"){
            result=qPow(operand1,operand2);
            expression = QString("%1 %2 %3 = %4")
                             .arg(QString::number(operand1))
                             .arg("^")
                             .arg(QString::number(operand2))
                             .arg(QString::number(result));
        }
        else if(op=="y√x"){
            result=qPow(operand1,1.0/operand2);
            expression = QString("%1 %2 %3 = %4")
                             .arg(QString::number(operand2))
                             .arg("√")
                             .arg(QString::number(operand1))
                             .arg(QString::number(result));
        }
        else if(op=="logy^x"){
            result = std::log(operand1) / std::log(operand2);
            expression = QString("%1 %2 ^ %3 = %4")
                             .arg("log")
                             .arg(QString::number(operand2))
                             .arg(QString::number(operand1))
                             .arg(QString::number(result));
        }
        operands.push_back(QString::number(result));


        // 将表达式添加到历史记录列表
        historyRecords.append(expression);

        // 更新显示历史记录的文本框内容
        updateHistoryDisplay();

        return QString::number(result);
    }

    return first;
}

void Science::updateHistoryDisplay()
{
    QString historyText;
    for (const QString &record : historyRecords) {
        historyText += record + "\n";
    }
    ui->HistoryText->setText(historyText);
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


void Science::on_btnEqual_clicked()
{
    if(operand!=""){
        operands.push_back(operand);
        operand="";
        QString result=calculation();
        ui->Display->setText(result);
    }
}


void Science::on_btnPoint_clicked()
{
    if(!operand.contains("."))
        operand +=  qobject_cast<QPushButton*>(sender())->text();
    ui->Display->setText(operand);
}


void Science::on_btnDelete_clicked()
{
    operand=operand.left(operand.length()-1);
    ui->Display->setText(operand);
}


void Science::on_btnC_clicked()
{
    if(operands.size()==0){
        operands.push_back(operand);
    }
    if(operands.size()>0){
        operands.clear();
        opcodes.clear();
        operand="";
        ui->Display->setText(operand);
    }
    historyRecords.clear();
    updateHistoryDisplay();
}

void Science::btnNumClicked()
{
    QString digit=qobject_cast<QPushButton*>(sender())->text();

    if(digit=="0"&&operand=="0")
        digit="";

    if(digit!="0"&&operand=="0")
        operand="";
    if(digit=="π"){
        digit="";
        operand="3.1415926";
    }
    else if(digit=="e"){
        digit="";
        operand="2.1782818";
    }
    operand+=digit;

    ui->Display->setText(operand);
}

void Science::btnBinaryOperatorClicked()
{
    QString opcode=qobject_cast<QPushButton*>(sender())->text();
    if(operand!=""){

        operands.push_back(operand);

        operand="";

        opcodes.push_back(opcode);
        QString result=calculation();

        ui->Display->setText(result);

    }
    else if(operand==""&&operands.size()==1&&opcodes.size()==0){
        opcodes.push_back(opcode);
        QString result=calculation();
        ui->Display->setText(result);
    }
    if(opcode=="y√x"||opcode=="logy^x")
         on_btn2andND_clicked();
}

void Science::btnUnaryOperatorClicked()
{
    QString expression;
    if (operands.size() == 0)
        operands.push_back(operand);
    if (operands.size() > 0) {
        QString oper = operands.front();
        operands.pop_front();
        double result = oper.toDouble();
        operand = "";
        QString op = qobject_cast<QPushButton*>(sender())->text();

        // 记录原始操作数，用于构建表达式字符串
        QString originalOperand = QString::number(result);

        if (op == "%") {
            result /= 100.0;
            expression = QString("%1 %2 = %3")
                             .arg(originalOperand)
                             .arg(op)
                             .arg(QString::number(result));
        }
        else if (op == "1/x"){
            result = 1 / result;
            expression = QString("%1 %2 = %3")
                             .arg("1/")
                             .arg(originalOperand)
                             .arg(QString::number(result));
        }
        else if (op == "x²"){
            result *= result;
            expression = QString("%1 %2 = %3")
                             .arg(originalOperand)
                             .arg("^2")
                             .arg(QString::number(result));
        }
        else if (op == "²√x"){
            result = std::sqrt(result);
            expression = QString("%1 %2 = %3")
                             .arg("√")
                             .arg(originalOperand)
                             .arg(QString::number(result));
        }
        else if (op == "ln"){
            result = qLn(result);
            expression = QString("%1 (%2) = %3")
                             .arg(op)
                             .arg(originalOperand)
                             .arg(QString::number(result));
        }
        else if (op == "|x|"){
            result = std::abs(result);
            expression = QString("%1 (%2) = %3")
                             .arg("abs")
                             .arg(originalOperand)
                             .arg(QString::number(result));
        }
        else if (op == "10^x"){
            result = qPow(10, result);
            expression = QString("%1 ^ %2 = %3")
                             .arg(10)
                             .arg(originalOperand)
                             .arg(QString::number(result));
        }
        else if (op == "n!"){
            result = std::tgamma(result + 1);
            expression = QString("%1 %2 = %3")
                             .arg(originalOperand)
                             .arg("!")
                             .arg(QString::number(result));
        }
        else if(op=="2^x"){
            result= qPow(2, result);
            expression = QString("%1 ^%2 = %3")
                             .arg(2)
                             .arg(originalOperand)
                             .arg(QString::number(result));
            on_btn2andND_clicked();
        }
        else if(op=="e^x"){
            result=qPow(2.1782818,result);
            expression = QString("%1 ^%2 = %3")
                             .arg("e")
                             .arg(originalOperand)
                             .arg(QString::number(result));
            on_btn2andND_clicked();
        }
        else if(op=="x^3"){
            result=qPow(result,3);
            expression = QString("%1 ^%2 = %3")
                             .arg(originalOperand)
                             .arg(3)
                             .arg(QString::number(result));
            on_btn2andND_clicked();
        }
        else if(op=="3√x"){
            result=qPow(result,1.0/3.0);
            expression = QString("%1 %2 = %3")
                             .arg("3√")
                             .arg(originalOperand)
                             .arg(QString::number(result));
            on_btn2andND_clicked();
        }
        else if(op=="log"){
            result = log(result) ;
            expression = QString("%1 (%2) = %3")
                             .arg(op)
                             .arg(originalOperand)
                             .arg(QString::number(result));
        }
        ui->Display->setText(QString::number(result));
        operands.push_back(QString::number(result));
        // 将表达式添加到历史记录列表
        historyRecords.append(expression);

        // 更新显示历史记录的文本框内容
        updateHistoryDisplay();
    }
}

void Science::on_btnAddMinus_clicked()
{
    if(operands.size()==0&&operand!=""){
        operands.push_back(operand);
    }
    if(operands.size()>0){
        QString oper=operands.front();
        operands.pop_front();
        if(oper.contains("-")){
            double result=operand.toDouble();
            ui->Display->setText(QString::number(result));
            operands.push_back(QString::number(result));
        }
        else{
            double result=operand.toDouble();
            result=0-result;
            ui->Display->setText(QString::number(result));
            operands.push_back(QString::number(result));
        }
    }
}

void Science::on_btn2andND_clicked()
{
    isCheckedState =!isCheckedState;
    if(isCheckedState){
        ui->btn10andX->setText("2^x");
        ui->btnLn->setText("e^x");
        ui->btnLog->setText("logy^x");
        ui->btnXandY->setText("y√x");
        ui->btnSquare->setText("x^3");
        ui->btnSqrt->setText("3√x");
    ui->btn2andND->setStyleSheet("background-color: #800080;");
    }
    else{
        ui->btn10andX->setText("10^x");
        ui->btnLn->setText("ln");
        ui->btnLog->setText("log");
        ui->btnXandY->setText("x^y");
        ui->btnSquare->setText("x²");
        ui->btnSqrt->setText("²√x");
        ui->btn2andND->setStyleSheet("background-color: #FFFFFF;");
    }
}


void Science::on_btnLog_clicked()
{
    QString op = qobject_cast<QPushButton*>(sender())->text();
    if(op =="log"){
        btnUnaryOperatorClicked();
    }
    else{
        btnBinaryOperatorClicked();
    }
}

