h22267
s 00013/00000/00125
d D 3.2 88/03/28 12:23:44 bostic 13 12
c add Berkeley specific header
e
s 00000/00000/00125
d D 3.1 87/08/11 10:20:22 minshall 12 11
c New version numbering.
e
s 00001/00001/00124
d D 1.11 87/07/16 11:52:35 minshall 11 10
c New directory structure.
e
s 00002/00001/00123
d D 1.10 87/07/15 15:26:56 minshall 10 9
c New directory structure.
e
s 00002/00002/00122
d D 1.9 87/07/15 14:15:05 minshall 9 8
c Use support.asm
e
s 00022/00015/00102
d D 1.8 87/07/03 15:49:54 minshall 8 7
c Add in PC stuff.
e
s 00049/00012/00068
d D 1.7 87/06/30 23:53:37 minshall 7 6
c mkmake, etc.
e
s 00003/00001/00077
d D 1.6 87/06/19 15:05:24 minshall 6 5
c New directories, new cleanup.
e
s 00013/00003/00065
d D 1.5 87/06/15 10:46:08 minshall 5 4
c sourcelist target.
e
s 00005/00010/00063
d D 1.4 87/05/28 17:26:46 minshall 4 3
c New .h file; translate table in separate .o file.
e
s 00007/00005/00066
d D 1.3 87/05/22 12:21:16 minshall 3 2
c New directory structure.
e
s 00002/00002/00069
d D 1.2 87/05/13 08:57:27 minshall 2 1
c First version since split from bsd_screen (curses_screen?).
e
s 00071/00000/00000
d D 1.1 87/05/12 14:20:25 minshall 1 0
c date and time created 87/05/12 14:20:25 by minshall
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
I 7
# msdos versus unix defines
O	= .o
D 8
PC_O	= .obj
E 8
I 8
#PC_O	= .obj
E 8

X	=
D 8
PC_X	= .exe
E 8
I 8
#PC_X	= .exe
E 8

I 8
L	=
#PC_L	= -link

E 8
E 7
I 1
CC	= cc
I 7
D 8
PC_CC	= cl
E 8
I 8
#PC_CC	= cl
E 8

MV	= mv
D 8
PC_MV	= rename
E 8
I 8
#PC_MV	= rename
E 8

RM	= rm -f
D 8
PC_RM= erase
E 8
I 8
#PC_RM= erase
E 8

LINT_ARGS =
D 8
PC_LINT_ARGS = -DLINT_ARGS
E 8
I 8
#PC_LINT_ARGS = -DLINT_ARGS
E 8

DEBUG_FLAGS = -g
D 8
PC_DEBUG_FLAGS = -Zi -Od
E 8
I 8
#PC_DEBUG_FLAGS = -Zi -Od
E 8

AR	= ar
D 8
C	=
PC_AR	= lib
PC_C	= +
E 8
I 8
AR1	= cr
AR2	=
AR3	=
#PC_AR	= lib
#PC_AR1	=
#PC_AR2	= +
#PC_AR3	= ";"
E 8

RANLIB	= ranlib
D 8
PC_RANLIB = echo "Done with "
E 8
I 8
#PC_RANLIB = echo "Done with "
E 8

E 7
PRINT	= print

D 7
DEFINES =
E 7
I 7
DEFINES = ${LINT_ARGS}
E 7

INCLUDES = -I.

OPTIMIZE = -O
D 7
OPTIMIZE = -g
E 7
I 7
OPTIMIZE = ${DEBUG_FLAGS}
E 7

CFLAGS	= $(OPTIMIZE) $(INCLUDES) $(DEFINES)

# Lint flags
LINTFLAGS	= -hbxaz

D 3
ALLC = termout.c
E 3
I 3
D 5
ALLC = termout.c system.c
E 5
I 5
ALLH =	spint.h termout.ext video.h
E 5
E 3

I 5
ALLC = spintc.c system.c termout.c

D 9
ALLASM =	spintasm.asm
E 9
I 9
ALLASM =	spintasm.asm support.asm
E 9

E 5
D 3
ALLO = termout.o
E 3
I 3
D 7
ALLO = termout.o system.o
E 7
I 7
D 8
ALLO = termout$O system$O
E 8
I 8
D 9
ALLO = spintasm$O spintc$O system$O termout$O
E 9
I 9
ALLO = spintasm$O spintc$O support$O system$O termout$O
E 9
E 8
E 7
E 3

D 2
ALLH = terminal.h
E 2
I 2
D 5
ALLH =
E 5
I 5
ALLPRINT =	${ALLH} ${ALLASM} ${ALLC}
E 5
E 2

I 5
ALLSOURCE =	${ALLPRINT} makefile makefile.mak

I 7
.c.obj:
	${CC} ${CFLAGS} -c $<

