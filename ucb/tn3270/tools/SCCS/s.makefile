h41202
s 00013/00000/00181
d D 3.2 88/03/28 12:08:14 bostic 17 16
c add Berkeley specific headers
e
s 00000/00000/00181
d D 3.1 87/08/11 10:20:48 minshall 16 15
c New version numbering.
e
s 00004/00001/00177
d D 1.15 87/07/16 12:16:22 minshall 15 14
c Remove mkmake from PC tools.
e
s 00028/00028/00150
d D 1.14 87/07/15 15:27:21 minshall 14 13
c New directory structure.
e
s 00034/00021/00144
d D 1.13 87/07/03 15:50:09 minshall 13 12
c Add in PC stuff; move in mkmake.y.
e
s 00080/00042/00085
d D 1.12 87/06/30 23:53:43 minshall 12 11
c mkmake, etc.
e
s 00003/00003/00124
d D 1.11 87/06/19 15:05:36 minshall 11 10
c New directories, new cleanup.
e
s 00033/00034/00094
d D 1.10 87/06/19 12:52:52 minshall 10 9
c Directory changes.
e
s 00012/00004/00116
d D 1.9 87/06/15 10:46:16 minshall 9 8
c sourcelist target.
e
s 00009/00002/00111
d D 1.8 87/06/08 08:47:52 minshall 8 7
c Convert to work without termcodes.m4 (== m4.out).
e
s 00002/00005/00111
d D 1.7 87/05/31 17:10:23 minshall 7 6
c Version without termcodes.m4.
e
s 00002/00002/00114
d D 1.6 87/05/31 10:52:39 minshall 6 5
c 'ectype' is NOT an executable.
e
s 00013/00011/00103
d D 1.5 87/05/22 09:52:10 minshall 5 4
c New directory structure.
e
s 00010/00004/00104
d D 1.4 87/05/21 21:59:19 minshall 4 3
c Add mkastods.c
e
s 00015/00000/00093
d D 1.3 87/05/10 16:41:17 minshall 3 2
c Try to make work after a 'make clean'
e
s 00003/00000/00090
d D 1.2 87/05/10 11:38:53 minshall 2 1
c ACTION
e
s 00090/00000/00000
d D 1.1 87/05/10 11:38:19 minshall 1 0
c date and time created 87/05/10 11:38:19 by minshall
e
u
U
t
T
I 17
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
E 17
I 12
# msdos versus unix defines
O	= .o
D 13
PC_O	= .obj
E 13
I 13
#PC_O	= .obj
E 13

X	=
D 13
PC_X	= .exe
E 13
I 13
#PC_X	= .exe
E 13

I 13
L	=
#PC_L	= -link

E 13
E 12
I 1
CC	= cc
I 12
D 13
PC_CC	= cl
E 13
I 13
#PC_CC	= cl
E 13

MV	= mv
D 13
PC_MV	= rename
E 13
I 13
#PC_MV	= rename
E 13

RM	= rm -f
D 13
PC_RM= erase
E 13
I 13
#PC_RM= erase
E 13

LINT_ARGS =
D 13
PC_LINT_ARGS = -DLINT_ARGS
E 13
I 13
#PC_LINT_ARGS = -DLINT_ARGS
E 13

DEBUG_FLAGS = -g
D 13
PC_DEBUG_FLAGS = -Zi -Od
E 13
I 13
#PC_DEBUG_FLAGS = -Zi -Od
E 13

AR	= ar
D 13
C	=
PC_AR	= lib
PC_C	= +
E 13
I 13
AR1	= cr
AR2	=
AR3	=
#PC_AR	= lib
#PC_AR1	=
#PC_AR2	= +
#PC_AR3	= ";"
E 13

RANLIB	= ranlib
D 13
PC_RANLIB = echo "Done with "
E 13
I 13
#PC_RANLIB = echo "Done with "
E 13

E 12
PRINT	= print

I 12
DEFINES	= ${LINT_ARGS}

