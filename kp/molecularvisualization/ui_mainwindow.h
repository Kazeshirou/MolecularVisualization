/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "view.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Open;
    QAction *bnsaction;
    QAction *spasefillaction;
    QAction *timeron;
    QAction *timeroff;
    QAction *editAction;
    QAction *createAction;
    QAction *deleteAction;
    QAction *saveAction;
    QAction *editBondAction;
    QAction *createBondAction;
    QAction *deleteBondAction;
    QAction *OpenGL;
    QAction *Shader;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    View *view;
    QMenuBar *menuBar;
    QMenu *File;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *Edit;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 800));
        MainWindow->setMaximumSize(QSize(800, 800));
        Open = new QAction(MainWindow);
        Open->setObjectName(QStringLiteral("Open"));
        bnsaction = new QAction(MainWindow);
        bnsaction->setObjectName(QStringLiteral("bnsaction"));
        spasefillaction = new QAction(MainWindow);
        spasefillaction->setObjectName(QStringLiteral("spasefillaction"));
        timeron = new QAction(MainWindow);
        timeron->setObjectName(QStringLiteral("timeron"));
        timeroff = new QAction(MainWindow);
        timeroff->setObjectName(QStringLiteral("timeroff"));
        editAction = new QAction(MainWindow);
        editAction->setObjectName(QStringLiteral("editAction"));
        createAction = new QAction(MainWindow);
        createAction->setObjectName(QStringLiteral("createAction"));
        deleteAction = new QAction(MainWindow);
        deleteAction->setObjectName(QStringLiteral("deleteAction"));
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QStringLiteral("saveAction"));
        editBondAction = new QAction(MainWindow);
        editBondAction->setObjectName(QStringLiteral("editBondAction"));
        createBondAction = new QAction(MainWindow);
        createBondAction->setObjectName(QStringLiteral("createBondAction"));
        deleteBondAction = new QAction(MainWindow);
        deleteBondAction->setObjectName(QStringLiteral("deleteBondAction"));
        OpenGL = new QAction(MainWindow);
        OpenGL->setObjectName(QStringLiteral("OpenGL"));
        Shader = new QAction(MainWindow);
        Shader->setObjectName(QStringLiteral("Shader"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        view = new View(centralWidget);
        view->setObjectName(QStringLiteral("view"));

        gridLayout->addWidget(view, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        File = new QMenu(menuBar);
        File->setObjectName(QStringLiteral("File"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        Edit = new QMenu(menuBar);
        Edit->setObjectName(QStringLiteral("Edit"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(File->menuAction());
        menuBar->addAction(Edit->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        File->addAction(Open);
        File->addAction(saveAction);
        menu->addAction(bnsaction);
        menu->addAction(spasefillaction);
        menu_2->addAction(timeron);
        menu_2->addAction(timeroff);
        Edit->addAction(editAction);
        Edit->addAction(deleteAction);
        menu_3->addAction(OpenGL);
        menu_3->addAction(Shader);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \320\274\320\276\320\273\320\265\320\272\321\203\320\273", Q_NULLPTR));
        Open->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        Open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        bnsaction->setText(QApplication::translate("MainWindow", "\320\250\320\260\321\200\320\276-\321\201\321\202\320\265\321\200\320\266\320\275\320\265\320\262\320\276\320\265", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        bnsaction->setToolTip(QApplication::translate("MainWindow", "\320\250\320\260\321\200\320\276-\321\201\321\202\320\265\321\200\320\266\320\275\320\265\320\262\320\276\320\265", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        bnsaction->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        spasefillaction->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\321\217\321\216\321\211\320\265\320\265 \320\277\321\200\320\276\321\201\321\202\321\200\320\260\320\275\321\201\321\202\320\262\320\276", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        spasefillaction->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        timeron->setText(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        timeron->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        timeroff->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\272\320\273\321\216\321\207\320\270\321\202\321\214", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        timeroff->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        editAction->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        createAction->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", Q_NULLPTR));
        deleteAction->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        saveAction->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        saveAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        editBondAction->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\272\320\276\320\262\320\260\320\273\320\265\320\275\321\202\320\275\321\203\321\216 \321\201\320\262\321\217\320\267\321\214", Q_NULLPTR));
        createBondAction->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\276\320\262\320\260\320\273\320\265\320\275\321\202\320\275\321\203\321\216 \321\201\320\262\321\217\320\267\321\214", Q_NULLPTR));
        deleteBondAction->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\276\320\262\320\260\320\273\320\265\320\275\321\202\320\275\321\203\321\216 \321\201\320\262\321\217\320\267\321\214", Q_NULLPTR));
        OpenGL->setText(QApplication::translate("MainWindow", "C OpenGL", Q_NULLPTR));
        Shader->setText(QApplication::translate("MainWindow", "C OpenGL \320\270 \321\210\320\265\320\271\320\264\320\265\321\200\320\276\320\274 \321\201\321\204\320\265\321\200", Q_NULLPTR));
        File->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\220\320\275\320\270\320\274\320\260\321\206\320\270\321\217", Q_NULLPTR));
        Edit->setTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\236\320\272\320\275\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
