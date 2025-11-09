#include <stdio.h> 
int main()
{
  int c,c1,c2;
  int f=0;
  int l=0; 
 static char *keyword[128]={
   "END", "FOR", "NEXT", "DATA", "DIM", "READ", "LET", "GO", "RUN", "IF",
    "RESTORE", "RETURN", "REM", "'", "STOP", "ELSE", "TRON", "TROFF", "DEFSTR",
    "DEFINT", "DEFSNG", "DEFDBL", "ON", "WAIT", "ERROR", "RESUME", "AUTO",
    "DELETE", "LOCATE", "CLS", "CONSOLE", "PSET", "MOTOR", "SKIP", "EXEC",
    "BEEP", "COLOR", "LINE", "BOX", "UNMASK", "ATTRB", "DEF", "POKE", "PRINT",
    "CONT", "LIST ", "CLEAR", "WHILE ", "WHEN", "NEW", "SAVE", "LOAD", "MERGE",
    "OPEN", "CLOSE ", "INPEN", "PEN", "PLAY", "TAB(", "TO", "SUB", "FN",
    "SPC(", "USING", "USR", "ERL", "ERR", "OFF", "THEN ", "NOT", "STEP",
    "+", "-", "*", "/", "^", "AND", "OR", "XOR", "EQV", "IMP", "MOD", "@",
    ">", "=", "<",
    /* DOS specific */
    "DSKINI", "DSKO$", "KILL", "NAME", "FIELD", "LSET", "RSET",
    "PUT", "GET", "VERIFY", "DEVICE", "DIR", "FILES", "WRITE", "UNLOAD",
    "BACKUP", "COPY", "CIRCLE", "PAINT", "DRAW", "RENUM", "SWAP", "DENSITY"
 };
 
 static char *func[128]=
   { /* functions: 0xff prefix */
     "SGN", "INT", "ABS", "FRE", "SQR", "LOG", "EXP", "COS", "SIN",
     "TAN", "PEEK", "LEN", "STR$", "VAL", "ASC", "CHR$", "EOF", "CINT", "CSNG",
     "CDBL", "FIX", "HEX$", "OCT$", "STICK", "STRIG", "GR$", "LEFT$", "RIGHT$",
     "MID$", "INSTR", "VARPTR", "RND", "INKEY$", "INPUT", "CSRLIN", "POINT",
     "SCREEN", "POS", "PTRIG",
     /* DOS specific */
     "DSKL", "CVI", "CVS", "CVD", "MKI$", "MKS$", "MKD$", "LOC", "LOF",
     "SPACE$", "STRING$", "DSKI$"
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

     /* Start of a function or junk*/ 
     if (c==0xff) {f=1;} 
  if (c>=0x80) {
    if (!f) {
      printf("%s ",keyword[c-0x80]);
    } else if (c!=0xff ) {
      printf("%s",func[c-0x80]);
      f=0;
    }
  }
  if (c==0x01 && f==1) {
  /* 10 ff followed by 01 3c 01 ff : ignore */ 
  c1=getchar();
  c1=getchar();
  c1=getchar(); 
  f=0; 
  }   
c=getchar(); 
} 

}
