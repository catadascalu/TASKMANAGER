/********************************************************************************
** Form generated from reading UI file 'Window.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *taskTable;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *descriptionBox;
    QLineEdit *statusBox;
    QLineEdit *idBox;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *startButton;
    QPushButton *endButton;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(400, 300);
        verticalLayout_5 = new QVBoxLayout(Window);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        taskTable = new QTableWidget(Window);
        if (taskTable->columnCount() < 3)
            taskTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        taskTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        taskTable->setObjectName(QStringLiteral("taskTable"));
        taskTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_4->addWidget(taskTable);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Window);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Window);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(Window);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        descriptionBox = new QLineEdit(Window);
        descriptionBox->setObjectName(QStringLiteral("descriptionBox"));

        verticalLayout_2->addWidget(descriptionBox);

        statusBox = new QLineEdit(Window);
        statusBox->setObjectName(QStringLiteral("statusBox"));

        verticalLayout_2->addWidget(statusBox);

        idBox = new QLineEdit(Window);
        idBox->setObjectName(QStringLiteral("idBox"));

        verticalLayout_2->addWidget(idBox);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        addButton = new QPushButton(Window);
        addButton->setObjectName(QStringLiteral("addButton"));

        verticalLayout_3->addWidget(addButton);

        removeButton = new QPushButton(Window);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        verticalLayout_3->addWidget(removeButton);

        startButton = new QPushButton(Window);
        startButton->setObjectName(QStringLiteral("startButton"));

        verticalLayout_3->addWidget(startButton);

        endButton = new QPushButton(Window);
        endButton->setObjectName(QStringLiteral("endButton"));

        verticalLayout_3->addWidget(endButton);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = taskTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Window", "DESCRIPTION", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = taskTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Window", "STATUS", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = taskTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Window", "PROGRAMMER ID", nullptr));
        label->setText(QApplication::translate("Window", "DESCRIPTION", nullptr));
        label_2->setText(QApplication::translate("Window", "STATUS", nullptr));
        label_3->setText(QApplication::translate("Window", "ID", nullptr));
        addButton->setText(QApplication::translate("Window", "ADD", nullptr));
        removeButton->setText(QApplication::translate("Window", "REMOVE", nullptr));
        startButton->setText(QApplication::translate("Window", "START", nullptr));
        endButton->setText(QApplication::translate("Window", "DONE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
