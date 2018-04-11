#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class Molecule;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

    Molecule *m_molecule;

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void setMolecule(Molecule *m);

signals:
    void moleculeChange();

private slots:
    void on_atomNumber_valueChanged(int arg1);

    void on_bondNumber_valueChanged(int arg1);

    void on_okButton_clicked();

    void on_deleteButton_clicked();

    void on_atomElement_textChanged(const QString &arg1);

    void on_atomRadii_valueChanged(double arg1);

    void on_atomX_valueChanged(double arg1);

    void on_atomY_valueChanged(double arg1);

    void on_atomZ_valueChanged(double arg1);

    void atomColorChanged(QColor arg1);

    void bondColorChanged(QColor arg1);

    void on_bondAtom1_valueChanged(int arg1);

    void on_bondAtom2_valueChanged(int arg1);

    void on_bondRadii_valueChanged(double arg1);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