E 12
INCLUDES = -I.

OPTIMIZE = -O
D 12
OPTIMIZE = -g
E 12
I 12
OPTIMIZE = ${DEBUG_FLAGS}
E 12

CFLAGS	= $(OPTIMIZE) $(INCLUDES) $(DEFINES)

# Lint flags
LINTFLAGS	= -hbxaz

D 4
ALLC = dohits.c ectype.c mkastosc.c mkdctype.c mkdstoas.c mkhits.c prt3270.c
E 4
I 4
D 9
ALLC = dohits.c ectype.c mkastosc.c mkdctype.c \
		mkastods.c mkdstoas.c mkhits.c prt3270.c
E 4

E 9
ALLH = dohits.h ectype.h

I 13
ALLY = mkmake.y

E 13
I 9
ALLC = dohits.c ectype.c mkastods.c mkastosc.c mkdctype.c \
		mkdstoas.c mkhits.c prt3270.c

E 9
D 4
ALLO =	prt3270.o mkdctype.o ectype.o mkdstoas.o mkhits.o dohits.o mkastosc.o
E 4
I 4
D 12
ALLO =	prt3270.o mkdctype.o ectype.o \
		mkastods.o mkdstoas.o mkhits.o dohits.o mkastosc.o
E 12
I 12
ALLO =	prt3270$O mkdctype$O ectype$O \
D 13
		mkastods$O mkdstoas$O mkhits$O dohits$O mkastosc$O
E 13
I 13
		mkastods$O mkdstoas$O mkhits$O mkmake$O dohits$O mkastosc$O
E 13
E 12
E 4

I 9
D 13
ALLPRINT =	${ALLH} ${ALLC}
E 13
I 13
ALLPRINT =	${ALLH} ${ALLC} ${ALLY}
E 13

ALLSOURCE =	${ALLPRINT} makefile makefile.mak

I 15
MKMAKE		= mkmake$X
#PC_MKMAKE	=

E 15
E 9
D 4
ALLEXE = prt3270 mkdctype ectype mkdstoas mkhits mkastosc
E 4
I 4
D 6
ALLEXE = prt3270 mkdctype ectype mkastods mkdstoas mkhits mkastosc
E 6
I 6
D 13
ALLEXE	=	mkastods mkastosc mkdctype mkdstoas mkhits prt3270
E 13
I 13
ALLEXE	=	mkastods$X mkastosc$X mkdctype$X mkdstoas$X \
D 15
			mkhits$X mkmake$X prt3270$X
E 15
I 15
			mkhits$X ${MKMAKE} prt3270$X
E 15
E 13
E 6
E 4

I 12
.c.obj:
	${CC} ${CFLAGS} -c $<

E 12
tools:
	@echo Need to specify WHICH tool ...

D 4
all:	mkastosc mkhits mkdstoas mkdctype prt3270
E 4
I 4
D 6
all:	mkastosc mkhits mkastods mkdstoas mkdctype prt3270
E 6
I 6
all:	${ALLEXE}
E 6
E 4
	@echo done.

D 5
prt3270:	prt3270.o ../system/globals.o ../ascii/ebctab.o
	${CC} ${CFLAGS} -o prt3270 prt3270.o ../system/globals.o \
E 5
I 5
D 8
prt3270:	prt3270.o ../general/globals.o ../ascii/ebctab.o
E 8
I 8
D 10
prt3270:	prt3270.o ../general/globals.o ../ascii/ebctab.o \
				../ascii/astosc.o ../ctlr/kbd.out
E 10
I 10
D 12
prt3270:	prt3270.o ../general/globals.o ../apilib/asc_ebc.o \
				../apilib/astosc.o ../ctlr/kbd.out
E 10
E 8
	${CC} ${CFLAGS} -o prt3270 prt3270.o ../general/globals.o \
E 5
D 8
							../ascii/ebctab.o
E 8
I 8
D 10
					../ascii/ebctab.o ../ascii/astosc.o
