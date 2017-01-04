h01900
s 00002/00000/00193
d D 1.19 87/10/26 07:46:36 bostic 20 19
c add depend label
e
s 00012/00007/00181
d D 1.18 87/04/07 15:51:36 mckusick 19 17
c port for tahoe from Nir peleg of CCI
e
s 00002/00002/00186
d R 1.18 87/03/18 18:09:40 mckusick 18 17
c sources have moved
e
s 00001/00001/00187
d D 1.17 86/04/25 20:07:52 mckusick 17 16
c cleanup clean
e
s 00003/00003/00185
d D 1.16 85/10/08 22:25:38 bloom 16 15
c use cd instead of chdir (chdir not in doc for /bin/sh)
e
s 00001/00001/00187
d D 1.15 85/09/07 15:53:01 mckusick 15 14
c strip on install
e
s 00004/00002/00184
d D 1.14 85/06/07 19:39:03 mckusick 14 13
c add copyright
e
s 00003/00003/00183
d D 1.13 83/02/08 12:50:23 mckusick 13 12
c update for new source structure
e
s 00002/00001/00184
d D 1.12 82/10/18 23:42:42 mckusick 12 11
c use DESTDIR in install
e
s 00002/00002/00183
d D 1.11 82/10/13 17:52:34 mckusick 11 10
c change HOME from cmd to ucb
e
s 00011/00012/00174
d D 1.10 82/09/02 20:36:57 linton 10 9
c changed way library stuff is compiled and linked
e
s 00002/00002/00184
d D 1.9 82/08/03 17:35:19 mckusick 9 8
c restore sccs keywords
e
s 00004/00003/00182
d D 1.8 82/08/03 17:32:05 mckusick 8 7
c use rm -f to suppress errors
e
s 00001/00001/00184
d D 1.7 82/05/19 20:38:49 linton 7 6
c forgot about in print about .yacc and .lex
e
s 00012/00001/00173
d D 1.6 82/05/19 20:37:20 linton 6 5
c added "clean" and "print" and changed "install" to depend on a.out
e
s 00007/00008/00167
d D 1.5 82/03/08 19:01:01 linton 5 4
c removed need for "compile.csh" by using complicated csh expression
e
s 00001/00001/00174
d D 1.4 82/01/23 16:32:15 linton 4 3
c added "-DVAX" to CFLAGS
e
s 00004/00002/00171
d D 1.3 82/01/20 10:27:04 linton 3 2
c objfmt.h dependency
e
s 00015/00016/00158
d D 1.2 82/01/19 01:34:45 linton 2 1
c added -DOBJ to CFLAGS
e
s 00174/00000/00000
d D 1.1 82/01/18 19:10:52 linton 1 0
c date and time created 82/01/18 19:10:52 by linton
e
u
U
t
T
I 1
D 9
#/* Copyright (c) 1982 Regents of the University of California */
E 9
I 9
D 14
# Copyright (c) 1982 Regents of the University of California
E 14
I 14
# Copyright (c) 1982 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 14
E 9
#
D 5
# static char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
D 9
# static char sccsid[] = "@(#)Makefile 1.4 1/23/82";
E 9
I 9
D 14
#	%W%	(Berkeley)	%G%
E 14
I 14
#	%W% (Berkeley) %G%
E 14
E 9
E 5
#
# make file for pdx
#
I 2
# For best results edit this file in vi with tabstop=4.
#
E 2
# The file "defs.h" is included by all, it has most of the type
# declarations (since you can't have forward type references in C).
# It also defines various things of general use and includes <stdio.h>.
#
D 2
# Library files:
E 2
I 2
D 10
# The subdirectory "library" contains routines which are generally useful
# and are independent from pdx.  These are compiled into a separate archive
# and they must be made independently from pdx.
E 10
I 10
# The file "library.c" contains routines which are generally useful
# and are independent from pdx.
E 10
E 2
#
D 2
#	error.c, erecover.c	- error handling
#	pwait.c			- wait for a specific process
#	syserr.c, cerror.s	- low level error handling
#
E 2
D 10
# N.B.: My version of cerror automatically catches certain erros
E 10
I 10
# N.B.: My version of cerror in "cerror.s" automatically catches certain errors
E 10
#	such as out of memory, I/O error.  If you re-make pdx with
#	the standard cerror, the program could fault unexpectedly.
#
D 3
#	Also, this makefile contains NO HEADER DEPENDENCIES.  So
E 3
I 3
#	Also, this makefile contains almost NO HEADER DEPENDENCIES.  So
E 3
#	if you modify a header file in a non-trivial way, you need
#	to touch the C files that include it.
#

