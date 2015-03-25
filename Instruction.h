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
    virtual bool execute ()=0;
    virtual void displayReg(char);
    
    bool isRFormat();
    bool isJFormat();
    bool isIFormat();
    static void select(Instruction *, unsigned char);
    
protected:
    
   unsigned int word;
   unsigned char opcode;
    
};

#endif /* defined(__AssemblyProject__Instruction__) */
