#include "simulatorwindow.h"
#include <Instruction.h>
#include "ui_simulatorwindow.h"
#include <QStringListModel>
#include <QStandardItemModel>
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
    finished=false;

    ui->setupUi(this);

    ui->DisassemblerTab->setObjectName("Text Segment");
    ui->DataSegment->setObjectName("Data Segment & Console");
   ui->DisassemblerTab->setEnabled(true);

   // Registers
   model = new QStandardItemModel(32,2,this);
   model->setHorizontalHeaderItem(0, new QStandardItem(QString("Register")));
   model->setHorizontalHeaderItem(1, new QStandardItem(QString("Value")));
   ui->registers->setModel(model);

   this->setRegistersName();

    this->Disassembler();

   //DataSegment

   model2 = new QStandardItemModel(8*1024,4,this);

   model2->setHorizontalHeaderItem(0, new QStandardItem(QString("Value (+0)")));
   model2->setHorizontalHeaderItem(1, new QStandardItem(QString("Value (+1)")));
   model2->setHorizontalHeaderItem(2, new QStandardItem(QString("Value (+2)")));
   model2->setHorizontalHeaderItem(3, new QStandardItem(QString("Value (+3)")));

   //model2->setVerticalHeaderItem(0, new QStandardItem(QString("Address")));

   for (int i=0; i<8*1024; i++)
   {
       model2->setVerticalHeaderItem(i,new QStandardItem(QString::number(0x10010000+4*i)));
   }

   ui->DataSegment->setModel(model2);

}

SimulatorWindow::~SimulatorWindow()
{
    delete ui;
}

void SimulatorWindow::Disassembler()
{

    vector<QString> * v;
    v=S->disassembler();

    // text edit
    QVector<QString> v0=QVector<QString>::fromStdVector(*v);

    for(int i=0; i<v0.size(); i++)
        ui->disassemblerOut->append(v0[i]);
    //ui->disassemblerOut->setVerticalScrollBar();
    delete v;
}

void SimulatorWindow::setRegistersName()
{

    for (int i=0; i<32; i++)
       {
        model->setItem(i,0,new QStandardItem(QString::fromStdString(Instruction::displayReg(i))));
        }
    // Put in table view
    ui->registers->setModel(model);
}

void SimulatorWindow::setRegistersContent()
{
    for (int i=0; i<32; i++)
       {
        model->setItem(i,1,new QStandardItem(QString::number(Instruction::registers[i])));
        }
    // Put in table view
    ui->registers->setModel(model);
}

void SimulatorWindow::setDataContent()
{
    for(int i=0;i<8*1024; i++)
        model2->setItem(i/4,i%4,new QStandardItem(QString::number(Instruction::memory[i])));

    ui->DataSegment->setModel(model2);
}

void SimulatorWindow::setConsoleOut()
{
    QVector<QString> * v;
    v=S->getConsole();

    QString s="";
    for(int i=0; i<v->size(); i++)
        s+=v->at(i);
//    ui->Console->clear();
//    for(int i=0; i<v->size(); i++)
//        ui->Console->append(v->at(i));
    ui->Console->setText(s);
}

void SimulatorWindow::on_commandLinkButton_clicked()
{
    // run 1 step
   if(!finished)
   {
       finished=S->run1();
   }

   this->setConsoleOut();
   this->setRegistersContent();
}

void SimulatorWindow::on_commandLinkButton_2_clicked() //Run button
{
    int maxSize=S->getTextSize();
    if(!finished){
    do
    {
         finished=S->run1();
         this->setRegistersContent();
         this->setConsoleOut();

    }while (!finished && Instruction::pc<maxSize-1);
    }
}
