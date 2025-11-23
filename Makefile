# Copyright (C) 1994,1995,1996 Free Software Foundation, Inc.
# Originally written by Christian A. Ratliff for GW-Basic
# Addition of CPM,TRS80,MSX etc...
# by Edmond Orignac (2011 to 2023) 
# This file is part of the gwbasic translator.
#
# The gwbasic translator is free software; you can redistribute it
# and/or modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 1, or
# (at your option) any later version.
#
# The gwbasic translator is distributed in the hope that it will be
# useful, but WITHOUT ANY WARRANTY; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with gwb; see the file COPYING.  If not, write to the Free
# Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
#
# $Id: Makefile,v 1.2 1995/02/10 22:38:24 ratlifc Exp ratlifc $
#

CC	= cc
CFLAGS	= -g -DNO_UTYPES
#LIBS	= -lcurses -ltermcap
# If on a NeXT use -lncurses
LIBS	= -lncurses -ltermcap

# ARCH	= next_mach20
INSTDIR = /usr/local/bin/ 

# We only build the tested Microsoft BASICs
# leaving out untested BASICs and the ZBasic on Apple II and MS-DOS
MISCFILES= README TODO COPYRIGHT CHANGES README.MSX README.2
MAN	= amsbascii.1 cocoascii.1 cpmascii.1 drascii.1 \
	gwascii.1 msxascii.1 trs80ascii.1 trsm4ascii.1 \
	to7ascii.1 mc10ascii.1  
HEADERS	= gwbasic.h gwb_commands.h gwb_executor.h \
	 gwb_interpreter.h coco.h dragon32.h trs80.h\
	cpm_interpreter.h  msx_interpreter.h  atarimsb.h  oric.h
SOURCE	= gwb_enviroment.c trs_interpreter.c gwb_commands.c gwb_executor.c \
	gwb_operands.c cpm_interpreter.c msx_interpreter.c gwb_interpreter.c\
	coco.c dragon.c trsm4.c atari_msb.c to7ascii.c mc10ascii.c 
OBJECTS	= gwb_enviroment.o gwb_commands.o gwb_executor.o \
	gwb_operands.o
MSX	= msx_interpreter.o 
TRS	= trs_interpreter.o
GW	= gwb_interpreter.o
CPM	= cpm_interpreter.o
COCO	= coco.o 
DRAG	= dragon.o
TRS4	= trsm4.o
AMSB	= atari_msb.o
ORIC	= oric.o
#SOR	= sorcerer.o 
#OSI	= osi.o
#XTAL   = xtal.o
#CCOL	= compucolor.o
#NSCM	= nascom.o
#TI99	= ti99.o 
BINARY1	= trs80ascii
BINARY2	= msxascii
BINARY3 = gwascii  
BINARY4	= cpmascii  
BINARY5 = cocoascii
BINARY6	= drascii
BINARY7 = trsm4ascii
BINARY8	= amsbascii
BINARY9 = oricascii
BINARY10 = to7ascii
BINARY11 = mc10ascii
BINARY12 = zba2ascii
BINARY13 = zbpc2ascii
BINARY14 = ozbpc2ascii

# For the moment, we don't build sorcerer/osi/xtal/nascom/ti99

BINARY= $(BINARY1) $(BINARY2) $(BINARY3) $(BINARY4) $(BINARY5) $(BINARY6) $(BINARY7) $(BINARY8) $(BINARY9)

all:	$(BINARY)   

$(BINARY1): $(HEADERS) $(OBJECTS) $(TRS) 
	$(CC) $(CFLAGS) -o $(BINARY1) $(OBJECTS) $(TRS) $(LIBS)

$(BINARY2): $(HEADERS) $(OBJECTS) $(MSX) 
	$(CC) $(CFLAGS) -o $(BINARY2) $(OBJECTS) $(MSX) $(LIBS)

$(BINARY3): $(HEADERS) $(OBJECTS) $(GW) 
	$(CC) $(CFLAGS) -o $(BINARY3) $(OBJECTS) $(GW) $(LIBS)

$(BINARY4): $(HEADERS) $(OBJECTS) $(CPM) 
	$(CC) $(CFLAGS) -o $(BINARY4) $(OBJECTS) $(CPM) $(LIBS)

$(BINARY5): $(HEADERS) $(OBJECTS) $(COCO) 
	$(CC) $(CFLAGS) -o $(BINARY5) $(OBJECTS) $(COCO) $(LIBS)

$(BINARY6): $(HEADERS) $(OBJECTS) $(DRAG) 
	$(CC) $(CFLAGS) -o $(BINARY6) $(OBJECTS) $(DRAG) $(LIBS)

$(BINARY7): $(HEADERS) $(OBJECTS) $(TRS4) 
	$(CC) $(CFLAGS) -o $(BINARY7) $(OBJECTS) $(TRS4) $(LIBS)

$(BINARY8): $(HEADERS) $(OBJECTS) $(AMSB)
	$(CC) $(CFLAGS) -o $(BINARY8) $(OBJECTS) $(AMSB) $(LIBS)

$(BINARY9): $(HEADERS) $(OBJECTS) $(ORIC)
	$(CC) $(CFLAGS) -o $(BINARY9) $(OBJECTS) $(ORIC) $(LIBS)

$(BINARY10): to7ascii.c
	$(CC) $(CFLAGS) -o $(BINARY10) $<

$(BINARY11): mc10ascii.c
	$(CC) $(CFLAGS) -o $(BINARY11) $<

$(BINARY12): zba2ascii.c
	$(CC) $(CFLAGS) -o $(BINARY12) $<

$(BINARY13): zbpc2ascii.c
	$(CC) $(CFLAGS) -o $(BINARY13) $<

$(BINARY14): ozbpc2ascii.c
	$(CC) $(CFLAGS) -o $(BINARY14) $<
clean:
	rm -f *.o $(BINARY) *~

tests:	$(BINARY)
	echo "Under version 2.0 simple tests are not possible"

install: $(BINARY)
	cp -f $(INSTDIR)/$(BINARY) $(INSTDIR)/$(BINARY).old
	cp -f $(BINARY) $(INSTDIR)/$(BINARY)

dist:
	-mkdir /tmp/trs80ascii-0.1
	-cp $(SOURCE) $(HEADERS) $(MISCFILES) $(MAN) Makefile /tmp/trs80ascii-0.1
	-(cd /tmp ; tar cvf - trs80ascii-0.1 | gzip ) > trs80ascii-0.1.tar.gz
	-rm -rf /tmp/trs80ascii-0.1

#
# $Log: Makefile,v $
# Revision 1.2  1995/02/10  22:38:24  ratlifc
# added lots of headers, sources, and objects; removed link to math lib
#
# Revision 1.1  1995/02/08  23:02:19  ratlifc
# initial transfer to gwbasic 2.0
#