E 10
I 10
					../apilib/asc_ebc.o ../apilib/astosc.o
E 12
I 12
D 13
prt3270:	prt3270$O ../general/globals$O ../apilib/asc_ebc$O \
E 13
I 13
D 14
prt3270$X:	prt3270$O ../general/globals$O ../apilib/asc_ebc$O \
E 13
				../apilib/astosc$O ../ctlr/kbd.out
E 14
I 14
prt3270$X:	prt3270$O ../general/globals$O ../api/asc_ebc$O \
				../api/astosc$O ../ctlr/kbd.out
E 14
	${CC} ${CFLAGS} -o prt3270 prt3270$O ../general/globals$O \
D 14
					../apilib/asc_ebc$O ../apilib/astosc$O
E 14
I 14
					../api/asc_ebc$O ../api/astosc$O
E 14
E 12
E 10
E 8

D 10
mkastosc:	mkastosc.o dohits.o ../ascii/asctab.o ../ctlr/ebc_disp.o
E 10
I 10
D 12
mkastosc:	mkastosc.o dohits.o ../apilib/asc_ebc.o ../apilib/ebc_disp.o
E 10
	$(CC) $(CFLAGS) -o mkastosc mkastosc.o dohits.o \
D 10
			../ascii/asctab.o ../ctlr/ebc_disp.o
E 10
I 10
			../apilib/asc_ebc.o ../apilib/ebc_disp.o
E 12
I 12
D 13
mkastosc:	mkastosc$O dohits$O ../apilib/asc_ebc$O ../apilib/ebc_disp$O
E 13
I 13
D 14
mkastosc$X:	mkastosc$O dohits$O ../apilib/asc_ebc$O ../apilib/ebc_disp$O
E 14
I 14
mkastosc$X:	mkastosc$O dohits$O ../api/asc_ebc$O ../api/ebc_disp$O
E 14
E 13
	$(CC) $(CFLAGS) -o mkastosc mkastosc$O dohits$O \
D 14
			../apilib/asc_ebc$O ../apilib/ebc_disp$O
E 14
I 14
			../api/asc_ebc$O ../api/ebc_disp$O
E 14
E 12
E 10
I 4

D 10
mkastods:	mkastods.o ../ascii/asctab.o ../ctlr/ebc_disp.o
	$(CC) $(CFLAGS) -o mkastods mkastods.o ../ascii/asctab.o \
						../ctlr/ebc_disp.o
E 10
I 10
D 12
mkastods:	mkastods.o ../apilib/asc_ebc.o ../apilib/ebc_disp.o
	$(CC) $(CFLAGS) -o mkastods mkastods.o ../apilib/asc_ebc.o \
						../apilib/ebc_disp.o
E 12
I 12
D 13
mkastods:	mkastods$O ../apilib/asc_ebc$O ../apilib/ebc_disp$O
E 13
I 13
D 14
mkastods$X:	mkastods$O ../apilib/asc_ebc$O ../apilib/ebc_disp$O
E 13
	$(CC) $(CFLAGS) -o mkastods mkastods$O ../apilib/asc_ebc$O \
						../apilib/ebc_disp$O
E 14
I 14
mkastods$X:	mkastods$O ../api/asc_ebc$O ../api/ebc_disp$O
	$(CC) $(CFLAGS) -o mkastods mkastods$O ../api/asc_ebc$O \
						../api/ebc_disp$O
E 14
E 12
E 10
E 4

D 10
mkdstoas:	mkdstoas.o ../ascii/ebctab.o ../ctlr/ebc_disp.o
	$(CC) $(CFLAGS) -o mkdstoas mkdstoas.o ../ascii/ebctab.o \
						../ctlr/ebc_disp.o
E 10
I 10
D 12
mkdstoas:	mkdstoas.o ../apilib/asc_ebc.o ../apilib/ebc_disp.o
	$(CC) $(CFLAGS) -o mkdstoas mkdstoas.o ../apilib/asc_ebc.o \
						../apilib/ebc_disp.o
