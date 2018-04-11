#ifndef BASEPAINTER_H
#define BASEPAINTER_H

#include <QImage>
#include <QColor>

class basePainter
{
    QImage *img;
    QRgb color;

    QRgb intensityColor(double i);
    int round(double x);
    int sign(double x);

public:
    explicit basePainter(QImage &image, QRgb col);
    void pixel(QPoint point);
    void pixel(QPoint point, QRgb col);
    void drawLine(QPoint start, QPoint end);
    void drawCircle(QPoint center, int r);
    void setColor(QRgb col);
    void setImage(QImage &image);

};

#endif // BASEPAINTER_H
