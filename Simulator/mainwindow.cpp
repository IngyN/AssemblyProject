#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Simulator * S, int argc, char * argv[]) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(argc>3)
    {
        cout <<"Error: too many arguments"<<endl;
    }
    else if(argc==3)
    {
        // name and textFile and Memory
        Simulator S;
        if (S.readTextFromFile(argv[1]))
        {
            if(S.readMemoryFromFile(argv[2]))
                S.run();
        }

    }
    else if(argc==2)
    {
        // name and textFile
        Simulator S;
        string s="";
        if(S.readTextFromFile(argv[1]))
        {
            S.readMemoryFromFile(s);
            S.run();
        }


    }
//    else if (argc==1)
//    {
//        cout << "Error: too few arguments"<<endl;
//        string s="";
//        Simulator S;

//        if(S.readTextFromFile(s))
//        {
//            S.readMemoryFromFile(s);
//            S.run();
//        }
//        else
//        {
//            cout <<"\n\nError invalid file\n"<<endl;
//        }

//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString textsource=ui->lineEdit->text();

}