E 12
I 12
D 13
mkdstoas:	mkdstoas$O ../apilib/asc_ebc$O ../apilib/ebc_disp$O
E 13
I 13
D 14
mkdstoas$X:	mkdstoas$O ../apilib/asc_ebc$O ../apilib/ebc_disp$O
E 13
	$(CC) $(CFLAGS) -o mkdstoas mkdstoas$O ../apilib/asc_ebc$O \
						../apilib/ebc_disp$O
E 14
I 14
mkdstoas$X:	mkdstoas$O ../api/asc_ebc$O ../api/ebc_disp$O
	$(CC) $(CFLAGS) -o mkdstoas mkdstoas$O ../api/asc_ebc$O \
						../api/ebc_disp$O
E 14
E 12
E 10

D 10
mkhits:	mkhits.o dohits.o ../ascii/asctab.o ../ctlr/ebc_disp.o
	$(CC) $(CFLAGS) -o mkhits mkhits.o dohits.o ../ascii/asctab.o \
						../ctlr/ebc_disp.o
E 10
I 10
D 12
mkhits:	mkhits.o dohits.o ../apilib/asc_ebc.o ../apilib/ebc_disp.o
	$(CC) $(CFLAGS) -o mkhits mkhits.o dohits.o ../apilib/asc_ebc.o \
						../apilib/ebc_disp.o
E 12
I 12
D 13
mkhits:	mkhits$O dohits$O ../apilib/asc_ebc$O ../apilib/ebc_disp$O
E 13
I 13
D 14
mkhits$X:	mkhits$O dohits$O ../apilib/asc_ebc$O ../apilib/ebc_disp$O
E 13
	$(CC) $(CFLAGS) -o mkhits mkhits$O dohits$O ../apilib/asc_ebc$O \
						../apilib/ebc_disp$O
E 14
I 14
mkhits$X:	mkhits$O dohits$O ../api/asc_ebc$O ../api/ebc_disp$O
	$(CC) $(CFLAGS) -o mkhits mkhits$O dohits$O ../api/asc_ebc$O \
						../api/ebc_disp$O
E 14
E 12
E 10

D 10
mkdctype:	mkdctype.o ../ctlr/ebc_disp.o ectype.o
	$(CC) $(CFLAGS) -o mkdctype mkdctype.o ../ctlr/ebc_disp.o ectype.o
E 10
I 10
D 12
mkdctype:	mkdctype.o ../apilib/ebc_disp.o ectype.o
	$(CC) $(CFLAGS) -o mkdctype mkdctype.o ../apilib/ebc_disp.o ectype.o
E 12
I 12
D 13
mkdctype:	mkdctype$O ../apilib/ebc_disp$O ectype$O
E 13
I 13
mkmake:	mkmake$O
	${CC} ${CFLAGS} -o mkmake mkmake$O

D 14
mkdctype$X:	mkdctype$O ../apilib/ebc_disp$O ectype$O
E 13
	$(CC) $(CFLAGS) -o mkdctype mkdctype$O ../apilib/ebc_disp$O ectype$O
E 14
I 14
mkdctype$X:	mkdctype$O ../api/ebc_disp$O ectype$O
	$(CC) $(CFLAGS) -o mkdctype mkdctype$O ../api/ebc_disp$O ectype$O
E 14
E 12
E 10

I 8
D 10
../ascii/astosc.o:
	(cd ../ascii; make astosc.o)
E 10
I 10
D 12
../apilib/astosc.o:
	(cd ../apilib; make astosc.o)
E 12
I 12
D 14
../apilib/astosc$O:
	(cd ../apilib; make astosc$O)
E 14
I 14
../api/astosc$O:
	(cd ../api; make astosc$O)
E 14
E 12
E 10

E 8
I 3
D 10
../ascii/ebctab.o:
	(cd ../ascii; make ebctab.o)
