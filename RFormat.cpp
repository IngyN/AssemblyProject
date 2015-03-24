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
    
    
    
    // add addu sub and or xor srl sll syscall jr
    
    
    
}

void RFormat::display()
{
    switch(func)
    {
        case 0x20: // ADD
            cout << "\tADD\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
    
            break;
            
        case 0x21: // ADDU
            cout << "\tADDU\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            
            break;
            
        case 0x22: // SUB
            cout << "\tSUB\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            
            break;
            
        case 0x24: // AND
            cout << "\tAND\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            
            break;
            
        case 0x25: // OR
            cout << "\tOR\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            
            break;
            
        case 0x26: // XOR
            cout << "\tXOR\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            
            break;
            
        case 0x02: // SRL
            cout << "\tSRL\t$" << dec << rd << ", $" << rs << ", " << shamt << endl ;
            
            break;
            
        case 0x00: // SLL
            cout << "\tSLL\t$" << dec << rd << ", $" << rs << ", " << shamt << endl ;
            
            break;
            
        case 0x0c: // SYSCALL
            cout << "\tSYSCALL\t" << endl ;
            
            break;
            
        case 0x08: // JR
            cout << "\tJR\t$" << rs << endl ;
            
            break;
            
        default:
            cout << "\tUnkown R-Format Instruction" << endl;
    }
    
}
void RFormat::execute()
{
    switch(func)
    {
        case 0x20: // ADD
            
            
            break;
            
        case 0x21: // ADDU
            registers[rd]=registers[rs] + registers[rt];
            
            break;
            
        case 0x22: // SUB
            cout << "\tSUB\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            
            break;
            
        case 0x24: // AND
            cout << "\tAND\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            
            break;
            
        case 0x25: // OR
            cout << "\tOR\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            
            break;
            
        case 0x26: // XOR
            cout << "\tXOR\t$" << dec << rd << ", $" << rs << ", $" << rt << endl ;
            
            break;
            
        case 0x02: // SRL
            cout << "\tSRL\t$" << dec << rd << ", $" << rs << ", " << shamt << endl ;
            
            break;
            
        case 0x00: // SLL
            cout << "\tSLL\t$" << dec << rd << ", $" << rs << ", " << shamt << endl ;
            
            break;
            
        case 0x0c: // SYSCALL
            cout << "\tSYSCALL\t" << endl ;
            
            break;
            
        case 0x08: // JR
            cout << "\tJR\t$" << rs << endl ;
            
            break;
            
        default:
            cout << "\tUnkown R-Format Instruction" << endl;
    
    
    
    
    
    
}



