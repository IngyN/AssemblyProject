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

class RFormat;
class JFormat;
class IFormat;

class Instruction
{
public:
    Instruction ();
    ~Instruction();
    
    void setWord(unsigned int);
    
    virtual void decode ()=0;
    virtual void display ()=0;
    virtual bool execute (unsigned int & pc)=0;
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
    int registers [32];
    
    unsigned char memory[8*1024];	// This array represents the data memory available
    // only 8KB of data memory
    // Starts from address 0x10010000

    
};

#endif /* defined(__AssemblyProject__Instruction__) */
