//
//  main.cpp
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//


#include <iostream>
#include "Simulator.h"

using namespace std;

int main(int argc, const char * argv[])
{
    if(argc>3)
    {
        cout <<"too many arguments";
    }
    else if(argc==3)
    {
        Simulator S;
        S.readTextFromFile(argv[1]);
        S.readMemoryFromFile(argv[2]);
    }

    return 0;
}