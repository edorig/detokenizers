/* 
   Copyright (C) 1994,1995 Free Software Foundation, Inc.
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
 * $Id: gwb_enviroment.c,v 1.4 1996/01/09 03:36:46 ratlifc Exp $
 */

#include "gwbasic.h"


extern int ge_system(), ge_run(), ge_list(), ge_load(), gi_parse(), ge_help(),
  ge_credits(), ge_version(), ge_change(), ge_auto(), ge_new();

typedef struct {
  char *name;
  int (*function)();
  int len;
} cmdTable;

cmdTable cmds[] = {
  "list", ge_list, 4,
  "help", ge_help, 4,
  "run", ge_run, 3,
  "load", ge_load, 4,
  "new", ge_new, 3,
  "auto", ge_auto, 4,
  "credits", ge_credits, 7,
  "version", ge_version, 7,
  "ver", ge_version, 3,
  "system", ge_system, 6,
  0, 0
  };

void ge_setup()
{
  ge_version("");
  printf("(c) Copyright Blue Rose Design 1994,1995\n");
  printf("lots o'bytes free\n");
}


int ge_command()
{
  char buf[BUFSIZ],
       code[BUFSIZ];
  int idx,
      lineno;

  bzero(buf, BUFSIZ);

  gets(buf);

  if (!*buf) return 1;
  
  for (idx = 0; cmds[idx].name; idx++) {
    if (!(strncasecmp(cmds[idx].name, buf, cmds[idx].len))) {
      char *p = &buf[cmds[idx].len+1];
      for (;p && *p && *p == ' '; p++);
      return cmds[idx].function(p);
    }
  }

  bzero(code, BUFSIZ);
  if (sscanf(buf, "%d %[^\n]s", &lineno, code) == 2)
    ge_change(lineno, code);
  else
    printf("%s\n", gwb_errors[2]);

  return 1;
}


int ge_interpret()
{
  printf("Ok\n");
  return ge_command();
}

void gwb_dprintf(char *format, ...)
{
  va_list lvar;
  char msg[BUFSIZ];

  if (!gwb_debug) return;

  va_start(lvar, format);
  (void)vsprintf(msg, format, lvar);
  va_end(lvar);

  (void)fprintf(stderr, "DEBUG: %s\n", msg);
  fflush(stderr);
}

int gwb_debug;

int main(int argc, char *argv[])
{
  if (argc > 1 && !strcasecmp(argv[1], "-d")) {
    gwb_debug = 1;
    (void)fprintf(stderr, "%s: debugging enabled\n", argv[0]);
    sleep(3);
  }
  system("tput clear");
  ge_setup();

  while (ge_interpret());
  system("tput clear");

  exit(0);
}

/*
 * $Log: gwb_enviroment.c,v $
 * Revision 1.4  1996/01/09  03:36:46  ratlifc
 * Added AUTO and NEW commands; Added debugging printf-style code
 *
 * Revision 1.3  1995/02/10  15:44:03  ratlifc
 * switched code to use new errors array; added ge_change() to handle
 * changes to the loaded file
 *
 * Revision 1.2  1995/02/10  13:39:59  ratlifc
 * moved header elements to global gwbasic.h; removed command code to
 * separate file; added special handling of <enter>; performance improvement
 * with command processing
 *
 * Revision 1.1  1995/02/09  13:57:56  ratlifc
 * first release of 2.0a
 *
 */

