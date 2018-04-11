#ifndef BASECONTEXT_H
#define BASECONTEXT_H

#include <QMatrix4x4>
#include <QColor>

class BaseContext
{
public:
    enum Mode { BnS, SPACEFILL };
    enum Type { NoOpenGL, OpenGl, SHADER };
    BaseContext(const int width, const int height);
    virtual ~BaseContext() = default;

    static void setMode(Mode m) { mode = m;}
    static Mode getMode() { return mode; }
    void setType(Type m) { type = m; }
    Type getType() { return type; }
    void setViewMatrix(QMatrix4x4 &m) { m_viewMatrix = m; }
    QMatrix4x4 &getViewMatrix() { return m_viewMatrix; }
    QMatrix4x4 &getViewPortMatrix() { return m_viewPortMatrix; }
    QMatrix4x4 &getProjectionMatrix() { return m_projectionMatrix; }

    virtual void clear() = 0;
    virtual void resize(const int width, const int height) = 0;
    virtual void resize(const QSize &s) = 0;

protected:
    float n;
    float f;
    static Mode mode;
    Type type;

    int m_width;
    int m_height;
    QColor m_color;
    QVector3D m_lightdir;
    QMatrix4x4 m_projectionMatrix;
    QMatrix4x4 m_viewMatrix;
    QMatrix4x4 m_viewPortMatrix;
    float m_min;
};

#endif // BASECONTEXT_H