I 12
DESTDIR	=
E 12
D 2
HOME	= /vb/arpa/linton
LIB	= ${HOME}/lib/libc.a
INSTALL	= ${HOME}/bin/pdx
E 2
I 2
D 11
HOME	= /usr/src/cmd/pdx
E 11
I 11
HOME	= /usr/src/ucb/pdx
E 11
D 5
LIB		= ${HOME}/library/pdxlib
E 5
I 5
D 10
LIB	= ${HOME}/library/pdxlib
E 10
I 10
LIB	= library.o cerror.o
E 10
E 5
I 3
D 11
PASCAL	= /usr/src/cmd/pascal/
E 11
I 11
D 13
PASCAL	= /usr/src/ucb/pascal/
E 13
I 13
SRCDIR	= ../src/
E 13
E 11
E 3
D 12
INSTALL	= /usr/ucb/pdx
E 12
I 12
INSTALL	= ${DESTDIR}/usr/ucb/pdx
E 12
E 2

D 10
#
# LDFLAGS should be -i for pdp-11
#

E 10
I 8
RM	= /bin/rm -f
E 8
D 2
CFLAGS	= -Disvaxpx -I.. -O
E 2
I 2
D 3
CFLAGS	= -Disvaxpx -I.. -I../../pascal -DOBJ -O
E 3
I 3
D 4
CFLAGS	= -Disvaxpx -I.. -I${PASCAL} -DOBJ -O
E 4
I 4
D 13
CFLAGS	= -Disvaxpx -I.. -I${PASCAL} -DOBJ -DVAX -O
E 13
I 13
D 19
CFLAGS	= -Disvaxpx -I.. -I../${SRCDIR} -DOBJ -DADDR32 -O
E 19
I 19
CFLAGS	= -I.. -I../${SRCDIR} -DOBJ -DADDR32 -O
LINTFLAGS= -I. -I${SRCDIR} -DOBJ -DADDR32
E 19
E 13
E 4
E 3
E 2
D 10
LDFLAGS	=
E 10
I 10
LDFLAGS	= # -i for pdp-11
E 10

D 5
#
# Regardless of what CFLAGS is, the file "compile.csh" controls
# how compilation is done for the majority of the source files.
#

E 5
.c.o:
	@echo "compiling $*.c"
D 5
	@csh -f compile.csh $*.c
E 5
I 5
	@csh -f -c ' \
	    set a=$*.c; \
D 16
	    if ($$a:h != $$a) chdir $$a:h; \
E 16
I 16
	    if ($$a:h != $$a) cd $$a:h; \
E 16
	    ${CC} ${CFLAGS} -c $$a:t \
	'
E 5

I 10
D 19
.s.o:
	@echo "assembling $*.s"
	@cc -c $*.s

E 19
E 10
#
# source directory specifications
#

MAIN		= main/
SYMTAB		= symtab/
SOURCE		= source/
COMMAND		= command/
TREE		= tree/
D 2
SYM		= sym/
E 2
I 2
D 10
SYM			= sym/
E 10
I 10
SYM		= sym/
E 10
E 2
BREAKPOINT	= breakpoint/
RUNTIME		= runtime/
OBJECT		= object/
MAPPINGS	= mappings/
PROCESS		= process/
MACHINE		= machine/

BPOBJ =\
	${BREAKPOINT}bp.o\
	${BREAKPOINT}bpact.o\
	${BREAKPOINT}fixbps.o\
	${BREAKPOINT}status.o\
	${BREAKPOINT}printnews.o\
	${BREAKPOINT}setbps.o\
	${BREAKPOINT}trinfo.o\
	${BREAKPOINT}trcond.o

OBJOBJ =\
	${OBJECT}readobj.o\
	${OBJECT}readsym.o\
	${OBJECT}maketypes.o

MAPOBJ =\
	${MAPPINGS}functab.o\
	${MAPPINGS}objaddr.o\
	${MAPPINGS}srcfile.o\
	${MAPPINGS}srcline.o

CMDOBJ =\
	${COMMAND}y.tab.o\
	${COMMAND}lex.yy.o\
	${COMMAND}remake.o

RUNTIMEOBJ =\
	${RUNTIME}frame.o\
	${RUNTIME}wheredump.o\
	${RUNTIME}isactive.o\
	${RUNTIME}address.o\
	${RUNTIME}callproc.o\
	${RUNTIME}entry.o

MACHOBJ =\
	${MACHINE}nextaddr.o\
	${MACHINE}setbp.o\
	${MACHINE}optab.o\
	${MACHINE}printdata.o\
	${MACHINE}printerror.o\
D 19
	${MACHINE}printinst.o\
	${MACHINE}pxerrors.o
E 19
I 19
	${MACHINE}printinst.o
E 19

