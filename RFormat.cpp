//
//  RFormat.cpp
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "RFormat.h"

void RFormat::decode()
{
    opcode = word >> 26;
    
    func  = word & 0x3F;
    shamt = (word>>6) & 0x1f;
    rd    = (word>>11) & 0x1f;
    rt    = (word>>16) & 0x1f;
    rs    = (word>>21) & 0x1f;
    
    
}