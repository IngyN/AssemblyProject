#include "simulatorwindow.h"
#include "ui_simulatorwindow.h"
#include <vector>

using namespace std;

SimulatorWindow::SimulatorWindow(QWidget *parent, Simulator * S) :
    QMainWindow(parent),
    ui(new Ui::SimulatorWindow)
{
    this->Disassembler();
    ui->setupUi(this);
}

SimulatorWindow::~SimulatorWindow()
{
    delete ui;
}

void SimulatorWindow::Disassembler()
{
    vector<string> * v;
    v=S->disassembler();
    ui->listView->setModel(new QStringListModel(QList<QString>::fromStdVector(v)));
}
