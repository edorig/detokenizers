/* 
   Copyright (C) 1994,1995,1996 Free Software Foundation, Inc.
   Written by Christian A. Ratliff
   Modified for Exidy Sorcerer ROM-PAC Basic by Edmond Orignac 

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
 * $Id: gwb_interpreter.c,v 1.3 1996/01/09 03:39:05 ratlifc Exp $
 */


#include "exidy.h"

float gi_power(float value, int expo)
{
  float f = 1.0;

  if (expo == 0) return 1.0;
  if (expo < 0) {
    for (; expo++; f = f * value);
    f = 1/f;
  } else {
    for (; expo--; f = f * value);
  }
  return (float)f;
}

char *gi_binary(int byte, char *buf)
{
  int x = 7, y = 0;

  for (; x > -1; x--) {
    if (y == 4) {
      buf[y++] = ' ';
    }
    buf[y++] = (((byte) & (1 << x)) ? '1' : '0');
  }
  buf[10] = '\0';
  return (char *)buf;
}

char *gi_futz_byte(const u_char op, gwb_optable gop[])
{
  static char buf[BUFSIZ];
  int x = 0,
      idx = 0;
  bzero(buf, BUFSIZ);

  /* if this is a normal printable ASCII character then display it */
  if (op >= 0x20 && op < 0x7F) {
    buf[x++] = op;
  } else {
    for (idx = 0; gop[idx].opcode && gop[idx].opcode != op; ++idx);
    if (!gop[idx].opcode) {
      if (op < 0x1b) x += sprintf(&buf[x], "%d", (op - 0x11));
      else x += sprintf(&buf[x], " [opcode %x] ", op);
    } else {
      x += sprintf(&buf[x], "%s", gop[idx].name);
    }
  }
  return (char *)buf;
}



char *gi_show(FILE *fp)
{
  u_char b;
  u_char buf[BUFSIZ];
  int x = 0;

  memset(buf, 0, BUFSIZ);
  
  for (b = fgetc(fp); !feof(fp); b = fgetc(fp)) {

    if (feof(fp)) return (char *)NULL;
      
    switch (b) {
    case 0x00: { /* the end of an instruction */
      u_char *tmp = (char *)malloc((strlen(buf) * sizeof(char)) + 2);
      strcpy(tmp, buf);
      return (char *)tmp;
      break;
    }
    case 0x0e: /* a number designator, used for GOTO and GOSUB */
      x += sprintf(&buf[x], "%d", (fgetc(fp) | (fgetc(fp) << 8)));
      break;
    case 0xf:
      x += sprintf(&buf[x], "%d", fgetc(fp));
      break;
    case 0x1c:
      /*    case 0x1d: */ 
      x += sprintf(&buf[x], "%d", (fgetc(fp) | (fgetc(fp) << 8)));
      break;
      /*    case 0x30:
	    x += sprintf(&buf[x], "%s", gi_futz_byte(fgetc(fp), gwb_duops)); */  
    case '(': 
    case 0xa5:/*    + sign */ 
    case 0xa6:/*    - sign */  
    case 0xa7:/*    * sign */
    case 0xa8:/*    / sign  */ 
    case 0xad: { /* = sign; this is a numeric operation, try to read a number */
      int c;
      if ((c = fgetc(fp)) > 0x80) {
	ungetc(c, fp);
	x += sprintf(&buf[x], "%s", gi_futz_byte(b, gwb_ops));
      } else {

	switch (c) {
	case '\"':
	  x += sprintf(&buf[x], "%s%c%c", gi_futz_byte(b, gwb_ops), c,
		       fgetc(fp));
	  break;
	case 0xc: {
	  int hw1 = fgetc(fp),
	      hw2 = fgetc(fp);
	  x += sprintf(&buf[x], "%s&H%2.2X%2.2X", gi_futz_byte(b, gwb_ops),
		       hw2, hw1);
	}
	  break;

	case 0xf:
	  x += sprintf(&buf[x], "%s%d", gi_futz_byte(b, gwb_ops), fgetc(fp));
	  break;

	case 0x1c:
	case 0x1d:
	case 0x1f:
	  {
	    int hw1 = fgetc(fp),
                hw2 = fgetc(fp),
	        hw3 = fgetc(fp),
	        hw4 = fgetc(fp);

	    if (c != 0x1f) {
	      float f1 = 0.0, f2 = 0.0, f = 0.0;
	      
	      f1 = (float)(((float)hw2 * (float)gi_power(2.0, -15)) +
			   ((float)hw1 * (float)gi_power(2.0, -23)) +
			   ((float)hw3 * (float)gi_power(2.0, -7)) + 1.0);
	      f2 = (float)gi_power(2.0, (hw4 - 129));
	      
	      x += sprintf(&buf[x], "%s%2.7G", gi_futz_byte(b, gwb_ops),
			   (f1*f2));
	    } else {
	      double f1=0.0, f2=0.0;
	      int hw5=fgetc(fp),
		hw6 = fgetc(fp),
	        hw7 = fgetc(fp),
	        hw8 = fgetc(fp);
	      f1 = (double)(((double)hw1 *(double)gi_power(2.0, -55)) +
			    ((double)hw2 *(double)gi_power(2.0, -47)) +
			    ((double)hw3 *(double)gi_power(2.0, -38)) +
			    ((double)hw4 *(double)gi_power(2.0, -31)) +
			    ((double)hw6 * (double)gi_power(2.0, -15)) +
			    ((double)hw5 * (double)gi_power(2.0, -23)) +
			    ((double)hw7 * (double)gi_power(2.0, -7)) + 1.0);
	      f2 = (double)gi_power(2.0, (hw8 - 129));

	      x += sprintf(&buf[x], "%s %2.16G",gi_futz_byte(b, gwb_ops),
			   (f1*f2));
	    }
	  }
	  break;

	default:
	  if (c > 0x1F)
	    x += sprintf(&buf[x], "%s%c", gi_futz_byte(b, gwb_ops), c);
	  else
	    x += sprintf(&buf[x], "%s%d", gi_futz_byte(b, gwb_ops), (c-0x11));
	}
      }
    }
      break;
    case 0x94: /* the second part of the timer opcode */
      break;

      /*     case 0xff:  a dual opcode thang  (not possible on TRS-80 Model II Basic) 
      x += sprintf(&buf[x], "%s", gi_futz_byte(fgetc(fp), gwb_duops));
      break;  */ 

    default:
      x += sprintf(&buf[x], "%s", gi_futz_byte(b, gwb_ops));
    }
  }
  if (*buf) {
    u_char *tmp = (char *)malloc((strlen(buf) * sizeof(char)) + 2);
    strcpy(tmp, buf);
    return (char *)tmp;
  } else {
    (void)fprintf(stderr, "WARNING: gi_show() exit without return\n");
    return (char *)NULL;
  }
}


