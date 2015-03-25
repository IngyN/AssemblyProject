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

}
void IFormat::display ()
{
    switch(opcode)
    {
        case 0x23:	// LW
            signedImm 		= (imm & 0x8000) ? (0xFFFF0000 | imm): imm;	// sign extending the immediate field
            address 	= registers[rs] + signedImm;
            cout << "0x" << hex << pc << "\tLW\t$" << dec << rt << "," << sImm << "($" << rs << ")" << endl;
            //regs[rt]	= memory[address - 0x10010000];		// uncommenting this would crash the program as othe instructions are not implemented
            break;
            
        default:
            cout << "0x" << hex << pc << "\tUnkown I-Format Instruction" << endl;
            
    }
}
bool IFormat::execute ()
{
    
}