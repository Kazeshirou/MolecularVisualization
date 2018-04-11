#include "context.h"

Context::Context(const int width, const int height) :
    BaseContext(width, height),
    m_image(width, height, QImage::Format_ARGB32),
    m_zbuffer(nullptr)
{
    type = NoOpenGL;
    m_min = f;
    m_image.fill(m_color);
    m_zbuffer = newZbuffer(width, height);
}

Context::Context(const QSize &size) :
    BaseContext(size.width(), size.height()),
    m_image(m_width, m_height, QImage::Format_ARGB32),
    m_zbuffer(nullptr)
{
    type = NoOpenGL;
    m_min = f;
    m_image.fill(m_color);
    m_zbuffer = newZbuffer(m_width, m_height);
}

Context::~Context()
{
    deleteZbuffer();
}

void Context::clear()
{
    m_image.fill(m_color);
    for (int i = 0; i < m_width; i++)
        for (int j = 0; j < m_height; j++)
            m_zbuffer[i][j] = m_min;
}

void Context::resize(const int width, const int height)
{
    if ((width == m_width) && (height == m_height))
        return;
    float **zbuffer = newZbuffer(width, height);
    m_image = QImage(width, height, QImage::Format_ARGB32);
    m_image.fill(m_color);
    deleteZbuffer();
    m_zbuffer = zbuffer;
    m_width = width;
    m_height = height;
    float aspect = m_width/ (m_height ? (float)m_height : 1.);
    m_projectionMatrix.setToIdentity();
    m_projectionMatrix.perspective(45, aspect, n,f );
    m_viewPortMatrix.setToIdentity();
    m_viewPortMatrix.translate(QVector3D(m_width/2.,m_height/2.,(f-n)/2.));
    m_viewPortMatrix.scale(m_width/2.,m_height/2.,(f-n)/2.);
}

void Context::resize(const QSize &s)
{
    int width = s.width();
    int height = s.height();
    if ((width == m_width) && (height == m_height))
        return;
    float **zbuffer = newZbuffer(width, height);
    m_image = QImage(width, height, QImage::Format_ARGB32);
    m_image.fill(m_color);
    deleteZbuffer();
    m_zbuffer = zbuffer;
    m_width = width;
    m_height = height;
    float aspect = m_width/ (m_height ? (float)m_height : 1.);
    m_projectionMatrix.setToIdentity();
    m_projectionMatrix.perspective(45, aspect, n,f);
    m_viewPortMatrix.setToIdentity();
    m_viewPortMatrix.translate(QVector3D(m_width/2.,m_height/2.,(f-n)/2.));
    m_viewPortMatrix.scale(m_width/2.,m_height/2.,(f-n)/2.);
}

QColor Context::getPixel(const int x, const int y)
{
    if (x >= m_width || y >= m_height || x < 0 || y < 0 )
        return QColor(0,0,0);
    return m_image.pixel(x, y);
}

void Context::setPixel(const int x, const int y, const float z, const QColor color, const QVector3D norm)
{
    if (x >= m_width || y >= m_height || x < 0 || y < 0 || z < n || z > f)
        return;
    if (z <= m_zbuffer[x][y]){
        QColor col = colorWithIntensity(color, norm);
        m_image.setPixel(x, y, col.rgba());
        m_zbuffer[x][y] = z;
    }
}

QImage &Context::getImage()
{
    return m_image;
}

QColor Context::colorWithIntensity(const QColor color, QVector3D n)
{
    double intens = QVector3D::dotProduct(n, m_lightdir);
    return QColor(std::max(color.red()*intens,0.),std::max(color.green()*intens,0.),std::max(color.blue()*intens,0.));
}

float** Context::newZbuffer(const int width, const int height)
{
    float **zbuffer;
    zbuffer = new float*[width];
    for (int i = 0; i < width; i++){
        zbuffer[i] = new float[height];
        for (int j = 0; j < height; j++)
            zbuffer[i][j] = m_min;
    }
    return zbuffer;
}

float **Context::newZbuffer(const QSize &size)
{
    int width = size.width();
    int height = size.height();
    float **zbuffer;
    zbuffer = new float*[width];
    for (int i = 0; i < width; i++){
        zbuffer[i] = new float[height];
        for (int j = 0; j < height; j++)
            zbuffer[i][j] = m_min;
    }
    return zbuffer;
}

void Context::deleteZbuffer()
{
    if (m_zbuffer){
        for (int i = 0; i < m_width; i++)
            delete m_zbuffer[i];
        delete m_zbuffer;
        m_zbuffer = nullptr;
    }
}
