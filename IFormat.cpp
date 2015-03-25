//
//  IFormat.cpp
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "IFormat.h"
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
        case 0x23:
            
            break;
            
            
            
//        case 0x23:	// LW
//            signedImm 		= (imm & 0x8000) ? (0xFFFF0000 | imm): imm;	// sign extending the immediate field
//            address 	= registers[rs] + signedImm;
//            cout << "\tLW\t$" << dec << rt << "," << signedImm << "($" << rs << ")" << endl;
//            
//            break;
//            
//            
//        case 0x2b:	// SW
//            signedImm 		= (imm & 0x8000) ? (0xFFFF0000 | imm): imm;	// sign extending the immediate field
//            address 	= registers[rs] + signedImm;
//            cout << "\tSW\t$" << dec << rt << "," << signedImm << "($" << rs << ")" << endl;
//            
//            break;
            
        default:
            cout << "\tUnkown I-Format Instruction" << endl;
            
    }
}
bool IFormat::execute ()
{
    return false;
    
}