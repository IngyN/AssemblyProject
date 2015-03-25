//
//  Globals.h
//  AssemblyProject
//
//  Created by Ingy on 3/25/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#ifndef AssemblyProject_Globals_h
#define AssemblyProject_Globals_h

static unsigned int pc;
// Registers
// 32 registers of size 32 bits (4bytes).
int registers [32];

unsigned char memory[8*1024];	// This array represents the data memory available
// only 8KB of data memory
// Starts from address 0x10010000

#endif
