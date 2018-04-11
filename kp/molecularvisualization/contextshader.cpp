#include "contextshader.h"

ContextShader::ContextShader(const int width, const int height) :
    BaseContext(width, height),
    m_functions(nullptr)
{
    type = SHADER;
}

ContextShader::ContextShader(const int width, const int height, QOpenGLFunctions *functions) :
    BaseContext(width, height),
    m_functions(nullptr)
{
    type = SHADER;
    functions->glClearColor(m_color.red()/255.,m_color.green()/255.,m_color.blue()/255.,1);
    functions->glEnable(GL_DEPTH_TEST);
    functions->glEnable(GL_CULL_FACE);
    functions->glEnable(GL_POINT_SIZE);
    functions->glEnable(GL_POINT_SPRITE);
    functions->glEnable(GL_POINT_SMOOTH);
    functions->glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    initShaders();
}

void ContextShader::clear()
{
    m_functions->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void ContextShader::resize(const int width, const int height)
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

void ContextShader::resize(const QSize &s)
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

void ContextShader::activate()
{
    clear();
    m_program.bind();
    m_program.setUniformValue("u_projectionMatrix", m_projectionMatrix);
    m_program.setUniformValue("u_lightPosition", QVector4D(0.0, 0.0, 0.0, 0.1));
    m_program.setUniformValue("u_lightPower", 1.0f);
    m_program.setUniformValue("u_viewMatrix", m_viewMatrix);
    GLfloat viewport[4];
    m_functions->glGetFloatv(GL_VIEWPORT,viewport);
    QVector4D vp(viewport[0],viewport[1],viewport[2],viewport[3]);
    m_program.setUniformValue("u_viewport",vp);
}

void ContextShader::setFunctions(QOpenGLFunctions *f)
{
    m_functions = f;
    m_functions->glClearColor(m_color.red()/255.,m_color.green()/255.,m_color.blue()/255.,1);
    m_functions->glEnable(GL_DEPTH_TEST);
    m_functions->glEnable(GL_CULL_FACE);
    m_functions->glEnable(GL_POINT_SIZE);
    m_functions->glEnable(GL_POINT_SPRITE);
    m_functions->glEnable(GL_POINT_SMOOTH);
    m_functions->glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    initShaders();
}

void ContextShader::initShaders()
{
    if (m_program.isLinked())
        return;
    if (!m_program.addCacheableShaderFromSourceFile(QOpenGLShader::Vertex,":/shader/spherevert.vsh"))
        return;
    if (!m_program.addCacheableShaderFromSourceFile(QOpenGLShader::Fragment, ":/shader/spherefrag.fsh"))
        return;
    if (!m_program.link())
        return;
}
