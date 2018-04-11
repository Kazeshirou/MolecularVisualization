#include "baseview.h"

bool BaseView::m_animation = true;
BaseView::BaseView(QWidget *parent) : QOpenGLWidget(parent), m_angle(0), m_camera(new Camera)
{
    m_camera->translate(QVector3D(0.0,0.0,-100.0));
    m_timer.start(40, this);
}

void BaseView::setMolecule(Molecule *m)
{
    m_objects.clear();
    m_objects.append(m);
    update();
}

