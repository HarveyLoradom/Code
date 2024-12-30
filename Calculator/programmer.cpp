#include "programmer.h"
#include "ui_programmer.h"
#include"mainwindow.h"
#include"date.h"
#include"currency.h"
#include"capacity.h"
#include"science.h"
#include<QPainter>
#include<QString>
#include <QColorDialog>
#include<QFontDialog>



Programmer::Programmer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Programmer)
{
    ui->setupUi(this);
    ui->btnHEX->setStyleSheet("background-color: #800080;");

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
        {Qt::Key_A,ui->btnA},
        {Qt::Key_B,ui->btnB},
        {Qt::Key_C,ui->btnC},
        {Qt::Key_D,ui->btnD},
        {Qt::Key_E,ui->btnE},
        {Qt::Key_F,ui->btnF},
    };

    digitBinarys={{Qt::Key_Asterisk,ui->btnMulti},
                    {Qt::Key_Slash,ui->btnDivide},
                    {Qt::Key_Plus,ui->btnAdd},
                    {Qt::Key_Minus,ui->btnMinus},
                    };

    digitElse={{Qt::Key_Period,ui->btnPoint},
        {Qt::Key_Return,ui->btnCE},            //字母键盘的Enter键
        {Qt::Key_Equal,ui->btnAddMinus},     // =键
        {Qt::Key_Enter,ui->btnEqual},        //数字键盘Enter
        {Qt::Key_Backspace,ui->btnDelete}, //Backspace键
    };

    digitHEX={
        {Qt::Key_Period,ui->btnPoint},
    };
    foreach(auto btn,digitBTNs)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnHEX_clicked()));

    digitDEC={
        {Qt::Key_Period,ui->btnPoint},
        {Qt::Key_A,ui->btnA},
        {Qt::Key_B,ui->btnB},
        {Qt::Key_C,ui->btnC},
        {Qt::Key_D,ui->btnD},
        {Qt::Key_E,ui->btnE},
        {Qt::Key_F,ui->btnF},
    };

    foreach(auto btn, digitBTNs)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnDEC_clicked()));

    digitOCT={
        {Qt::Key_Period,ui->btnPoint},
        {Qt::Key_A,ui->btnA},
        {Qt::Key_B,ui->btnB},
        {Qt::Key_C,ui->btnC},
        {Qt::Key_D,ui->btnD},
        {Qt::Key_E,ui->btnE},
        {Qt::Key_F,ui->btnF},
        {Qt::Key_8,ui->btnNum8},
        {Qt::Key_9,ui->btnNum9},
    };

    foreach(auto btn, digitBTNs)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnOCT_clicked()));

    digitBIN={
        {Qt::Key_Period,ui->btnPoint},
        {Qt::Key_A,ui->btnA},
        {Qt::Key_B,ui->btnB},
        {Qt::Key_C,ui->btnC},
        {Qt::Key_D,ui->btnD},
        {Qt::Key_E,ui->btnE},
        {Qt::Key_F,ui->btnF},
        {Qt::Key_2,ui->btnNum2},
        {Qt::Key_3,ui->btnNum3},
        {Qt::Key_4,ui->btnNum4},
        {Qt::Key_5,ui->btnNum5},
        {Qt::Key_6,ui->btnNum6},
        {Qt::Key_7,ui->btnNum7},
        {Qt::Key_8,ui->btnNum8},
        {Qt::Key_9,ui->btnNum9},
    };

    foreach(auto btn, digitBTNs)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnBIN_clicked()));

    digitALL={
        {Qt::Key_A,ui->btnA},
        {Qt::Key_B,ui->btnB},
        {Qt::Key_C,ui->btnC},
        {Qt::Key_D,ui->btnD},
        {Qt::Key_E,ui->btnE},
        {Qt::Key_F,ui->btnF},
        {Qt::Key_0,ui->btnNum0},
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

    Edit={ui->DisplayHEX,ui->DisplayOCT,ui->DisplayDEC,ui->DisplayBIN};
    ui->DisplayHEX->setReadOnly(true);

    digitBinarys={{Qt::Key_Asterisk,ui->btnMulti},
                    {Qt::Key_Slash,ui->btnDivide},
                    {Qt::Key_Plus,ui->btnAdd},
                    {Qt::Key_Minus,ui->btnMinus},
        {Qt::Key_Bluetooth,ui->btnRightRight},
        {Qt::Key_ContrastAdjust,ui->btnLeftLeft},
                    {Qt::Key_New,ui->btnPercent},
                    };

    foreach(auto btn,digitBinarys)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));

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