E 10
I 10
D 12
../apilib/asc_ebc.o:
	(cd ../apilib; make asc_ebc.o)
E 12
I 12
D 14
../apilib/asc_ebc$O:
	(cd ../apilib; make asc_ebc$O)
E 14
I 14
../api/asc_ebc$O:
	(cd ../api; make asc_ebc$O)
E 14
E 12
E 10
I 8

../ctlr/kbd.out:
	(cd ../ctlr; make kbd.out)
E 8

D 10
../ctlr/ebc_disp.o:
	(cd ../ctlr; make ebc_disp.o)
E 10
I 10
D 12
../apilib/ebc_disp.o:
	(cd ../apilib; make ebc_disp.o)
E 12
I 12
D 14
../apilib/ebc_disp$O:
	(cd ../apilib; make ebc_disp$O)
E 14
I 14
../api/ebc_disp$O:
	(cd ../api; make ebc_disp$O)
E 14
E 12
E 10

D 10
../ascii/asctab.o:
	(cd ../ascii; make asctab.o)

E 10
D 5
../keyboard/m4.out:
	(cd ../keyboard; make m4.out)
E 5
I 5
D 7
../ascii/m4.out:
	(cd ../ascii; make m4.out)
E 5

E 7
D 5
../system/globals.o:
	(cd ../system; make globals.o)
E 5
I 5
D 12
../general/globals.o:
	(cd ../general; make globals.o)
E 12
I 12
../general/globals$O:
	(cd ../general; make globals$O)
E 12
E 5

I 9
sourcelist:	${ALLSOURCE}
	@for i in ${ALLSOURCE}; \
D 11
		do (echo ${DIRPATH}/$$i); done
E 11
I 11
		do (echo ${DIRPATH}$$i); done
E 11

E 9
E 3
print:
D 9
	${PRINT} ${ALLH} ${ALLC}
E 9
I 9
	${PRINT} ${ALLPRINT}
E 9

tags:	${ALLC} ${ALLH}
	ctags -t ${ALLC} ${ALLH}

I 2
action:
	${ACTION}

E 2
clean:
D 11
	-rm errs makefile.bak ${ALLO} ${ALLEXE}
I 10
	sccs clean
E 11
I 11
D 12
	-rm -f errs makefile.bak ${ALLO} ${ALLEXE}
E 12
I 12
D 13
	for i in errs makefile.bak ${ALLO} ${ALLEXE}; \
E 13
I 13
	for i in errs makefile.bak y.tab.c y.output ${ALLO} ${ALLEXE}; \
E 13
		do (${RM} $$i); done

sccsclean:
E 12
	-sccs clean
E 11
	-sccs get makefile
E 10

lint:
	lint ${LINTFLAGS} ${INCLUDES} ${DEFINES} -DTN3270 \
				${TNMAIN} ${MOSTC} -lcurses
	lint ${LINTFLAGS} ${INCLUDES} ${DEFINES} ${MSMAIN} map3270.c -lcurses

.DEFAULT:
	sccs get $<

depend:
	grep '^#include' ${ALLC} | grep -v '<' | \
	sed -e 's/:[^"]*"\([^"]*\)".*/: \1/' \
D 12
	    -e 's/\.c/.o/' | \
E 12
I 12
	    -e 's/\.c/$$O/' | \
E 12
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
	echo '$$r makedep' >>eddep
	echo '/^# DO NOT DELETE THIS LINE/+1,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
I 12
	-rm -f makefile.bak
E 12
	cp makefile makefile.bak
	ed - makefile < eddep
	rm eddep makedep

# DO NOT DELETE THIS LINE

