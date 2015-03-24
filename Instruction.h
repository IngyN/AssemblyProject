//
//  Instruction.h
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#ifndef __AssemblyProject__Instruction__
#define __AssemblyProject__Instruction__

class Instruction
{
public:
    Instruction ();
    ~Instruction();
    
    virtual void decode ()=0;
    virtual void display ()=0;
    virtual void execute ()=0;
    
    static void select(Instruction *, unsigned char);
    
protected:
    
   unsigned char Word[4];

    
};

#endif /* defined(__AssemblyProject__Instruction__) */
