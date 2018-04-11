#ifndef TRANSFORMATIONAL_H
#define TRANSFORMATIONAL_H


#include <QVector3D>
#include <QVector2D>

class QQuaternion;
class QMatrix4x4;
class BaseContext;

struct VertexData {
    VertexData()
    {
    }
    VertexData(QVector3D p, QVector2D t, QVector3D n)
        : position(p),
          texCoord(t),
          normal(n)
    {
    }
    QVector3D position;
    QVector2D texCoord;
    QVector3D normal;
};

class Transformational
{
public:
    Transformational() = default;
    virtual ~Transformational() = default;
    virtual void rotate(const QQuaternion &r) = 0;
    virtual void translate(const QVector3D &t) = 0;
    virtual void scale(const QVector3D &s) = 0;
    virtual void setGlobalTransform(const QMatrix4x4 &g) = 0;
    virtual void draw(BaseContext *c) = 0;
};

#endif // TRANSFORMATIONAL_H
