#ifndef MOLECULE_H
#define MOLECULE_H

#include "transformational.h"

#include <QString>
#include <QVector>
#include <QQuaternion>
#include <QVector3D>
#include <QMatrix4x4>

class Atom;
class Bond;

class Molecule : public Transformational
{
    QVector<Atom *> atoms;
    QVector<Bond *> bonds;
    QVector3D m_position;
    QVector3D m_scale;
    QVector3D m_translate;
    QQuaternion m_rotate;
    QMatrix4x4 m_globalTransform;

public:
    explicit Molecule();
    explicit Molecule(const QString filename);
    ~Molecule();

    void rotate(const QQuaternion &r);
    void translate(const QVector3D &t);
    void scale(const QVector3D &s);
    void setGlobalTransform(const QMatrix4x4 &g);
    void draw(BaseContext *c);

    void loadFromFile(const QString filename);
    int getAtomNumber() const { return atoms.size(); }
    int getBondNmber() const { return bonds.size(); }

    Atom *getAtom(int i) { return atoms[i]; }
    Bond *getBond(int i) { return bonds[i]; }
    void addAtom(Atom *a) { atoms.append(a); }
    void addBond(Bond *b) { bonds.append(b); }
    void deleteAtom(int i) { atoms.remove(i); }
    void deleteBond(int i) { bonds.remove(i); }
private:
    void findBonds();
};

#endif // MOLECULE_H
