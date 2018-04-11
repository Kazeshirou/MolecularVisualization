#ifndef MYVIEW_H
#define MYVIEW_H

#include <QWidget>
#include <QVector>

#include <basepainter.h>

enum { WHITE = qRgb(255,255,255), BLACK = qRgb(0,0,0) };
class myView : public QWidget
{
    Q_OBJECT

    QImage img;
    basePainter *painter;  // sharedptr!
    QRgb backgroundColor;
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *e);
    void mousePressEvent(QMouseEvent *e);

public:
    explicit myView(QWidget *parent = nullptr);
    ~myView();
    QImage &getImage();
    void setImage(QImage image);
    void setBackgroundColor(QRgb color);
    void setPainter(basePainter *paint);
    basePainter *getPainter();

};

#endif // MYVIEW_H
