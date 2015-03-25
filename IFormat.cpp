//
//  IFormat.cpp
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "IFormat.h"
#include "Globals.h"
#include <iostream>
using namespace std;

void IFormat::decode ()
{
    opcode = word >> 26;
    
    imm = word & 0xffff;
    rt    = (word>>16) & 0x1f;
    rs    = (word>>21) & 0x1f;

    
    //addi, addiu, andi, ori, xori, lw, sw, sb, lb, lh, sh, beq, bne, slti, lui
}
void IFormat::display ()
{
    switch(opcode)
    {
        case 0x8:
            cout << "\tADDI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0x9:
            cout << "\tADDIU\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
        
        case 0xc:
            cout << "\tANDI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0xd:
            cout << "\tORI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0xe:
            cout << "\tXORI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0x23://LW
            
            cout << "\tLW\t";
            displayReg(rt);
            cout<< ","<< dec << imm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;

            break;
            
        case 0x2b://SW
            cout << "\tSW\t";
            displayReg(rt);
            cout<< ","<< dec << imm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;

            break;
            
        case 0x20://LB
            cout << "\tLB\t";
            displayReg(rt);
            cout<< ","<< dec << imm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x28://SB
            cout << "\tSB\t";
            displayReg(rt);
            cout<< ","<< dec << imm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x21://LH
            cout << "\tLH\t";
            displayReg(rt);
            cout<< ","<< dec << imm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x29://SH
            cout << "\tSH\t";
            displayReg(rt);
            cout<< ","<< dec << imm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x4:
            cout << "\tBEQ\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0x5:
            cout << "\tBNE\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0xa:
            cout << "\tSLTI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0xf:
            cout << "\tLUI\t";
            displayReg(rt);
            cout<< ","<< dec << imm<<endl;
            
            break;


            
        default:
            cout << "\tUnkown I-Format Instruction" << endl;
            
    }
}
bool IFormat::execute ()
{
    switch (opcode)
    {
        case 0x8:
            cout << "\tADDI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0x9:
            cout << "\tADDIU\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0xc:
            cout << "\tANDI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0xd:
            cout << "\tORI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0xe:
            cout << "\tXORI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0x23://LW
            
            cout << "\tLW\t";
            displayReg(rt);
            cout<< ","<< dec << imm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x2b://SW
            cout << "\tSW\t";
            displayReg(rt);
            cout<< ","<< dec << imm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x20://LB
            cout << "\tLB\t";
            displayReg(rt);
            cout<< ","<< dec << imm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x28://SB
            cout << "\tLB\t";
            displayReg(rt);
            cout<< ","<< dec << imm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x21://LH
            cout << "\tLH\t";
            displayReg(rt);
            cout<< ","<< dec << imm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x29://SH
            cout << "\tLH\t";
            displayReg(rt);
            cout<< ","<< dec << imm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x4:
            cout << "\tBEQ\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0x5:
            cout << "\tBNE\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0xa:
            cout << "\tSLTI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
        case 0xf:
            cout << "\tLUI\t";
            displayReg(rt);
            cout<< ","<< dec << imm<<endl;
            
            break;
            
            
            
        default:
            cout << "\tUnkown I-Format Instruction" << endl;
            
        case 0x23:
        {
            signedImm 		= (imm & 0x8000) ? (0xFFFF0000 | imm): imm;	// sign extending the immediate field
            address 	= registers[rs] + signedImm;
            break;
        }
            
            
    }
    
    //for now
    return true;
}














