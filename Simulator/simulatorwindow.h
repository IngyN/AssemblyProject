#ifndef SIMULATORWINDOW_H
#define SIMULATORWINDOW_H

#include <QMainWindow>
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
    ~SimulatorWindow();

private:
    Ui::SimulatorWindow *ui;
    Simulator *S;
};

#endif // SIMULATORWINDOW_H
