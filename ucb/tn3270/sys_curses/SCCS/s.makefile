h12892
s 00013/00000/00123
d D 3.2 88/03/28 11:55:24 bostic 12 11
c add Berkeley specific headers
e
s 00000/00000/00123
d D 3.1 87/08/11 10:20:05 minshall 11 10
c New version numbering.
e
s 00002/00002/00121
d D 1.10 87/07/15 15:26:25 minshall 10 9
c New directory structure.
e
s 00019/00012/00104
d D 1.9 87/07/03 15:49:41 minshall 9 8
c Add in PC stuff.
e
s 00050/00013/00066
d D 1.8 87/06/30 23:53:26 minshall 8 7
c mkmake, etc.
e
s 00008/00006/00071
d D 1.7 87/06/19 15:05:06 minshall 7 6
c New directories, new cleanup.
e
s 00010/00002/00067
d D 1.6 87/06/15 10:45:36 minshall 6 5
c sourcelist target.
e
s 00005/00003/00064
d D 1.5 87/06/12 13:52:44 minshall 5 4
c New 'system.c' file.
e
s 00005/00010/00062
d D 1.4 87/05/28 17:25:57 minshall 4 3
c New header file; translate table in separate .o file.
e
s 00008/00007/00064
d D 1.3 87/05/22 11:19:13 minshall 3 2
c New directory structure (plus cast fix in termout.c).
e
s 00003/00000/00068
d D 1.2 87/05/10 11:36:29 minshall 2 1
c ACTION.
e
s 00068/00000/00000
d D 1.1 86/11/12 12:06:16 minshall 1 0
c date and time created 86/11/12 12:06:16 by minshall
e
u
U
t
T
I 12
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
E 12
I 8
# msdos versus unix defines
O	= .o
D 9
PC_O	= .obj
E 9
I 9
#PC_O	= .obj
E 9

X	=
D 9
PC_X	= .exe
E 9
I 9
#PC_X	= .exe
E 9

I 9
L	=
#PC_L	= -link

E 9
E 8
I 1
CC	= cc
I 8
D 9
PC_CC	= cl
E 9
I 9
#PC_CC	= cl
E 9

MV	= mv
D 9
PC_MV	= rename
E 9
I 9
#PC_MV	= rename
E 9

RM	= rm -f
D 9
PC_RM= erase
E 9
I 9
#PC_RM= erase
E 9

LINT_ARGS =
D 9
PC_LINT_ARGS = -DLINT_ARGS
E 9
I 9
#PC_LINT_ARGS = -DLINT_ARGS
E 9

DEBUG_FLAGS = -g
D 9
PC_DEBUG_FLAGS = -Zi -Od
E 9
I 9
#PC_DEBUG_FLAGS = -Zi -Od
E 9

AR	= ar
D 9
C	=
PC_AR	= lib
PC_C	= +
E 9
I 9
AR1	= cr
AR2	=
AR3	=
#PC_AR	= lib
#PC_AR1	=
#PC_AR2	= +
#PC_AR3	= ";"
E 9

RANLIB	= ranlib
D 9
PC_RANLIB = echo "Done with "
E 9
I 9
#PC_RANLIB = echo "Done with "
E 9

E 8
PRINT	= print

D 8
DEFINES =
E 8
I 8
DEFINES = ${LINT_ARGS}
E 8

INCLUDES = -I.

OPTIMIZE = -O
D 8
OPTIMIZE = -g
E 8
I 8
OPTIMIZE = ${DEBUG_FLAGS}
E 8

CFLAGS	= $(OPTIMIZE) $(INCLUDES) $(DEFINES)

# Lint flags
LINTFLAGS	= -hbxaz

I 6
ALLH = terminal.h termout.ext

E 6
D 5
ALLC = termout.c
E 5
I 5
ALLC = system.c termout.c
E 5

D 5
ALLO = termout.o
E 5
I 5
D 8
ALLO = system.o termout.o
E 8
I 8
ALLO = system$O termout$O
E 8
E 5

D 6
ALLH = terminal.h
E 6
I 6
ALLPRINT =	${ALLH} ${ALLC}
E 6

I 6
ALLSOURCE =	${ALLPRINT} makefile

I 8
.c.obj:
	${CC} ${CFLAGS} -c $<

E 8
E 6
D 3
screenlib:	$(ALLO)
	ar cr screenlib $(ALLO)
	ranlib screenlib
