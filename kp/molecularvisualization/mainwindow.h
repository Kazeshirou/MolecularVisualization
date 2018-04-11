#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ViewGL;
class ViewShader;
class Molecule;
class Dialog;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    ViewGL *viewGL;
    ViewShader *viewShader;
    Molecule *molecule;

    Dialog *dialog;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setMolecule();
public slots:

    void updateAll();

private slots:
    void on_OpenGL_triggered();

    void on_Shader_triggered();

    void on_Open_triggered();

    void on_bnsaction_triggered();

    void on_spasefillaction_triggered();

    void on_saveAction_triggered();

    void on_deleteAction_triggered();

    void on_editAction_triggered();

    void on_timeron_triggered();

    void on_timeroff_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
