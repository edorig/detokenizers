#include "gwbasic.h"

typedef struct {
  int opcode;
  char *name;
} gwb_optable;

/* source for the opcodes: The Sorcerer's Apprentice Vol. 3, no. 4 p. 17 
contains a table translating TRS-80 Model II Basic opcodes to Exidy Sorcerer 
ROM-PAC Basic opcodes. Since keywords corresponding to the opcodes for TRS-80 were available, the table was used to build a table of keywords corresponding to opcodes for the Exidy Sorcerer. The table contained two errors. D0 in place of DD affecting the SQR function, and F8 in place of FA affecting the MID$ function. With these two errors corrected, the opcode for the LOG function remains unknown.  */ 

gwb_optable gwb_ops[] = {
0x80,"END",
0x81,"FOR",
0x82,"NEXT",
0x83,"DATA",
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
0x91,"OUT",
0x92,"ON",
0x96,"POKE",
0x97,"PRINT",
0x9a,"CLEAR",
0x9e,"TAB(",
0x9f,"TO",
0xa0,"FN",
0xa2,"THEN",
0xa3,"NOT",
0xa4,"STEP",
0xa5,"+",
0xa6,"-",
0xa7,"*",
0xa8,"/",
0xac,">",
0xad,"=",
0xae,"<",
0xaf,"SGN",
0xb0,"INT",
0xb1,"ABS",
0xb3,"FRE",
0xb4,"INP",
0xb5,"POS",
0xb6,"SQR",
0xb7,"RANDOM",
0xb8,"RND",
/* 0xdf,"LOG", is missing */ 
0xb9,"EXP",
0xba,"COS",
0xbb,"SIN",
0xbc,"TAN",
0xbd,"ATN",
0xbe,"PEEK",
0xbf,"LEN",
0xc0,"STR$",
0xc1,"VAL",
0xc2,"ASC",
0xc3,"CHR$",
0xc4,"LEFT$",
0xc5,"RIGHT$",
0xc6,"MID$",
0x00, 0
  };
