#ifndef CILINDER_H
#define CILINDER_H

#include "transformational.h"

#include <QColor>
#include <QVector4D>
#include <QMatrix4x4>
#include <QOpenGLBuffer>

class Cilinder: public Transformational
{
protected:
    static float m_radii;
    static QColor m_color;
    QVector3D m_position;
    QVector3D m_position1;
    QVector3D m_scale;
    QQuaternion m_rotate;
    QMatrix4x4 m_globalTransform;   

public:
    explicit Cilinder(const QVector3D pos, const QVector3D pos1);
    void rotate(const QQuaternion &r);
    void translate(const QVector3D &t);
    void scale(const QVector3D &s);
    void setGlobalTransform(const QMatrix4x4 &g);
    virtual void draw(BaseContext *c);

    static QColor getColor() { return m_color; }
    static void setColor(QColor color) { m_color = color; }
    static float getRadii() { return m_radii; }
    static void setRadii (float radii) { m_radii = radii; }
    static int sign(float x);

private:
    void drawNoOpenGL(BaseContext *c);
    void drawOpenGl(BaseContext *c);

    void loadFromObj();
    void init(const QVector<VertexData> &vertData, const QVector<GLuint> &indexes);

    static QOpenGLBuffer m_vertexBuffer;
    static QOpenGLBuffer m_indexBuffer;
    static QVector<VertexData> vertexes;
    static QVector<GLuint> indexes;

};

#endif // CILINDER_H
