h20343
s 00013/00000/00130
d D 3.2 88/03/28 12:54:41 bostic 13 12
c add Berkeley specific header
e
s 00000/00000/00130
d D 3.1 87/08/11 10:18:18 minshall 12 11
c New version numbering.
e
s 00003/00003/00127
d D 1.11 87/07/15 15:25:03 minshall 11 10
c New directory structure
e
s 00019/00012/00111
d D 1.10 87/07/03 15:49:08 minshall 10 9
c Add in PC stuff.
e
s 00051/00014/00072
d D 1.9 87/06/30 23:53:09 minshall 9 8
c mkmake, etc.
e
s 00014/00037/00072
d D 1.8 87/06/19 15:04:20 minshall 8 7
c New directories, new cleanup.
e
s 00003/00002/00106
d D 1.7 87/06/15 14:59:43 minshall 7 6
c Add mset.c to ALLC (but not ALLO).
e
s 00010/00002/00098
d D 1.6 87/06/15 10:45:15 minshall 6 5
c sourcelist target.
e
s 00010/00016/00090
d D 1.5 87/05/31 17:09:48 minshall 5 4
c Version without termcodes.m4.
e
s 00022/00005/00084
d D 1.4 87/05/28 17:22:21 minshall 4 3
c Add disp_asc.o
e
s 00034/00012/00055
d D 1.3 87/05/22 09:53:30 minshall 3 2
c New directory structure.
e
s 00003/00000/00064
d D 1.2 87/05/10 11:32:59 minshall 2 1
c ACTION.
e
s 00064/00000/00000
d D 1.1 87/05/10 11:28:05 minshall 1 0
c date and time created 87/05/10 11:28:05 by minshall
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
I 9
# msdos versus unix defines
O	= .o
D 10
PC_O	= .obj
E 10
I 10
#PC_O	= .obj
E 10

X	=
D 10
PC_X	= .exe
E 10
I 10
#PC_X	= .exe
E 10

I 10
L	=
#PC_L	= -link

E 10
E 9
I 1
CC	= cc
I 9
D 10
PC_CC	= cl
E 10
I 10
#PC_CC	= cl
E 10

MV	= mv
D 10
PC_MV	= rename
E 10
I 10
#PC_MV	= rename
E 10

RM	= rm -f
D 10
PC_RM= erase
E 10
I 10
#PC_RM= erase
E 10

LINT_ARGS =
D 10
PC_LINT_ARGS = -DLINT_ARGS
E 10
I 10
#PC_LINT_ARGS = -DLINT_ARGS
E 10

DEBUG_FLAGS = -g
D 10
PC_DEBUG_FLAGS = -Zi -Od
E 10
I 10
#PC_DEBUG_FLAGS = -Zi -Od
E 10

AR	= ar
D 10
C	=
PC_AR	= lib
PC_C	= +
E 10
I 10
AR1	= cr
AR2	=
AR3	=
#PC_AR	= lib
#PC_AR1	=
#PC_AR2	= +
#PC_AR3	= ";"
E 10

RANLIB	= ranlib
D 10
PC_RANLIB = echo "Done with "
E 10
I 10
#PC_RANLIB = echo "Done with "
E 10

E 9
PRINT	= print

I 3
D 9
DEFINES = 
E 9
I 9
DEFINES = ${LINT_ARGS}
E 9

E 3
INCLUDES = -I.

OPTIMIZE = -O
D 9
OPTIMIZE = -g
E 9
I 9
OPTIMIZE = ${DEBUG_FLAGS}
E 9

CFLAGS	= $(OPTIMIZE) $(INCLUDES) $(DEFINES)

# Lint flags
LINTFLAGS	= -hbxaz

I 3
KBD	= 3270pc.kbd
KBD	= unix.kbd


D 4


E 4
E 3
# The source files...
D 3
ALLH =	ascebc.h
E 3
I 3
D 4
ALLH = state.h ascebc.h
E 4
I 4
D 5
ALLH = ascebc.h disp_asc.h state.h
E 5
I 5
D 6
ALLH = astosc.h ascebc.h disp_asc.h state.h
E 6
I 6
D 7
ALLH = astosc.h ascebc.h disp_asc.h map3270.ext state.h termin.ext
E 7
I 7
D 8
ALLH = ascebc.h astosc.h disp_asc.h map3270.ext state.h termin.ext
E 8
I 8
ALLH = map3270.ext state.h termin.ext
E 8
E 7
E 6
E 5
E 4
E 3

