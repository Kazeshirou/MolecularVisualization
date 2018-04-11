#include "contextgl.h"

ContextGL::ContextGL(const int width, const int height) :
    BaseContext(width, height),
    m_functions(nullptr)
{
    type = OpenGl;
}


ContextGL::ContextGL(const int width, const int height, QOpenGLFunctions *functions) :
    BaseContext(width, height),
    m_functions(functions)
{
    type = OpenGl;
    functions->glClearColor(m_color.red()/255.,m_color.green()/255.,m_color.blue()/255.,1);
    functions->glEnable(GL_DEPTH_TEST);
    functions->glEnable(GL_CULL_FACE);
    initShaders();
}

ContextGL::ContextGL(const QSize &size, QOpenGLFunctions *functions) :
    BaseContext(size.width(), size.height()),
    m_functions(functions)
{
    type = OpenGl;
    functions->glClearColor(m_color.red()/255.,m_color.green()/255.,m_color.blue()/255.,1);
    functions->glEnable(GL_DEPTH_TEST);
    functions->glEnable(GL_CULL_FACE);
    functions->glEnable(GL_SMOOTH);
    initShaders();
}

void ContextGL::clear()
{
    m_functions->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void ContextGL::resize(const int width, const int height)
{
    if ((width == m_width) && (height == m_height))
        return;
    m_width = width;
    m_height = height;
    float aspect = m_width/ (m_height ? (float)m_height : 1.);
    m_projectionMatrix.setToIdentity();
    m_projectionMatrix.perspective(45, aspect, n,f );
    m_viewPortMatrix.setToIdentity();
    m_viewPortMatrix.translate(QVector3D(m_width/2.,m_height/2.,(f-n)/2.));
    m_viewPortMatrix.scale(m_width/2.,m_height/2.,(f-n)/2.);
}

void ContextGL::resize(const QSize &s)
{
    int width = s.width();
    int height = s.height();
    if ((width == m_width) && (height == m_height))
        return;
    float aspect = m_width/ (m_height ? (float)m_height : 1.);
    m_projectionMatrix.setToIdentity();
    m_projectionMatrix.perspective(45, aspect, n,f );
    m_viewPortMatrix.setToIdentity();
    m_viewPortMatrix.translate(QVector3D(m_width/2.,m_height/2.,(f-n)/2.));
    m_viewPortMatrix.scale(m_width/2.,m_height/2.,(f-n)/2.);
}

void ContextGL::activate()
{
    clear();
    m_program.bind();
    m_program.setUniformValue("u_projectionMatrix", m_projectionMatrix);
    m_program.setUniformValue("u_lightPosition", QVector4D(0.0, 0.0, 0.0, 0.1));
    m_program.setUniformValue("u_lightPower", 1.0f);
    m_program.setUniformValue("u_viewMatrix", m_viewMatrix);
}

void ContextGL::setFunctions(QOpenGLFunctions *f)
{
    m_functions = f;
    m_functions->glClearColor(m_color.red()/255.,m_color.green()/255.,m_color.blue()/255.,1);
    m_functions->glEnable(GL_DEPTH_TEST);
    m_functions->glEnable(GL_CULL_FACE);
    initShaders();
}

void ContextGL::initShaders()
{
    if (m_program.isLinked())
        return;
    if (!m_program.addCacheableShaderFromSourceFile(QOpenGLShader::Vertex,":/shader/vert.vsh"))
        return;
    if (!m_program.addCacheableShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader/frag.fsh"))
        return;
    // link связывает наши шейдеры в один и протягивает сквозь них переменные  varying
    if (!m_program.link())
        return;
}
