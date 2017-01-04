h11298
s 00002/00064/00118
d D 5.6 00/08/28 10:07:03 msokolov 14 13
c remove astoks.h on make clean, it's a generated file
e
s 00093/00041/00089
d D 5.5 87/06/02 23:23:24 bostic 13 12
c new template
e
s 00003/00000/00127
d D 5.4 87/05/31 20:31:30 bostic 12 11
c added depend label
e
s 00001/00001/00126
d D 5.3 86/04/28 02:57:47 lepreau 11 10
c clean better
e
s 00000/00004/00127
d D 5.2 85/06/19 16:48:15 mckusick 10 9
c get rid of SCCS rule
e
s 00006/00001/00125
d D 5.1 85/04/24 12:09:54 dist 9 8
c Add copyright
e
s 00011/00010/00115
d D 4.8 83/10/14 16:37:17 ralph 8 7
c fixed debugging info and phase error message for label defs.
e
s 00001/00004/00124
d D 4.7 83/08/14 22:07:55 sam 7 6
c a simpler way to do it?
e
s 00001/00003/00127
d D 4.6 83/07/02 23:23:34 sam 6 5
c put SCCS keywords back in
e
s 00002/00002/00128
d D 4.5 83/07/02 23:22:25 root 5 4
c for rrh
e
s 00001/00000/00129
d D 4.4 82/12/15 02:51:09 linton 4 3
c defined AS to be /bin/as to ensure correct assembly of "aspseudo.s"
e
s 00000/00000/00129
d D 4.3 82/02/14 16:36:19 rrh 3 2
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00000/00000/00129
d D 4.2 82/02/14 16:18:56 rrh 2 1
c Syncrhonizing this new file to release 4.2
e
s 00129/00000/00000
d D 4.1 82/02/14 16:06:22 rrh 1 0
c date and time created 82/02/14 16:06:22 by rrh
e
u
U
t
T
I 1
D 6
LOCAL = /usr/ucb/

E 6
I 6
D 9
#	%M%	%I%	%E%
E 9
I 9
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
E 9
E 6
#
#	as.h		Definitions for data structures
#	asnumber.h	Definitions for all numbers: byte .. G format float
#	asscan.h	Definitions for the character scanner
#	asscanl.h	Definitions for the character scanner;
#				local to asscan?.c
#	astokfix.awk
#	astoks.H	The defines for tokens that yacc produced
#				This is processed by astokfix.awk to yield:
#	astoks.h	Included implicitly in as.h
#	asexpr.h	The macros for parsing and expressions
#	assyms.h	Macros for dealing with the symbol table
#	instrs.h	Definitions to make instrs more readable
#
#	asscan1.c	buffer management, yylex, and buffer drainer
#	asscan2.c	character scanner, and buffer filler
#	asscan3.c	character sets definitions (initialized data)
#	asscan4.c	constructs normal integers; interfaces with bignum?.c
#
#	bignum1.c	constructs large integers; utility routines
#	bignum2.c	packs/unpacks floating point numbers
#	natof.c		constructs large floating point #'s, ala atof
#
#	asparse.c	parser
#	asexpr.c	parses expressions, constructs and evaluates
#				expression trees
#
#	asmain.c	main body
#	assyms.c	symbol table processing routines
#	asjxxx.c	Fixes jxxx instructions
#	ascode.c	Emits code
#	assizetab.c	Converts internal ordinal #'s into sizes, strings, etc
#	asio.c		Does block I/O and faster versions of fwrite
#
#	aspseudo.c	Symbol table definitions for reserved words
#	instrs		included in pseudo.c; instructions and semantic info
#				for each instructions
#
D 6

E 6
D 8
HDRS = astoks.H astokfix.awk as.h asscan.h assyms.h asexpr.h 
E 8
I 8
D 13
HDRS = astoks.H astokfix.awk as.h asexpr.h asnumber.h asscan.h asscanl.h \
E 13
I 13
HDRS=	astoks.H astokfix.awk as.h asexpr.h asnumber.h asscan.h asscanl.h \
E 13
	assyms.h instrs.h
E 8
D 13

SRCS = asscan1.c asscan2.c asscan3.c asscan4.c \
	bignum1.c bignum2.c natof.c floattab.c \
	asmain.c asparse.c \
	asexpr.c assyms.c \
	asjxxx.c ascode.c aspseudo.c \
	assizetab.c asio.c

OBJS = asscan1.o asscan2.o asscan3.o asscan4.o \
	bignum1.o bignum2.o natof.o floattab.o\
	asparse.o asexpr.o \
	asmain.o assyms.o \
	asjxxx.o ascode.o aspseudo.o \
	assizetab.o asio.o

E 13
I 13
SRCS=	asscan1.c asscan2.c asscan3.c asscan4.c bignum1.c bignum2.c natof.c \
	floattab.c asmain.c asparse.c asexpr.c assyms.c asjxxx.c ascode.c \
	aspseudo.c assizetab.c asio.c
