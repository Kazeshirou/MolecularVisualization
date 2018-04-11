#ifndef BOND_H
#define BOND_H

#include "cilinder.h"

class Atom;
class Cilinder;
class BaseContext;

class Bond : public Cilinder
{
    int m_atomIndexes[2];
    Atom *m_atoms[2];
public:
    explicit Bond(int i1, int i2, Atom *a1, Atom *a2);

    int &getAtomIndex(int a) { return a ? m_atomIndexes[1] : m_atomIndexes[0]; }
    void setAtomIndex(int atomNumber, int index) { atomNumber ? m_atomIndexes[1] = index
                                 : m_atomIndexes[0] = index; }
    void setAtom(int a, Atom *atom);
    void update(int a);

    virtual void draw(BaseContext *c);
};

#endif // BOND_H
