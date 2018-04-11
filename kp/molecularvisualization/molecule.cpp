#include "molecule.h"

#include <QFile>
#include <QTextStream>

#include "atom.h"
#include "bond.h"

Molecule::Molecule() :
    m_scale(1,1,1)
{

}

Molecule::Molecule(const QString filename) :
    m_scale(1,1,1)
{
    loadFromFile(filename);
}

Molecule::~Molecule()
{
    for (int i = 0; i < atoms.size(); i++)
        delete atoms[i];
    for (int i = 0; i < bonds.size(); i++)
        delete bonds[i];
}

void Molecule::rotate(const QQuaternion &r)
{
    m_rotate = r*m_rotate;
}

void Molecule::translate(const QVector3D &t)
{
    m_translate += t;
}

void Molecule::scale(const QVector3D &s)
{
    m_scale *= s;
}

void Molecule::setGlobalTransform(const QMatrix4x4 &g)
{
    m_globalTransform = g;
}

void Molecule::draw(BaseContext *c)
{
    QMatrix4x4 modelMatrix;
    modelMatrix.translate(m_translate);
    modelMatrix.rotate(m_rotate);
    modelMatrix.scale(m_scale);
    modelMatrix = m_globalTransform * modelMatrix;

    for (int i = 0; i < atoms.size(); i++){
        atoms[i]->setGlobalTransform(modelMatrix);
        atoms[i]->draw(c);
    }
    for (int i = 0; i < bonds.size(); i++){
        bonds[i]->setGlobalTransform(modelMatrix);
        bonds[i]->draw(c);
    }
}

void Molecule::loadFromFile(const QString fileName)
{

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        //throw FileOpenException("Не удалось открыть файл!");
        return;
    }
    atoms.clear();
    bonds.clear();
    QTextStream in(&file);
    QString str;
    QVector3D center(0.,0.,0.);
    while (!in.atEnd()){
        in >> str;
        if (str == "ATOM"){
            double x,y,z;
            in >> str;
            QString elem;
            in >> elem;
            in >> str;
            in >> str;
            in >> str;
            in >> str;
            x = str.toDouble();
            in >> str;
            y = str.toDouble();
            in >> str;
            z = str.toDouble();
            QVector3D t(x,y,z);
            atoms.push_back(new Atom(elem,t));
            center += t;
        }
    }
    center /= float(atoms.size());
    for (int i = 0; i < atoms.size(); i++){
        atoms[i]->getPosition() -= center;
    }
    findBonds();

    qDebug() << "Количество считанных атомов: " << atoms.size();

    qDebug() << "Количество найденных связей: " << bonds.size();
}

bool f(Atom *a1, Atom *a2){
    return a1->getPosition().x() < a2->getPosition().x();
}

void Molecule::findBonds(){

    const float k = 0.58;
    const float MIND=0.8;
    const float MAXD=MAX_COVALENT_RADIUS*2*k;

    std::sort(atoms.begin(), atoms.end(), f);

    for (int i = 0; i < atoms.size()-1; i++){
        float px = atoms[i]->getPosition().x();
        for (int j = i + 1; j < atoms.size(); j++){
            if (atoms[j]->getPosition().x() < px-MAXD)
                break;
            else{
                float maxd = (atoms[i]->getRadii() + atoms[j]->getRadii())*k;
                float dist = (atoms[i]->getPosition() - atoms[j]->getPosition()).lengthSquared();
                if ((dist>=MIND*MIND) && (dist<=maxd*maxd))
                    bonds.push_back(new Bond(i, j, atoms[i], atoms[j]));
            }
        }
    }
}