Line *gi_parse(FILE *fp)
{
  u_int cb[4] = {0, 0, 0, 0},  /* the four 'control bytes' */
        lineno = 0;
  u_char *line;


  /* first read off the four 'control bytes' and build the line number */
  cb[0] = fgetc(fp); cb[1] = fgetc(fp); cb[2] = fgetc(fp); cb[3] = fgetc(fp);
  lineno = (cb[2] | (cb[3] << 8));

  /* read in the bytes until we get an EOF or the end of the instruction */
  if ((line = gi_show(fp))) {
    Line *ln = (Line *)malloc(sizeof(Line));
    gwb_dprintf("made it past first malloc(%d)", sizeof(Line));
#if 0
    gwb_dprintf("entering second malloc(%d)", strlen(line)+2);
    ln->l_str = (char *)malloc((strlen(line) + 2) * sizeof(char));
    gwb_dprintf("made it past second malloc(%d)", strlen(line)+2);
    (void)strcpy(ln->l_str, line);
#endif
    ln->l_str = line;       /* line was malloc'ed by gi_show() */
    ln->l_num = lineno;
    ln->l_flag.loaded = 1;
    ln->l_flag.update = 0;

    return (Line *)ln;
  } else {
    return (Line *)NULL;
  }
}

Program *gi_open(const char *fname)
{
  FILE *bprog;
  Program *p = (Program *)malloc(sizeof(Program)),
          *head = p;
  Line *l;

  gwb_dprintf("Made it to gi_open(\"%s\")", fname);

  p->next = p->prev = (Program *)NULL;
  p->line = (Line *)NULL;

  if (!(bprog = fopen(fname, "r"))) {
    perror("gwbasic");
    free(p);
    return (Program *)NULL;
  }

  if (fgetc(bprog) != 0xff) {
    printf("gwbasic: failed to find gwbasic magic cookie\n");
    fclose(bprog);
    free(p);
    return (Program *)NULL;
  }

  while ((l = gi_parse(bprog)) != (Line *)NULL) {
    p->next = (Program *)malloc(sizeof(Program));
    p->next->line = l;
    p->next->prev = p;
    p = p->next;
  }
  p->next = (Program *)NULL;

  return (Program *)head;
}
 


/*
 * $Log: gwb_interpreter.c,v $
 * Revision 1.3  1996/01/09  03:39:05  ratlifc
 * Switched a whole mess of char's to u_char's (SGI defaults different than
 * BSDI does); BSDI's gcc pukes on returned static autos; Trap an early
 * dropout condition in gi_parse()
 *
 * Revision 1.2  1995/02/10  15:46:14  ratlifc
 * changed interpreter to use new Program and Line structures
 *
 * Revision 1.1  1995/02/09  13:58:32  ratlifc
 * initial release of 2.0a
 *
 */

