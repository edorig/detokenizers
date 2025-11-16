#include <stdio.h>
 #include <stdlib.h>
int main()
{
  
  int c1,c2,j,ln=0,ll[2],il;
    /* The list of keywords is not complete. Obtained from tokenized programs. 
  keywords preceded by a question mark are guesses bases on the keyword order in
 the MS-DOS version of zbasic
  */ 
 
static char *keyword[128]={ "LONG", "FOR", "COLOR", "PLOT", "CLS", "XELSE", "$86", "NEXT",
    "DATA", "INPUT", "DIM", "READ", "$8C", "GOTO", "$8E", "IF", "RESTORE",
    "GOSUB", "RETURN", "REM", "STOP", "ELSE", "TRON ", "TROFF", "$98",
    "DEFINT", "DEFSNG", "DEFDBL", "FILL", "SWAP", "SOUND", "END", "$A0",
    "ON", "OPEN", "ROUTE", "$A4", "$A5", "CLOSE", "MACHLG", "LOCATE", "$A9",
    "$AA", "BOX", "$AC", "CALL", "MODE", "LPRINT ", "DEF", "POKE", "PRINT ",
    "$B3", "DO", "UNTIL", "$B6", "$B7", "?CLEAR", "WHILE", "WEND", "PAGE",
    "$BC", "LINE", "FN", "USR", "$C0", "VARPTR", "INSTR", "POINT", "$C4",
    "NOT", "$C6", "PEEK", "?TAB", "USING", "SPC", "WORD", "TO", "THEN", "STEP", "AND", "OR",
    "$D1", "$D2", "$D3", "$D4",
    "LEN", "VAL", "ASC", "SGN", "INT", "ABS", "$DB", "$DC", "SQR",
     "RND","LOG", "EXP", "COS", "SIN", "TAN", "ATN", "$E5", "$E6",
    "MOUSE", "$E8", "$E9", "$EA", "PSTR$", "$EC", "$ED",
     "CHR$","?HEX$", "$F0", "$F1", "UNS$", "STR$", "INDEX$", "$F5", "TIME$",
     "DATE$", "INKEY$", "LEFT$", "RIGHT$", "MID$", "STRING$", "?SPACE$","UCASE$","[line no.] "
    };
 c1=0;
 il=0; 
  while ((c1!=EOF) && (ln<65535)) {
    c1=getchar();
    c2=getchar();
    ln=256*c2+c1; 
    printf("\n%d ",ln);
    if (ln==65535) {
      printf(" END\n");
      exit(0);
    }
    c1=getchar();
    if ((c1!=EOF) && (ln<65535)) {
      /*     printf("%d bytes\n",c1); */ 
      for (j=1;j<=c1-1;j++) {
	c2=getchar();
	if (c2==EOF) exit(0); 
	if ((c2<0x80) && (c2>=0x20) && (il==0)) {putchar(c2);}

	if ((c2>=0x80) && (c2<0xff) &&(il==0)) {
      printf("%s",keyword[c2-0x80]);
	}
	
	if (il>0) {
	  ll[il-1]=c2;
	  il--;
	  if (il==0) printf(" %d ",256*ll[0]+ll[1]);
	}
	if ((c2==0xff) && (il==0)) il=2;
      }
    }
  }
  return(0); 
}
