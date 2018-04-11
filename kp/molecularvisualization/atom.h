#ifndef ATOM_H
#define ATOM_H

#include <QString>
#include <QVector3D>
#include <QMap>
#include <QColor>

#include "sphere.h"

#define MAX_COVALENT_RADIUS 1.688f

class Atom : public Sphere
{
    QString m_elem;
public:
    explicit Atom(const QString &elem, const QVector3D &position);
    explicit Atom(const QString &elem);

    static QColor getColor(QString elem);
    static float getRadii(QString elem);
    QColor getColor() const { return m_color; }
    float getRadii() const { return m_radii; }
    QString getElement() { return m_elem; }
    void setElement(QString elem) { m_elem = elem; }
};

#endif // ATOM_H
