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
 * $Id: gwb_executor.h,v 1.1 1996/01/09 03:31:28 ratlifc Exp $
 */

#define T_NONE    -1
#define T_STR      0
#define T_INT      2
#define T_FLT      3
#define T_DBL      4

#define STR_MAX  255

typedef struct {
  char *v_name;
  short v_type;
  union {
    char   s[STR_MAX];
    int    i;
    float  f;
    double d;
  } v_val;
} Var;


Line *lp;   /* Line Pointer, indicates the current line being executed */
char *ip;   /* Instruction Pointer, where in the line are we executing */



/*
 * $Log: gwb_executor.h,v $
 * Revision 1.1  1996/01/09  03:31:28  ratlifc
 * Initial revision
 *
 */

