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
#include "Globals.h"

using namespace std;

Simulator::Simulator()
{
    pc=-1;
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
        while(true && textSegment.size()<maxSize)
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
void Simulator::readMemoryFromFile(string source)
{
    // read from file and store in memory
    char temp[4]={0,0,0,0};
    int index=0;
    
    ifstream inFile;
    string inFileName = "";
    
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
                    memory[index++]=temp[i];
                }
            
            // If 4 bytes cannot be read from the file (i.e. end of file has been reached), break the loop.
        }
    }
    
    else // The input file cannot be opened
    {
        cout << "Cannot access input file" << endl;
    }
    
    inFile.close();
}

void Simulator::run()
{
    bool finished =false;
    
    while (!finished && pc<textSegment.size())
    {
        pc++;
        textSegment [pc] ->decode();
        finished=textSegment[pc]->execute();
        
    }
    
}



