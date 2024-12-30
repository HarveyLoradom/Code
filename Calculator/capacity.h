#ifndef CAPACITY_H
#define CAPACITY_H

#include <QMainWindow>
#include<QPushButton>

namespace Ui {
class Capacity;
}

class Capacity : public QMainWindow
{
    Q_OBJECT

public:
    explicit Capacity(QWidget *parent = nullptr);
    ~Capacity();
    double getExchangeRate(const QString &fromCapacity, const QString &toCapacity);
    void convertCapacity();
    QString Amount;
    QMap<int,QPushButton*> digitBTNs;
    QMap<int,QPushButton*> digitElse;

private slots:


    void on_Currency_triggered();

    void on_Standard_triggered();

    void on_Science_triggered();

    void on_Programmer_triggered();

    void on_Date_triggered();

    void btnNumClicked();
    void on_btnPoint_clicked();
    void on_btnCE_clicked();
    void on_btnDelete_clicked();

    void on_startEdit_clicked();
    void on_endEdit_clicked();

    void on_comboxStart_activated();

    void on_comboxEnd_activated();

    void on_Theme_triggered();

    void on_Background_triggered();

    void on_Font_triggered();

    void on_FontColor_triggered();

    void on_FontBackgroundColor_triggered();

private:
    Ui::Capacity *ui;
};

#endif // CAPACITY_H
