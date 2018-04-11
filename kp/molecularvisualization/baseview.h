#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QBasicTimer>

#include "camera.h"
#include "molecule.h"


class Molecule;

class BaseView : public QOpenGLWidget
{
    Q_OBJECT

    double m_angle;
protected:
    static bool m_animation;
    QVector2D m_mousePosition;
    Camera *m_camera;
    QVector<Transformational *> m_objects;
    QBasicTimer m_timer;

public:
    BaseView(QWidget *parent = nullptr);
    virtual ~BaseView() { delete m_camera; }
    virtual void setMolecule(Molecule *m);

    void timerEvent(QTimerEvent *e)
    {
        if (!m_animation)
            return;
        Q_UNUSED(e);
        m_angle += M_PI / 360.0;
        m_camera->rotate(QQuaternion::fromAxisAndAngle(0, 1, 0, m_angle));

        update();
    }

    void mousePressEvent(QMouseEvent *e)
    {
        if (e->buttons() == Qt::LeftButton)
            m_mousePosition = QVector2D(e->localPos());
        e->accept();
    }
    void mouseMoveEvent(QMouseEvent *e)
    {
        if (e->buttons() != Qt::LeftButton) return;

        QVector2D diff = QVector2D(e->localPos()) - m_mousePosition;
        m_mousePosition = QVector2D(e->localPos());

        float angle = diff.length() / 2.0; // коэффициент можно менять
        QVector3D axis = QVector3D(diff.y(), diff.x(), 0.0); // вектор перпендикулярно движению мыши, минус не нужен, тк в OpenGL и QT оси у направлены в разные стороны
        m_camera->rotate(QQuaternion::fromAxisAndAngle(axis,angle));
        update();
    }
    void wheelEvent(QWheelEvent *e)
    {
        if (e->delta() > 0){
            if (m_camera->getTranslate().z() < -20)
                m_camera->translate(QVector3D(0.0,0.0,1));
        }
        else if (e->delta() < 0 )
            m_camera->translate(QVector3D(0.0,0.0,-1));
        update();
    }

    static void setAnimation(bool f) { m_animation = f; }

public slots:
    void changed() { update(); }
};

#endif // BASEVIEW_H
