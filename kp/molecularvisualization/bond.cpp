#include "bond.h"
#include "atom.h"

Bond::Bond(int i1, int i2, Atom *a1, Atom *a2) :
    Cilinder(a1->getPosition(), a2->getPosition())
{
    m_atomIndexes[0] = i1;
    m_atomIndexes[1] = i2;
    m_atoms[0] = a1;
    m_atoms[1] = a2;
}

void Bond::setAtom(int a, Atom *atom)
{
    if (a){
        m_atoms[1] = atom;
        m_position1 = atom->getPosition();
    }
    else{
        m_atoms[0] = atom;
        m_position = atom->getPosition();
    }
}

void Bond::draw(BaseContext *c)
{
    m_position = m_atoms[0]->getPosition();
    m_position1 = m_atoms[1]->getPosition();
    Cilinder::draw(c);
}


