#include <stdio.h>
#include <stdlib.h> 

int main (int argc, char *argv[])
{
  int z,z1,z2,j,ln,st,r;
  int c[2]; 
  /* Tokens starting with 0x80 */ 

  char *keyword1[] = { "LONG","FOR","COLOR","PLOT","CLS","XELSE","[0x80-06]","NEXT","DATA","INPUT","DIM",
 "READ","[0x80-0c]","GOTO","RUN","IF","RESTORE","GOSUB","RETURN","SYSTEM","ELSE"
,
 "TRON","TROFF","[0x80-17]","DEFINT","DEFSNG","DEFDBL","FILL","SWAP","SOUND","END","[0x80-1f]","ON","OPEN","ROUTE","RATIO","CIRCLE","CLOSE","MACHLG","LOCATE","[0x80-28]","KILL","BOX","RECORD","CALL","MODE","LPRINT","DEF","POKE","PRINT","WRITE","DO","UNTIL","DELAY","[0x80-36]","CLEAR","WHILE","WEND","[0x80-3a]","[0x80-3b]","SELECT","CASE","[0x80-3e]","COORDINATE"};

  
   /* Tokens starting with 0x8a */

  char *keyword2[] = { "TAB","USING","SPC","WORD","TO","THEN","STEP","AND","OR","[0x8a-09]","MOD",
 "REM","'","[0x8a-0d]","[0x8a-0e]","[0x8a-0f]","[0x8a-10]","[0x8a-11]","[0x8a-12]","[0x8a-13]","[0x8a-14]",
 "[0x8a-15]","[0x8a-16]","[0x8a-17]","[0x8a-18]","[0x8a-19]","[0x8a-1a]","[0x8a-1b]","[0x8a-1c]","[0x8a-1d]","[0x8a-1e]","[0x8a-1f]","[0x8a-20]"};

  /* Tokens starting with 0x86 : numeric functions */

 char *keyword3[] = { "[0x86-00]","?LET","LEN","VAL","ASC","SGN","INT","ABS","[0x86-08]","[0x86-09]","SQR",
 "RND","?LOG","?EXP","COS","SIN","?TAN","?ATN","CVI","?CVB","MOUSE",
 "REC","LOC","LOF","[0x86-18]","[0x86-19]","[0x86-1a]","[0x86-1b]","[0x86-1c]","[0x86-1d]","[0x86-1e]","[0x86-1f]","[0x86-20]"};

  /* Tokens starting with 0x82 */

 char *keyword4[] = { "PAGE","[0x82-01]","LINE","FN","USR","ERROR","[0x82-06]","[0x82-07]","[0x82-08]","[0x82-09]","[0x82-0a]",
 "[0x82-0b]","[0x82-0c]","[0x82-0d]","[0x82-0e]","[0x82-0f]","[0x82-10]","[0x82-11]","[0x82-12]","[0x82-13]","[0x82-14]",
 "[0x82-15]","[0x82-16]","[0x82-17]","[0x82-18]","[0x82-19]","[0x82-1a]","[0x82-1b]","[0x82-1c]","[0x82-1d]","[0x82-1e]","[0x82-1f]","[0x82-20]"};

/* Tokens starting with 0x88: String functions */
 /* COMMAND$ is not in the documentation, but it contains the value on the command line */
 
 char *keyword5[] = { "PSTR$","UNS$","[0x88-02]","CHR$","[0x88-04]","[0x88-05]","[0x88-06]","[0x88-07]","STR$","INDEX$","ERRMSG$",
 "TIME$","[0x88-0c]","INKEY$","LEFT$","RIGHT$","MID$","STRING$","SPACE$","UCASE$","COMMAND$",
 "[0x88-15]","[0x88-16]","[0x88-17]","[0x88-18]","[0x88-19]","[0x88-1a]","[0x88-1b]","[0x88-1c]","[0x88-1d]","[0x88-1e]","[0x88-1f]","[0x88-20]"};

  /* Tokens starting with 0x84: they seem to be machine dependent */
 char *keyword6[] = { "VARPTR","INSTR","[0x84-02]","SEG","NOT","[0x84-05]","PEEKWORD","EOF","[0x84-08]","[0x84-09]","[0x84-0a]",
 "[0x84-0b]","[0x84-0c]","CARDTYPE","VARSEG","[0x84-0f]","[0x84-10]","[0x84-11]","[0x84-12]","[0x84-13]","[0x84-14]",
 "[0x84-15]","[0x84-16]","[0x84-17]","[0x84-18]","[0x84-19]","[0x84-1a]","[0x84-1b]","[0x84-1c]","[0x84-1d]","[0x84-1e]","[0x84-1f]","[0x84-20]"};

  
  z=getchar();
  if (z!=0xe4) {
    printf("Not a ZBasic program !");
    exit(0);
  }
  while((z=getchar())!=EOF) {
  z1=getchar();
  z2=getchar();
  ln=z1+256*z2;
  
  if (ln==65535) {
    printf("\n");
    exit(0);
  }
  
  printf("\n %d ",ln);
  st=0; 
  for (j=1;j<=z-2;j++) {
    z1=getchar();
    /* Not a token */
    if (st==7) {
      r--;
      c[r]=z1;
      if (r==0) {
	printf (" %d ",c[1]+256*c[0]);
	st=0;
      }
      if (r<0) {
	/* This should not happen */ 
	printf (" [%d]",c[1]+256*c[0]);
	printf ("Error !");
	st=0;
      }
    }
      
    if ((0x20<=z1) && (z1<0x80) && (st==0) && (j>=4)) putchar(z1);
    /* First part of a token */ 
    if (z1==0x80) st=1;
    if (z1==0x8a) st=2;
    if (z1==0x86) st=3;
    if (z1==0x82) st=4;
    if (z1==0x88) st=5;
    if (z1==0x84) st=6;
    if (z1==0xff) {
      st=7;
      r=2;
    }
    /* second part of a token */ 
    if ((z1<=0x3f) && (st==1)) {printf ("%s ",keyword1[z1]);
    st=0;
  }

    if ((z1<0x20) && (st==2)) {
      printf ("%s ",keyword2[z1]);
      st=0;
  }
    
  if ((z1<0x20) && (st==3)) {
    printf ("%s ",keyword3[z1]);
    st=0;
  }

  if ((z1<0x20) && (st==4)) {
    printf ("%s ",keyword4[z1]);
    st=0;
  }
  if ((z1<0x20) && (st==5)) {
    printf ("%s ",keyword5[z1]);
    st=0;
  }
 if ((z1<0x20) && (st==6)) {
   printf ("%s ",keyword6[z1]);
    st=0;
 }


  }
  
  }
}