OBJS=	asscan1.o asscan2.o asscan3.o asscan4.o bignum1.o bignum2.o natof.o \
	floattab.o asparse.o asexpr.o asmain.o assyms.o asjxxx.o ascode.o \
	aspseudo.o assizetab.o asio.o
E 13
GRIND = astoks.h as.h asscan.h assyms.h asexpr.h instrs.h asnumber.h \
D 13
	asscanl.h asscan1.c asscan2.c asscan3.c asscan4.c \
	bignum1.c bignum2.c natof.c floattab.c \
	asmain.c asscan.c asparse.c asexpr.c \
	assyms.c asjxxx.c ascode.c asio.c \
	assizetab.c aspseudo.c
E 13
I 13
	asscanl.h asscan1.c asscan2.c asscan3.c asscan4.c bignum1.c \
	bignum2.c natof.c floattab.c asmain.c asscan.c asparse.c asexpr.c \
	assyms.c asjxxx.c ascode.c asio.c assizetab.c aspseudo.c
E 13

D 13
DESTDIR = 

#
E 13
#	available flags:
#
#	AS		This is the assembler; always set
#  (UNIX and VMS are mutually exclusive.)
#	UNIX		Must be set if the assembler is to produce a.out
#			files for UNIX.
#
#	VMS		Must be set if the assembler is to produce executables
#			for VMS (Thanks to David Kashtan, SRI for these fixes)
#
#	if VMS is set, then these two flags are also valid:
#			(necessary to frob system calls and '$' conventions
#	VMSDEVEL	The assembler is being compiled under VMS
#	UNIXDEVEL	The assembler is being compiled under UNIX
#
#
#	DEBUG		print out various debugging information
#			in the first pass
#
#	FLEXNAMES	All names are stored internally as true character
#			strings, null terminated, and can be no more
#			than BUFSIZ long.
#			
I 13
AS=	/bin/as
DFLAGS=	-DAS
CFLAGS=	-O ${DFLAGS}
E 13

I 4
D 13
AS = /bin/as
E 4
LD = /bin/ld
E 13
I 13
as: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 13

D 5
DFLAGS= -DAS -DUNIX -DUNIXDEVEL -DFLEXNAMES
E 5
I 5
D 13
DFLAGS= -DAS
E 5
D 8
CFLAGS = -O $(DFLAGS)
E 8
I 8
CFLAGS = -O ${DFLAGS}
E 8

LDFLAGS = -O

