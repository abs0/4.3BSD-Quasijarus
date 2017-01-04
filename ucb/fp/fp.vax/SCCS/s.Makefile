h28139
s 00002/00000/00046
d D 4.2 87/05/31 21:09:57 bostic 2 1
c added depend label
e
s 00046/00000/00000
d D 4.1 85/09/07 15:57:07 mckusick 1 0
c date and time created 85/09/07 15:57:07 by mckusick
e
u
U
t
T
I 1
#  FP interpreter/compiler
#  Copyright (c) 1982  Scott B. Baden
#  Berkeley, California
#
#  Copyright (c) 1982 Regents of the University of California.
#  All rights reserved.  The Berkeley software License Agreement
#  specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
DESTDIR =

FP_SYS = 	runFp.l fpMain.l\
		scanner.l parser.l codeGen.l\
		primFp.l utils.l fpPP.l handlers.l fpMeasures.l

FP_SYSO = 	runFp.o fpMain.o\
		scanner.o parser.o codeGen.o\
		primFp.o utils.o  fpPP.o handlers.o fpMeasures.o

.SUFFIXES:
.SUFFIXES:	.l .o
.l.o:
		liszt -axq $<


fp:		${FP_SYSO}
		/bin/rm -f fp
		echo "(progn (load 'runFp)\
			     (dumplisp fp))" | lisp > junk.fp
		chmod 755 fp

${FP_SYSO}:	specials.l fpMacs.o


install:	fp
		install -s fp ${DESTDIR}/usr/ucb/fp

clean:		
		rm -f core *.[ox] junk.fp


listings:	${FP_SYS}
		print runFp.l fpMain.l scanner.l parser.l codeGen.l \
		primFp.l utils.l fpPP.l handlers.l fpMeasures.l \
		specials.l fpMacs.l  &
I 2

depend:
E 2
E 1
