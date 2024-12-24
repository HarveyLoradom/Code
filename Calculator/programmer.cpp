#include "programmer.h"
#include "ui_programmer.h"
#include"mainwindow.h"
#include"date.h"
#include"currency.h"
#include"capacity.h"
#include"science.h"
#include<QPainter>



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
    setButtonDisable(digitHEX);
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
    setButtonBackgroundColor(ui->btnHEX);
    setButtonEnable();
    setButtonDisable(digitHEX);
}



void Programmer::on_btnDEC_clicked()
{
    setButtonBackgroundColor(ui->btnDEC);
    setButtonEnable();
    setButtonDisable(digitDEC);
}


void Programmer::on_btnOCT_clicked()
{
    setButtonBackgroundColor(ui->btnOCT);
    setButtonEnable();
    setButtonDisable(digitOCT);
}


void Programmer::on_btnBIN_clicked()
{
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

void Programmer::btnHEX_clicked()
{

}

void Programmer::btnDEC_clicked()
{

}

void Programmer::btnOCT_clicked()
{

}

void Programmer::btnBIN_clicked()
{
    // 获取发送信号的按钮对象（这里假设你的按钮点击信号正确连接到此槽函数）
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton)
    {
        return;  // 如果转换失败，直接返回，避免后续错误
    }

    QString buttonText = clickedButton->text();

    // 将按钮文本转换为对应的二进制位（这里限定只处理 '0' 和 '1' 的输入）
    bool ok;
    int currentDigit = buttonText.toInt(&ok, 2);
    if (!ok || (currentDigit!= 0 && currentDigit!= 1))
    {
        return;  // 如果转换失败或者输入不是0或1，直接返回，不处理
    }

    // 如果操作数为空且点击的是0，保持显示0
    if (operand.isEmpty() && currentDigit == 0)
    {
        operand = "0";
    }
    else if (operand.isEmpty() && currentDigit == 1)
    {
        operand = "0001";
    }
    else
    {
        // 操作数不为空时的处理逻辑
        if (currentDigit == 0)
        {
            // 进行左移操作（整体左移一位，高位补0，低位舍弃）
            operand = operand.left(operand.length() - 1) + "0";
        }
        else
        {
            // 将操作数转换为十进制整数
            int decimalOperand = operand.toInt(nullptr, 2);
            // 按照二进制加法规则，在最低位加1
            decimalOperand += 1;
            // 将新的十进制结果转换回二进制字符串
            operand = QString::number(decimalOperand, 2);
            // 确保操作数始终保持4位宽度，不足前面补0
            operand = operand.rightJustified(4, '0');
        }

        // 检查位数是否达到需要补齐的条件，进行补齐操作
        int numGroups = operand.length() / 4;
        if (operand.length() % 4!= 0)
        {
            numGroups++;
        }
        int targetLength = numGroups * 4;
        operand = operand.rightJustified(targetLength, '0');
    }


    ui->Display->setText(operand);
}


void Programmer::on_btnCE_clicked()
{
    ui->Display->setText("");
}

