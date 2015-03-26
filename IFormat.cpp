//
//  IFormat.cpp
//  AssemblyProject
//
//  Created by Ingy on 3/24/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "IFormat.h" 
#include <iostream>
using namespace std;

void IFormat::decode ()
{
    opcode = word >> 26;
    
    imm = word & 0x0000ffff;
    rt    = (word>>16) & 0x0000001f;
    rs    = (word>>21) & 0x0000001f;
    signedImm 	= (imm & 0x8000) ? (0xFFFF0000 | imm): imm;	// sign extending the immediate field
    
    //addi, addiu, andi, ori, xori, lw, sw, sb, lb, lh, sh, beq, bne, slti, lui
}
void IFormat::display ()
{
    switch(opcode)
    {
        case 0x08:
            cout << "\tADDI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< hex <<signedImm<<endl;
            
            break;
            
        case 0x09:
            cout << "\tADDIU\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< hex << signedImm<<endl;
            
            break;
        
        case 0x0c:
            cout << "\tANDI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< hex << signedImm<<endl;
            
            break;
            
        case 0x0d:
            cout << "\tORI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< dec <<signedImm<<endl;
            
            break;
            
        case 0x0e:
            cout << "\tXORI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< hex <<signedImm<<endl;
            
            break;
            
        case 0x23://LW
            
            cout << "\tLW\t";
            displayReg(rt);
            cout<< ","<< hex <<signedImm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;

            break;
            
        case 0x2b://SW
            cout << "\tSW\t";
            displayReg(rt);
            cout<< ","<< hex <<signedImm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;

            break;
            
        case 0x20://LB
            cout << "\tLB\t";
            displayReg(rt);
            cout<< ","<< hex << signedImm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x28://SB
            cout << "\tSB\t";
            displayReg(rt);
            cout<< ","<< hex <<signedImm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x21://LH
            cout << "\tLH\t";
            displayReg(rt);
            cout<< ","<< hex <<signedImm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x29://SH
            cout << "\tSH\t";
            displayReg(rt);
            cout<< ","<< hex <<signedImm;
            cout<< "(";
            displayReg(rs);
            cout <<")"<<endl;
            
            break;
            
        case 0x04:
            cout << "\tBEQ\t";
            displayReg(rs);
            cout<< ",";
            displayReg(rt);
            cout<< ", 0x"<< hex <<signedImm<<endl;
            
            break;
            
        case 0x05:
            cout << "\tBNE\t";
            displayReg(rs);
            cout<< ",";
            displayReg(rt);
            cout<< ", "<<dec<<signedImm<<endl;
            
            break;
            
        case 0x0a:
            cout << "\tSLTI\t";
            displayReg(rt);
            cout<< ",";
            displayReg(rs);
            cout<< ","<< hex << signedImm<<endl;
            
            break;
            
        case 0x0f:
            cout << "\tLUI\t";
            displayReg(rt);
            cout<< ","<< hex << signedImm<<endl;
            
            break;


            
        default:
            cout << "\tUnkown I-Format Instruction" << endl;
            
    }
}
bool IFormat::execute ()
{

    switch (opcode)
    {
        case 0x08://ADDI
           
            if(((registers[rs]& 0x80000000)^(signedImm & 0x80000000))){
                // Same sign
                int temp=registers[rs] + signedImm;
                
                if(!((temp&0x80000000)^(registers[rs]&0x80000000)))
                {
                    // sign of result != sign of operands => overflow!
                    cout <<"OVERFLOW"<<endl;
                }
                else
                    registers[rt]=temp;
            }
            else{
                // no overflow (signs are different)
                registers[rt]=registers[rs] + signedImm;
            }
            
            break;
            
        case 0x09://ADDIU
            registers[rt]=registers[rs] + signedImm;
            
            break;
            
        case 0x0c://ANDI
            registers[rt]=registers[rs] & signedImm;
            break;
            
        case 0x0d://ORI
            registers[rt]=registers[rs] | signedImm;
            
            break;
            
        case 0x0e:
            registers[rt]=registers[rs] ^ signedImm;
            
            break;
            
            //REMEMBER THE MEMORY ACCESS PROBLEM
            
        case 0x23://LW
            
            for(int i=0; i<4;i++)
            {
                registers[rt]= registers[rt] | (memory[rs +signedImm - 0x10010000+i]>>(24-8*i)& 0x000000ff);
            }
            
            
            break;
            
        case 0x2b://SW
            
            for(int i=0; i<4;i++)
            {
                memory[rs +signedImm - 0x10010000 +i]= (registers[rt]>>(24-8*i)& 0x000000ff);
                
            }

            
            break;
            
        case 0x20://LB
            registers[rt]= memory[rs +signedImm - 0x10010000];
            
            break;
            
        case 0x28://SB
            memory[rs +signedImm - 0x10010000] = registers[rt];
            
            break;
            
        case 0x21://LH
            
            for(int i=0; i<2;i++)
            {
                registers[rt]= registers[rt] | (memory[rs +signedImm - 0x10010000]>>(24-8*i)& 0x000000ff);
            }

            break;
            
        case 0x29://SH

            break;
            
        case 0x04://BEQ

            if(registers[rt]==registers[rs])
                pc=pc+signedImm;
           
            break;
            
        case 0x05: // BNE
            if(registers[rt]!=registers[rs])
                pc=pc+signedImm;
            
            break;
            
        case 0x0a: //SLTI
            if(registers[rs]<signedImm)
                registers[rt]=1;
            else
                registers[rt]=0;
            
            break;
            
        case 0x0f://LUI

            registers[rt] = imm<<16 |0x0000;
            break;
            
       
            
    }
    
    //for now
    return false;
}















