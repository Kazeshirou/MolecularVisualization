/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "colorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_12;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_11;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpinBox *atomNumber;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *atomElement;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *atomRadii;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout;
    colorButton *atomColor;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *atomX;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *atomY;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *atomZ;
    QWidget *tab_2;
    QGroupBox *groupBox_13;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_14;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_15;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QSpinBox *bondNumber;
    QGroupBox *groupBox_16;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_5;
    QSpinBox *bondAtom1;
    QGroupBox *groupBox_17;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_6;
    QSpinBox *bondAtom2;
    QGroupBox *groupBox_18;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_19;
    QGridLayout *gridLayout_7;
    colorButton *bondColor;
    QGroupBox *groupBox_12;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_7;
    QDoubleSpinBox *bondRadii;
    QGroupBox *groupBox_20;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *okButton;
    QPushButton *deleteButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(736, 500);
        Dialog->setMinimumSize(QSize(736, 500));
        verticalLayout_12 = new QVBoxLayout(Dialog);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        gridLayout_6 = new QGridLayout(tab1);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_11 = new QGroupBox(tab1);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_4 = new QGroupBox(groupBox_11);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(groupBox_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        atomNumber = new QSpinBox(groupBox);
        atomNumber->setObjectName(QStringLiteral("atomNumber"));
        atomNumber->setEnabled(true);
        atomNumber->setMaximum(10000000);

        verticalLayout_2->addWidget(atomNumber);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(groupBox_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        atomElement = new QLineEdit(groupBox_2);
        atomElement->setObjectName(QStringLiteral("atomElement"));
        atomElement->setMaxLength(5);

        verticalLayout->addWidget(atomElement);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox_4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        atomRadii = new QDoubleSpinBox(groupBox_3);
        atomRadii->setObjectName(QStringLiteral("atomRadii"));
        atomRadii->setDecimals(3);
        atomRadii->setMinimum(0.01);
        atomRadii->setSingleStep(0.1);
        atomRadii->setValue(1);

        verticalLayout_3->addWidget(atomRadii);


        verticalLayout_4->addWidget(groupBox_3);


        horizontalLayout_2->addWidget(groupBox_4);

        groupBox_10 = new QGroupBox(groupBox_11);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        verticalLayout_6 = new QVBoxLayout(groupBox_10);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox_5 = new QGroupBox(groupBox_10);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout = new QGridLayout(groupBox_5);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        atomColor = new colorButton(groupBox_5);
        atomColor->setObjectName(QStringLiteral("atomColor"));

        gridLayout->addWidget(atomColor, 0, 1, 1, 1);


        verticalLayout_6->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(groupBox_10);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        horizontalLayout = new QHBoxLayout(groupBox_6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_7 = new QGroupBox(groupBox_6);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_2 = new QGridLayout(groupBox_7);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        atomX = new QDoubleSpinBox(groupBox_7);
        atomX->setObjectName(QStringLiteral("atomX"));
        atomX->setDecimals(3);
        atomX->setMinimum(-1e+9);
        atomX->setMaximum(1e+9);

        gridLayout_2->addWidget(atomX, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_7);

        groupBox_8 = new QGroupBox(groupBox_6);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        gridLayout_4 = new QGridLayout(groupBox_8);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        atomY = new QDoubleSpinBox(groupBox_8);
        atomY->setObjectName(QStringLiteral("atomY"));
        atomY->setDecimals(3);
        atomY->setMinimum(-1e+8);
        atomY->setMaximum(1e+8);

        gridLayout_4->addWidget(atomY, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_8);

        groupBox_9 = new QGroupBox(groupBox_6);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        gridLayout_3 = new QGridLayout(groupBox_9);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        atomZ = new QDoubleSpinBox(groupBox_9);
        atomZ->setObjectName(QStringLiteral("atomZ"));
        atomZ->setMinimumSize(QSize(0, 0));
        atomZ->setDecimals(3);
        atomZ->setMinimum(-1e+7);
        atomZ->setMaximum(1e+12);

        gridLayout_3->addWidget(atomZ, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_9);


        verticalLayout_6->addWidget(groupBox_6);


        horizontalLayout_2->addWidget(groupBox_10);


        gridLayout_6->addWidget(groupBox_11, 0, 0, 1, 1);

        tabWidget->addTab(tab1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_13 = new QGroupBox(tab_2);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        groupBox_13->setGeometry(QRect(0, 0, 554, 269));
        horizontalLayout_3 = new QHBoxLayout(groupBox_13);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_14 = new QGroupBox(groupBox_13);
        groupBox_14->setObjectName(QStringLiteral("groupBox_14"));
        verticalLayout_5 = new QVBoxLayout(groupBox_14);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_15 = new QGroupBox(groupBox_14);
        groupBox_15->setObjectName(QStringLiteral("groupBox_15"));
        verticalLayout_7 = new QVBoxLayout(groupBox_15);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_4 = new QLabel(groupBox_15);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_7->addWidget(label_4);

        bondNumber = new QSpinBox(groupBox_15);
        bondNumber->setObjectName(QStringLiteral("bondNumber"));
        bondNumber->setEnabled(true);
        bondNumber->setMaximum(1000000000);

        verticalLayout_7->addWidget(bondNumber);


        verticalLayout_5->addWidget(groupBox_15);

        groupBox_16 = new QGroupBox(groupBox_14);
        groupBox_16->setObjectName(QStringLiteral("groupBox_16"));
        verticalLayout_8 = new QVBoxLayout(groupBox_16);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_5 = new QLabel(groupBox_16);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_8->addWidget(label_5);

        bondAtom1 = new QSpinBox(groupBox_16);
        bondAtom1->setObjectName(QStringLiteral("bondAtom1"));
        bondAtom1->setMaximum(1000000000);

        verticalLayout_8->addWidget(bondAtom1);


        verticalLayout_5->addWidget(groupBox_16);

        groupBox_17 = new QGroupBox(groupBox_14);
        groupBox_17->setObjectName(QStringLiteral("groupBox_17"));
        verticalLayout_9 = new QVBoxLayout(groupBox_17);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_6 = new QLabel(groupBox_17);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_9->addWidget(label_6);

        bondAtom2 = new QSpinBox(groupBox_17);
        bondAtom2->setObjectName(QStringLiteral("bondAtom2"));
        bondAtom2->setMaximum(1000000000);

        verticalLayout_9->addWidget(bondAtom2);


        verticalLayout_5->addWidget(groupBox_17);


        horizontalLayout_3->addWidget(groupBox_14);

        groupBox_18 = new QGroupBox(groupBox_13);
        groupBox_18->setObjectName(QStringLiteral("groupBox_18"));
        verticalLayout_10 = new QVBoxLayout(groupBox_18);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        groupBox_19 = new QGroupBox(groupBox_18);
        groupBox_19->setObjectName(QStringLiteral("groupBox_19"));
        gridLayout_7 = new QGridLayout(groupBox_19);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        bondColor = new colorButton(groupBox_19);
        bondColor->setObjectName(QStringLiteral("bondColor"));

        gridLayout_7->addWidget(bondColor, 0, 1, 1, 1);

        groupBox_12 = new QGroupBox(groupBox_19);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        verticalLayout_11 = new QVBoxLayout(groupBox_12);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_7 = new QLabel(groupBox_12);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_11->addWidget(label_7);

        bondRadii = new QDoubleSpinBox(groupBox_12);
        bondRadii->setObjectName(QStringLiteral("bondRadii"));
        bondRadii->setDecimals(3);
        bondRadii->setSingleStep(0.1);
        bondRadii->setValue(0.1);

        verticalLayout_11->addWidget(bondRadii);


        gridLayout_7->addWidget(groupBox_12, 1, 1, 1, 1);


        verticalLayout_10->addWidget(groupBox_19);


        horizontalLayout_3->addWidget(groupBox_18);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_12->addWidget(tabWidget);

        groupBox_20 = new QGroupBox(Dialog);
        groupBox_20->setObjectName(QStringLiteral("groupBox_20"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_20);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        okButton = new QPushButton(groupBox_20);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout_4->addWidget(okButton);

        deleteButton = new QPushButton(groupBox_20);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout_4->addWidget(deleteButton);


        verticalLayout_12->addWidget(groupBox_20);


        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", " \320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        groupBox_11->setTitle(QString());
        groupBox_4->setTitle(QString());
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Dialog", "\320\235\320\276\320\274\320\265\321\200 \320\260\321\202\320\276\320\274\320\260:", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_2->setText(QApplication::translate("Dialog", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202:", Q_NULLPTR));
        atomElement->setInputMask(QString());
        groupBox_3->setTitle(QString());
        label_3->setText(QApplication::translate("Dialog", "\320\240\320\260\320\264\320\270\321\203\321\201:", Q_NULLPTR));
        groupBox_10->setTitle(QString());
        groupBox_5->setTitle(QApplication::translate("Dialog", "\320\246\320\262\320\265\321\202:", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("Dialog", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265:", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("Dialog", "X", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("Dialog", "Y", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("Dialog", "Z", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("Dialog", "\320\220\321\202\320\276\320\274", Q_NULLPTR));
        groupBox_13->setTitle(QString());
        groupBox_14->setTitle(QString());
        groupBox_15->setTitle(QString());
        label_4->setText(QApplication::translate("Dialog", "\320\235\320\276\320\274\320\265\321\200 \320\272\320\276\320\262\320\260\320\273\320\265\320\275\321\202\320\275\320\276\320\271 \321\201\320\262\321\217\320\267\320\270:", Q_NULLPTR));
        groupBox_16->setTitle(QString());
        label_5->setText(QApplication::translate("Dialog", "\320\220\321\202\320\276\320\2741:", Q_NULLPTR));
        groupBox_17->setTitle(QString());
        label_6->setText(QApplication::translate("Dialog", "\320\220\321\202\320\276\320\2742:", Q_NULLPTR));
        groupBox_18->setTitle(QString());
        groupBox_19->setTitle(QApplication::translate("Dialog", "\320\246\320\262\320\265\321\202:", Q_NULLPTR));
        groupBox_12->setTitle(QString());
        label_7->setText(QApplication::translate("Dialog", "\320\240\320\260\320\264\320\270\321\203\321\201", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog", "\320\232\320\276\320\262\320\260\320\273\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\320\262\321\217\320\267\321\214", Q_NULLPTR));
        groupBox_20->setTitle(QString());
        okButton->setText(QApplication::translate("Dialog", "\320\236\320\272", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("Dialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
