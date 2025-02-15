/* 
   Copyright (C) 1994,1995 Free Software Foundation, Inc.
   Written by Christian A. Ratliff

   This file is part of the gwbasic translator.

   The gwbasic translator is free software; you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 1, or
   (at your option) any later version.

   The gwbasic translator is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with gwb; see the file COPYING.  If not, write to the Free
   Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
*/
/*
 * $Id: gwb_interpreter.h,v 1.2 1995/02/10 13:41:10 ratlifc Exp $
 */

#include "gwbasic.h"

typedef struct {
  int opcode;
  char *name;
} gwb_optable;

/* With some improvements using  extra info on GW-BASIC tokenised program format. */ 

gwb_optable gwb_ops[] = {
  0x81, "END",
  0x82, "FOR",
  0x83, "NEXT",
  0x84, "DATA",
  0x85, "INPUT",
  0x86, "DIM",
  0x87, "READ",
  0x88, "LET", 
  0x89, "GOTO",
  0x8a, "RUN", 
  0x8b, "IF",
  0x8c, "RESTORE", 
  0x8d, "GOSUB",
  0x8e, "RETURN",
  0x8f, "REM",
  0x90, "STOP",  
  0x91, "PRINT", 
  0x92, "LEN", /* Some doc. mentions CLEAR instead */ 
  0x93, "LIST", 
  0x94, "NEW", 
  0x95, "ON",
  0x96, "WAIT", 
  0x97, "DEF",
  0x98, "POKE", 
  0x99, "CONT",
  0x9c, "OUT", 
  0x9d, "LPRINT",
  0x9e, "LLIST", 
  0xa0, "WIDTH",
  0xa1, "ELSE",
  0xa2, "TRON", 
  0xa3, "TROFF", 
  0xa4, "SWAP", 
  0xa5, "ERASE", 
  0xa6, "EDIT", 
  0xa7, "ERROR",
  0xa8, "RESUME", 
  0xa9, "DELETE", 
  0xaa, "AUTO", 
  0xab, "RENUM",  
  0xac, "DEFSTR", 
  0xad, "DEFINT", 
  0xae, "DEFSNG", 
  0xaf, "DEFDBL", 
  0xb0, "LINE", 
  0xb1, "WHILE", 
  0xb2, "WEND", 
  0xb3, "CALL", 
  0xb7, "WRITE", 
  0xb8, "OPTION", 
  0xb9, "RANDOMIZE",
  0xba, "OPEN", 
  0xbb, "CLOSE", 
  0xbf, "COLOR",
  0xbc, "LOAD",
  0xbd, "MERGE", 
  0xbe, "SAVE", 
  0xbf, "COLOR", 
  0xc0, "CLS",
  0xc1, "MOTOR", 
  0xc2, "BSAVE",
  0xc3, "BLOAD", 
  0xc4, "SOUND", 
  0xc5, "BEEP", 
  0xc6, "PSET", 
  0xc7, "PRESET", 
  0xc8, "SCREEN",
  0xc9, "KEY",
  0xca, "LOCATE",
  0xcc, "TO",
  0xcd, "THEN",
  0xce, "TAB(",
  0xcf, "STEP",
  0xd0, "USR", 
  0xd1, "FN", 
  0xd2, "SPC(", 
  0xd3, "NOT", 
  0xd4, "ERL", 
  0xd5, "ERR", 
  0xd6, "STRING$",
  0xd7, "USING", 
  0xd8, "INSTR", 
  0xd9, "'", 
  0xda, "VARPTR", 
  0xdb, "CSRLIN",  
  0xdc, "POINT",
  0xdd, "OFF",
  0xde, "INKEY$",
  0xe6, ">",
  0xe7, "=",
  0xe8, "<",
  0xe9, "+",
  0xea, "-",
  0xeb, "*",
  0xec, "/",
  0xed, "^",
  0xee, "AND",
  0xef, "OR",
  0xf0, "XOR",
  0xf1, "IMP",
  0xf2, "IMP",
  0xf3, "MOD",
  0xf4, "\\", 
  0xfe, "TIMER",
  0xff, " DUOP ",
  0x00, 0
  };

/* 2bytes tokens beginning 0xfd */ 
gwb_optable gwb_duopsd[]= {
  0x81, "CVI", 
  0x82, "CVS",
  0x84, "MKI$",
  0x85, "MKS$",
  0x86, "MKD$", 
  0x8b, "EXTERR",   
  0x00, 0
  };  

/* 2bytes token beginning 0xfe */ 

gwb_optable gwb_duopse[]= {
  0x81, "FILES",
  0x82, "FIELD",
  0x83, "SYSTEM", 
  0x84, "NAME",
  0x85, "LSET", 
  0x86, "RSET",
  0x87, "KILL",
  0x88, "PUT",
  0x89, "GET",
  0x8a, "RESET",
  0x8b, "COMMON",
  0x8c, "CHAIN",
  0x8d, "DATE$",
  0x8e, "TIME$",
  0x8f, "PAINT",
  0x90, "COM",
  0x91, "CIRCLE",
  0x92, "DRAW",
  0x93, "PLAY",
  0x94, "TIMER",
  0x95, "ERDEV",
  0x96, "IOCTL",
  0x97, "CHDIR",
  0x98, "MKDIR",
  0x99, "RMDIR",
  0x9a, "SHELL",
  0x9b, "ENVIRON", 
  0x9c, "VIEW", 
  0x9d, "WINDOW", 
  0x9e, "PMAP", 
  0x9f, "PALETTE",
  0xa0, "LCOPY",
  0xa1, "CALLS",
  0xa4, "NOISE", /* For IBM PC Jr */ 
  0xa5, "PCOPY", /* For IBM PC Jr or EGA system */ 
  0xa6, "TERM", /* For IBM PC Jr */ 
  0xa7, "LOCK", 
  0xa8, "UNLOCK",
  0x00, 0
}; 

/* 2bytes token beginning 0xff */ 
gwb_optable gwb_duops[] = {
  0x81, "LEFT$", 
  0x82, "RIGHT$", 
  0x83, "MID$",
  0x84, "SGN", 
  0x85, "INT",
  0x86, "ABS",
  0x87, "SQR",
  0x88, "RND",
  0x89, "SIN",
  0x8a, "LOG",
  0x8b, "EXP", 
  0x8c, "COS", 
  0x8d, "TAN", 
  0x8e, "ATN", 
  0x8f, "FRE", 
  0x90, "INP", 
  0x91, "POS", 
  0x92, "LEN",
  0x93, "STR$",
  0x94, "VAL", 
  0x95, "ASC",
  0x96, "CHR$",
  0x97, "PEEK",
  0x98, "SPACE$",
  0x99, "OCT$",
  0x9a, "HEX$",
  0x9b, "LPOS", 
  0x9c, "CINT",
  0x9d, "CSNG",
  0x9e, "CDBL",
  0x9f, "FIX",
  0xa0, "PEN",
  0xa1, "STICK",
  0xa2, "STRIG", 
  0xa3, "EOF",
  0xa4, "LOC", 
  0xa5, "LOF", 
  0x00, 0
  };



/*
 * $Log: gwb_interpreter.h,v $
 * Revision 1.2  1995/02/10  13:41:10  ratlifc
 * moved header elements to global gwbasic.h header
 *
 * Revision 1.1  1995/02/08  23:06:35  ratlifc
 * initial transfer to gwbasic 2.0
 *
 */

