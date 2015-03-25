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



            
        default:
            cout << "\tUnkown I-Format Instruction" << endl;
            
    }
}
bool IFormat::execute ()
{
    switch (opcode)
    {
        case 0x23:
            signedImm 		= (imm & 0x8000) ? (0xFFFF0000 | imm): imm;	// sign extending the immediate field
            address 	= registers[rs] + signedImm;
            break;
    }
}





