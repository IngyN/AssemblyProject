//
//  JFormat.cpp
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "JFormat.h"

JFormat::JFormat(unsigned int Word)
{
    this->Instruction::word=Word;
}

JFormat::~JFormat()
{
    
}

void JFormat::decode (unsigned int pc)
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
    
    this->execute();

}

void JFormat::display()
{
    
}

void JFormat::execute()
{
    switch (opcode) {
        case 0x02:
            
            break;
        case 0x03:
            break;
        default:
            cout << "\nUnknown J-Format instruction"<<endl;
            break;
    }

}