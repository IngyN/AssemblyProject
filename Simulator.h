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
    
    void display ();
    void run();
    
    void readTextFromFile(string);
    
private:
    // Text segment
    
    vector<Instruction *> textSegment; // starting address: 0x 0400 0000

};

#endif /* defined(__AssemblyProject__Simulator__) */
