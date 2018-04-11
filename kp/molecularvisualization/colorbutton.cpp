#include "colorbutton.h"
#include "QColorDialog"
#include "QPainter"

colorButton::colorButton(QWidget *parent) : QWidget(parent)
{
    currentColor = Qt::white;
}


void colorButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setBrush(QBrush(currentColor));
    painter.drawRect(QRect(QPoint(0,0),
                               QPoint(this->width(),this->height())));
}

void colorButton::setColor(QColor color)
{
    currentColor = color;
    update();
}

void colorButton::mousePressEvent(QMouseEvent *)
{
    currentColor = QColorDialog::getColor();
    emit changedColor(currentColor);
}

QColor &colorButton::color()
{
    return currentColor;
}
