#include "myview.h"

#include <QPainter>
#include <QResizeEvent>
#include <cmath>

myView::myView(QWidget *parent) : QWidget(parent),
    backgroundColor(WHITE)
{
    painter = new basePainter(img, BLACK);
    this->setMouseTracking(true);
    this->setEnabled(true);
}

myView::~myView()
{
    delete painter;
}

void myView::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0,0,img);
}

void myView::resizeEvent(QResizeEvent *e)
{
    QRgb col;
    int width = e->size().width();
    int height = e->size().height();
    int oldw = e->oldSize().width();
    int oldh = e->oldSize().height();
    QImage im = QImage(width, height, QImage::Format_ARGB32);
    if (oldw >= width && oldh >= height)
        im = img.copy(0,0,width,height);
    else{
        im.fill(backgroundColor);
        int ci = oldw >= width ? 0 : (width-oldw)/2;
        int cj = oldh >= height ? 0 : (height-oldh)/2;
        for (int i = 0; (i < oldw) && (i < width); i++)
            for (int j = 0; (j < oldh) && (j < height); j++)
                if ((col = img.pixel(i,j)) != backgroundColor)
                    im.setPixel(ci+i,cj+j,col);
    }
    img = im;
    painter->setImage(img);
}

void myView::mousePressEvent(QMouseEvent *)
{
    painter->drawLine(QPoint(10,10),QPoint(50,50));
    update();
}

QImage &myView::getImage()
{
    return img;
}

void myView::setImage(QImage image)
{
    img = image;
    painter->setImage(img);
    update();
}

void myView::setBackgroundColor(QRgb color)
{
    QRgb oldc = backgroundColor;
    backgroundColor = color;
    for (int i = 0; i < img.width(); i++)
        for (int j = 0; j < img.height(); j++)
            if (img.pixel(i,j) == oldc)
                img.setPixel(i,j,backgroundColor);
    update();
}


void myView::setPainter(basePainter *paint)
{
    paint->setImage(img);
    delete painter;
    painter = paint;
}

basePainter *myView::getPainter()
{
    return painter;
}
