//
//  JFormat.cpp
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "JFormat.h"
#include <iostream>
#include <cmath>

using namespace std;

JFormat::JFormat()
{
    
}

JFormat::~JFormat()
{
    
}

void JFormat::decode ()
{
    //j, jal
    
    // get target Address
    
    // mask opcode in the word
    targetAddress = this->Instruction::word & 0xfff00000;
    
    // shift left 2 bits (add 00 at the end)
    targetAddress <<= 2;
    
    // mask to keep 4 most significant bits
    pc = pc & 0x00ffffff;
    
    targetAddress|=pc;

}

void JFormat::display()
{
    
}

bool JFormat::execute(unsigned int & pc)
{
    switch (opcode) {
        case 0x02:
            // j
            if((pc+targetAddress)<(192*pow(2,26)+pow(2,12))&&(pc+targetAddress)>0 )
                pc+=targetAddress;
            break;
            
        case 0x03:
            // jal
            if((pc+targetAddress)<(192*pow(2,26)+pow(2,12))&&(pc+targetAddress)>0 )
            {
                registers[31]=pc+1;
                pc+=targetAddress;
            }
            break;
            
        default:
            cout << "\nUnknown J-Format instruction"<<endl;
            break;
    }
    
    return false;

}