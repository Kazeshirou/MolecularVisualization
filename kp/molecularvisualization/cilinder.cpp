#include "cilinder.h"
#include "context.h"
#include "contextgl.h"

#include <QFile>
#include <QTextStream>

float Cilinder::m_radii = 0.2f;
QColor Cilinder::m_color = QColor(255,255,255);
QVector<VertexData> Cilinder::vertexes;
QVector<GLuint> Cilinder::indexes;
QOpenGLBuffer Cilinder::m_vertexBuffer;
QOpenGLBuffer Cilinder::m_indexBuffer = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);


Cilinder::Cilinder(const QVector3D pos, const QVector3D pos1) :
    m_position(pos),
    m_position1(pos1),
    m_scale(1,1,1)
{

    m_globalTransform.setToIdentity();
}

void Cilinder::rotate(const QQuaternion &r)
{
    m_rotate = r * m_rotate;
}

void Cilinder::translate(const QVector3D &t)
{
    m_position += t;
    m_position1 += t;
}

void Cilinder::scale(const QVector3D &s)
{
    m_scale *= s;
}

void Cilinder::setGlobalTransform(const QMatrix4x4 &g)
{
    m_globalTransform = g;
}

void Cilinder::draw(BaseContext *c)
{
    if (c->getMode() == BaseContext::SPACEFILL)
        return;
    BaseContext::Type t = c->getType();
    if (t == BaseContext::NoOpenGL)
        drawNoOpenGL(c);
    else if (t == BaseContext::OpenGl)
        drawOpenGl(c);
}

int Cilinder::sign(float x)
{
    return x ? (x > 0 ? 1 : -1) : 0;
}

void Cilinder::drawNoOpenGL(BaseContext *c)
{
    Context *context = dynamic_cast<Context *>(c);
    QMatrix4x4 viewMatrix = context->getViewMatrix();
    QMatrix4x4 projectionMatrix = context->getProjectionMatrix();
    QMatrix4x4 modelMatrix;
    modelMatrix.setToIdentity(); // 2 поворот
    modelMatrix.scale(m_scale); // 1 масштаб
    float r = m_radii*modelMatrix(0,0)*projectionMatrix(0,0);
    modelMatrix = projectionMatrix*viewMatrix*m_globalTransform * modelMatrix;
    QVector4D p2 = modelMatrix*QVector4D(m_position,1.f);
    QVector4D p1 = modelMatrix*QVector4D(m_position1,1.f);
    double z = p1.w(),dz = p2.w()-z;
    r = r/p2.w()*context->getViewPortMatrix()(0,0);
    p2 = QVector4D(p2.x()/p2.w(),p2.y()/p2.w(),p2.z()/p2.w(),1);
    p1 = QVector4D(p1.x()/p1.w(),p1.y()/p1.w(),p1.z()/p1.w(),1);
    p2 = context->getViewPortMatrix()*p2;
    p1 = context->getViewPortMatrix()*p1;
    double r2 = r*r;
    int x = p1[0]+0.5, x1 = p2[0]+0.5, y = p1[1]+0.5, y1 = p2[1]+0.5;

    if ((x == x1) && (y == y1))
        return;

    double dx0 = x1-x;
    double dy0 = y1-y;
    x1 = x;
    y1 = y;
    double l = dx0*dx0+dy0*dy0;
    double dx = -dy0;
    double dy = dx0;
    int sx = sign(dx);
    int sy = sign(dy);
    dx = sqrt(dx*dx/l*r2);//std::abs(dx);
    dy = sqrt(dy*dy/l*r2);//std::abs(dy);
    bool f;
    if (dx > dy)
        f = false;
    else{
        f = true;
        double t = dx;
        dx = dy;
        dy = t;
    }

    double m = 2*dy;
    double e = m-dx;
    QVector<QVector3D> points;
    QVector<QVector3D> colors;
    int ty = 0, tx = 0;
    for (int i = 0; i < dx+1; i++){
        double dz = sqrt(r2-tx*tx-ty*ty);
        QVector3D n(-tx,-ty,dz);
        dz = dz*m_radii/r;
        points.push_back(QVector3D(x,y,z-dz));
        points.push_back(QVector3D(x1,y1,z-dz));
        n.normalize();
        colors.push_back(n);
        n[0] *= -1;
        n[1] *= -1;
        colors.push_back(n);
        if (e > 0){
            if (!f){
                double tx1 = tx+1;
                dz = sqrt(r2-tx1*tx1-ty*ty);
                QVector3D n(-tx1,-ty,dz);
                dz = dz*m_radii/r;
                points.push_back(QVector3D(x+sx,y,z-dz));
                points.push_back(QVector3D(x1-sx,y1,z-dz));
                n.normalize();
                colors.push_back(n);
                n[0] *= -1;
                n[1] *= -1;
                colors.push_back(n);
                y += sy;
                y1 -= sy;
                ty++;
            }
            else{
                double ty1 = ty+1;
                dz = sqrt(r2-tx*tx-ty1*ty1);
                QVector3D n(-tx,-ty1-1,dz);
                dz = dz*m_radii/r;
                points.push_back(QVector3D(x,y+sy,z-dz));
                points.push_back(QVector3D(x1,y1-sy,z-dz));
                n.normalize();
                colors.push_back(n);
                n[0] *= -1;
                n[1] *= -1;
                colors.push_back(n);
                x += sx;
                x1 -= sx;
                tx++;
            }
            e -= 2*dx;
        }
        if (!f){
            x += sx;
            x1 -= sx;
            tx++;
        }
        else{
            y += sy;
            y1 -= sy;
            ty++;
        }
        e += m;
    }


    dx = dx0;
    dy = dy0;
    sx = sign(dx);
    sy = sign(dy);
    dx *= sx;
    dy *= sy;
    if (dx > dy)
        f = false;
    else{
        f = true;
        int t = dx;
        dx = dy;
        dy = t;
    }
    m = 2*dy;
    e = m-dx;
    tx = 0;
    dz /= dx;

    for (int i = 0; i < dx+1; i++){
        y = 0;
        x = 0;
        if (e > 0){
            if (!f)
                y = sy;
            else
                x = sx;
            e -= 2*dx;
        }
        if (!f)
            x = sx;
        else
            y = sy;
        e += m;
        for (int j = 0; j < points.size(); j++){
            context->setPixel(points[j].x()+0.5,points[j].y()+0.5, points[j].z(),m_color,colors[j]);
            points[j][0] += x;
            points[j][1] += y;
            points[j][2] += dz;
        }
    }
}

