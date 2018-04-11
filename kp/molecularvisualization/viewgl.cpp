#include "viewgl.h"

ViewGL::ViewGL(QWidget *parent) :
    BaseView(parent),
    m_context(600, 600)
{
    setWindowTitle(QString("С OpenGL"));
}


void ViewGL::resizeGL(int w, int h)
{
    m_context.resize(w, h);
}

void ViewGL::paintGL()
{
    m_context.setFunctions(context()->functions());
    m_context.clear();
    m_context.activate();
    m_camera->draw(&m_context);
    for (int i = 0; i < m_objects.size(); i++)
        m_objects[i]->draw(&m_context);
}