void Programmer::on_btnHEX_clicked()
{
    setTextReadOnly(ui->DisplayHEX);
    setButtonBackgroundColor(ui->btnHEX);
    setButtonEnable();
    setButtonDisable(digitHEX);
}



void Programmer::on_btnDEC_clicked()
{
    setTextReadOnly(ui->DisplayDEC);
    setButtonBackgroundColor(ui->btnDEC);
    setButtonEnable();
    setButtonDisable(digitDEC);
}


void Programmer::on_btnOCT_clicked()
{
    setTextReadOnly(ui->DisplayOCT);
    setButtonBackgroundColor(ui->btnOCT);
    setButtonEnable();
    setButtonDisable(digitOCT);
}


void Programmer::on_btnBIN_clicked()
{
    setTextReadOnly(ui->DisplayBIN);
    setButtonBackgroundColor(ui->btnBIN);
    setButtonEnable();
    setButtonDisable(digitBIN);
}

void Programmer::setButtonBackgroundColor(QPushButton *clickedButton)
{
    // 先将所有按钮的背景色恢复为默认（这里假设默认是白色，你可以根据实际情况调整）
    ui->btnHEX->setStyleSheet("background-color: #FFFFFF;");
    ui->btnDEC->setStyleSheet("background-color: #FFFFFF;");
    ui->btnOCT->setStyleSheet("background-color: #FFFFFF;");
    ui->btnBIN->setStyleSheet("background-color: #FFFFFF;");
    // 再将被点击的按钮背景色设置为紫色
    clickedButton->setStyleSheet("background-color: #800080;");
}

void Programmer::setButtonDisable(QMap<int, QPushButton *> digit)
{
    foreach(auto btn,digit)
        btn->setEnabled(false);
}

void Programmer::setButtonEnable()
{
    foreach(auto btn,digitALL)
        btn->setEnabled(true);
}

void Programmer::setTextReadOnly(QLineEdit *text)
{
    foreach(auto edit,Edit){
        if(edit==text)
            edit->setReadOnly(true);
        else
            edit->setReadOnly(false);
    }
}

void Programmer::btnHEX_clicked()
{
    if(ui->DisplayHEX->isReadOnly()){
        QString digit=qobject_cast<QPushButton*>(sender())->text();

        if(digit=="0"&&operandHEX=="0")
            digit="";

        if(digit!="0"&&operandHEX=="0")
            operandHEX="";

        operandHEX+=digit;

        ui->Display->setText(operandHEX);
        toChange(operandHEX);
    }
}

void Programmer::btnDEC_clicked()
{
    if(ui->DisplayDEC->isReadOnly()){
        QString digit=qobject_cast<QPushButton*>(sender())->text();

        if(digit=="0"&&operandDEC=="0")
            digit="";

        if(digit!="0"&&operandDEC=="0")
            operandDEC="";

        operandDEC+=digit;

        ui->Display->setText(operandDEC);
        toChange(operandDEC);
    }
}

void Programmer::btnBIN_clicked()
{
    if (ui->DisplayBIN->isReadOnly()) {
        QString digit = qobject_cast<QPushButton*>(sender())->text();

        // 如果点击的是0且当前操作数也是0，去除这个0（避免多个前导0）
        if (digit == "0" && operandBIN == "0") {
            digit = "";
        }

        // 如果点击的不是0但当前操作数是0，清空当前操作数，准备重新输入
        if (digit!= "0" && operandBIN == "0") {
            operandBIN = "";
        }

        operandBIN += digit;
        QString displayBIN;
        // 获取当前二进制数字的总长度
        int binLength = operandBIN.size();

        // 判断当前长度除以4的余数，若余数为0，表示刚好是4的倍数，不需要补零
        if ((binLength % 4 !=0)) {
            // 计算需要补零的位数
            int zerosToAdd = 4 - (binLength % 4);
            QString zeros = QString("0").repeated(zerosToAdd);

            // 在前面添加零
            displayBIN = zeros + operandBIN;
        }
        else if(binLength%4==0){
            displayBIN=operandBIN;
        }

        ui->Display->setText(displayBIN);
        toChange(operandBIN);
    }
}

