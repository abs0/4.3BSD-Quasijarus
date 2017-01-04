h38672
s 00013/00000/00146
d D 3.2 88/03/28 12:28:48 bostic 13 12
c add Berkeley specific headers
e
s 00000/00000/00146
d D 3.1 87/08/11 10:19:10 minshall 12 11
c New version numbering.
e
s 00019/00012/00127
d D 1.11 87/07/03 15:49:34 minshall 11 10
c Add in PC stuff.
e
s 00048/00011/00091
d D 1.10 87/06/30 23:53:21 minshall 10 9
c mkmake, etc.
e
s 00009/00008/00093
d D 1.9 87/06/19 15:04:47 minshall 9 8
c New directories, new cleanup.
e
s 00005/00004/00096
d D 1.8 87/06/18 13:56:32 minshall 8 7
c Add vaxbsubs.s and genbsubs.c.
e
s 00010/00002/00090
d D 1.7 87/06/15 10:45:44 minshall 7 6
c sourcelist targets.
e
s 00006/00005/00086
d D 1.6 87/05/22 11:18:44 minshall 6 5
c New directory structure
e
s 00003/00000/00088
d D 1.5 87/05/10 11:37:06 minshall 5 4
c ACTION
e
s 00001/00001/00087
d D 1.4 87/05/10 11:15:35 minshall 4 3
c 
e
s 00001/00001/00087
d D 1.3 87/04/01 16:10:06 minshall 3 2
c Make close/open sequences work in a more rational manner.
e
s 00014/00001/00074
d D 1.2 86/11/16 15:37:53 minshall 2 1
c bsubs belong in the "system" directory.
e
s 00075/00000/00000
d D 1.1 86/11/16 15:33:49 minshall 1 0
c date and time created 86/11/16 15:33:49 by minshall
e
u
U
t
T
I 13
#
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
#
#	%W% (Berkeley) %G%
#
E 13
I 10
# msdos versus unix defines
O	= .o
D 11
PC_O	= .obj
E 11
I 11
#PC_O	= .obj
E 11

X	=
D 11
PC_X	= .exe
E 11
I 11
#PC_X	= .exe
E 11

I 11
L	=
#PC_L	= -link

E 11
E 10
I 1
CC	= cc
I 10
D 11
PC_CC	= cl
E 11
I 11
#PC_CC	= cl
E 11

MV	= mv
D 11
PC_MV	= rename
E 11
I 11
#PC_MV	= rename
E 11

RM	= rm -f
D 11
PC_RM= erase
E 11
I 11
#PC_RM= erase
E 11

LINT_ARGS =
D 11
PC_LINT_ARGS = -DLINT_ARGS
E 11
I 11
#PC_LINT_ARGS = -DLINT_ARGS
E 11

DEBUG_FLAGS = -g
D 11
PC_DEBUG_FLAGS = -Zi -Od
E 11
I 11
#PC_DEBUG_FLAGS = -Zi -Od
E 11

AR	= ar
D 11
C	=
PC_AR	= lib
PC_C	= +
E 11
I 11
AR1	= cr
AR2	=
AR3	=
#PC_AR	= lib
#PC_AR1	=
#PC_AR2	= +
#PC_AR3	= ";"
E 11

RANLIB	= ranlib
D 11
PC_RANLIB = echo "Done with "
E 11
I 11
#PC_RANLIB = echo "Done with "
E 11

E 10
PRINT	= print

D 10
DEFINES = 
E 10
I 10
DEFINES = ${LINT_ARGS}
E 10

D 3
INCLUDES = -I.
E 3
I 3
D 4
INCLUDES = -I. -I..
E 4
I 4
INCLUDES = -I.
E 4
E 3

OPTIMIZE = -O
D 10
OPTIMIZE = -g
E 10
I 10
OPTIMIZE = ${DEBUG_FLAGS}
E 10

CFLAGS	= $(OPTIMIZE) $(INCLUDES) $(DEFINES)

# Lint flags
LINTFLAGS	= -hbxaz
# How to install the bloody thing...

DESTDIR=

BINDIR		= $(DESTDIR)/usr/ucb
ETCDIR		= $(DESTDIR)/etc
MANDIR		= $(DESTDIR)/usr/man/man

# Names for the terminal libraries...
LIBCURSES	= -lcurses
LIBTERM		= -ltermlib

# The source files...
D 7
ALLH =	globals.h
E 7
I 7
ALLH =	bsubs.ext general.h globals.h
E 7

ALLC =	globals.c

