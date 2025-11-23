#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc,char *argv[])
{
  int c,c1,c2,j,z,r;
  int ln; 
  int u[2]; 

  
  /* Tokens preceded by 0x80 */ 
    char *keyword1[] = { "LONG","FOR","COLOR","PLOT","CLS","XELSE","[0x80-06]","NEXT","DATA","INPUT","DIM",
 "READ","[0x80-0c]","GOTO","[0x80-0e]","IF","RESTORE?","GOSUB","RETURN","SYSTEM","ELSE",
 "TRON","[0x80-16]","[0x80-17]","DEFINT","DEFSNG","DEFDBL","FILL","SWAP","SOUND","END","[0x80-1f]","ON","OPEN","ON?","RATIO","CIRCLE","CLOSE","MACHLG","LOCATE","[0x80-28]","KILL","BOX","RECORD","APPEND?","MODE","LPRINT","DEF","POKE","PRINT","WRITE","DO","UNTIL","DELAY","[0x80-36]","CLEAR","WHILE","WEND","[0x80-3a]","[0x80-3b]","SELECT","CASE","[0x80-3e]","COORDINATE"};

   /* Tokens preceded by 0x8a */
 char *keyword2[] = { "TAB","USING","SPC","WORD?","TO","THEN","STEP","AND","OR","[0x8a-09]","MOD",
 "REM","'","[0x8a-0d]","[0x8a-0e]","[0x8a-0f]","[0x8a-10]","[0x8a-11]","[0x8a-12]","[0x8a-13]","[0x8a-14]",
 "[0x8a-15]","[0x8a-16]","[0x8a-17]","[0x8a-18]","[0x8a-19]","[0x8a-1a]","[0x8a-1b]","[0x8a-1c]","[0x8a-1d]","[0x8a-1e]","[0x8a-1f]","[0x8a-20]"};

  /* Tokens preceded by 0x86 : numeric functions */
 char *keyword3[] = { "[0x86-00]","[0x86-01]","LEN","VAL","ASC","SGN","INT","ABS","[0x86-08]","[0x86-09]","SQR",
 "RND","[0x86-0c]","[0x86-0d]","COS","SIN","[0x86-10]","[0x86-11]","CVI","[0x86-13]","MOUSE",
 "REC","LOC","LOF","[0x86-18]","[0x86-19]","[0x86-1a]","[0x86-1b]","[0x86-1c]","[0x86-1d]","[0x86-1e]","[0x86-1f]","[0x86-20]"};
  /* Tokens preceded by 0x82 */
char *keyword4[] = { "PAGE","[0x82-01]","LINE","FN","USR","ERROR","[0x82-06]","[0x82-07]","[0x82-08]","[0x82-09]","[0x82-0a]",
 "[0x82-0b]","[0x82-0c]","[0x82-0d]","[0x82-0e]","[0x82-0f]","[0x82-10]","[0x82-11]","[0x82-12]","[0x82-13]","[0x82-14]",
 "[0x82-15]","[0x82-16]","[0x82-17]","[0x82-18]","[0x82-19]","[0x82-1a]","[0x82-1b]","[0x82-1c]","[0x82-1d]","[0x82-1e]","[0x82-1f]","[0x82-20]"};
 /* Tokens preceded by 0x88: String functions */
 /* CMDLINE$ is not in the documentation, but it contains the value on the command line */ 
 char *keyword5[] = { "PSTR$","?UNS$","[0x88-02]","CHR$","[0x88-04]","[0x88-05]","[0x88-06]","[0x88-07]","STR$","INDEX$","ERRMSG$",
 "TIME$","[0x88-0c]","INKEY$","LEFT$","RIGHT$","MID$","STRING$","?SPACE$","UCASE$","COMMAND$",
 "[0x88-15]","[0x88-16]","[0x88-17]","[0x88-18]","[0x88-19]","[0x88-1a]","[0x88-1b]","[0x88-1c]","[0x88-1d]","[0x88-1e]","[0x88-1f]","[0x88-20]"};
 /* Tokens preceded by 0x84 */
 char *keyword6[] = { "VARPTR","INSTR","[0x84-02]","SEG?","NOT","[0x84-05]","PEEKWORD","EOF","[0x84-08]","[0x84-09]","[0x84-0a]",
 "[0x84-0b]","[0x84-0c]","[0x84-0d]","VARSEG","[0x84-0f]","[0x84-10]","[0x84-11]","[0x84-12]","[0x84-13]","[0x84-14]",
 "[0x84-15]","[0x84-16]","[0x84-17]","[0x84-18]","[0x84-19]","[0x84-1a]","[0x84-1b]","[0x84-1c]","[0x84-1d]","[0x84-1e]","[0x84-1f]","[0x84-20]"};
 
  
  c=getchar();
  if (c!=0xe4) {
    printf ("Not a ZBasic program !");
    exit(0);
  }
  while ((c=getchar())!=EOF)
    {
      /* Read line number */ 
      c1=getchar();
      if (c1==EOF) exit(0); 
      c2=getchar();
       if (c2==EOF) exit(0); 
      printf ("\n%d ",c1+256*c2);
      /* After the line number 0x80 0x00 0x00 */ 
      c1=getchar();
      if (c1==EOF) exit(0); 
      if ((c1!=0x80) && (c1!=0x00))  printf("Error !\n");
      if (c1==0x00) printf("[LABEL] ");
       c1=getchar();
      if (c1!=0x00) printf("Error !\n");
      c1=getchar();
      if (c1!=0x00) printf("Error !\n");
      /* Now advance to the end of the line */ 
      for (j=1;j<=c-5;j++) {
	c1=getchar();
	 if (c1==EOF) exit(0);
	 if (isprint(c1) && (z==0) ) putchar(c1);
	 
	  /* Next two bytes are line number */ 
	 if (z==7) {
	   r--; 
	   u[r]=c1;
	   if (r==0) { 
	     printf(" %d ",256*u[0]+u[1]);
	     z=0;
	     r=0; 
	   }
	 }
	
	   if (c1==0xff) {
	     //	     printf ("[line]"); 
	     z=7;
	     r=2;
	   }
	 /* Two byte keyword */ 
	   if (c1==0x80) z=1;
	   if (c1==0x8a) z=2;
	   if (c1==0x86) z=3;
	   if (c1==0x82) z=4;
	   if (c1==0x88) z=5;
	   if (c1==0x84) z=6;
	   
	   
	   if ((c1<0x40) && (z==1)) {
	     printf("%s ",keyword1[c1]);
	     z=0; 
	   }
      
	   if ((c1<0x21) && (z==2)) {
	     printf ("%s ",keyword2[c1]);
	     z=0;
	   }
	   if ((c1<0x21) && (z==3)) {
	     printf ("%s ",keyword3[c1]);
	     z=0;
	   }

	   if ((c1<0x21) && (z==4)) {
	     printf ("%s ",keyword4[c1]);
	     z=0;
	   }
	   if ((c1<0x21) && (z==5)) {
	     printf ("%s ",keyword5[c1]);
	     z=0;
	   }
	   if ((c1<0x21) && (z==6)) {
	     printf ("%s ",keyword6[c1]);
	     z=0;
	   }
      }
    }
  return(0); 
}
