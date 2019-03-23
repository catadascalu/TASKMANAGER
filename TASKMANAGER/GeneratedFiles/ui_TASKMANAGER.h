/********************************************************************************
** Form generated from reading UI file 'TASKMANAGER.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TASKMANAGERClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TASKMANAGERClass)
    {
        if (TASKMANAGERClass->objectName().isEmpty())
            TASKMANAGERClass->setObjectName(QStringLiteral("TASKMANAGERClass"));
        TASKMANAGERClass->resize(600, 400);
        menuBar = new QMenuBar(TASKMANAGERClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TASKMANAGERClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TASKMANAGERClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TASKMANAGERClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TASKMANAGERClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TASKMANAGERClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TASKMANAGERClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TASKMANAGERClass->setStatusBar(statusBar);

        retranslateUi(TASKMANAGERClass);

        QMetaObject::connectSlotsByName(TASKMANAGERClass);
    } // setupUi

    void retranslateUi(QMainWindow *TASKMANAGERClass)
    {
        TASKMANAGERClass->setWindowTitle(QApplication::translate("TASKMANAGERClass", "TASKMANAGER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TASKMANAGERClass: public Ui_TASKMANAGERClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
