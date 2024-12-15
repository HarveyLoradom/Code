#ifndef SUBJECT_H
#define SUBJECT_H

#include <QMainWindow>

namespace Ui {
class Subject;
}

class Subject : public QMainWindow
{
    Q_OBJECT

public:
    explicit Subject(QWidget *parent = nullptr);
    ~Subject();

private slots:
    void on_Standard_triggered();

private:
    Ui::Subject *ui;
};

#endif // SUBJECT_H
