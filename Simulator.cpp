//
//  Simulator.cpp
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Simulator.h"
#include <cmath>


using namespace std;

Simulator::Simulator()
{
    Instruction::pc=-1;
}

Simulator::~Simulator()
{
    
}

bool Simulator::readTextFromFile(string source)
{
    unsigned int instWord=0;
    
    Instruction * p=NULL;
    ifstream inFile;
    string inFileName = "";
    
    bool flag =true;
    
    if(source=="")
    {
        // Get the binary filename from the user
        cout << "Enter the binary filename (e.g. sample1.bin): ";
        cin >> inFileName;
        
        // Open the binary file to start reading the instructions
        inFile.open(inFileName.c_str(), ios::in | ios::binary);
        
    }
    else
    {
        inFile.open(source.c_str(), ios::in | ios::binary);
    }
    
    long long maxSize= (pow(2, 26)*3)/4;
    
    // If the file is open (this will evaluate to false if the file could not be found)
    if(inFile.is_open())
    {
        // Start reading and decoding the instructions.
        while(textSegment.size()<maxSize)
        {
            // Read 4 bytes (an instruction) from the file
            if(!inFile.read((char *)&instWord, 4))
                break; // If 4 bytes cannot be read from the file (i.e. end of file has been reached), break the loop.
            
            Instruction::select(p, instWord>>26, instWord);
            
            textSegment.push_back(p);
        }
    }
    
    else // The input file cannot be opened
    {
        cout << "Cannot access input file" << endl;
        flag=false;
    }
    
    inFile.close();
    return flag;
}
bool Simulator::readMemoryFromFile(string source)
{
    bool flag =true;
    
    // read from file and store in memory
    char temp[4]={0};
    int index=0;
    
    ifstream inFile;
    string inFileName = "";
    
    if(source=="")
    {
        cout << "Would you like to enter a memory file?"<<endl;
        char c;
        cin >> c;
        c=toupper(c);
        
        if(c=='Y')
        {
            cout << "\nMemory file path: "<<endl;
            cin >>source;
        }
        
        else
            cout <<"No memory file"<<endl;
    }
    
    if(source!="")
    {
        inFile.open(source.c_str(), ios::in | ios::binary);
        
        
        long long maxSize= 2048;
        
        // If the file is open (this will evaluate to false if the file could not be found)
        if(inFile.is_open())
        {
            // Start reading and decoding the instructions.
            while(textSegment.size()<maxSize && !inFile.eof())
            {
                // Read 4 bytes (an instruction) from the file
                for(int i=0; i<4; i++)
                    if(inFile.read(&temp[i], 1))
                    {
                        Instruction::memory[index++]=temp[i];
                    }
                
                // If 4 bytes cannot be read from the file (i.e. end of file has been reached), break the loop.
            }
        }
        
        else // The input file cannot be opened
        {
            cout << "Cannot access input file" << endl;
            flag=false;
        }
        inFile.close();
    }

    return flag;
}

void Simulator::run()
{
    
    bool finished =false;
    
    Instruction::displayAll();
    
    do
    {
        Instruction::pc++;
        textSegment [Instruction::pc] ->decode();
        textSegment [Instruction::pc] ->display();
        
    }while (Instruction::pc<textSegment.size()-1);
    
    Instruction::pc =-1;
    
    do
    {
        Instruction::pc++;
        finished=textSegment[Instruction::pc]->execute();
        
        Instruction::registers[Instruction::pc%32];
        Instruction::memory[Instruction::pc];
        
    }while (!finished && Instruction::pc<textSegment.size()-1);
    
    Instruction::displayAll();
    
}



