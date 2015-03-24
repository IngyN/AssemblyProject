//
//  Instruction.h
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#ifndef __AssemblyProject__Instruction__
#define __AssemblyProject__Instruction__
#include <bitset>
using namespace std;

class Instruction
{
public:
    Instruction ();
    ~Instruction();
    
    void setWord(unsigned int);
    
    virtual void decode ()=0;
    virtual void display ()=0;
    virtual void execute ()=0;
    virtual void displayReg(char);
    
    bool isRFormat();
    bool isJFormat();
    bool isIFormat();
    static void select(Instruction *, unsigned char);
    
protected:
    
   unsigned int word;
   unsigned char opcode;

    // Registers
    // 32 registers of size 32 bits (4bytes).
    bitset <32> registers [32];
    
};

#endif /* defined(__AssemblyProject__Instruction__) */
