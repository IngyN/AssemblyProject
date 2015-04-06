#include "simulatorwindow.h"
#include "ui_simulatorwindow.h"
#include <QStringListModel>
#include <QFlags>
#include <QTextEdit>
#include <QVector>
#include <vector>
#include <iostream>

using namespace std;

SimulatorWindow::SimulatorWindow(QWidget *parent, Simulator * S) :
    QMainWindow(parent),
    ui(new Ui::SimulatorWindow)
{
    this->S=S;

 ui->setupUi(this);
    ui->DisassemblerTab->setObjectName("Text Segment");
   ui->DisassemblerTab->setEnabled(true);

    cout <<"shit2"<<endl;
    this->Disassembler();

    //parent->close();
    // Set registers as well
    // change tab names
}

SimulatorWindow::~SimulatorWindow()
{
    delete ui;
}

void SimulatorWindow::Disassembler()
{
    cout<<"shitty"<<endl;
    vector<QString> * v;
    v=S->disassembler();
    cout <<"shit3"<<endl;
    // text edit
    QVector<QString> v0=QVector<QString>::fromStdVector(*v);

    for(int i=0; i<v0.size(); i++)
        ui->disassemblerOut->append(v0[i]);
    //ui->disassemblerOut->setVerticalScrollBar();
    delete v;
}