PROCOBJ =\
	${PROCESS}runcont.o\
	${PROCESS}pstatus.o\
	${PROCESS}rdwr.o\
	${PROCESS}resume.o\
	${PROCESS}start.o\
	${PROCESS}step.o\
	${PROCESS}ptrace.o

SYMOBJ =\
	${SYM}predicates.o\
	${SYM}attributes.o\
	${SYM}printdecl.o\
	${SYM}which.o\
	${SYM}print.o\
	${SYM}printval.o\
	${SYM}tree.o

TREEOBJ =\
	${TREE}build.o\
	${TREE}eval.o\
	${TREE}opinfo.o\
	${TREE}prtree.o\
	${TREE}tfree.o\
	${TREE}tr_equal.o\
	${TREE}tracestop.o\
	${TREE}misc.o\
	${TREE}assign.o

OBJS =\
	${MAIN}main.o\
	${SYMTAB}symtab.o\
	${SOURCE}source.o\
	${CMDOBJ}\
	${TREEOBJ}\
	${SYMOBJ}\
	${BPOBJ}\
	${RUNTIMEOBJ}\
	${OBJOBJ}\
	${MAPOBJ}\
	${PROCOBJ}\
	${MACHOBJ}

D 10
a.out: ${OBJS}
E 10
I 10
a.out: ${OBJS} ${LIB}
E 10
	@echo "linking"
	@cc ${LDFLAGS} ${OBJS} ${LIB}

profile: ${OBJS}
	@echo "linking with -p"
	@cc ${LDFLAGS} -p ${OBJS} ${LIB}
I 19

lint:
	@cd ${COMMAND}; yacc -d grammar.yacc; lex token.lex
	-@lint ${LINTFLAGS} `echo ${OBJS} library.c | sed 's/\.o/.c/g'`
	@${RM} ${COMMAND}lex.yy.c ${COMMAND}y.tab.c

cerror.o:
	@echo "assembling `machine`/$*.s"
	@cc -c `machine`/$*.s
E 19

D 2
${COMMAND}lex.yy.o: ${COMMAND}token.lex ${COMMAND}y.tab.h
	chdir ${COMMAND}; lex token.lex; cc -c ${CFLAGS} lex.yy.c
	rm ${COMMAND}lex.yy.c

E 2
${COMMAND}y.tab.o: ${COMMAND}grammar.yacc
D 16
	chdir ${COMMAND}; yacc -d grammar.yacc; cc -c ${CFLAGS} y.tab.c
E 16
I 16
	cd ${COMMAND}; yacc -d grammar.yacc; cc -c ${CFLAGS} y.tab.c
E 16
D 8
	rm ${COMMAND}y.tab.c
E 8
I 8
	${RM} ${COMMAND}y.tab.c
E 8

I 2
${COMMAND}lex.yy.o: ${COMMAND}token.lex ${COMMAND}y.tab.h
D 16
	chdir ${COMMAND}; lex token.lex; cc -c ${CFLAGS} lex.yy.c
E 16
I 16
	cd ${COMMAND}; lex token.lex; cc -c ${CFLAGS} lex.yy.c
E 16
D 8
	rm ${COMMAND}lex.yy.c
E 8
I 8
	${RM} ${COMMAND}lex.yy.c
E 8

E 2
${BPOBJ}:	${BREAKPOINT}bp.rep
${RUNTIMEOBJ}:	${RUNTIME}frame.rep
${PROCOBJ}:	${PROCESS}process.rep
${SYMOBJ}:	${SYM}sym.rep
${TREEOBJ}:	${TREE}tree.rep
${OBJOBJ}:	${OBJECT}objsym.rep
I 3
D 13
${OBJECT}readobj.o ${OBJECT}readsym.o: ${PASCAL}objfmt.h
E 13
I 13
${OBJECT}readobj.o ${OBJECT}readsym.o: ${SRCDIR}objfmt.h
E 13
E 3

D 6
install:
E 6
I 6
install: a.out
E 6
D 2
	cp a.out ${INSTALL}
	strip ${INSTALL}
E 2
I 2
D 15
	mv a.out ${INSTALL}
E 15
I 15
	install -s a.out ${INSTALL}
E 15
I 6

clean:
D 8
	rm a.out */*.o
E 8
I 8
D 17
	${RM} a.out */*.o
E 17
I 17
	${RM} a.out *.o */*.o
E 17
E 8

I 20
depend:

E 20
#
# Warning:  This will produce a very long listing.  You would be better
#           off just looking at things on-line.
#

print:
D 7
	pr *.h [a-z]*/*.{h,rep,c}
E 7
I 7
	pr *.h [a-z]*/*.{h,rep,yacc,lex,c}
E 7
E 6
E 2
E 1