D 3
ALLC = asctab.c ebctab.c
E 3
I 3
D 5
ALLC = map3270.c termin.c asctab.c ebctab.c
E 5
I 5
D 7
ALLC = astosc.c map3270.c termin.c asctab.c ebctab.c
E 7
I 7
D 8
ALLC = asctab.c astosc.c ebctab.c map3270.c mset.c termin.c
E 8
I 8
ALLC = map3270.c mset.c termin.c
E 8
E 7
E 5
E 3

I 7
D 9
# We don't include mset.o here...
E 7
D 3
ALLO	= asctab.o ebctab.o
E 3
I 3
D 4
ALLO	= map3270.o termin.o asctab.o ebctab.o
E 4
I 4
D 5
ALLO	= map3270.o termin.o asctab.o ebctab.o disp_asc.o
E 5
I 5
D 8
ALLO	= astosc.o map3270.o termin.o asctab.o ebctab.o disp_asc.o
E 8
I 8
ALLO	= map3270.o termin.o
E 9
I 9
# We don't include mset$O here...
ALLO	= map3270$O termin$O
E 9
E 8
E 5
E 4
E 3

I 6
ALLPRINT = default.map ${ALLH} ${ALLC}

ALLSOURCE =	${ALLPRINT} makefile makefile.mak

E 6
I 3
D 5
M4FILE = termcodes.m4

E 5
E 3
.s.o:
	/lib/cpp -E $< | as -o $@

I 9
.c.obj:
	${CC} ${CFLAGS} -c $<

E 9
D 3
asciilib:	${ALLO}
	ar cr asciilib ${ALLO}
	ranlib asciilib
E 3
I 3
D 8
ascii.lib:	$(ALLO)
	ar cr ascii.lib $(ALLO)
	ranlib ascii.lib
E 8
I 8
asciilib.a:	$(ALLO)
D 9
	ar cr asciilib.a $(ALLO)
	ranlib asciilib.a
E 9
I 9
	${RM} $@
D 10
	for i in ${ALLO}; do (${AR} cr $@ $C $$i); done
E 10
I 10
	for i in ${ALLO}; do (${AR} ${AR1} $@ ${AR2} $$i${AR3}); done
E 10
	${RANLIB} $@
E 9
E 8
E 3

clean:
D 3
	rm -f $(ALLO) errs makefile.bak asciilib
E 3
I 3
D 4
	rm -f $(ALLO) m4.out astosc.out errs makefile.bak ascii.lib
E 4
I 4
D 5
	rm -f $(ALLO) m4.out astosc.out disp_asc.out asc_disp.out \
E 5
I 5
D 8
	rm -f $(ALLO) astosc.out disp_asc.out asc_disp.out \
E 5
				errs makefile.bak ascii.lib
E 8
I 8
D 9
	rm -f $(ALLO) errs makefile.bak asciilib.a
E 9
I 9
	for i in $(ALLO) errs makefile.bak asciilib.a; \
		do (${RM} $$i); done

sccsclean:
E 9
	-sccs clean
	-sccs get makefile
E 8
E 4
E 3

I 6
sourcelist:	${ALLSOURCE}
	@for i in ${ALLSOURCE}; \
D 8
		do (echo ${DIRPATH}/$$i); done
E 8
I 8
		do (echo ${DIRPATH}$$i); done
E 8

E 6
print:
D 3
	${PRINT} ${ALLH}
	${PRINT} ${ALLC}
E 3
I 3
D 6
	${PRINT} ${ALLH} ${ALLC}
E 6
I 6
	${PRINT} ${ALLPRINT}
E 6
E 3

tags:	${ALLC} ${ALLH}
	ctags -t ${ALLC} ${ALLH}

I 2
action:
	${ACTION}

E 2
lint:
D 3
	lint ${LINTFLAGS} ${INCLUDES} ${DEFINES} -DTN3270 $(ALLC)
E 3
I 3
	lint ${LINTFLAGS} ${INCLUDES} ${DEFINES} ${ALLC}
E 3

.DEFAULT:
	sccs get $<

