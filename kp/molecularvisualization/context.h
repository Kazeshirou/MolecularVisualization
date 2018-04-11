#ifndef CONTEXT_H
#define CONTEXT_H

#include "basecontext.h"
#include <QImage>


class Context : public BaseContext
{
    QImage m_image;
    float **m_zbuffer;

public:
    explicit Context(const int width, const int height);
    explicit Context(const QSize &size);
    ~Context();

    void clear();
    void resize(const int width, const int height);
    void resize(const QSize &size);


    QColor getPixel(const int x, const int y);
    void setPixel(const int x, const int y, const float z, const QColor color, const QVector3D norm);
    QImage &getImage();

private:
    float **newZbuffer(const int width, const int height);
    float **newZbuffer(const QSize &size);
    void deleteZbuffer();

    QColor colorWithIntensity(const QColor color, QVector3D n);

};

#endif // CONTEXT_H
