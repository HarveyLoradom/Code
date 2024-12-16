#include "date.h"
#include "ui_date.h"
#include"programmer.h"
#include"science.h"
#include"currency.h"
#include"capacity.h"
#include"mainwindow.h"
#include"QDate"
#include"QDateEdit"

Date::Date(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Date)
{
    ui->setupUi(this);
    QDate currentDate = QDate::currentDate();
    ui->stackedWidget->setCurrentIndex(0);
    ui->radioAdd->setChecked(true);
    ui->StartDate->setDate(currentDate);
    ui->EndDate->setDate(currentDate);
    calculateDateDiff();
    ui->DisplayDate1->setReadOnly(true);
    ui->StartedDate->setDate(currentDate);
    calculateDateDiff();
    ui->DisplayDate2->setReadOnly(true);
}

Date::~Date()
{
    delete ui;
}

void Date::calculateDateDiff()
{
    QDateEdit *startDate = ui->StartDate;
    QDateEdit *endDate = ui->EndDate;
    QDate date1 = startDate->date();
    QDate date2 = endDate->date();

    // 先计算总天数差值
    int totalDaysDiff = date1.daysTo(date2);
    if (totalDaysDiff < 0) {
        totalDaysDiff = -totalDaysDiff;
    }

    int yearsDiff = totalDaysDiff / 365;
    int remainingDaysAfterYears = totalDaysDiff % 365;
    int monthsDiff = remainingDaysAfterYears / 30;
    int remainingDaysAfterMonths = remainingDaysAfterYears % 30;
    int weeksDiff = remainingDaysAfterMonths / 7;
    int daysDiff = remainingDaysAfterMonths % 7;

    QString resultText;
    if (yearsDiff > 0) {
        resultText = QString("%1年").arg(yearsDiff);
        remainingDaysAfterYears -= yearsDiff * 365;
    }
    if (monthsDiff > 0) {
        if (!resultText.isEmpty()) {
            resultText += " ";
        }
        resultText += QString("%1月").arg(monthsDiff);
        remainingDaysAfterMonths -= monthsDiff * 30;
    }
    if (weeksDiff > 0) {
        if (!resultText.isEmpty()) {
            resultText += " ";
        }
        resultText += QString("%1周").arg(weeksDiff);
        remainingDaysAfterMonths -= weeksDiff * 7;
    }
    if (daysDiff > 0) {
        if (!resultText.isEmpty()) {
            resultText += " ";
        }
        resultText += QString("%1天").arg(daysDiff);
    }
    if(date1==date2){
        resultText="相同日期";
    }
    ui->DisplayDate1->setText(resultText);
}

void Date::calculatedDateDiff()
{
    bool RadioChecked=ui->radioAdd->isChecked();
    QDateEdit *startedDate = ui->StartedDate;
    QSpinBox *Year = ui->spinYear;
    QSpinBox *Month = ui->spinMonth;
    QSpinBox *Day=ui->spinDay;

    QDate originalDate = startedDate->date();
    int yearsToModify = Year->value();
    int monthsToModify = Month->value();
    int daysToModify=Day->value();

    QDate newDate = originalDate;

    if (RadioChecked) {
        // 如果radioAdd为true，进行添加操作
        newDate = newDate.addYears(yearsToModify).addMonths(monthsToModify).addDays(daysToModify);
    } else {
        // 如果radioAdd为false，进行减去操作
        newDate = newDate.addYears(-yearsToModify).addMonths(-monthsToModify).addDays(daysToModify);
    }
    // 将修改后的日期按照指定格式转换为字符串
    QString formattedDate = newDate.toString("yyyy年MM月dd日");
    // 在界面的某个QLabel（这里假设为resultLabel）上显示修改后的日期信息
    ui->DisplayDate2->setText(formattedDate);
}

void Date::on_Standard_triggered()
{
    MainWindow *mainwinodw=new MainWindow();
    this->hide();
    mainwinodw->show();
}


void Date::on_Science_triggered()
{
    Science *science=new Science();
    this->hide();
    science->show();
}


void Date::on_Programmer_triggered()
{
    Programmer *programmer=new Programmer();
    this->hide();
    programmer->show();
}


void Date::on_Currency_triggered()
{
    Currency *currency=new Currency();
    this->hide();
    currency->show();
}


void Date::on_Capacity_triggered()
{
    Capacity *capacity=new Capacity();
    this->hide();
    capacity->show();
}


void Date::on_ComboxChoice_activated(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}


void Date::on_StartDate_userDateChanged()
{
    calculateDateDiff();
}


void Date::on_EndDate_userDateChanged()
{
    calculateDateDiff();
}


void Date::on_StartedDate_userDateChanged()
{
    calculatedDateDiff();
}


void Date::on_spinYear_textChanged()
{
    calculatedDateDiff();
}


void Date::on_spinMonth_textChanged()
{
    calculatedDateDiff();
}


void Date::on_spinDay_textChanged()
{
    calculatedDateDiff();
}