D 5
dohits.o: ../ascii/ascebc.h ../ctlr/ebc_disp.h ../ctlr/function.h dohits.h
E 5
I 5
D 10
dohits.o: ../general/general.h ../ascii/ascebc.h ../ctlr/ebc_disp.h
E 10
I 10
D 12
dohits.o: ../general/general.h ../apilib/asc_ebc.h ../apilib/ebc_disp.h
E 10
dohits.o: ../ctlr/function.h dohits.h
E 5
ectype.o: ectype.h
D 5
mkastosc.o: ../keyboard/m4.out ../ascii/ascebc.h ../ctlr/ebc_disp.h
mkastosc.o: ../ctlr/function.h dohits.h
E 5
I 5
D 7
mkastosc.o: ../general/general.h ../ascii/m4.out ../ascii/ascebc.h
E 7
I 7
D 10
mkastosc.o: ../general/general.h ../ascii/ascebc.h
E 7
mkastosc.o: ../ctlr/ebc_disp.h ../ctlr/function.h dohits.h
E 5
mkdctype.o: ../ctlr/ebc_disp.h ectype.h
I 5
mkastods.o: ../ascii/ascebc.h ../ctlr/ebc_disp.h
E 5
mkdstoas.o: ../ascii/ascebc.h ../ctlr/ebc_disp.h
mkhits.o: ../ascii/ascebc.h ../ctlr/ebc_disp.h ../ctlr/function.h dohits.h
D 5
prt3270.o: ../ascii/ascebc.h ../ctlr/hostctlr.h ../ctlr/screen.h
prt3270.o: ../keyboard/m4.out ../system/globals.h
E 5
I 5
prt3270.o: ../general/general.h ../ascii/ascebc.h ../ctlr/hostctlr.h
D 7
prt3270.o: ../ctlr/screen.h ../ascii/m4.out ../general/globals.h
E 7
I 7
prt3270.o: ../ctlr/screen.h ../general/globals.h
E 10
I 10
mkastods.o: ../apilib/asc_ebc.h ../apilib/ebc_disp.h
mkastosc.o: ../general/general.h ../ctlr/function.h dohits.h
mkdctype.o: ../apilib/ebc_disp.h ectype.h
mkdstoas.o: ../apilib/asc_ebc.h ../apilib/ebc_disp.h
mkhits.o: ../ctlr/function.h dohits.h
prt3270.o: ../general/general.h ../apilib/asc_ebc.h ../ctlr/hostctlr.h
prt3270.o: ../ctlr/screen.h ../ctlr/function.h ../apilib/astosc.h
prt3270.o: ../general/globals.h ../ctlr/kbd.out
E 12
I 12
D 14
dohits$O: ../general/general.h ../apilib/asc_ebc.h ../apilib/ebc_disp.h
E 14
I 14
dohits$O: ../general/general.h ../api/asc_ebc.h ../api/ebc_disp.h
E 14
dohits$O: ../ctlr/function.h dohits.h
ectype$O: ectype.h
D 14
mkastods$O: ../apilib/asc_ebc.h ../apilib/ebc_disp.h
E 14
I 14
mkastods$O: ../api/asc_ebc.h ../api/ebc_disp.h
E 14
mkastosc$O: ../general/general.h ../ctlr/function.h dohits.h
D 14
mkdctype$O: ../apilib/ebc_disp.h ectype.h
mkdstoas$O: ../apilib/asc_ebc.h ../apilib/ebc_disp.h
E 14
I 14
mkdctype$O: ../api/ebc_disp.h ectype.h
mkdstoas$O: ../api/asc_ebc.h ../api/ebc_disp.h
E 14
mkhits$O: ../ctlr/function.h dohits.h
D 14
prt3270$O: ../general/general.h ../apilib/asc_ebc.h ../ctlr/hostctlr.h
prt3270$O: ../ctlr/screen.h ../ctlr/function.h ../apilib/astosc.h
E 14
I 14
prt3270$O: ../general/general.h ../api/asc_ebc.h ../ctlr/hostctlr.h
prt3270$O: ../ctlr/screen.h ../ctlr/function.h ../api/astosc.h
E 14
prt3270$O: ../general/globals.h ../ctlr/kbd.out
E 12
E 10
E 7
E 5
E 1
