/* 
   Copyright (C) 1994 Free Software Foundation, Inc.
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
 * $Id: gwbasic.h,v 1.3 96/01/09 03:43:38 ratlifc Exp Locker: ratlifc $
 */

#include <stdio.h>
#include <errno.h>
#include <stdarg.h>

/* On the NeXT the basic curses is lame! */
#if defined(NeXT)
#include <ncurses.h>
#endif

/* Some platforms do not have a definition of the u_ types */
#if defined(NO_UTYPES)
typedef unsigned char u_char;
typedef unsigned int u_int;
#endif

#define GE_VERSION "2.2a"

typedef struct {
  u_char *l_str,
         *l_raw;
  int   l_num;
  struct {
    int loaded:1,
        update:1,
        reserved:30;
  } l_flag;
        
} Line;

typedef struct _program {
  Line *line;
  struct _program *next,
                  *prev;
} Program;

extern char *gwb_errors[];
extern int gwb_debug;

/*
 * $Log:	gwbasic.h,v $
 * Revision 1.3  96/01/09  03:43:38  ratlifc
 * Added support for debugging code; Changed char *'s to u_char *'s to handle
 * the SGI->BSD port
 * 
 * Revision 1.2  1995/02/10  15:48:26  ratlifc
 * incremented version number; added Line and Program structures; added
 * errors array external
 *
 * Revision 1.1  1995/02/10  13:38:51  ratlifc
 * initial checkin
 *
 */

