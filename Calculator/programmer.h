#ifndef PROGRAMMER_H
#define PROGRAMMER_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QPainter>
namespace Ui {
class Programmer;
}

class Programmer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Programmer(QWidget *parent = nullptr);
    ~Programmer();
    QMap<int,QPushButton*> digitBTNs;
    QMap<int,QPushButton*> digitBinarys;
    QMap<int,QPushButton*> digitElse;

    QMap<int,QPushButton*> digitHEX;
    QMap<int,QPushButton*> digitDEC;
    QMap<int,QPushButton*> digitOCT;
    QMap<int,QPushButton*> digitBIN;
    QMap<int,QPushButton*> digitALL;

    QString operand;
    QString opcode;
    QList<QString> operands;
    QList<QString> opcodes;

private slots:
    void on_Science_triggered();

    void on_Date_triggered();

    void on_Currency_triggered();

    void on_Capacity_triggered();

    void on_Standard_triggered();

    void on_btnHEX_clicked();

    void on_btnDEC_clicked();

    void on_btnOCT_clicked();

    void on_btnBIN_clicked();

    void setButtonBackgroundColor(QPushButton *clickedButton);

    void setButtonDisable(QMap<int,QPushButton*> digit);
    void setButtonEnable();

    void btnHEX_clicked();
    void btnDEC_clicked();
    void btnOCT_clicked();
    void btnBIN_clicked();

    void on_btnCE_clicked();

private:
    Ui::Programmer *ui;



};

#endif // PROGRAMMER_H
