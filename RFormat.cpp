//
//  RFormat.cpp
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "RFormat.h"
#include <iostream>
using namespace std;


void RFormat::decode()
{
    opcode = word >> 26;
    
    func  = word & 0x3F;
    shamt = (word>>6) & 0x1f;
    rd    = (word>>11) & 0x1f;
    rt    = (word>>16) & 0x1f;
    rs    = (word>>21) & 0x1f;
    
    
    
    // add addu sub and or xor srl sll syscall
    
    
    
}

void RFormat::display()
{
    switch(func)
    {
        case 0x20: // ADD
            cout << "\tADD\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            //regs[rd]=regs[rs]+regs[rt];
            break;
            
        case 0x21: // ADD
            cout << "\tADDU\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            //regs[rd]=regs[rs]+regs[rt];
            break;
            
        case 0x22: // ADD
            cout << "\tSUB\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            //regs[rd]=regs[rs]+regs[rt];
            break;
            
        case 0x24: // ADD
            cout << "\tAND\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            //regs[rd]=regs[rs]+regs[rt];
            break;
            
        case 0x25: // ADD
            cout << "\tOR\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            //regs[rd]=regs[rs]+regs[rt];
            break;
            
        case 0x26: // ADD
            cout << "\tXOR\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            //regs[rd]=regs[rs]+regs[rt];
            break;
            
        case 0x02: // ADD
            cout << "\tSRL\t$" << dec << rd << ", $" << rs << ", $" << shamt << endl ;
            //regs[rd]=regs[rs]+regs[rt];
            break;
            
        default:
            cout << "0x" << hex << pc << "\tUnkown R-Format Instruction" << endl;
    }
    
}