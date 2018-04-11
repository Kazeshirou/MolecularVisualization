#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "myview.h"

class mainWindow : public QMainWindow
{
    Q_OBJECT
    myView *view;

    void initScene();
public:
    explicit mainWindow(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MAINWINDOW_H
