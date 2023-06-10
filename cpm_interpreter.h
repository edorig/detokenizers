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


/* Opcodes for MBASIC on CP/M 80. Deduced from examination of dumps of 
saved BASIC programs and comparison with source listing */ 

gwb_optable gwb_ops[] = {
0x81,"END",
0x82,"FOR",
0x83,"NEXT",
0x84,"DATA",
0x85,"INPUT",
0x86,"DIM",
0x87,"READ",
0x88,"LET",
0x89,"GOTO",
0x8a,"RUN",
0x8b,"IF",
0x8c,"RESTORE",
0x8d,"GOSUB",
0x8e,"RETURN", 
0x8f,"REM",
0x90,"STOP",
0x91,"PRINT",
0x92,"CLEAR",
0x93,"LIST",
0x94,"NEW",
0x95,"ON",
0x96,"NULL",
0x97,"WAIT",
0x98,"DEF",
0x99,"POKE",
0x9a,"CONT",
0x9d,"OUT",
0x9e,"LPRINT",
0x9f,"LLIST",
0xa1,"WIDTH",
0xa2,"ELSE",
0xa3,"TRON",
0xa4,"TROFF",
0xa5,"SWAP",
0xa6,"ERASE",
0xa7,"EDIT",
0xa8,"ERROR",
0xa9,"RESUME",
0xaa,"DELETE",
0xab,"AUTO", 
0xac,"RENUM",
0xad,"DEFSTR",
0xae,"DEFINT",
0xaf,"DEFSNG",
0xb0,"DEFDBL",
0xb1,"LINE",
0xb4,"WHILE",
0xb5,"WEND",
0xb6,"CALL",
0xb7,"WRITE",
0xb8,"COMMON",
0xb9,"CHAIN",
0xba,"OPTION",
0xbb,"RANDOMIZE",
0xbd,"SYSTEM", 
0xbf,"OPEN",
0xc0,"FIELD",
0xc1,"GET",
0xc2,"PUT",
0xc3,"CLOSE",
0xc4,"LOAD",
0xc5,"MERGE",
0xc6,"FILES",
0xc7,"NAME",
0xc8,"KILL",
0xc9,"LSET",
0xca,"RSET",
0xcb,"SAVE",
0xcc,"RESET",
0xce,"TO",
0xcf,"THEN",
0xd0,"TAB(",
0xd2,"USR",
0xd3,"FN",
0xd4,"SPC(",
0xd5,"NOT", 
0xd6,"ERL",
0xd7,"ERR",
0xd8,"STRING$",
0xda,"INSTR",
0xdc,"VARPTR",
0xdd,"INKEY$",
0xef,">",
0xf0,"=",
0xf1,"<",
0xf2,"+", 
0xf3,"-",
0xf4,"*",
0xf5,"/",
0xf6,"^",
0xf7,"AND",
0xf8,"OR",
0xf9,"XOR", 
0xfa,"EQV",  
0xfb,"IMP",
0xfc,"MOD",
0xfd,"\\",     
0x00, 0
  };

/* There is a mysterious opcode b2, and another 7f. opcode b3 seems to stand for DRAW or LINE */ 

gwb_optable gwb_duops[] = {
0x81,"LEFT$",
0x82,"RIGHT$",
0x83,"MID$",
0x84,"SGN",
0x85,"INT",
0x86,"ABS",
0x87,"SQR",
0x88,"RND",
0x89,"SIN",
0x8e,"ATN",
0x8a,"LOG",
0x8b,"EXP",
0x8c,"COS",
0x8d,"TAN",
0x8f,"FRE",
0x90,"INP",
0x91,"POS",
0x92,"LEN",
0x93,"STR$",
0x94,"VAL",
0x95,"ASC",
0x96,"CHR$",
0x97,"PEEK",
0x98,"SPACE$",
0x99,"OCT$",
0x9a,"HEX$",
0x9b,"LPOS",
0x9c,"CINT",
0x9d,"CSNG",
0x9e,"CDBL",
0x9f,"FIX", 
0xab,"CVI",
0xac,"CVS",
0xad,"CVD",
0xaf,"EOF",
0xb0,"LOC",
0xb1,"LOF",
0xb2,"MKI$",
0xb3,"MKS$",
0xb4,"MKD$",
0x00, 0
  };


