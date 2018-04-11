#include "dialog.h"
#include "ui_dialog.h"
#include "molecule.h"
#include "atom.h"
#include "bond.h"

Dialog::Dialog(QWidget *parent):
    QDialog(parent),
    m_molecule(nullptr),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->atomColor, SIGNAL(changedColor(QColor)), this, SLOT(atomColorChanged(QColor)));
    connect(ui->bondColor, SIGNAL(changedColor(QColor)), this, SLOT(bondColorChanged(QColor)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setMolecule(Molecule *m)
{
    m_molecule = m;
    int k = m_molecule->getAtomNumber(), k1 = m_molecule->getBondNmber();
    ui->atomNumber->setMaximum(0);
    ui->bondNumber->setMaximum(0);
/*    ui->atomNumber->setValue(--k);
    ui->bondNumber->setValue(--k1)*/;
    on_atomNumber_valueChanged(0);
    on_bondNumber_valueChanged(0);
}

void Dialog::on_atomNumber_valueChanged(int arg1)
{
    if (arg1 < m_molecule->getAtomNumber()){
        Atom *a = m_molecule->getAtom(arg1);
        ui->atomColor->setColor(a->getColor());
        ui->atomElement->setText(a->getElement());
        ui->atomRadii->setValue(a->getRadii());
        QVector3D p = a->getPosition();
        ui->atomX->setValue(p.x());
        ui->atomY->setValue(p.y());
        ui->atomZ->setValue(p.z());
    }
}

void Dialog::on_bondNumber_valueChanged(int arg1)
{
    if (arg1 < m_molecule->getBondNmber()){
        Bond *b = m_molecule->getBond(arg1);
        ui->bondColor->setColor(b->getColor());
        ui->bondRadii->setValue(b->getRadii());
        ui->bondAtom1->setValue(b->getAtomIndex(0));
        ui->bondAtom2->setValue(b->getAtomIndex(1));
    }
}

void Dialog::on_okButton_clicked()
{
    if (!ui->tabWidget->currentIndex()){
        if ((ui->atomNumber->value() == m_molecule->getAtomNumber()) && ui->atomElement->text().length()){
            Atom *a = new Atom(ui->atomElement->text(), QVector3D(ui->atomX->value(), ui->atomY->value(), ui->atomZ->value()));
            m_molecule->addAtom(a);
            a->setRadii(ui->atomRadii->value());
            a->setColor(ui->atomColor->color());
            ui->atomNumber->setMaximum(m_molecule->getAtomNumber());
        }
    }
    else{
        int k = m_molecule->getAtomNumber();
        if (ui->bondNumber->value() == m_molecule->getBondNmber()){
            int a1 = ui->bondAtom1->value(), a2 = ui->bondAtom2->value();
            if ((a1 != a2) && (a1 < k) && (a2 < k)){
                Bond *b = new Bond(a1, a2, m_molecule->getAtom(a1), m_molecule->getAtom(a2));
                m_molecule->addBond(b);
                ui->bondNumber->setMaximum(m_molecule->getBondNmber());
            }
        }
    }

    emit moleculeChange();
}

void Dialog::on_deleteButton_clicked()
{
    if (!ui->tabWidget->currentIndex()){
        int k = ui->atomNumber->value();
        if (k < m_molecule->getAtomNumber()){
            m_molecule->deleteAtom(ui->atomNumber->value());
            ui->atomNumber->setMaximum(m_molecule->getAtomNumber());
        }
        for (int i = 0; i < m_molecule->getBondNmber(); i++){
            Bond *b = m_molecule->getBond(i);
            if ((b->getAtomIndex(0) == k) || (b->getAtomIndex(1) == k))
                m_molecule->deleteBond(i--);
        }
    }
    else
        if (ui->bondNumber->value() < m_molecule->getBondNmber()){
            m_molecule->deleteBond(ui->bondNumber->value());
            ui->bondNumber->setMaximum(m_molecule->getBondNmber());
        }

    emit moleculeChange();
}

void Dialog::on_atomElement_textChanged(const QString &arg1)
{
    int i = ui->atomNumber->value();
    if (arg1.length() && (i < m_molecule->getAtomNumber())){
        Atom *a = m_molecule->getAtom(i);
        a->setElement(arg1);
    }
}

void Dialog::on_atomRadii_valueChanged(double arg1)
{
    int i = ui->atomNumber->value();
    if (i < m_molecule->getAtomNumber()){
        Atom *a = m_molecule->getAtom(i);
        a->setRadii(arg1);
    }

    emit moleculeChange();
}

void Dialog::on_atomX_valueChanged(double arg1)
{
    int i = ui->atomNumber->value();
    if (i < m_molecule->getAtomNumber()){
        Atom *a = m_molecule->getAtom(i);
        QVector3D p = a->getPosition();
        p.setX(arg1);
        a->setPosition(p);
    }

    emit moleculeChange();
}

void Dialog::on_atomY_valueChanged(double arg1)
{
    int i = ui->atomNumber->value();
    if (i < m_molecule->getAtomNumber()){
        Atom *a = m_molecule->getAtom(i);
        QVector3D p = a->getPosition();
        p.setY(arg1);
        a->setPosition(p);
    }

    emit moleculeChange();
}

void Dialog::on_atomZ_valueChanged(double arg1)
{
    int i = ui->atomNumber->value();
    if (i < m_molecule->getAtomNumber()){
        Atom *a = m_molecule->getAtom(i);
        QVector3D p = a->getPosition();
        p.setZ(arg1);
        a->setPosition(p);
    }

    emit moleculeChange();
}

void Dialog::atomColorChanged(QColor arg1)
{
    int i = ui->atomNumber->value();
    if (i < m_molecule->getAtomNumber()){
        Atom *a = m_molecule->getAtom(i);
        a->setColor(arg1);
    }

    emit moleculeChange();
}

void Dialog::bondColorChanged(QColor arg1)
{
    int i = ui->bondNumber->value();
    if (i < m_molecule->getBondNmber()){
        Bond::setColor(arg1);
    }

    emit moleculeChange();
}

void Dialog::on_bondAtom1_valueChanged(int arg1)
{
    int i = ui->bondNumber->value();
    if (i < m_molecule->getBondNmber()){
        if (arg1 < m_molecule->getAtomNumber()){
            Bond *b = m_molecule->getBond(i);
            b->setAtomIndex(0, arg1);
            b->setAtom(0, m_molecule->getAtom(arg1));
        }
    }

    emit moleculeChange();
}

void Dialog::on_bondAtom2_valueChanged(int arg1)
{
    int i = ui->bondNumber->value();
    if (i < m_molecule->getBondNmber()){
        if (arg1 < m_molecule->getAtomNumber()){
            Bond *b = m_molecule->getBond(i);
            b->setAtomIndex(1, arg1);
            b->setAtom(1, m_molecule->getAtom(arg1));
        }

    }

    emit moleculeChange();
}

void Dialog::on_bondRadii_valueChanged(double arg1)
{
    int i = ui->bondNumber->value();
    if (i < m_molecule->getBondNmber()){
        Bond::setRadii(arg1);
    }

    emit moleculeChange();
}
