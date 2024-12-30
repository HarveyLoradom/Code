#ifndef CURRENCY_H
#define CURRENCY_H

#include <QMainWindow>
#include<QMap>
#include<QPushButton>
#include"QLineEdit"

namespace Ui {
class Currency;
}

class Currency : public QMainWindow
{
    Q_OBJECT

public:
    explicit Currency(QWidget *parent = nullptr);
    ~Currency();
    double getExchangeRate(const QString &fromCurrency, const QString &toCurrency);
    void convertCurrency();
    QString Amount;
    QMap<int,QPushButton*> digitBTNs;
    QMap<int,QPushButton*> digitElse;

private slots:
    void on_Science_triggered();

    void on_Standard_triggered();

    void on_Programmer_triggered();

    void on_Date_triggered();

    void on_Capacity_triggered();

    void on_comboxEnd_activated();

    void on_comboxStart_activated();


    void btnNumClicked();
    void on_btnPoint_clicked();
    void on_btnCE_clicked();
    void on_btnDelete_clicked();

    void on_startEdit_clicked();
    void on_endEdit_clicked();

    void on_Theme_triggered();

    void on_Background_triggered();

    void on_Font_triggered();

    void on_FontColor_triggered();

    void on_FontBackgroundColor_triggered();

private:
    Ui::Currency *ui;


};

#endif // CURRENCY_H