I 7
D 8
ALLPRINT =	${ALLH} ${ALLC}

ALLSOURCE =	${ALLPRINT} makefile makefile.mak

E 8
E 7
D 2
ALLO	= globals.o
E 2
I 2
#
#	In a vax environment, we use vaxbsubs.s, which gives us a fair amount
#	of increased performance.  We have provided genbsubs.c, which perform
#	(more or less) the same function.
SUBS = vaxbsubs.s
SUBS = genbsubs.c

D 10
SUBSO = vaxbsubs.o
SUBSO = genbsubs.o
E 10
I 10
SUBSO = vaxbsubs$O
SUBSO = genbsubs$O
E 10

ALLS = vaxbsubs.s
I 8

ALLPRINT =	${ALLH} ${ALLC} vaxbsubs.s genbsubs.c

ALLSOURCE =	${ALLPRINT} makefile makefile.mak

E 8
ALLS =

D 10
ALLO	= globals.o ${SUBSO}
E 10
I 10
ALLO	= globals$O ${SUBSO}
E 10
E 2

.s.o:
	/lib/cpp -E $< | as -o $@

I 10
.c.obj:
	${CC} ${CFLAGS} -c $<

E 10
D 6
systemlib:	${ALLO}
	ar cr systemlib ${ALLO}
	ranlib systemlib
E 6
I 6
D 9
general.lib:	${ALLO}
	ar cr general.lib ${ALLO}
	ranlib general.lib
E 9
I 9
generallib.a:	${ALLO}
D 10
	ar cr generallib.a ${ALLO}
	ranlib generallib.a
E 10
I 10
	${RM} $@
D 11
	for i in ${ALLO}; do (${AR} cr $@ $C $$i); done
E 11
I 11
	for i in ${ALLO}; do (${AR} ${AR1} $@ ${AR2} $$i${AR3}); done
E 11
	${RANLIB} $@
E 10
E 9
E 6

clean:
D 6
	rm -f $(ALLO) errs makefile.bak systemlib
E 6
I 6
D 9
	rm -f $(ALLO) errs makefile.bak general.lib
E 9
I 9
D 10
	rm -f $(ALLO) errs makefile.bak generallib.a
E 10
I 10
	for i in $(ALLO) errs makefile.bak generallib.a; \
		do (${RM} $$i); done

sccsclean:
E 10
	-sccs clean
	-sccs get makefile
E 9
E 6

I 7
sourcelist:	${ALLSOURCE}
	@for i in ${ALLSOURCE}; \
D 9
		do (echo ${DIRPATH}/$$i); done
E 9
I 9
		do (echo ${DIRPATH}$$i); done
E 9

E 7
print:
D 7
	${PRINT} ${ALLH} ${ALLC}
E 7
I 7
	${PRINT} ${ALLPRINT}
E 7

tags:	${ALLC} ${ALLH}
	ctags -t ${ALLC} ${ALLH}

I 5
action:
	${ACTION}

E 5
lint:
	lint ${LINTFLAGS} ${INCLUDES} ${DEFINES} ${ALLC}

.DEFAULT:
	sccs get $<

depend:
	grep '^#include' ${ALLC} ${ALLH} | grep -v '<' | \
	sed -e 's/:[^"]*"\([^"]*\)".*/: \1/' \
D 10
	    -e 's/\.c/.o/' | \
E 10
I 10
	    -e 's/\.c/$$O/' | \
E 10
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
	echo '$$r makedep' >>eddep
	echo '/^# DO NOT DELETE THIS LINE/+1,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
I 10
	-rm -f makefile.bak
E 10
	cp makefile makefile.bak
	ed - makefile < eddep
	rm eddep makedep

# DO NOT DELETE THIS LINE

D 9
globals.o: ../ctlr/hostctlr.h ../ascii/ascebc.h ../ctlr/dctype.h
D 6
globals.o: ../ctlr/options.h ../ctlr/screen.h ../keyboard/state.h globals.h
E 6
I 6
globals.o: ../ctlr/options.h ../ctlr/screen.h ../ascii/state.h globals.h
globals.o: ../general/general.h
E 9
I 9
D 10
globals.o: ../ctlr/hostctlr.h ../ctlr/oia.h ../ctlr/options.h ../ctlr/screen.h
globals.o: globals.h ../general/general.h
E 10
I 10
globals$O: ../ctlr/hostctlr.h ../ctlr/oia.h ../ctlr/options.h ../ctlr/screen.h
globals$O: globals.h ../general/general.h
E 10
E 9
E 6
E 1
