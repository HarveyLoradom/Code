#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include<QKeyEvent>
#include<QMap>
#include<QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString operand;
    QString opcode;
    QStack<QString> operands;
    QStack<QString> opcodes;
    QMap<int,QPushButton*> digitBTNs;
    QMap<int,QPushButton*> digitBinarys;
    QMap<int,QPushButton*> digitUnBinarys;
    QMap<int,QPushButton*> digitElse;
    QString calculation(bool *ok=NULL);

private:
    Ui::MainWindow *ui;


private slots:
    void btnNumClicked();
    void btnBinaryOperatorClicked();
    void btnUnaryOperatorClicked();

    void on_btnPoint_clicked();

    void on_btnDelete_clicked();

    void on_btnC_clicked();

    void on_btnEqual_clicked();

    void on_btnCE_clicked();

    virtual void keyPressEvent(QKeyEvent *event);

    void on_btnAddMinus_clicked();
    void on_Science_triggered();
    void on_Programmer_triggered();
    void on_Date_triggered();
    void on_Currency_triggered();
    void on_Capacity_triggered();
};
#endif // MAINWINDOW_H
