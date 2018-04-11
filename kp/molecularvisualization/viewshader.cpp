#include "viewshader.h"

ViewShader::ViewShader(QWidget *parent) :
    BaseView(parent),
    m_context(600, 600)
{
    setWindowTitle(QString("Со специальным шейдером сфер"));
}


void ViewShader::resizeGL(int w, int h)
{
    m_context.resize(w, h);
}

void ViewShader::paintGL()
{
    m_context.setFunctions(context()->functions());
    m_context.clear();
    m_context.activate();
    m_camera->draw(&m_context);
    for (int i = 0; i < m_objects.size(); i++)
        m_objects[i]->draw(&m_context);
}
