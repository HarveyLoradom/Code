#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QMouseEvent>
#include <QObject>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MyLineEdit(QWidget *parent = nullptr);

signals:
    void clicked();  // 自定义clicked信号

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // MYLINEEDIT_H
