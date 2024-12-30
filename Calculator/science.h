#ifndef SCIENCE_H
#define SCIENCE_H

#include <QMainWindow>
#include<QPushButton>
namespace Ui {
class Science;
}

class Science : public QMainWindow
{
    Q_OBJECT

public:
    explicit Science(QWidget *parent = nullptr);
    ~Science();
    QString operand;
    QString opcode;
    QList<QString> operands;
    QList<QString> opcodes;
    QMap<int,QPushButton*> digitBTNs;

    QString calculation(bool *ok=NULL);
    QList<QString> historyRecords;
    QMap<int,QPushButton*> digitBinarys;
    QMap<int,QPushButton*> digitUnBinarys;
    QMap<int,QPushButton*> digitElse;


    void updateHistoryDisplay();
    bool hasResult;
    bool isCheckedState;




private slots:
    void on_Standard_triggered();

    void on_Programmer_triggered();

    void on_Date_triggered();

    void on_Currency_triggered();

    void on_Capacity_triggered();



    void on_btnEqual_clicked();
    void on_btnPoint_clicked();
    void on_btnDelete_clicked();
    void on_btnC_clicked();
    void btnNumClicked();

    void btnBinaryOperatorClicked();
    void btnUnaryOperatorClicked();
    void on_btnAddMinus_clicked();


    void on_btn2andND_clicked();

    void on_btnLog_clicked();

    void on_Theme_triggered();

    void on_Background_triggered();

    void on_Font_triggered();

    void on_FontColor_triggered();

    void on_FontBackgroundColor_triggered();

private:
    Ui::Science *ui;
};

#endif // SCIENCE_H