void Programmer::btnOCT_clicked()
{
    if(ui->DisplayOCT->isReadOnly()){
        QString digit=qobject_cast<QPushButton*>(sender())->text();

        if(digit=="0"&&operandOCT=="0")
            digit="";
        if(digit!="0"&&operandOCT=="0")
            operandOCT="";
        operandOCT+=digit;
        ui->Display->setText(operandOCT);
        toChange(operandOCT);
    }
}



void Programmer::toChange(QString operand)
{
    if(ui->DisplayDEC->isReadOnly()){
        bool ok;
        int decimal = operand.toInt(&ok);
        if (!ok) {
            qDebug() << "输入的不是合法的十进制数字字符串";
            return;
        }
        ui->DisplayDEC->setText(operand);
        // 转换为二进制
        QString binary = QString::number(decimal, 2);
        int length = binary.length();
        int paddingLength = 4 - (length % 4);
        if (length % 4!= 0) {
            binary = QString(paddingLength, '0').append(binary);
        }
        ui->DisplayBIN->setText(binary);

        // 转换为八进制
        QString octal = QString::number(decimal, 8);
        ui->DisplayOCT->setText(octal);

        // 转换为十六进制
        QString hexadecimal = QString::number(decimal, 16).toUpper();  // 转换为大写形式的十六进制字符串表示
        ui->DisplayHEX->setText(hexadecimal);
    }
    else if(ui->DisplayHEX->isReadOnly()){
        bool ok;
        int hexadecimal = operand.toInt(&ok, 16);
        if (!ok) {
            qDebug() << "输入的不是合法的十六进制数字字符串";
            return;
        }
        ui->DisplayHEX->setText(operand);
        // 转换为二进制
        QString binary = QString::number(hexadecimal, 2);
        int length = binary.length();
        int paddingLength = 4 - (length % 4);
        if (length % 4!= 0) {
            binary = QString(paddingLength, '0').append(binary);
        }

        ui->DisplayBIN->setText(binary);

        // 转换为八进制
        QString octal = QString::number(hexadecimal, 8);
        ui->DisplayOCT->setText(octal);

        // 转换为十进制
        QString decimal = QString::number(hexadecimal, 10).toUpper();  // 转换为大写形式的十六进制字符串表示
        ui->DisplayDEC->setText(decimal);
    }
    else if(ui->DisplayOCT->isReadOnly()){
        bool ok;
        int octal = operand.toInt(&ok, 8);
        if (!ok) {
            qDebug() << "输入的不是合法的八进制数字字符串";
            return;
        }
        ui->DisplayOCT->setText(operand);
        // 转换为二进制
        QString binary = QString::number(octal, 2);
        int length = binary.length();
        int paddingLength = 4 - (length % 4);
        if (length % 4!= 0) {
            binary = QString(paddingLength, '0').append(binary);
        }

        ui->DisplayBIN->setText(binary);

        // 转换为十进制
        QString decimal = QString::number(octal, 10);
        ui->DisplayDEC->setText(decimal);

        // 转换为十六进制
        QString hexadecimal = QString::number(octal, 16).toUpper();  // 转换为大写形式的十六进制字符串表示
        ui->DisplayHEX->setText(hexadecimal);
    }
    else if(ui->DisplayBIN->isReadOnly()){
        bool ok;
        int binary = operand.toInt(&ok, 2);
        if (!ok) {
            qDebug() << "输入的不是合法的二进制数字字符串";
            return;
        }
        QString binarystr = QString::number(binary, 2);
        int length = binarystr.length();
        int paddingLength = 4 - (length % 4);
        if (length % 4!= 0) {
            binarystr = QString(paddingLength, '0').append(binarystr);
        }
        ui->DisplayBIN->setText(binarystr);
        // 转换为八进制
        QString octal = QString::number(binary, 8);
        ui->DisplayOCT->setText(octal);

        // 转换为十进制
        QString decimal = QString::number(binary, 10);
        ui->DisplayDEC->setText(decimal);

        // 转换为十六进制
        QString hexadecimal = QString::number(binary, 16).toUpper();  // 转换为大写形式的十六进制字符串表示
        ui->DisplayHEX->setText(hexadecimal);
    }

}