E 7
E 5
D 8
screenlib:	$(ALLO)
E 8
I 8
syslib.a:	$(ALLO)
E 8
D 7
	ar cr screenlib $(ALLO)
	ranlib screenlib
E 7
I 7
	${RM} $@
D 8
	for i in ${ALLO}; do (${AR} cr $@ $C $$i); done
E 8
I 8
	for i in ${ALLO}; do (${AR} ${AR1} $@ ${AR2} $$i${AR3}); done
E 8
	${RANLIB} $@
E 7

clean:
D 4
	rm -f $(ALLO) disp_asc.out errs makefile.bak screenlib
E 4
I 4
D 7
	rm -f $(ALLO) errs makefile.bak screenlib
E 7
I 7
D 8
	for i in $(ALLO) errs makefile.bak screenlib; \
E 8
I 8
	for i in $(ALLO) errs makefile.bak syslib.a; \
E 8
		do (${RM} $$i); done

sccsclean:
E 7
I 6
	-sccs clean
	-sccs get makefile
E 6
E 4

I 5
sourcelist:	${ALLSOURCE}
	@for i in ${ALLSOURCE}; \
D 6
		do (echo ${DIRPATH}/$$i); done
E 6
I 6
		do (echo ${DIRPATH}$$i); done
E 6

E 5
print:
D 5
	${PRINT} ${ALLC} ${ALLH}
E 5
I 5
	${PRINT} ${ALLPRINT}
E 5

tags:	${ALLC} ${ALLH}
	ctags -t ${ALLC} ${ALLH}

action:
	${ACTION}

lint:
	lint ${LINTFLAGS} ${INCLUDES} ${DEFINES} -DTN3270 \
				${TNMAIN} ${MOSTC} -lcurses
	lint ${LINTFLAGS} ${INCLUDES} ${DEFINES} ${MSMAIN} map3270.c -lcurses

.DEFAULT:
	sccs get $<

D 4
disp_asc.out:	../ctlr/ebc_disp.o
	(cd ../tools; make mkdstoas $(MFLAGS) )
	-/bin/rm $@
	../tools/mkdstoas > $@

E 4
depend:
	grep '^#include' ${ALLC} ${ALLH} | grep -v '<' | \
	sed -e 's/:[^"]*"\([^"]*\)".*/: \1/' \
D 7
	    -e 's/\.c/.o/' | \
E 7
I 7
	    -e 's/\.c/$$O/' | \
E 7
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
	echo '$$r makedep' >>eddep
	echo '/^# DO NOT DELETE THIS LINE/+1,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
I 7
	-rm -f makefile.bak
E 7
	cp makefile makefile.bak
	ed - makefile < eddep
	rm eddep makedep

# DO NOT DELETE THIS LINE

I 10
spintc$O: ../general/general.h spint.h
system$O: ../general/general.h ../ctlr/api.h spint.h ../general/globals.h
E 10
D 2
termout.o: terminal.h ../telnet.ext ../ctlr/hostctlr.h ../ctlr/inbound.ext
E 2
I 2
D 3
termout.o: ../telnet.ext ../ctlr/hostctlr.h ../ctlr/inbound.ext
E 2
termout.o: ../ctlr/options.ext ../ctlr/outbound.ext ../ctlr/screen.h
termout.o: ../keyboard/map3270.ext ../system/globals.h disp_asc.out
E 3
I 3
D 4
termout.o: ../general.h ../telnet.ext ../ctlr/hostctlr.h ../ctlr/inbound.ext
E 4
I 4
D 7
termout.o: ../general/general.h ../telnet.ext ../ascii/disp_asc.h
termout.o: ../ascii/map3270.ext ../ctlr/hostctlr.h ../ctlr/inbound.ext
E 4
termout.o: ../ctlr/oia.h ../ctlr/options.ext ../ctlr/outbound.ext
D 4
termout.o: ../ctlr/screen.h ../keyboard/map3270.ext ../system/globals.h video.h
termout.o: disp_asc.out
system.o: ../api/api.h spint.h
E 4
I 4
termout.o: ../ctlr/screen.h ../general/globals.h video.h
system.o: ../general/general.h ../api/api.h spint.h ../general/globals.h
E 7
I 7
D 11
termout$O: ../general/general.h ../telnet.ext ../ascii/disp_asc.h
E 11
I 11
termout$O: ../general/general.h ../telnet.ext ../api/disp_asc.h
E 11
termout$O: ../ascii/map3270.ext ../ctlr/hostctlr.h ../ctlr/inbound.ext
termout$O: ../ctlr/oia.h ../ctlr/options.ext ../ctlr/outbound.ext
termout$O: ../ctlr/screen.h ../general/globals.h video.h
D 10
system$O: ../general/general.h ../api/api.h spint.h ../general/globals.h
E 10
E 7
E 4
E 3
E 1