void Cilinder::drawOpenGl(BaseContext *c)
{
    if (!vertexes.size())
        loadFromObj();
    if (!m_vertexBuffer.isCreated() || !m_indexBuffer.isCreated())
        return;
    QVector3D t = m_position1 - m_position;
    QVector3D p = t.normalized();
    p = (p + QVector3D(0, 1, 0))*0.5;
    QMatrix4x4 modelMatrix;
    modelMatrix.setToIdentity();
    modelMatrix.translate(m_position + t*0.5);
    modelMatrix.rotate(m_rotate*QQuaternion::fromAxisAndAngle(p,180));
    modelMatrix.scale(m_scale*QVector3D(m_radii, t.length(), m_radii));// 1 масштаб
    modelMatrix = m_globalTransform * modelMatrix;
    ContextGL *context = dynamic_cast<ContextGL *>(c);
    QOpenGLShaderProgram *program = context->getProgram();
    program->setUniformValue("u_modelMatrix", modelMatrix);

    m_vertexBuffer.bind();
    m_indexBuffer.bind();
    int offset = 0;

    //задаём атрибуты шейдера
    int colLock = program->attributeLocation("a_color");
    program->setAttributeValue(colLock, m_color);
    int vertLock = program->attributeLocation("a_position");
    program->enableAttributeArray(vertLock);
    program->setAttributeBuffer(vertLock, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);
    offset += sizeof(QVector2D);

    int normLock = program->attributeLocation("a_normal");
    program->enableAttributeArray(normLock);
    program->setAttributeBuffer(normLock, GL_FLOAT, offset, 3, sizeof(VertexData));

    context->getFunctions()->glDrawElements(GL_TRIANGLES, m_indexBuffer.size(), GL_UNSIGNED_INT,0);

    m_vertexBuffer.release();
    m_indexBuffer.release();
}

void Cilinder::loadFromObj()
{
    QFile objFile(":/obj/cilinder.obj");
    if (!objFile.exists()){
        qDebug() << "File not found";
        return;
    }
    QVector<QVector3D> coords;
    QVector<QVector2D> texCoords;
    QVector<QVector3D> normals;

    objFile.open(QIODevice::ReadOnly);
    QTextStream input(&objFile);
    while (!input.atEnd()){
        QString str = input.readLine();
        QStringList list = str.split(" ");
        if (list[0] == "#"){
            continue;
        }
        else if (list[0] == "mtllib"){
            // обработать файл с материалами
        }
        else if (list[0] == "v"){
            coords.append(QVector3D(list[1].toFloat(),list[2].toFloat(),list[3].toFloat()));
            continue;
        }
        else if (list[0] == "vt"){
            texCoords.append(QVector2D(list[1].toFloat(),list[2].toFloat()));
            continue;
        }
        else if (list[0] == "vn"){
            normals.append(QVector3D(list[1].toFloat(),list[2].toFloat(),list[3].toFloat()));
            continue;
        }
        else if (list[0] == "f"){
            for (int i = 1; i <= 3; i++){
                QStringList vert = list[i].split("/");
                vertexes.append(VertexData(coords[vert[0].toLong() - 1], (texCoords.size()?texCoords[vert[1].toLong() - 1]:QVector2D(0.0,0.0)), normals[vert[2].toLong()-1]));
                indexes.append(indexes.size());
            }
            continue;
        }
    }
    objFile.close();

    init(vertexes, indexes);    
    qDebug() << "Количество треугольников аппроксимирующих цилиндр: " << indexes.size()/3;
}

void Cilinder::init(const QVector<VertexData> &vertData, const QVector<GLuint> &indexes)
{
    if (m_vertexBuffer.isCreated())
        m_vertexBuffer.destroy();
    if (m_indexBuffer.isCreated())
        m_indexBuffer.destroy();

    m_vertexBuffer.create();
    m_vertexBuffer.bind();
    m_vertexBuffer.allocate(vertData.constData(), vertData.size() * sizeof(VertexData));
    m_vertexBuffer.release();

    m_indexBuffer.create();
    m_indexBuffer.bind();
    m_indexBuffer.allocate(indexes.constData(), indexes.size() * sizeof(GLuint));
    m_indexBuffer.release();

}
