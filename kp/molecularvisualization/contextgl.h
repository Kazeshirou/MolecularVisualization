#ifndef CONTEXTGL_H
#define CONTEXTGL_H

#include "basecontext.h"

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

class ContextGL : public BaseContext
{
    QOpenGLFunctions *m_functions;
    QOpenGLShaderProgram m_program;

public:
    explicit ContextGL(const int width, const int height);
    explicit ContextGL(const int width, const int height, QOpenGLFunctions *functions);
    explicit ContextGL(const QSize &size, QOpenGLFunctions *functions);

    void clear();
    void resize(const int width, const int height);
    void resize(const QSize &size);

    void activate();
    QOpenGLShaderProgram *getProgram() { return &m_program; }
    QOpenGLFunctions *&getFunctions() { return m_functions; }
    void setFunctions(QOpenGLFunctions *f);
private:
    void initShaders();
};

#endif // CONTEXTGL_H
