#include "basecontext.h"

BaseContext::Mode BaseContext::mode = BaseContext::SPACEFILL;

BaseContext::BaseContext(const int width, const int height) :
    n(10.f),
    f(200.f),
    m_width(width),
    m_height(height),
    m_color(50,50,50),
    m_lightdir(0,0,1)
{
    float aspect = m_width/ (m_height ? (float)m_height : 1.);
    m_projectionMatrix.setToIdentity();
    m_projectionMatrix.perspective(45, aspect, n, f);
    m_viewPortMatrix.setToIdentity();
    m_viewPortMatrix.translate(QVector3D(m_width/2.,m_height/2.,(f-n)/2.));
    m_viewPortMatrix.scale(m_width/2.,m_height/2.,(f-n)/2.);
}
