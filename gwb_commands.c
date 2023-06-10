/* 
   Copyright (C) 1994,1996 Free Software Foundation, Inc.
   Written by Christian A. Ratliff

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
 * $Id: gwb_commands.c,v 1.3 1996/01/09 03:35:27 ratlifc Exp $
 */

#include "gwbasic.h"
#include "gwb_commands.h"

static Program *ge_prog;


int ge_credits(char *buf)
{
  printf("Modular Unix BASIC\n");
  printf("\nWritten by Christian A. Ratliff <ratlifc@ctron.com>\n");
  printf("Floating Point Format by Matt Nelson <nelsonm@ctron.com>\n");
  printf("Name and Testing by Erik Barstow <ebarstow@ctron.com>\n");
  printf("\nbased on Microsoft GW-BASIC 3.23\n");
  printf("(c) Copyright Microsoft 1983,1984,1985,1986,1987,1988\n");

  return 1;
}

int ge_help(char *buf)
{
  int x = 0;

  if (!*buf) {
    printf("-- %s --\n", gwb_help[x++]);
    for (; *gwb_help[x]; x++)
      printf("\t%s\n", gwb_help[x]);
    return 1;
  }

  for (; strcmp(gwb_help[x], "--END--") ; x++) {
    if (!strcasecmp(gwb_help[x], buf)) {

      printf("-- %s --\n", gwb_help[x++]);
      for (; *gwb_help[x]; x++)
	printf("\t%s\n", gwb_help[x]);
      return 1;
    }
  }

}

int ge_version(char *buf)
{
  printf("Modular Unix BASIC, version %s\n", GE_VERSION);
  return 1;
}

int ge_system(char *buf)
{
  return 0;
}

int ge_run(char *buf)
{
  if (!ge_prog) printf("LOAD a BASIC program first\n");
  else gx_process(ge_prog);

  return 1;
}

int ge_load(char *buf)
{
  char fname[BUFSIZ];

  bzero(fname, BUFSIZ);

  if (sscanf(buf, "\"%[^\"]s\"", fname) == 1) {
    int len = strlen(buf);

    ge_new("");
    ge_prog = (Program *)gi_open(fname);
    if (buf[len-2] == ',' && (buf[len-1] == 'r' || buf[len-1] == 'R')) {
      ge_run("");
    }
  } else {
    printf("Syntax Error\n");
  }
  return 1;
}

int ge_list(char *buf)
{
  int start = 0, end = 0;
  char dev[BUFSIZ];
  FILE *output = stdout;

  bzero(dev, BUFSIZ);

  if (buf && *buf) {
    int ret = sscanf(buf, "%d-%d,%s", &start, &end, dev);

    if (!ret && *buf == ',') strcpy(dev, &buf[1]);

    if (*dev) {
      if (!strcasecmp(dev, "prn")) {
	printf("Output to PRN is not supported\n");
	return 1;
      }
      if (!(output = fopen(dev, "w"))) {
	perror("gwbasic");
	return 1;
      }
    }
  }

  if (ge_prog) {
    Program *p = ge_prog->next;
    for (; p; p = p->next) {
      if (start || end) {
	if (p->line->l_num >= start && p->line->l_num <= end)
	  (void)fprintf(output, "%d %s\n", p->line->l_num, p->line->l_str);
	else 
	  if (!end && start == p->line->l_num)
	    (void)fprintf(output, "%d %s\n", p->line->l_num, p->line->l_str);
      } else {
	(void)fprintf(output, "%d %s\n", p->line->l_num, p->line->l_str);
      }
    }
  }

  if (output != stdout) fclose(output);

  return 1;
}


