//
//  RFormat.cpp
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "RFormat.h"
#include <iostream>
#include <iomanip>
#include <QString>

using namespace std;


void RFormat::decode()
{

    func  = (word & 0x3f);
    shamt = (word>>6) & 0x1f;
    rd    = (word>>11) & 0x1f;
    rt    = (word>>16) & 0x1f;
    rs    = (word>>21) & 0x1f;
    
    // add addu sub and or xor srl sll syscall jr
    
    
    
}

string RFormat::display()
{
    string s;
    switch(func)
    {
        case 0x20: // ADD
            s="\tadd\t\t"+displayReg(rd)+","+displayReg(rs)+","+displayReg(rt)+"\n";
            break;
            
        case 0x21: // ADDU
            s="\taddu\t"+displayReg(rd)+","+displayReg(rs)+","+displayReg(rt)+"\n";
            
            break;
            
        case 0x22: // SUB
            s="\tsub\t\t"+displayReg(rd)+","+displayReg(rs)+","+displayReg(rt)+"\n";
            break;
            
        case 0x24: // AND
            s="\tand\t\t"+displayReg(rd)+","+displayReg(rs)+","+displayReg(rt)+"\n";
            break;
            
        case 0x25: // OR
            s="\tor\t\t"+displayReg(rd)+","+displayReg(rs)+","+displayReg(rt)+"\n";
            break;
            
        case 0x26: // XOR
            s="\txor\t\t"+displayReg(rd)+","+displayReg(rs)+","+displayReg(rt)+"\n";
            break;
            
        case 0x2a: //SLT
            s="\tslt\t\t"+displayReg(rd)+","+displayReg(rs)+","+displayReg(rt)+"\n";
            break;
            
        case 0x02: // SRL
            s="\tsrl\t\t"+displayReg(rd)+","+displayReg(rs)+","+QString::number(int(shamt)).toStdString()+"\n";
            
            break;
            
        case 0x00: // SLL
            s="\tsll\t\t"+displayReg(rd)+","+displayReg(rs)+","+QString::number(int(shamt)).toStdString()+"\n";
            break;
            
        case 0x0c: // SYSCALL
            s="\tsyscall\t\n\n";
            
            break;
            
        case 0x08: // JR
            s="\tjr\t\t"+displayReg(rs)+"\n";
            break;
            
        default:
            s="\tUnkown R-Format Instruction\n";
    }
    return s;
}

bool RFormat::execute()
{
    bool finished = false;
    
    switch(func)
    {
        case 0x20: // ADD
            //signed addition
            if(!((registers[rs]& 0x80000000)^(registers[rt]& 0x80000000))){
                // Same sign
                int temp=registers[rs] + registers[rt];
                
                if(((temp&0x80000000)^(registers[rs]&0x80000000)))
                {
                    // sign of result != sign of operands => overflow!
                    cout <<"OVERFLOW"<<endl;
                }
                else
                    registers[rd]=temp;
            }
            else{
                // no overflow (signs are different)
                registers[rd]=registers[rs] + registers[rt];
            }
            break;
            
        case 0x21: // ADDU
            registers[rd]=registers[rs] + registers[rt];
            
            break;
            
        case 0x22: // SUB
            //signed substraction

            if(!((registers[rs]& 0x80000000)^(registers[rt]& 0x80000000))){
                // Same sign
                int temp=registers[rs] - registers[rt];
                
                if(((temp&0x80000000)^(registers[rs]&0x80000000)))
                {
                    // sign of result != sign of operands => overflow!
                    cout <<"OVERFLOW"<<endl;
                }
                else
                    registers[rd]=temp;
            }
            else{
                // no overflow (signs are different)
                registers[rd]=registers[rs] - registers[rt];
            }
            
            break;
            
        case 0x24: // AND
            registers[rd]=registers[rs] & registers[rt];
            
            break;
            
        case 0x25: // OR
            registers[rd]=registers[rs] | registers[rt];
            
            break;
            
        case 0x26: // XOR
            registers[rd]=registers[rs] ^ registers[rt];
            
            break;
            
        case 0x2a: //SLT
            registers[rd]=(registers[rs]<registers[rt])?1:0;
            break;
            
        case 0x02: // SRL
            registers[rd] = unsigned(registers[rt])>>shamt;
            
            break;
            
        case 0x00: // SLL
            registers[rd] = registers[rt]<<shamt;
            
            break;
            
        case 0x0c: // SYSCALL
            cout <<dec;
            switch (registers[2])//$v0
        {
            case 1://Print an integer
                cout << registers[4];
                break;
                
            case 11://Print a character
                cout << registers[4];
                break;
                
            case 4://Print a string
            {
                bool nullFound= false;
                
                for(int i = registers[4]-0x10010000;nullFound==false;i++)
                {
                        if(memory[i]=='\0')
                            nullFound= true;
                        else
                            cout << memory[i];
                }
                
                break;
            }
            case 10://Exit
            {
                finished = true;
                cout << "\n\nProgram exit.\n";
                break;

            }
                                
            default:
                break;
        }
            
            break;
            
        case 0x08: // JR
            pc = (registers[rs]-0x00400000-4)/4;// Starting address of text segment
            break;
            
        default:
            cout << "\tUnkown R-Format Instruction" << endl;
            
        
            
            
    }
    return finished;
}

