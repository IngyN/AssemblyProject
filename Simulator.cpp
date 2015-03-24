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

using namespace std;

Simulator::Simulator()
{
    pc=0;
    
    //Initialize registers
    for (int i=0; i<32;i++)
        registers[i].reset();
    
    //Memory
    for(char i: memory)
        i=NULL;
}

Simulator::~Simulator()
{
    
}

void Simulator::readTextFromFile(string source)
{
    unsigned int instWord=0;
    Instruction * p=NULL;
    ifstream inFile;
    string inFileName = "";
    
    // Get the binary filename from the user
    cout << "Enter the binary filename (e.g. sample1.bin): ";
    cin >> inFileName;
    
    // Open the binary file to start reading the instructions
    inFile.open(inFileName.c_str(), ios::in | ios::binary);
    
    // If the file is open (this will evaluate to false if the file could not be found)
    if(inFile.is_open())
    {
        // Start reading and decoding the instructions.
        while(true)
        {
            // Read 4 bytes (an instruction) from the file
            if(!inFile.read((char *)&instWord, 4))
                break; // If 4 bytes cannot be read from the file (i.e. end of file has been reached), break the loop.
            
            Instruction::select(p, instWord>>26);
            
            textSegment.push_back(p);
        }
    }
    
    else // The input file cannot be opened
    {
        cout << "Cannot access input file" << endl;
    }
    
    inFile.close();
}