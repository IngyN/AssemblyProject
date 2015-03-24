//
//  Simulator.h
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#ifndef __AssemblyProject__Simulator__
#define __AssemblyProject__Simulator__

#include "IFormat.h"
#include "JFormat.h"
#include "RFormat.h"
#include <bitset>
#include <vector>

using namespace std;

class Simulator
{
public:
    Simulator();
    ~Simulator();
    
    void fetch(); // increment pc here
    void decode();
    void execute();
    void display ();
    
    
    void readTextFromFile(string);
    
private:
    // Text segment
    
    vector<Instruction *> textSegment; // starting address: 0x 0400 0000
    
    unsigned char memory[8*1024];	// This array represents the data memory available
    // only 8KB of data memory
    // Starts from address 0x10010000
    
    // Registers
    // 32 registers of size 32 bits (4bytes).
    bitset <32> registers [32];
    
    // Program counter
    static unsigned int pc;
};

#endif /* defined(__AssemblyProject__Simulator__) */
