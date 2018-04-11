#ifndef SPHERE_H
#define SPHERE_H

#include "transformational.h"

#include <QColor>
#include <QVector4D>
#include <QMatrix4x4>
#include <QOpenGLBuffer>

class Sphere : public Transformational
{
protected:
    float m_radii;
    QColor m_color;
    QVector3D m_position;
    QVector3D m_scale;
    QMatrix4x4 m_globalTransform;

public:
    explicit Sphere(const float radii, const QColor color, const QVector3D position);
    void rotate(const QQuaternion &r);
    void translate(const QVector3D &t);
    void scale(const QVector3D &s);
    void setGlobalTransform(const QMatrix4x4 &g);
    void draw(BaseContext *c);

    float getRadii() const { return m_radii; }
    void setRadii(float radii) { m_radii = radii; }
    QColor getColor() const {return m_color; }
    void setColor(QColor color) { m_color = color; }
    QVector3D &getPosition() { return m_position; }
    void setPosition(QVector3D position) { m_position = position; }

private:
    void drawNoOpenGL(BaseContext *c);
    void drawOpenGl(BaseContext *c);
    void drawShader(BaseContext *c);

    void loadFromObj();
    void init(const QVector<VertexData> &vertData, const QVector<GLuint> &indexes);

    static QOpenGLBuffer m_vertexBuffer;
    static QOpenGLBuffer m_indexBuffer;
    static QVector<VertexData> vertexes;
    static QVector<GLuint> indexes;

};

#endif // SPHERE_H
