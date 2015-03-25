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
            cout << "\tADD\t";
            displayReg(rd);
            cout<< ",";
            displayReg(rs);
            cout<< ",";
            displayReg(rt);
            cout <<endl;
    
            break;
            
        case 0x21: // ADDU
            cout << "\tADDU\t";
            displayReg(rd);
            cout<< ",";
            displayReg(rs);
            cout<< ",";
            displayReg(rt);
            cout <<endl;
            
            break;
            
        case 0x22: // SUB
            cout << "\tSUB\t";
            displayReg(rd);
            cout<< ",";
            displayReg(rs);
            cout<< ",";
            displayReg(rt);
            cout <<endl;
            
            break;
            
        case 0x24: // AND
            cout << "\tAND\t";
            displayReg(rd);
            cout<< ",";
            displayReg(rs);
            cout<< ",";
            displayReg(rt);
            cout <<endl;
            
            break;
            
        case 0x25: // OR
            cout << "\tOR\t";
            displayReg(rd);
            cout<< ",";
            displayReg(rs);
            cout<< ",";
            displayReg(rt);
            cout <<endl;
            
            break;
            
        case 0x26: // XOR
            cout << "\tXOR\t";
            displayReg(rd);
            cout<< ",";
            displayReg(rs);
            cout<< ",";
            displayReg(rt);
            cout <<endl;
            
            break;
            
        case 0x02: // SRL
            cout << "\tSRL\t";
            displayReg(rd);
            cout<< ",";
            displayReg(rs);
            cout<< ",";
            displayReg(rt);
            cout <<endl;
            
            break;
            
        case 0x00: // SLL
            cout << "\tSLL\t";
            displayReg(rd);
            cout<< ",";
            displayReg(rs);
            cout<< ",";
            displayReg(rt);
            cout <<endl;
            
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

bool RFormat::execute()
{
    bool finished = false;
    
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
            registers[rd]=registers[rs] & registers[rt];
            
            break;
            
        case 0x25: // OR
            registers[rd]=registers[rs] | registers[rt];
            
            break;
            
        case 0x26: // XOR
            registers[rd]=registers[rs] ^ registers[rt];
            
            break;
            
        case 0x02: // SRL
            registers[rd] = registers[rs]>>shamt;
            
            break;
            
        case 0x00: // SLL
            registers[rd] = registers[rs]<<shamt;
            
            break;
            
        case 0x0c: // SYSCALL
            switch (registers[2])
        {
                case 1://Print an integer
                    cout << registers[4];
                    break;
                
                case 11://Print a character
                    cout << registers[4];
                break;
                
                case 4://Print a string
                int i = memory[registers[4]];
                while(memory[i]!=NULL)
                {
                    
                }
                
                break;
                
                case 10://Print an integer
                finished = true;
                cout << "Program exit.\n";
                break;
                
                default:
                    break;
            }
            
            break;
            
        case 0x08: // JR
            pc = registers[31];
            break;
            
        default:
            cout << "\tUnkown R-Format Instruction" << endl;
    
    
    
    
    
           
}
     return finished;
}

