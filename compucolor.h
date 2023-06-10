#include "gwbasic.h"

typedef struct {
  int opcode;
  char *name;
} gwb_optable;




/* Compucolor BASIC : Source for the tokens http://fileformats.archiveteam.org/wiki/Compucolor_BASIC_tokenized_file */
/* Documentation on the compucolor is available from http://oldcomputers.net/compucolor-ii.html */  
gwb_optable gwb_ops[] = {
0x80,"END",
0x81,"FOR",
0x82,"NEXT",
0x83,"DATA",
0x84,"INPUT",
0x85,"DIM",
0x86,"READ",
0x87,"FILE",
0x88,"GOTO",
0x89,"RUN",
0x8a,"IF",
0x8b,"RESTORE",
0x8c,"GOSUB",
0x8d,"RETURN",
0x8e,"REM",
0x8f,"GET",
0x90,"OUT",
0x91,"PUT",
0x92,"PLOT",
0x93,"SAVE",
0x94,"LOAD",
0x95,"POKE",
0x96,"PRINT",
0x97,"LIST",
0x98,"CONT",
0x99,"CLEAR",
0x9a,"DEF",
0x9F,"FN",
0xae,"SGN",
0xaf,"INT",
0xb0,"ABS",
0xb1,"CALL",
0xb2,"FRE",
0xb3,"INP",
0xb4,"POS",
0xb5,"SQR",
0xb6,"RND",
0xb7,"LOG",
0xb9,"COS",
0xba,"SIN",
0xbb,"TAN",
  0x00, 0
  }; 