D 8
as:	$(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o as
E 8
I 8
as:	${OBJS}
	${CC} ${LDFLAGS} ${OBJS} -o as
E 8

E 13
D 8
.c.o:	astoks.h
	$(CC) $(CFLAGS) -c $*.c
E 8
I 8
.c.o:	astoks.h ${HDRS}
	${CC} ${CFLAGS} -c $*.c
E 8

astoks.h: astoks.H astokfix.awk
	awk -f astokfix.awk < astoks.H > astoks.h

D 13
aspseudo.o:	as.h astoks.h aspseudo.c instrs.h instrs.as
E 13
I 13
aspseudo.o: as.h astoks.h aspseudo.c instrs.h instrs.as
E 13
D 5
	$(CC) -S $(CFLAGS) aspseudo.c
E 5
I 5
D 7
	$(CC) -S $(DFLAGS) aspseudo.c
E 5
	sh ./:rofix aspseudo.s
	$(AS) -o aspseudo.o aspseudo.s
	rm aspseudo.s
E 7
I 7
D 8
	$(CC) -c -R $(DFLAGS) aspseudo.c
E 8
I 8
	${CC} -c -R ${DFLAGS} aspseudo.c
E 8
E 7

instrs.as: instrs
	(echo FLAVOR AS ; cat instrs) | awk -f instrs > instrs.as

D 13
lint:
D 8
	lint $(DFLAGS) $(SRCS)
E 8
I 8
	lint ${DFLAGS} ${SRCS}
E 8
clean:
E 13
I 13
lint: FRC
	lint ${CFLAGS} ${SRCS}

clean: FRC
E 13
D 8
	rm -f $(OBJS) as
E 8
I 8
D 11
	rm -f ${OBJS} as
E 11
I 11
D 14
	rm -f ${OBJS} instrs.as as core a.out errs
E 14
I 14
	rm -f ${OBJS} astoks.h instrs.as as core a.out errs
E 14
I 12

D 13
depend:
E 13
I 13
D 14
depend: instrs.as FRC
E 14
I 14
depend: astoks.h instrs.as FRC
E 14
	mkdep ${CFLAGS} ${SRCS}
E 13

E 12
E 11
E 8
D 13
install:
	install -s as ${DESTDIR}/bin
E 13
I 13
install: FRC
	install -s -o bin -g bin -m 755 as ${DESTDIR}/bin/as
E 13

I 13
tags: FRC
	ctags ${SRCS}

E 13
print:
D 8
	pr Makefile $(HDRS) $(SRCS)
E 8
I 8
	pr Makefile ${HDRS} ${SRCS}
I 13

FRC:
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
D 14

asscan1.o: asscan1.c asscanl.h /usr/include/stdio.h as.h
asscan1.o: /usr/include/sys/types.h /usr/include/a.out.h
asscan1.o: /usr/include/sys/exec.h /usr/include/stab.h instrs.h astoks.h
asscan1.o: asnumber.h asscan.h
asscan2.o: asscan2.c asscanl.h /usr/include/stdio.h as.h
asscan2.o: /usr/include/sys/types.h /usr/include/a.out.h
asscan2.o: /usr/include/sys/exec.h /usr/include/stab.h instrs.h astoks.h
asscan2.o: asnumber.h asscan.h
asscan3.o: asscan3.c asscanl.h /usr/include/stdio.h as.h
asscan3.o: /usr/include/sys/types.h /usr/include/a.out.h
asscan3.o: /usr/include/sys/exec.h /usr/include/stab.h instrs.h astoks.h
asscan3.o: asnumber.h asscan.h
asscan4.o: asscan4.c asscanl.h /usr/include/stdio.h as.h
asscan4.o: /usr/include/sys/types.h /usr/include/a.out.h
asscan4.o: /usr/include/sys/exec.h /usr/include/stab.h instrs.h astoks.h
asscan4.o: asnumber.h asscan.h
bignum1.o: bignum1.c /usr/include/errno.h /usr/include/stdio.h as.h
bignum1.o: /usr/include/sys/types.h /usr/include/a.out.h
bignum1.o: /usr/include/sys/exec.h /usr/include/stab.h instrs.h astoks.h
bignum1.o: asnumber.h
bignum2.o: bignum2.c /usr/include/stdio.h as.h /usr/include/sys/types.h
bignum2.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
bignum2.o: instrs.h astoks.h asnumber.h
natof.o: natof.c /usr/include/stdio.h /usr/include/ctype.h /usr/include/errno.h
natof.o: as.h /usr/include/sys/types.h /usr/include/a.out.h
natof.o: /usr/include/sys/exec.h /usr/include/stab.h instrs.h astoks.h
natof.o: asnumber.h
floattab.o: floattab.c /usr/include/stdio.h as.h /usr/include/sys/types.h
floattab.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
floattab.o: instrs.h astoks.h asnumber.h
asmain.o: asmain.c /usr/include/stdio.h /usr/include/ctype.h
asmain.o: /usr/include/signal.h as.h /usr/include/sys/types.h
asmain.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
asmain.o: instrs.h astoks.h asnumber.h assyms.h asscan.h asexpr.h
asmain.o: /usr/include/sys/stat.h
asparse.o: asparse.c /usr/include/stdio.h as.h /usr/include/sys/types.h
asparse.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
asparse.o: instrs.h astoks.h asnumber.h asscan.h assyms.h asexpr.h
asexpr.o: asexpr.c /usr/include/stdio.h as.h /usr/include/sys/types.h
asexpr.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
asexpr.o: instrs.h astoks.h asnumber.h asscan.h asexpr.h
assyms.o: assyms.c /usr/include/stdio.h /usr/include/ctype.h as.h
assyms.o: /usr/include/sys/types.h /usr/include/a.out.h /usr/include/sys/exec.h
assyms.o: /usr/include/stab.h instrs.h astoks.h asnumber.h asscan.h assyms.h
asjxxx.o: asjxxx.c /usr/include/stdio.h as.h /usr/include/sys/types.h
asjxxx.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
asjxxx.o: instrs.h astoks.h asnumber.h assyms.h
ascode.o: ascode.c /usr/include/stdio.h as.h /usr/include/sys/types.h
ascode.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
ascode.o: instrs.h astoks.h asnumber.h assyms.h
aspseudo.o: aspseudo.c /usr/include/stdio.h as.h /usr/include/sys/types.h
aspseudo.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
aspseudo.o: instrs.h astoks.h asnumber.h instrs.as
assizetab.o: assizetab.c /usr/include/stdio.h as.h /usr/include/sys/types.h
assizetab.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
assizetab.o: instrs.h astoks.h asnumber.h assyms.h
asio.o: asio.c /usr/include/stdio.h as.h /usr/include/sys/types.h
asio.o: /usr/include/a.out.h /usr/include/sys/exec.h /usr/include/stab.h
asio.o: instrs.h astoks.h asnumber.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 14
E 13
E 8
D 10

sources: ${SRCS} ${HDRS}
${SRCS} ${HDRS}:
	sccs get $@
E 10
E 1
