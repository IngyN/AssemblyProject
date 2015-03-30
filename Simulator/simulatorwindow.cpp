#include "simulatorwindow.h"
#include "ui_simulatorwindow.h"
#include <QStringListModel>
#include <QList>
#include <QVector>
#include <vector>
#include <iostream>

using namespace std;

SimulatorWindow::SimulatorWindow(QWidget *parent, Simulator * S) :
    QMainWindow(parent),
    ui(new Ui::SimulatorWindow)
{
    this->S=S;
    cout <<"shit"<<endl;
  parent->close();
    cout <<"shit"<<endl;
    this->Disassembler();
    // Set registers as well
    // change tab names
    ui->setupUi(this);
}

SimulatorWindow::~SimulatorWindow()
{
    delete ui;
}

void SimulatorWindow::Disassembler()
{
    vector<QString> * v;
    v=S->disassembler();
    ui->disassemblerOut->setModel(new QStringListModel(QList<QString>::fromVector(QVector<QString>::fromStdVector(*v))));

    delete v;
}