void Programmer::on_btnCE_clicked()
{
    if(operandHEXs.size()==0||operandOCTs.size()==0||operandDECs.size()==0||operandBINs.size()==0){
        operandHEXs.push_back(operandHEX);
        operandDECs.push_back(operandDEC);
        operandOCTs.push_back(operandOCT);
        operandBINs.push_back(operandBIN);
    }
    if(operandHEXs.size()>0||operandOCTs.size()>0||operandDECs.size()>0||operandBINs.size()>0){
        operands.clear();
        opcodes.clear();
        operandHEX="";
        operandOCT="";
        operandBIN="";
        operandDEC="";
        ui->Display->setText(operandHEX);
        ui->Display->setText(operandOCT);
        ui->Display->setText(operandBIN);
        ui->Display->setText(operandDEC);

        QString oper="";
        foreach(auto edit,Edit)
            edit->setText(oper);
    }
}

void Programmer::on_btnEqual_clicked()
{
    if(*operand!=""){
        operands.push_back(*operand);
        *operand="";
        QString result=calculation();
        ui->Display->setText(result);
        toChange(result);
    }
}

void Programmer::btnBinaryOperatorClicked()
{
    if(ui->DisplayHEX->isReadOnly())
        operand=&operandHEX;
    else if(ui->DisplayDEC->isReadOnly())
        operand=&operandDEC;
    else if(ui->DisplayOCT->isReadOnly())
        operand=&operandOCT;
    else if(ui->DisplayBIN->isReadOnly())
        operand=&operandBIN;

    QString opcode=qobject_cast<QPushButton*>(sender())->text();
    if(*operand!=""){
        operands.push_back(*operand);
        *operand="";
        opcodes.push_back(opcode);
        QString result=calculation();
        ui->Display->setText(result);
        toChange(result);

    }
    else if(*operand==""&&operands.size()==1&&opcodes.size()==0){
        opcodes.push_back(opcode);
        QString result=calculation();
        ui->Display->setText(result);
        toChange(result);
    }
}

QString Programmer::calculation(bool *ok)
{
    int result = 0;
    int change=0;
    QString first = operands.front();
    if (operands.size() == 2 && opcodes.size() > 0) {
        // 取操作数
        if(ui->DisplayHEX->isReadOnly()){
            change=16;
        }
        else if(ui->DisplayDEC->isReadOnly()){
            change=10;
        }
        else if(ui->DisplayOCT->isReadOnly()){
            change=8;
        }
        else if(ui->DisplayBIN->isReadOnly()){
            change=2;
        }
        int operand1 = operands.front().toInt(nullptr, change);

        operands.pop_front();
        int operand2 = operands.front().toInt(nullptr, change);
        operands.pop_front();
        // 取操作符
        QString op = opcodes.front();
        opcodes.pop_front();

        if (op == "+") {
            result = operand1 + operand2;
        }
        else if (op == "-") {
            result = operand1 - operand2;
        }
        else if (op == "×") {
            result = operand1 * operand2;
        }
        else if (op == "÷") {
            if (operand2 == 0) {
                // 处理除数为0的情况，这里简单设置错误信息并返回
                if (ok) {
                    *ok = false;
                }
                return first;
            }
            result = operand1 / operand2;
        }
        else if(op=="<<"){
            result=operand1<<=operand2;
        }
        else if(op==">>"){
            result=operand1>>=operand2;
        }
        else if(op=="%"){
            result=std::fmod(operand1, operand2);
        }
        QString resultstr;
        if(ui->DisplayHEX->isReadOnly()){
            resultstr = QString::number(result, 16).toUpper();
        }
        else if(ui->DisplayDEC->isReadOnly()){
            resultstr = QString::number(result, 10);
        }
        else if(ui->DisplayOCT->isReadOnly()){
            resultstr = QString::number(result, 8);
        }
        else if(ui->DisplayBIN->isReadOnly()){
            resultstr = QString::number(result, 2);
        }

        operands.push_back(resultstr);

        return resultstr;
    }

    return first;
}

