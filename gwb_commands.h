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
 * $Id: gwb_commands.h,v 1.1 1996/01/09 03:31:21 ratlifc Exp $
 */

char *gwb_errors[] = {
  "Unkown error!!",
  "NEXT without FOR",
  "Syntax Error",
  "Return without GOSUB",
  "Out of Data",
  "Illegal function call",
  "Overflow",
  "Out of memory",
  "Undefined line number",
  "Subscript out of range",
  "Duplicate definition",
  "Division by zero",
  "Illegal direct",
  "Type mismatch",
  0
  };

char *gwb_help[] = {
  "GENERAL",
  "Commands are:  CREDITS, LIST, LOAD, RUN, SYSTEM, VERSION",

  "CREDITS",
  "If you need help with CREDITS, it is time to use a simpler",
  "programming language.",
  "",

  "LIST",
  "LIST [from_line][-to_line][,PRN|filespec]",
  "Displays program lines on the screen or sends the program",
  "lines to a file or device.",
  " ",
  "from_line - Specifies the first line of the program to be listed.",
  "-         - A dash separates from_line and to_line if both",
  "            parameters are specified. If to_line is omitted, the",
  "            program is listed starting at from_line.",
  "to_line   - Specifies the last line of the program to be listed.",
  "PRN       - Specifies the output of the program to the printer.",
  "filespec  - Specifies the filename of the listed program.",
  " ",
  "If both line parameters are omitted, the entire program is listed.",
  "",

  "LLIST",
  "LLIST [from_line][-to_line]",
  "Displays program lines on the printer",
  " ",
  "from_line - Specifies the first line of the program to be listed.",
  "-         - A dash separates from_line and to_line if both",
  "            parameters are specified. If to_line is omitted, the",
  "            program is listed starting at from_line.",
  "to_line   - Specifies the last line of the program to be listed.",
  " ",
  "If both line parameters are omitted, the entire program is listed.",
  "",

  "LOAD",
  "LOAD \"filespec\"[,R]",
  "Executes a NEW command and loads a program from disk.",
  " ",
  "filespec  - Specifies the name of the BASIC program to be loaded",
  "          - from disk. filespec must be entered between quotaion",
  "          - (\"\") marks.",
  ",R        - Immediately executes the program after loading",
  "",

  "NEW",
  "Erases the program in memory and initializes all variables.",
  "",

  "SYSTEM",
  "Exits the BASIC interpreter and returns to the MS-DOS command",
  "level. The contents of the current program in memory are NOT",
  "automatically SAVEd.",
  "",

  "VERSION",
  "Displays the version number of the BASIC interpreter.",
  "",

  "--END--"
};


	       

/*
 * $Log: gwb_commands.h,v $
 * Revision 1.1  1996/01/09  03:31:21  ratlifc
 * Initial revision
 *
 */
