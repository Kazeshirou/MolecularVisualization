#include "sphere.h"
#include "context.h"
#include "contextgl.h"
#include "contextshader.h"

#include <QFile>
#include <QTextStream>

QVector<VertexData> Sphere::vertexes;
QVector<GLuint> Sphere::indexes;
QOpenGLBuffer Sphere::m_vertexBuffer;
QOpenGLBuffer Sphere::m_indexBuffer = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);


Sphere::Sphere(const float radii, const QColor color, const QVector3D position) :
    m_radii(radii),
    m_color(color),
    m_position(position),
    m_scale(1.,1.,1.)
{
    m_globalTransform.setToIdentity();
}

void Sphere::rotate(const QQuaternion &r)
{
    Q_UNUSED(r);
    return;
}

void Sphere::translate(const QVector3D &t)
{
    m_position += t;
}

void Sphere::scale(const QVector3D &s)
{
    m_scale *= s;
}

void Sphere::setGlobalTransform(const QMatrix4x4 &g)
{
    m_globalTransform = g;
}

void Sphere::draw(BaseContext *c)
{
    BaseContext::Type t = c->getType();
    if (t == BaseContext::NoOpenGL)
        drawNoOpenGL(c);
    else if (t == BaseContext::OpenGl)
        drawOpenGl(c);
    else
        drawShader(c);

}

void Sphere::drawNoOpenGL(BaseContext *c)
{
    Context *context = dynamic_cast<Context *>(c);
    QMatrix4x4 viewMatrix = context->getViewMatrix();
    QMatrix4x4 projectionMatrix = context->getProjectionMatrix();
    QMatrix4x4 modelMatrix;
    modelMatrix.setToIdentity(); // 2 поворот
    modelMatrix.translate(m_position);
    modelMatrix.scale(m_scale); // 1 масштаб
    float r = m_radii*modelMatrix(0,0)*projectionMatrix(0,0);
    modelMatrix = projectionMatrix*viewMatrix*m_globalTransform * modelMatrix;
    QVector4D cent = modelMatrix*QVector4D(0,0,0,1);
    r = r/cent.w()*context->getViewPortMatrix()(0,0);
    if (context->getMode() == BaseContext::BnS)
        r *= 0.3;
    QVector4D center(cent.x()/cent.w(),cent.y()/cent.w(),cent.z()/cent.w(),1);
    center = context->getViewPortMatrix()*center;
    float z = cent.w();
    float r2 = r*r;
    if (r <= 0)
        return;
    int x = 0;
    int y = r;
    int deltai = 2*(1-r);
    while(y>=0){
        int yt1 = y+center.y();
        int yt2 = -y+center.y();
        int tx = x;
        for (int t = -x+center.x(), t1 = x+center.x(); t <= center.x(); t++,t1--){
            float tz = sqrt(r2-tx*tx-y*y);
            QVector3D n(-tx,y,tz);
            n.normalize();
            float z1 = z-tz*m_radii/r;
            context->setPixel(t1, yt1, z1, m_color, n);
            n[0] *= -1;
            context->setPixel(t, yt1, z1, m_color, n);
            n[1] *= -1;
            context->setPixel(t, yt2, z1, m_color,n);
            n[0] *= -1;
            context->setPixel(t1, yt2, z1, m_color,n);
            tx--;
        }
        if (deltai < 0 && (2*(deltai+y)-1 <= 0)){
            x++;
            deltai +=2*x+1;

        }
        else if (deltai > 0 && (2*(deltai-x)-1 >= 0)){
            y--;
            deltai += 1-2*y;
        }
        else{
            x++;
            y--;
            deltai += 2*(x-y+1);
        }
    }
}

void Sphere::drawOpenGl(BaseContext *c)
{
    if (!vertexes.size())
        loadFromObj();
    if (!m_vertexBuffer.isCreated() || !m_indexBuffer.isCreated())
        return;
    QMatrix4x4 modelMatrix;
    modelMatrix.setToIdentity();
    modelMatrix.translate(m_position);
    if (c->getMode() == BaseContext::BnS)
        modelMatrix.scale(m_scale*0.3*QVector3D(m_radii,m_radii,m_radii));
    else
        modelMatrix.scale(m_scale*QVector3D(m_radii,m_radii,m_radii));// 1 масштаб
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

void Sphere::drawShader(BaseContext *c)
{
    QMatrix4x4 modelMatrix;
    modelMatrix.setToIdentity();
    modelMatrix.scale(m_scale); // 1 масштаб
    modelMatrix = m_globalTransform * modelMatrix;
    ContextShader *context = dynamic_cast<ContextShader *>(c);
    QOpenGLShaderProgram *program = context->getProgram();
    program->setUniformValue("u_modelMatrix", modelMatrix);
    QOpenGLFunctions *functions = context->getFunctions();

    int vertLock = program->attributeLocation("a_position");
    program->setAttributeValue(vertLock,m_position);
    int colLock = program->attributeLocation("a_color");
    program->setAttributeValue(colLock, m_color);
    int radiiLock = program->attributeLocation("a_radii");
    program->setAttributeValue(radiiLock, m_radii);
    GLuint index[1];
    index[0] = 0;
    functions->glDrawElements(GL_POINTS, 1, GL_UNSIGNED_INT,index);
}

void Sphere::loadFromObj()
{
    QFile objFile(":/obj/sphere.obj");
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
    qDebug() << "Количество треугольников аппроксимирующих сферу: " << indexes.size()/3;
}

void Sphere::init(const QVector<VertexData> &vertData, const QVector<GLuint> &indexes)
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
