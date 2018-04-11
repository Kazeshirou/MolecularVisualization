#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QWidget>

class colorButton : public QWidget
{
    Q_OBJECT

    QColor currentColor;
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
signals:
    void changedColor(QColor color);
public:
    explicit colorButton(QWidget *parent = 0);
    QColor &color();
    void setColor(QColor color);
};

#endif // COLORBUTTON_H
