/* 
   Copyright (C) 1994,1995,2011 Free Software Foundation, Inc.
   Originally written by Christian A. Ratliff for GWBasic
   Conversion to MSX-Basic by Edmond Orignac (2011) 
   This file is part of the msxbasic translator.

   The msxbasic translator is free software; you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 1, or
   (at your option) any later version.

   The msxbasic translator is distributed in the hope that it will be
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

/* source for the opcodes: MSX 2 - Handboek
   Voor de gevorderde MSX 2 by Erik Schaut 1-3-1994 (in Dutch) */ 

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
0x96,"WAIT",
0x97,"DEF",
0x98,"POKE",
0x99,"CONT",
0x9a,"CSAVE",
0x9b,"CLOAD",
0x9c,"OUT",
0x9d,"LPRINT",
0x9e,"LLIST",
0x9f,"CLS",
0xa0,"WIDTH",
0xa1,"ELSE",
0xa2,"TRON",
0xa3,"TROFF",
0xa4,"SWAP",
0xa5,"ERASE",
0xa6,"ERROR",
0xa7,"RESUME",
0xa8,"DELETE",
0xa9,"AUTO",
0xaa,"RENUM",
0xab,"DEFSTR",
0xac,"DEFINT",
0xad,"DEFSNG",
0xae,"DEFDBL",
0xaf,"LINE",
0xb0,"OPEN",
0xb1,"FIELD",
0xb2,"GET",
0xb3,"PUT",
0xb4,"CLOSE",
0xb5,"LOAD",
0xb6,"MERGE",
0xb7,"FILES",
0xb8,"LSET",
0xb9,"RSET",
0xba,"SAVE",
0xbb,"LFILES",
0xbc,"CIRCLE",
0xbd,"COLOR",
0xbe,"DRAW",
0xbf,"PAINT",
0xc0,"BEEP",
0xc1,"PLAY",
0xc2,"PSET",
0xc3,"PRESET",
0xc4,"SOUND",
0xc5,"SCREEN",
0xc6,"VPOKE",
0xc7,"SPRITE",
0xc8,"VDP",
0xc9,"BASE",
0xca,"CALL",
0xcb,"TIME",
0xcc,"KEY",
0xcd,"MAX",
0xce,"MOTOR",
0xcf,"BLOAD",
0xd0,"BSAVE",
0xd1,"DSKO$",
0xd2,"SET",
0xd3,"NAME",
0xd4,"KILL",
0xd5,"IPL",
0xd6,"COPY",
0xd7,"CMD",
0xd8,"LOCATE",
0xd9,"TO",
0xda,"THEN",
0xdb,"TAB(",
0xdc,"STEP",
0xdd,"USR",
0xde,"FN",
0xdf,"SPC(",
0xe0,"NOT",
0xe1,"ERL",
0xe2,"ERR",
0xe3,"STRING$",
0xe4,"USING",
0xe5,"INSTR",
0xe4,"USING",
0xe5,"INSTR",
0xe6,"'",
0xe7,"VARPTR",
0xe8,"CSRLIN",
0xe9,"ATTR$",
0xea,"DSKI$",
0xeb,"OFF",
0xec,"INKEY$",
0xed,"POINT",
0xee,">",
0xef,"=",
0xf0,"<",
0xf1,"+",
0xf2,"-",
0xf3,"*",
0xf4,"/",
0xf5,"^",
0xf6,"AND",
0xf7,"OR",
0xf8,"XOR",
0xf9,"EQV",
0xfa,"IMP",
0xfb,"MOD",
0xfc,"\\",
  0x00, 0
  };

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
0x8a,"LOG",
0x8b,"EXP",
0x8c,"COS",
0x8d,"TAN",
0x8e,"ATN",
0x8f,"FRE",
0x90,"INP",
0x91,"POS",
0x92,"LEN",
0x93,"STR$",
0x94,"VAL",
0x95,"ASC",
0x96,"CHR$",
0x97,"PEEK",
0x98,"VPEEK",
0x99,"SPACE$",
0x9a,"OCT$",
0x9b,"HEX$",
0x9c,"LPOS",
0x9d,"BIN$",
0x9e,"CINT",
0x9f,"CSNG",
0xa0,"CDBL",
0xa1,"FIX",
0xa2,"STICK",
0xa3,"STRIG",
0xa4,"PDL",
0xa5,"PAD",
0xa6,"DSKF",
0xa7,"FPOS",
0xa8,"CVI",
0xa9,"CVS",
0xaa,"CVD",
0xab,"EOF",
0xac,"LOC",
0xad,"LOF",
0xae,"MKI$",
0xaf,"MKS$",
0xb0,"MKD$",
  0x00, 0
  };



/*
 * $Log: gwb_interpreter.h,v $
 * Revision 1.2  1995/02/10  13:41:10  ratlifc
 * moved header elements to global msxbasic.h header
 *
 * Revision 1.1  1995/02/08  23:06:35  ratlifc
 * initial transfer to msxbasic 2.0
 *
 */

