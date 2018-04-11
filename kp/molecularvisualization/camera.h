#ifndef CAMERA_H
#define CAMERA_H

#include "transformational.h"

#include <QMatrix4x4>

class Camera : public Transformational
{
    QQuaternion m_rotate;
    QVector3D m_translate;
    QVector3D m_scale;
    QMatrix4x4 m_globalTransform;
    QMatrix4x4 m_viewMatrix;

public:
    Camera();
    void draw(BaseContext *c);
    void rotate(const QQuaternion &r);
    void translate(const QVector3D &t);
    void scale(const QVector3D &s);
    void setGlobalTransform(const QMatrix4x4 &g);

    QVector3D &getTranslate() { return m_translate; }

};

#endif // CAMMERA_H