int ge_change(int line, char *code)
{
  Program *p;

  if (!ge_prog) {
    Program *pn = (Program *)malloc(sizeof(Program));
    pn->line = (Line *)malloc(sizeof(Line));
    pn->line->l_str = (char *)malloc((strlen(code)+2)*sizeof(char));
    ge_prog = (Program *)malloc(sizeof(Program));
    ge_prog->line = (Line *)NULL;
    ge_prog->next = pn;
    ge_prog->prev = (Program *)NULL;
    
    pn->line->l_num = line;
    (void)strcpy(pn->line->l_str, code);
    pn->line->l_flag.loaded = pn->line->l_flag.update = 0;
    pn->next = (Program *)NULL;
    pn->prev = ge_prog;
  } else if (!ge_prog->next) {
    Program *pn = (Program *)malloc(sizeof(Program));
    pn->line = (Line *)malloc(sizeof(Line));
    pn->line->l_str = (char *)malloc((strlen(code)+2)*sizeof(char));
    ge_prog->next = pn;

    pn->line->l_num = line;
    (void)strcpy(pn->line->l_str, code);
    pn->line->l_flag.loaded = pn->line->l_flag.update = 0;
    pn->next = (Program *)NULL;
    pn->prev = ge_prog;
  } else {
    for (p = ge_prog->next; p; p = p->next) {
      if (p->line) {
	if (p->line->l_num == line) {
	  free(p->line->l_str);
	  p->line->l_str = (char *)malloc((strlen(code)+2) * sizeof(char));
	  (void)strcpy(p->line->l_str, code);
	  p->line->l_flag.update = 1;
	} else if (p->line->l_num > line) {
	  Program *pn = (Program *)malloc(sizeof(Program));
	  pn->line = (Line *)malloc(sizeof(Line));
	  pn->line->l_str = (char *)malloc((strlen(code)+2)*sizeof(char));

	  pn->line->l_num = line;
	  (void)strcpy(pn->line->l_str, code);
	  pn->line->l_flag.loaded = pn->line->l_flag.update = 0;
	  pn->next = p;
	  pn->prev = p->prev;
	  p->prev->next = pn;
	  p->prev = pn;
	} else if (p->next == (Program *)NULL) {
	  Program *pn = (Program *)malloc(sizeof(Program));
	  pn->line = (Line *)malloc(sizeof(Line));
	  pn->line->l_str = (char *)malloc((strlen(code)+2)*sizeof(char));

	  pn->line->l_num = line;
	  (void)strcpy(pn->line->l_str, code);
	  pn->line->l_flag.loaded = pn->line->l_flag.update = 0;
	  pn->next = (Program *)NULL;
	  pn->prev = p;
	  p->next = pn;
	}
      }
    }
  }
  return 1;
}


int ge_auto(char *buf)
{
  int incr = 10,
      start = 10;
  char code[BUFSIZ];

  if (*buf) {
    int i = 0, s = 0;
    if (sscanf(buf, "%d,%d", &s, &i) == 2) {
      printf("AUTO both %d,%d\n", s, i);
      start = s; incr = i;
    } else if (sscanf(buf, ",%d", &i) == 1) {
      printf("AUTO incr %d\n", i);
      incr = i;
    } else if (sscanf(buf, "%d", &s) == 1) {
      printf("AUTO start %d\n", s);
      start = s;
    }
  }

  for (; ; start += incr) {
    char found = ' ';

    if (ge_prog && ge_prog->next) {
      Program *p = ge_prog->next;
      
      for (; p && found == ' '; p = p->next)
	if (p->line && p->line->l_num == start) found = '*';
    }

    printf("%d%c", start, found);
    fflush(stdout);

    if (!gets(code)) {
      printf("\n");
      clearerr(stdout);
      return 1;
    } else if (!*code) {
      continue;
    } else {
      ge_change(start, code);
    }

  }
  printf("AUTO fell out of loop\n");
  return 1;
}

int ge_new(char *buf)
{
  if (ge_prog) {
    Program *p;
    
    for (p = ge_prog; p; p = p->next) {
      if (p->line && p->line->l_str) free(p->line->l_str);
      if (p->line) free(p->line);
      free(p);
    }
  }
  ge_prog = (Program *)NULL;
  return 1;
}

/*
 * $Log: gwb_commands.c,v $
 * Revision 1.3  1996/01/09  03:35:27  ratlifc
 * Changed help code from simple printfs to a more useful style; Laid in
 * hooks for the Executor; Added support for the NEW command and modularized
 * the code which could call that command; Added the AUTO command
 *
 * Revision 1.2  1995/02/10  15:43:11  ratlifc
 * added error array; changed structure of LOAD and LIST to use a Program
 * structure instead of a file descriptor; added ge_change() to handle changes
 * of lines and additions to lines
 *
 * Revision 1.1  1995/02/10  13:40:19  ratlifc
 * initial splitting off from gwb_interpreter.c
 *
 */
