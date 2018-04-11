#ifndef CONTEXTSHADER_H
#define CONTEXTSHADER_H

#include "basecontext.h"

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

class ContextShader: public BaseContext
{
    QOpenGLFunctions *m_functions;
    QOpenGLShaderProgram m_program;

public:
    explicit ContextShader(const int width, const int height);
    explicit ContextShader(const int width, const int height, QOpenGLFunctions *functions);

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

#endif // CONTEXTSHADER_H
