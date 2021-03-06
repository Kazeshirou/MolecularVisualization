#include "camera.h"

#include "context.h"

Camera::Camera() :
    m_scale(1.0,1.0,1.0)
{
    m_globalTransform.setToIdentity();
}

void Camera::draw(BaseContext *c)
{
    c->setViewMatrix(m_viewMatrix);
}

void Camera::rotate(const QQuaternion &r)
{
    m_rotate = r * m_rotate;
    m_viewMatrix.setToIdentity();
    m_viewMatrix.translate(m_translate);
    m_viewMatrix.rotate(m_rotate);
    m_viewMatrix.scale(m_scale);
    m_viewMatrix = m_viewMatrix * m_globalTransform.inverted();

}

void Camera::translate(const QVector3D &t)
{
    m_translate += t;
    m_viewMatrix.setToIdentity();
    m_viewMatrix.translate(m_translate);
    m_viewMatrix.rotate(m_rotate);
    m_viewMatrix.scale(m_scale);
    m_viewMatrix = m_viewMatrix * m_globalTransform.inverted();

}

void Camera::scale(const QVector3D &s)
{
    m_scale *= s;
    m_viewMatrix.setToIdentity();
    m_viewMatrix.translate(m_translate);
    m_viewMatrix.rotate(m_rotate);
    m_viewMatrix.scale(m_scale);
    m_viewMatrix = m_viewMatrix * m_globalTransform.inverted();

}

void Camera::setGlobalTransform(const QMatrix4x4 &g)
{
    m_globalTransform = g;
    m_viewMatrix.setToIdentity();
    m_viewMatrix.translate(m_translate);
    m_viewMatrix.rotate(m_rotate);
    m_viewMatrix.scale(m_scale);
    m_viewMatrix = m_viewMatrix * m_globalTransform.inverted();

}

