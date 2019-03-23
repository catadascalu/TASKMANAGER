/********************************************************************************
** Form generated from reading UI file 'View.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QTableView *taskTableModel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *dBox;
    QLineEdit *sBox;
    QLineEdit *iBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addB;
    QPushButton *removeB;
    QPushButton *startB;
    QPushButton *endB;

    void setupUi(QWidget *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QStringLiteral("View"));
        View->resize(400, 300);
        verticalLayout_5 = new QVBoxLayout(View);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        taskTableModel = new QTableView(View);
        taskTableModel->setObjectName(QStringLiteral("taskTableModel"));

        verticalLayout_4->addWidget(taskTableModel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(View);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(View);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(View);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        dBox = new QLineEdit(View);
        dBox->setObjectName(QStringLiteral("dBox"));

        verticalLayout->addWidget(dBox);

        sBox = new QLineEdit(View);
        sBox->setObjectName(QStringLiteral("sBox"));

        verticalLayout->addWidget(sBox);

        iBox = new QLineEdit(View);
        iBox->setObjectName(QStringLiteral("iBox"));

        verticalLayout->addWidget(iBox);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addB = new QPushButton(View);
        addB->setObjectName(QStringLiteral("addB"));

        verticalLayout_2->addWidget(addB);

        removeB = new QPushButton(View);
        removeB->setObjectName(QStringLiteral("removeB"));

        verticalLayout_2->addWidget(removeB);

        startB = new QPushButton(View);
        startB->setObjectName(QStringLiteral("startB"));

        verticalLayout_2->addWidget(startB);

        endB = new QPushButton(View);
        endB->setObjectName(QStringLiteral("endB"));

        verticalLayout_2->addWidget(endB);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QWidget *View)
    {
        View->setWindowTitle(QApplication::translate("View", "Form", nullptr));
        label->setText(QApplication::translate("View", "DESCRIPTION", nullptr));
        label_2->setText(QApplication::translate("View", "STATUS", nullptr));
        label_3->setText(QApplication::translate("View", "ID", nullptr));
        addB->setText(QApplication::translate("View", "ADD", nullptr));
        removeB->setText(QApplication::translate("View", "REMOVE", nullptr));
        startB->setText(QApplication::translate("View", "START", nullptr));
        endB->setText(QApplication::translate("View", "DONE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
