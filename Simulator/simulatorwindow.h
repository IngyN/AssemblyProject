#ifndef SIMULATORWINDOW_H
#define SIMULATORWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include<Simulator.h>


namespace Ui {
class SimulatorWindow;
}

class SimulatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimulatorWindow(QWidget *parent = 0, Simulator *S=NULL);
    void Disassembler();
    void setRegistersName();
    void setRegistersContent();
    void setConsoleOut();
    void setDataContent();
    ~SimulatorWindow();

private slots:
    void on_commandLinkButton_clicked();
    void on_commandLinkButton_2_clicked();

private:
    Ui::SimulatorWindow *ui;
    Simulator *S;
    bool finished;
    QStandardItemModel * model;
    QStandardItemModel * model2;
};

#endif // SIMULATORWINDOW_H
