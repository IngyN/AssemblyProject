//
//  JFormat.h
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#ifndef __AssemblyProject__JFormat__
#define __AssemblyProject__JFormat__

#include "Instruction.h"

class JFormat: public Instruction
{
public:
    JFormat();
    ~JFormat();
    
    void decode ();

    void display ();
    void execute ();
    
private:
    
    unsigned char targetAddress[4];
    
};

#endif /* defined(__AssemblyProject__JFormat__) */
