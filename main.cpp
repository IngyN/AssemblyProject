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
        cout <<"Error: too many arguments"<<endl;
    }
    else if(argc==3)
    {
        // name and textFile and Memory
        Simulator S;
        if (S.readTextFromFile(argv[1]))
        {
            if(S.readMemoryFromFile(argv[2]))
                S.run();
        }
        
    }
    else if(argc==2)
    {
        // name and textFile
        Simulator S;
        string s="";
        if(S.readTextFromFile(argv[1]))
        {
            S.readMemoryFromFile(s);
            S.run();
        }
        
        
    }
    else if (argc==1)
    {
        cout << "Error: too few arguments"<<endl;
        string s="";
        Simulator S;
        
        if(S.readTextFromFile(s))
        {
            S.readMemoryFromFile(s);
            S.run();
        }
        
    }
    
    return 0;
}