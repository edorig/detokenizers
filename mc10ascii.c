#include <stdio.h> 
int main()
{
  int c,c1,c2;
  int f=0;
  int l=0;
  /* The list of keywords is complete. Sources: 
https://colorcomputerarchive.com/repo/MC-10/Documents/Manuals/Hardware/MC-10%20Operation%20and%20Language%20Reference%20Manual%20(Web)/toc.htm
http://alice32.free.fr/documentation/index.html [ROM Alice 32 Commentée par SEILEBOST]
  */ 
 static char *keyword[128]={
   "FOR", "GOTO", "GOSUB", "REM", "IF", "DATA", "PRINT", "ON", "INPUT", "END",
    "NEXT", "DIM", "READ", "LET", "RUN", "RESTORE", "RETURN", "STOP", "POKE",
    "CONT", "LIST", "CLEAR", "NEW", "CLOAD", "CSAVE", "LLIST", "LPRINT",
    "SET", "RESET", "CLS", "SOUND", "EXEC", "SKIPF", "TAB", "TO",
    " THEN", "NOT", "STEP", "OFF", "+", "-", "*", "/", "^",
    "AND", "OR ", ">", "=", "<", "SGN", "INT", "ABS", "USR",
    "RND", "SQR", "LOG", "EXP", "SIN", "COS", "TAN", "PEEK", "LEN",
    "STR$", "VAL", "ASC", "CHR$", "LEFT$", "RIGHT$", "MID$ ", "POINT", "STEP",
    "INKEY$", "MEM", "$C9", "$CA", "$CB", "$CC", "$CD", "$CE", "$CF", "$D0", "$D1", "$D2",
    "$D3", "$D4", "$D5"
    };
    
 
 
   
 c=getchar(); 
 while (c!=EOF) {
   /* Line number */ 

   /* End of line, 2 byte junk then line number */ 
     if (c==0) {
       putchar('\n');
       c=getchar();
       c=getchar();
       c1=getchar();
       c1*=0x100; 
       c1+=getchar(); 
       printf("%d ",c1);  
       c=getchar(); 
     }
   if (c<0x80 && c>=0x20) {putchar(c);}

     
  if (c>=0x80) {
      printf("%s",keyword[c-0x80]);
  }
  
  
c=getchar(); 
} 

}
