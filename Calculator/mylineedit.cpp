#include "MyLineEdit.h"

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent)
{
}

void MyLineEdit::mousePressEvent(QMouseEvent *event)
{
    QLineEdit::mousePressEvent(event);
    if (event->button() == Qt::LeftButton) {
        emit clicked();  // 当鼠标左键点击时，发射clicked信号
    }
}
