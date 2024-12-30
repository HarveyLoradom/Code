#ifndef DATE_H
#define DATE_H

#include <QMainWindow>

namespace Ui {
class Date;
}

class Date : public QMainWindow
{
    Q_OBJECT

public:
    explicit Date(QWidget *parent = nullptr);
    ~Date();

    void calculateDateDiff();
    void calculatedDateDiff();

private slots:
    void on_Standard_triggered();

    void on_Science_triggered();

    void on_Programmer_triggered();

    void on_Currency_triggered();

    void on_Capacity_triggered();

    void on_ComboxChoice_activated(int index);


    void on_StartDate_userDateChanged();

    void on_EndDate_userDateChanged();

    void on_StartedDate_userDateChanged();

    void on_spinYear_textChanged();

    void on_spinMonth_textChanged();

    void on_spinDay_textChanged();

    void on_Theme_triggered();

    void on_Background_triggered();

    void on_Font_triggered();

    void on_FontColor_triggered();

    void on_FontBackgroundColor_triggered();

private:
    Ui::Date *ui;
};

#endif // DATE_H
