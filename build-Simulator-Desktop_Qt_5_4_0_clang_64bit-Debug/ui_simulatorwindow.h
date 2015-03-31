/********************************************************************************
** Form generated from reading UI file 'simulatorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATORWINDOW_H
#define UI_SIMULATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimulatorWindow
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QTabWidget *tabs;
    QWidget *DisassemblerTab;
    QListView *disassemblerOut;
    QScrollBar *verticalScrollBar;
    QWidget *Data;
    QTableView *DataSegment;
    QTableView *registers;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *File;

    void setupUi(QMainWindow *SimulatorWindow)
    {
        if (SimulatorWindow->objectName().isEmpty())
            SimulatorWindow->setObjectName(QStringLiteral("SimulatorWindow"));
        SimulatorWindow->resize(773, 611);
        actionOpen = new QAction(SimulatorWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralwidget = new QWidget(SimulatorWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabs = new QTabWidget(centralwidget);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setGeometry(QRect(30, 20, 441, 521));
        DisassemblerTab = new QWidget();
        DisassemblerTab->setObjectName(QStringLiteral("DisassemblerTab"));
        disassemblerOut = new QListView(DisassemblerTab);
        disassemblerOut->setObjectName(QStringLiteral("disassemblerOut"));
        disassemblerOut->setGeometry(QRect(-5, -19, 441, 511));
        verticalScrollBar = new QScrollBar(DisassemblerTab);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(410, -1, 20, 491));
        verticalScrollBar->setOrientation(Qt::Vertical);
        tabs->addTab(DisassemblerTab, QString());
        Data = new QWidget();
        Data->setObjectName(QStringLiteral("Data"));
        DataSegment = new QTableView(Data);
        DataSegment->setObjectName(QStringLiteral("DataSegment"));
        DataSegment->setGeometry(QRect(0, -20, 441, 511));
        tabs->addTab(Data, QString());
        registers = new QTableView(centralwidget);
        registers->setObjectName(QStringLiteral("registers"));
        registers->setGeometry(QRect(490, 50, 251, 491));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(490, 20, 61, 31));
        commandLinkButton_2 = new QCommandLinkButton(centralwidget);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(670, 20, 71, 31));
        SimulatorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SimulatorWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 773, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        SimulatorWindow->setMenuBar(menubar);
        File = new QStatusBar(SimulatorWindow);
        File->setObjectName(QStringLiteral("File"));
        SimulatorWindow->setStatusBar(File);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(SimulatorWindow);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SimulatorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SimulatorWindow)
    {
        SimulatorWindow->setWindowTitle(QApplication::translate("SimulatorWindow", "Simulator", 0));
        actionOpen->setText(QApplication::translate("SimulatorWindow", "Open", 0));
        tabs->setTabText(tabs->indexOf(DisassemblerTab), QApplication::translate("SimulatorWindow", "Text Segment", 0));
#ifndef QT_NO_ACCESSIBILITY
        Data->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        tabs->setTabText(tabs->indexOf(Data), QApplication::translate("SimulatorWindow", "Data Segment", 0));
        commandLinkButton->setText(QApplication::translate("SimulatorWindow", "Next", 0));
        commandLinkButton_2->setText(QApplication::translate("SimulatorWindow", "Run", 0));
        menuFile->setTitle(QApplication::translate("SimulatorWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class SimulatorWindow: public Ui_SimulatorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATORWINDOW_H