E 3
I 3
D 7
sys.lib:	$(ALLO)
	ar cr sys.lib $(ALLO)
	ranlib sys.lib
E 7
I 7
syslib.a:	$(ALLO)
D 8
	ar cr syslib.a $(ALLO)
	ranlib syslib.a
E 8
I 8
	${RM} $@
D 9
	for i in ${ALLO}; do (${AR} cr $@ $C $$i); done
E 9
I 9
	for i in ${ALLO}; do (${AR} ${AR1} $@ ${AR2} $$i${AR3}); done
E 9
	${RANLIB} $@
E 8
E 7
E 3

clean:
D 3
	rm -f $(ALLO) disp_asc.out errs makefile.bak screenlib
E 3
I 3
D 4
	rm -f $(ALLO) disp_asc.out errs makefile.bak sys.lib
E 4
I 4
D 7
	rm -f $(ALLO) errs makefile.bak sys.lib
E 7
I 7
D 8
	rm -f $(ALLO) errs makefile.bak syslib.a
E 8
I 8
	for i in $(ALLO) errs makefile.bak syslib.a; \
		do (${RM} $$i); done

sccsclean:
E 8
	-sccs clean
	-sccs get makefile
E 7
E 4
E 3

I 6
sourcelist:	${ALLSOURCE}
	@for i in ${ALLSOURCE}; \
D 7
		do (echo ${DIRPATH}/$$i); done
E 7
I 7
		do (echo ${DIRPATH}$$i); done
E 7

E 6
print:
D 5
	${PRINT} ${ALLC} ${ALLH}
E 5
I 5
D 6
	${PRINT} ${ALLH} ${ALLC}
E 6
I 6
	${PRINT} ${ALLPRINT}
E 6
E 5

tags:	${ALLC} ${ALLH}
	ctags -t ${ALLC} ${ALLH}

I 2
action:
	${ACTION}

E 2
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
D 8
	    -e 's/\.c/.o/' | \
E 8
I 8
	    -e 's/\.c/$$O/' | \
E 8
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
	echo '$$r makedep' >>eddep
	echo '/^# DO NOT DELETE THIS LINE/+1,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
I 8
	-rm -f makefile.bak
E 8
	cp makefile makefile.bak
	ed - makefile < eddep
	rm eddep makedep

# DO NOT DELETE THIS LINE

I 5
D 8
system.o: ../general/general.h ../api/api.h ../apilib/api_exch.h
system.o: ../general/globals.h
E 5
D 3
termout.o: terminal.h ../telnet.ext ../ctlr/hostctlr.h ../ctlr/inbound.ext
termout.o: ../ctlr/options.ext ../ctlr/outbound.ext ../ctlr/screen.h
termout.o: ../keyboard/map3270.ext ../system/globals.h disp_asc.out
E 3
I 3
D 4
termout.o: ../general/general.h terminal.h ../telnet.ext ../ctlr/hostctlr.h
termout.o: ../ctlr/inbound.ext ../ctlr/oia.h ../ctlr/options.ext
termout.o: ../ctlr/outbound.ext ../ctlr/screen.h ../ascii/map3270.ext
termout.o: ../general/globals.h disp_asc.out
E 4
I 4
D 7
termout.o: ../general/general.h terminal.h ../telnet.ext ../ascii/disp_asc.h
E 7
I 7
termout.o: ../general/general.h terminal.h ../telnet.ext ../apilib/disp_asc.h
E 7
termout.o: ../ctlr/hostctlr.h ../ctlr/inbound.ext ../ctlr/oia.h
termout.o: ../ctlr/options.ext ../ctlr/outbound.ext ../ctlr/screen.h
termout.o: ../ascii/map3270.ext ../general/globals.h
E 8
I 8
D 10
system$O: ../general/general.h ../api/api.h ../apilib/api_exch.h
E 10
I 10
system$O: ../general/general.h ../ctlr/api.h ../api/api_exch.h
E 10
system$O: ../general/globals.h
D 10
termout$O: ../general/general.h terminal.h ../telnet.ext ../apilib/disp_asc.h
E 10
I 10
termout$O: ../general/general.h terminal.h ../telnet.ext ../api/disp_asc.h
E 10
termout$O: ../ctlr/hostctlr.h ../ctlr/inbound.ext ../ctlr/oia.h
termout$O: ../ctlr/options.ext ../ctlr/outbound.ext ../ctlr/screen.h
termout$O: ../ascii/map3270.ext ../general/globals.h
E 8
E 4
E 3
E 1
