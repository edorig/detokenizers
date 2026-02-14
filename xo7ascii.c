#include <stdio.h> 
int main()
{
  int c,c1,c2;
  int f=0;
  int l=0;  /* Source: Les mystères du X-07 par A. Tonix, E. Arevian, P. Millet p. 89 Fig. 27: Tableau des codes (Club C7, Paris, 1985)  */ 
 static char *keyword[128]={
   "END", "FOR", "NEXT", "DATA", "INPUT", "DIM", "READ", "LET", " GOTO", "RUN",
    "IF", "RESTORE", "GOSUB", "RETURN", "'", "STOP", "ELSE", "TR", "MOTOR",
    "DEFSTR", "DEFINT", "DEFSNG", "DEFDBL", "LINE", "ERROR", "RESUME", "OUT",
    "ON", "LPRINT", "DEF", "POKE", "PRINT", "CONT", "LIST", "LLIST",
    "CLEAR", "CIRCLE", "CONSOLE", "CLS", "COLOR", "EXEC", "LOCATE", "PSET", "PRESET",
    "OFF", "SLEEP ", "DIR", "DELETE ", "FSET", "PAINT", "LOAD", "SAVE", "INIT",
    "ERASE ", "BEEP ", "CLOAD", "CSAVE", "NEW", "TAB(", "TO", "FN", "USING",
    "ERL", "ERR", "STRING$", "INSTR", "INKEY$", "INP", "VARPTR ", "NOT", "STEP",
    "SNS", "ALM$", "DATE$", "TIME$", "START$", "KEY$", "SCREEN", " THEN", "NOT", "STEP", "+", "-",
    "*", "/", "<",
    " AND", " OR", "XOR", "EQV", "¥", "MOD", ">",
    "=", "<", "SGN", "INT", "ABS", "FRE", "POS", "SQR",
    "RND", "LOG", "EXP", "COS", "SIN", "TAN", "ATN", "PEEK","CINT","CSNG","CDBL","FIX","LEN","HEX$","STR$","VAL","ASC","CHR$","TKEY","LEFT$","RIGHT$","MID$","CSRLIN","STICK","STRIG","POINT",""
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
 /*      c1*=0x100; */  
       c1+=getchar()*0x100; 
       printf("%d ",c1);  
       c=getchar(); 
     }
   if (c<0x80 && c>=0x20) {putchar(c);}

     /* Start of a function or junk*/ 
 
  if (c>=0x80) printf("%s ",keyword[c-0x80]);


c=getchar(); 
} 

}
