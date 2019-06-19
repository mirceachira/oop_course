/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *nextDog;
    QTextEdit *currentDog;
    QPushButton *adoptCurrent;
    QPushButton *adoptFromAll;
    QPushButton *adoptFiltered;
    QListWidget *adoptionList;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 308);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        nextDog = new QPushButton(centralWidget);
        nextDog->setObjectName(QStringLiteral("nextDog"));
        nextDog->setGeometry(QRect(10, 140, 181, 25));
        currentDog = new QTextEdit(centralWidget);
        currentDog->setObjectName(QStringLiteral("currentDog"));
        currentDog->setGeometry(QRect(10, 10, 181, 121));
        adoptCurrent = new QPushButton(centralWidget);
        adoptCurrent->setObjectName(QStringLiteral("adoptCurrent"));
        adoptCurrent->setGeometry(QRect(10, 170, 181, 25));
        adoptFromAll = new QPushButton(centralWidget);
        adoptFromAll->setObjectName(QStringLiteral("adoptFromAll"));
        adoptFromAll->setGeometry(QRect(10, 200, 181, 25));
        adoptFiltered = new QPushButton(centralWidget);
        adoptFiltered->setObjectName(QStringLiteral("adoptFiltered"));
        adoptFiltered->setGeometry(QRect(10, 230, 181, 25));
        adoptionList = new QListWidget(centralWidget);
        adoptionList->setObjectName(QStringLiteral("adoptionList"));
        adoptionList->setGeometry(QRect(200, 10, 191, 241));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        nextDog->setText(QApplication::translate("MainWindow", "next dog", nullptr));
        adoptCurrent->setText(QApplication::translate("MainWindow", "adopt current", nullptr));
        adoptFromAll->setText(QApplication::translate("MainWindow", "adopt from all", nullptr));
        adoptFiltered->setText(QApplication::translate("MainWindow", "adopt filtered", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
