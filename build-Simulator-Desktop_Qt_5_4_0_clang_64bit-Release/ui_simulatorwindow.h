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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimulatorWindow
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QTabWidget *tabs;
    QWidget *DisassemblerTab;
    QTextEdit *disassemblerOut;
    QWidget *Data;
    QTableView *DataSegment;
    QTextEdit *Console;
    QCheckBox *checkBox;
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
        tabs->setGeometry(QRect(20, 20, 441, 531));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        tabs->setFont(font);
        DisassemblerTab = new QWidget();
        DisassemblerTab->setObjectName(QStringLiteral("DisassemblerTab"));
        disassemblerOut = new QTextEdit(DisassemblerTab);
        disassemblerOut->setObjectName(QStringLiteral("disassemblerOut"));
        disassemblerOut->setGeometry(QRect(10, 0, 421, 501));
        QFont font1;
        font1.setFamily(QStringLiteral("Courier New"));
        disassemblerOut->setFont(font1);
        disassemblerOut->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        disassemblerOut->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        disassemblerOut->setUndoRedoEnabled(false);
        disassemblerOut->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        tabs->addTab(DisassemblerTab, QString());
        Data = new QWidget();
        Data->setObjectName(QStringLiteral("Data"));
        DataSegment = new QTableView(Data);
        DataSegment->setObjectName(QStringLiteral("DataSegment"));
        DataSegment->setGeometry(QRect(10, 0, 421, 311));
        DataSegment->setEditTriggers(QAbstractItemView::NoEditTriggers);
        DataSegment->horizontalHeader()->setDefaultSectionSize(85);
        DataSegment->horizontalHeader()->setHighlightSections(true);
        DataSegment->horizontalHeader()->setMinimumSectionSize(4);
        DataSegment->verticalHeader()->setDefaultSectionSize(32);
        Console = new QTextEdit(Data);
        Console->setObjectName(QStringLiteral("Console"));
        Console->setGeometry(QRect(10, 330, 421, 171));
        Console->setUndoRedoEnabled(false);
        Console->setReadOnly(true);
        checkBox = new QCheckBox(Data);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(360, 310, 61, 20));
        tabs->addTab(Data, QString());
        registers = new QTableView(centralwidget);
        registers->setObjectName(QStringLiteral("registers"));
        registers->setGeometry(QRect(490, 50, 251, 491));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(registers->sizePolicy().hasHeightForWidth());
        registers->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(11);
        registers->setFont(font2);
        registers->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        registers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        registers->setProperty("showDropIndicator", QVariant(false));
        registers->setDragDropOverwriteMode(false);
        registers->setSelectionMode(QAbstractItemView::SingleSelection);
        registers->horizontalHeader()->setDefaultSectionSize(115);
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(490, 20, 61, 31));
        commandLinkButton->setFont(font1);
        commandLinkButton_2 = new QCommandLinkButton(centralwidget);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(670, 20, 71, 31));
        commandLinkButton_2->setFont(font1);
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

        tabs->setCurrentIndex(1);


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
        checkBox->setText(QApplication::translate("SimulatorWindow", "ASCII", 0));
        tabs->setTabText(tabs->indexOf(Data), QApplication::translate("SimulatorWindow", "Data Segment and Console", 0));
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
