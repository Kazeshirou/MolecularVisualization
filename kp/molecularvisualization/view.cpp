#include "view.h"

#include <QPainter>


View::View(QWidget *parent) :
    BaseView(parent),
    m_context(600, 600)
{

}

void View::resizeEvent(QResizeEvent *e)
{
    m_context.resize(e->size());
}

void View::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    m_context.clear();

    m_camera->draw(&m_context);
    for (int i = 0; i < m_objects.size(); i++)
        m_objects[i]->draw(&m_context);
    QPainter p(this);
    p.drawImage(0,0,m_context.getImage());
}

QImage &View::getImage()
{
    return m_context.getImage();
}



