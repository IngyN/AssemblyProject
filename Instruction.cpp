//
//  Instruction.cpp
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "Instruction.h"
#include <iostream>
//# include "RFormat.h"
using namespace std;

Instruction::Instruction()
{
    //Initialize registers
    for (int i=0; i<32;i++)
        registers[i].reset();
}

void Instruction ::select(Instruction *p, unsigned char opcode)
{
    if(opcode ==0)
    {
        // R format
        p = new RFormat;
    }
    else if(opcode==2 || opcode==3)
    {
        // J-Format (J & Jal)
        p = new JFormat;
    }
    
    else if( 16!=opcode && 17!=opcode &&18!=opcode && 19!=opcode)
    {
        // I-Format
        p =new IFormat;
    }
    
    else
    {
        // The opcode is not known
        cout << "\tOpcode: " << dec << opcode << " - Unkown Instruction" << endl;
    }
}

void Instruction::setWord(unsigned int w)
{
    word=w;
    opcode=w>>26;
}

bool  Instruction::isRFormat()
{
    return (opcode==0);
}

bool Instruction:: isJFormat()
{
    return (opcode==2 || opcode==3);
}
bool Instruction::isIFormat()
{
    return (16!=opcode && 17!=opcode &&18!=opcode && 19!=opcode && opcode!=2 && opcode !=3 && opcode != 0);
}

void Instruction::displayReg(char r)
{
    switch (r)
    {
        case 0x00:
            cout << "zero";
            break;
            
        case 0x00:
            cout << "zero";
            break;

        case 0x00:
            cout << "zero";
            break;
            
        case 0x00:
            cout << "zero";
            break;
            
        case 0x00:
            cout << "zero";
            break;
            
        case 0x00:
            cout << "zero";
            break;
            
        case 0x00:
            cout << "zero";
            break;
            
        case 0x00:
            cout << "zero";
            break;
            
        case 0x00:
            cout << "zero";
            break;
            
        case 0x00:
            cout << "zero";
            break;
            
        case 0x00:
            cout << "zero";
            break;
            
        case 0x00:
            cout << "zero";
            break;
            
        case 0x00:
            cout << "zero";
            break;

            
            
    }
}