void Programmer::on_btnDelete_clicked()
{
    if(ui->DisplayHEX->isReadOnly()){
        operandHEX=operandHEX.left(operandHEX.length()-1);
        ui->Display->setText(operandHEX);
        toChange(operandHEX);
    }
    else if(ui->DisplayDEC->isReadOnly()){
        operandDEC=operandDEC.left(operandDEC.length()-1);
        ui->Display->setText(operandDEC);
        toChange(operandDEC);
    }
    else if(ui->DisplayOCT->isReadOnly()){
        operandOCT=operandOCT.left(operandOCT.length()-1);
        ui->Display->setText(operandOCT);
        toChange(operandOCT);
    }
    else if(ui->DisplayBIN->isReadOnly()){
        operandBIN=operandBIN.left(operandBIN.length()-1);
        ui->Display->setText(operandBIN);
        toChange(operandBIN);
    }
}





void Programmer::on_Theme_triggered()
{
    static bool isDayMode = false;  // 初始化为白天模式，使用静态变量来记住当前模式状态
    if (this) {  // 直接使用this指针判断当前对象是否有效
        QString styleSheet;
        if (isDayMode) {
            // 白天模式的样式表内容，这里可以根据实际需求详细定义各种部件的样式
            styleSheet = "QMainWindow { background-color: #F3F3F3; color: black; }"
                         " QPushButton {background-color: #FFFFFF; color: black; font-size:15px;border: 1px solid #ccc;border-radius: 4px; }"
                         "#btnEqual{background-color:#8E3AA7;}"
                         " QPushButton:hover {background-color: #F3F3F3; }";
            isDayMode = false;
        }
        else {
            // 夜间模式的样式表内容，同样可按需细致调整样式规则
            styleSheet = "QMainWindow { background-color: #404040; color: white; }"
                         " QPushButton {background-color: #696969; color: white; font-size:15px;border: 1px solid #ccc;border-radius: 4px; }"
                         "#btnEqual{background-color:#8E3AA7;}"
                         " QPushButton:hover {background-color: #404040; }";
            isDayMode = true;
        }
        this->setStyleSheet(styleSheet);
    }
}


void Programmer::on_Background_triggered()
{
    QColorDialog colorDialog(this);
    QColor selectedColor = colorDialog.getColor(Qt::white, this);
    if (selectedColor.isValid()) {
        setStyleSheet(QString("QMainWindow{background-color: %1;}").arg(selectedColor.name()));
    }
}


void Programmer::on_Font_triggered()
{
    QFontDialog fontDialog(this);
    QFont selectedFont = fontDialog.currentFont();
    bool ok;
    selectedFont = fontDialog.getFont(&ok, selectedFont, this);
    if (ok) {
        QList<QWidget*> allWidgets = findChildren<QWidget*>();
        for (QWidget* widget : allWidgets) {
            QPushButton* button = qobject_cast<QPushButton*>(widget);
            if (button) {
                button->setFont(selectedFont);
            }

        }
        ui->Display->setFont(selectedFont);
        ui->HistoryText->setFont(selectedFont);
    }
}


void Programmer::on_FontColor_triggered()
{
    QColorDialog colorDialog(this);
    QColor selectedColor = colorDialog.getColor(Qt::white, this);
    if (selectedColor.isValid()) {
        QString styleSheet = QString("QPushButton {color: %1;} QLineEdit {color: %1;} QTextEdit{color:%1;}").arg(selectedColor.name());
        setStyleSheet(styleSheet);
    }
}


void Programmer::on_FontBackgroundColor_triggered()
{
    QColorDialog colorDialog(this);
    QColor selectedColor = colorDialog.getColor(Qt::white, this);
    if (selectedColor.isValid()) {
        setStyleSheet(QString("QPushButton {background-color: %1;}").arg(selectedColor.name()));
    }
}