I 3
D 5
astosc.out:	../ctlr/function.h ../ctlr/hostctlr.h ../ctlr/$(KBD) m4.out
E 5
I 5
D 8
astosc.out:	../ctlr/function.h ../ctlr/hostctlr.h ../ctlr/$(KBD)
E 5
	(cd ../tools; make mkastosc $(MFLAGS) )
	-/bin/rm $@
	../tools/mkastosc < ../ctlr/$(KBD) > $@
I 4

asc_disp.out:	../ctlr/ebc_disp.o
	(cd ../tools; make mkastods $(MFLAGS) )
	-/bin/rm $@
	../tools/mkastods > $@

disp_asc.out:	../ctlr/ebc_disp.o
	(cd ../tools; make mkdstoas $(MFLAGS) )
	-/bin/rm $@
	../tools/mkdstoas > $@

disp_asc.o:	disp_asc.h asc_disp.out disp_asc.out
	-/bin/rm $@ TMPfunc.c
	/bin/echo \#include \"disp_asc.h\" > TMPfunc.c
	/bin/echo \#include \"asc_disp.out\" >> TMPfunc.c
	/bin/echo \#include \"disp_asc.out\" >> TMPfunc.c
	$(CC) $(CFLAGS) -c TMPfunc.c
	-/bin/mv TMPfunc.o $@
E 4

E 8
D 5
m4.out:		termcodes.m4
	/bin/rm -f m4.out
	m4 termcodes.m4 > m4.out
	/bin/chmod 444 m4.out

E 5
E 3
depend:
	grep '^#include' ${ALLC} | grep -v '<' | \
	sed -e 's/:[^"]*"\([^"]*\)".*/: \1/' \
D 3
	    -e 's/\.c/.o/' \
	    -e 's,../[a-zA-Z]*/,,' | \
E 3
I 3
D 9
	    -e 's/\.c/.o/' | \
E 9
I 9
	    -e 's/\.c/$$O/' | \
E 9
E 3
	awk ' { if ($$1 != prev) { print rec; rec = $$0; prev = $$1; } \
		else { if (length(rec $$2) > 78) { print rec; rec = $$0; } \
		       else rec = rec " " $$2 } } \
	      END { print rec } ' > makedep
	echo '$$r makedep' >>eddep
	echo '/^# DO NOT DELETE THIS LINE/+1,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
I 9
	-rm -f makefile.bak
E 9
	cp makefile makefile.bak
	ed - makefile < eddep
	rm eddep makedep

# DO NOT DELETE THIS LINE

I 3
D 5
map3270.o: m4.out state.h ../general/globals.h map3270.ext default.map
termin.o: ../general/general.h m4.out state.h ../general/globals.h
termin.o: ../ctlr/function.h ../ctlr/inbound.ext ../ctlr/outbound.ext
termin.o: ../telnet.ext termin.ext astosc.out
E 5
I 5
D 8
astosc.o: ../general/general.h ../ctlr/function.h astosc.h state.h astosc.out
E 8
D 9
map3270.o: state.h ../general/globals.h map3270.ext default.map
I 8
mset.o: ../ctlr/function.h state.h ../apilib/astosc.h ../general/globals.h
mset.o: map3270.ext
E 8
termin.o: ../general/general.h ../ctlr/function.h ../ctlr/inbound.ext
D 8
termin.o: ../ctlr/outbound.ext ../telnet.ext termin.ext astosc.h state.h
termin.o: ../general/globals.h
E 5
E 3
asctab.o: ascebc.h
ebctab.o: ascebc.h
E 8
I 8
termin.o: ../ctlr/outbound.ext ../telnet.ext termin.ext ../apilib/astosc.h
termin.o: state.h ../general/globals.h
E 9
I 9
map3270$O: state.h ../general/globals.h map3270.ext default.map
D 11
mset$O: ../ctlr/function.h state.h ../apilib/astosc.h ../general/globals.h
E 11
I 11
mset$O: ../ctlr/function.h state.h ../api/astosc.h ../general/globals.h
E 11
mset$O: map3270.ext
termin$O: ../general/general.h ../ctlr/function.h ../ctlr/inbound.ext
D 11
termin$O: ../ctlr/outbound.ext ../telnet.ext termin.ext ../apilib/astosc.h
termin$O: state.h ../general/globals.h
E 11
I 11
termin$O: ../ctlr/outbound.ext ../telnet.ext termin.ext ../api/astosc.h state.h
termin$O: ../general/globals.h
E 11
E 9
E 8
E 1
