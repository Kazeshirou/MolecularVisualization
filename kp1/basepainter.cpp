#include "basepainter.h"
#include <QRgb>
#include <cmath>

basePainter::basePainter(QImage &image, QRgb col): img(&image),
    color(col)
{

}

QRgb basePainter::intensityColor(double i)
{
    i = 1-i;
    int red = qRed(color);
    red = red+(255-red)*i+0.5;
    int green = qGreen(color);
    green = green+(255-green)*i+0.5;
    int blue = qBlue(color);
    blue = blue+(255-blue)*i+0.5;
    return qRgb(red,green,blue);
}

int basePainter::round(double x)
{
   return int(x+0.5);
}

int basePainter::sign(double x)
{
    if (x > 0)
        return 1;
    else if (x == 0)
        return 0;
    else
        return -1;
}

void basePainter::pixel(QPoint point)
{
    if ((point.x() < img->width()) && (point.y() < img->height()) &&
            (point.x() >= 0) && (point.y() >= 0))
        img->setPixel(point, color);
}

void basePainter::pixel(QPoint point, QRgb col)
{
    if ((point.x() < img->width()) && (point.y() < img->height()) &&
            (point.x() >= 0) && (point.y() >= 0))
        img->setPixel(point, col);
}

void basePainter::drawLine(QPoint start, QPoint end)
{
    if (start == end){
        pixel(start);
        return;
    }
    int x = start.x();
    int y = start.y();
    double dx = end.x()-start.x();
    double dy = end.y()-start.y();
    int sx = sign(dx);
    int sy = sign(dy);
    dx = std::abs(dx);
    dy = std::abs(dy);

    bool f;
    if (dx > dy)
        f = false;
    else{
        f = true;
        int t = dx;
        dx = dy;
        dy = t;
    }

    int m = 2*dy;
    int e = m-dx;
    for (int i = 0; i < dx+1; i++){
        pixel(QPoint(x, y));
        if (e > 0){
            if (!f)
                y += sy;
            else
                x += sx;
            e -= 2*dx;
        }
        if (!f)
            x += sx;
        else
            y += sy;
        e += m;
    }
}

void basePainter::drawCircle(QPoint center, int r)
{
    if (r == 0){
        pixel(center);
        return;
    }
    int x = 0;
    int y = r;
    int deltai = 2*(1-r);
    while(y>=0){
        pixel(QPoint(x+center.x(), y+center.y()));
        pixel(QPoint(x+center.x(), -y+center.y()));
        pixel(QPoint(-x+center.x(), y+center.y()));
        pixel(QPoint(-x+center.x(), -y+center.y()));
        if (deltai < 0 && (2*(deltai+y)-1 <= 0)){
            x++;
            deltai +=2*x+1;

        }
        else if (deltai > 0 && (2*(deltai-x)-1 >= 0)){
            y--;
            deltai += 1-2*y;
        }
        else{
            x++;
            y--;
            deltai += 2*(x-y+1);
        }
    }
}

void basePainter::setColor(QRgb col)
{
    color = col;
}
void basePainter::setImage(QImage &image)
{
    img = &image;
}
