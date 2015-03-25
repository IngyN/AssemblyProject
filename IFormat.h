//
//  IFormat.h
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#ifndef __AssemblyProject__IFormat__
#define __AssemblyProject__IFormat__

#include "Instruction.h"

class IFormat: public Instruction
{
public:
    
    void decode ();
    void display ();
    void execute ();
    
private:
    unsigned char rs, rt, imm;
    int signedImm;
    
};

#endif /* defined(__AssemblyProject__IFormat__) */
