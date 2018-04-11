#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "viewgl.h"
#include "viewshader.h"
#include "molecule.h"
#include "basecontext.h"
#include "dialog.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    viewGL(new ViewGL()),
    viewShader(new ViewShader),
    molecule(new Molecule),
    dialog(new Dialog),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMolecule();

    connect(dialog, SIGNAL(moleculeChange()), this, SLOT(updateAll()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete viewGL;
    delete viewShader;
    delete molecule;
    delete dialog;
}

void MainWindow::updateAll()
{
    ui->view->update();
    viewGL->update();
    viewShader->update();
}

void MainWindow::on_OpenGL_triggered()
{
    viewGL->show();
}

void MainWindow::on_Shader_triggered()
{
    viewShader->show();
}

void MainWindow::setMolecule()
{
    ui->view->setMolecule(molecule);
    viewGL->setMolecule(molecule);
    viewShader->setMolecule(molecule);
}

void MainWindow::on_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(0,"Выберите файл","","*.pdb");
    if (!fileName.length())
        return;
    if (molecule)
        delete molecule;
    molecule = new Molecule(fileName);
    setMolecule();
}

void MainWindow::on_bnsaction_triggered()
{
    BaseContext::setMode(BaseContext::BnS);
    updateAll();
}

void MainWindow::on_spasefillaction_triggered()
{
    BaseContext::setMode(BaseContext::SPACEFILL);
    updateAll();
}

void MainWindow::on_saveAction_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(0,"Выберите имя файла","","*.jpeg,*.png");
    if (!fileName.size())
        return;
    int k;
    if ((k = fileName.indexOf(".png")) != -1){
        ui->view->getImage().save(fileName,"PNG",100);
        viewGL->grabFramebuffer().save("withOpenGL.png","PNG",100);
        viewShader->grabFramebuffer().save("withShader.png","PNG",100);
    }
    else if (fileName.indexOf(".jpeg") != -1){
        ui->view->grabFramebuffer().save(fileName,"JPEG",100);
        viewGL->grabFramebuffer().save("withOpenGL.jpeg","JPEG",100);
        viewShader->grabFramebuffer().save("withShader.jpeg","JPEG",100);
    }

}

void MainWindow::on_deleteAction_triggered()
{
    if (molecule)
        delete molecule;
    molecule = new Molecule();
    setMolecule();
}

void MainWindow::on_editAction_triggered()
{
    if (molecule) {
        dialog->setMolecule(molecule);
        dialog->show();
    }
}

void MainWindow::on_timeron_triggered()
{
    BaseView::setAnimation(true);
}

void MainWindow::on_timeroff_triggered()
{
    BaseView::setAnimation(false);
}
