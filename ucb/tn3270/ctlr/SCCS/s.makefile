h03352
s 00013/00000/00145
d D 3.2 88/03/28 12:34:22 bostic 18 17
c add Berkeley specific header
e
s 00000/00000/00145
d D 3.1 87/08/11 10:18:45 minshall 17 16
c New version numbering.
e
s 00001/00001/00144
d D 1.16 87/07/16 10:54:41 minshall 16 15
c Appropriate target for make in tools directory (PC version).
e
s 00009/00006/00136
d D 1.15 87/07/15 15:25:48 minshall 15 14
c New directory structure.
e
s 00003/00002/00139
d D 1.14 87/07/09 10:40:55 minshall 14 13
c add in function.c for 4.2 versions of /bin/cc.
e
s 00023/00017/00118
d D 1.13 87/07/03 15:49:28 minshall 13 12
c Add in PC stuff (including need to change rule for making 'kbd.out').
e
s 00056/00019/00079
d D 1.12 87/06/30 23:53:15 minshall 12 11
c mkmake, etc.
e
s 00015/00014/00083
d D 1.11 87/06/19 15:04:33 minshall 11 10
c New directories, new cleanup.
e
s 00011/00005/00086
d D 1.10 87/06/15 10:45:25 minshall 10 9
c sourcelist target.
e
s 00005/00005/00086
d D 1.9 87/05/24 16:50:00 minshall 9 8
c AcceptKeyboard, and globally known bits for shiftstate 
c (and a 'make depend').
e
s 00002/00001/00089
d D 1.8 87/05/22 15:14:08 minshall 8 7
c Missing oia.h in ALLH.
e
s 00012/00010/00078
d D 1.7 87/05/22 11:18:05 minshall 7 6
c New directory structure.
e
s 00005/00012/00083
d D 1.6 87/05/12 14:03:16 minshall 6 5
c Various changes.
e
s 00003/00000/00092
d D 1.5 87/05/10 11:33:57 minshall 5 4
c ACTION.
e
s 00012/00008/00080
d D 1.4 86/12/19 17:07:37 minshall 4 3
c Seems to work with 'close' then 'open'
e
s 00003/00003/00085
d D 1.3 86/11/16 20:44:01 minshall 3 2
c 1) Complete move of bsubs to ../system.  2) Deal with an 
c inadequacy in msc compiler.
e
s 00007/00017/00081
d D 1.2 86/11/16 15:38:15 minshall 2 1
c bsubs belong in the "system" directory.
e
s 00098/00000/00000
d D 1.1 86/11/16 13:35:37 minshall 1 0
c date and time created 86/11/16 13:35:37 by minshall
e
u
U
t
T
I 18
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
E 18
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

D 12
DEFINES =
E 12
I 12
DEFINES = ${LINT_ARGS}
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
# How to install the bloody thing...
E 4

I 4
# Which keyboard are we emulating.
KBD	= 3180.kbd
KBD	= 3270pc.kbd
KBD	= unix.kbd

E 4
# The source files...
D 8
ALLH =	dctype.h ebc_disp.h hostctlr.h kbdctlr.h options.h screen.h scrnctlr.h
E 8
I 8
D 9
ALLH =	dctype.h ebc_disp.h hostctlr.h kbdctlr.h oia.h options.h \
		screen.h scrnctlr.h
E 9
I 9
D 10
ALLH =	dctype.h ebc_disp.h function.h hostctlr.h oia.h options.h \
	screen.h scrnctlr.h
E 10
I 10
D 11
ALLH =	dctype.h ebc_disp.h function.h hostctlr.h inbound.ext oia.h \
E 11
I 11
D 15
ALLH =	function.h hostctlr.h inbound.ext oia.h \
E 15
I 15
ALLH =	api.h function.h hostctlr.h inbound.ext oia.h \
E 15
E 11
	options.ext options.h outbound.ext screen.h scrnctlr.h
E 10
E 9
E 8

D 3
MOSTC =	dctype.c ebc_disp.c genbsubs.c inbound.c options.c outbound.c
E 3
I 3
D 6
MOSTC =	dctype.c ebc_disp.c inbound.c options.c outbound.c
E 6
I 6
D 11
ALLC =	dctype.c ebc_disp.c inbound.c oia.c options.c outbound.c
E 11
I 11
D 14
ALLC =	inbound.c oia.c options.c outbound.c
E 14
I 14
D 15
ALLC =	function.c inbound.c oia.c options.c outbound.c
E 15
I 15
ALLC =	api.c function.c inbound.c oia.c options.c outbound.c
E 15
E 14
E 11
E 6
E 3

I 14
# Note: NO function.o!
E 14
D 2
#
#	In a vax environment, we use vaxbsubs.s, which gives us a fair amount
#	of increased performance.  We have provided genbsubs.c, which perform
#	(more or less) the same function.
SUBS = vaxbsubs.s
SUBS = genbsubs.c

SUBSO = vaxbsubs.o
SUBSO = genbsubs.o

ALLS = vaxbsubs.s
ALLS =

ALLC = ${MOSTC} ${SUBS}
E 2
D 6
ALLC = ${MOSTC}
I 2
ALLC = ${MOSTC}
E 6
I 6
D 11
ALLO =	dctype.o ebc_disp.o inbound.o oia.o options.o outbound.o
E 11
I 11
D 12
ALLO =	inbound.o oia.o options.o outbound.o
E 12
I 12
D 15
ALLO =	inbound$O oia$O options$O outbound$O
E 15
I 15
ALLO =	api$O inbound$O oia$O options$O outbound$O
E 15
E 12
E 11
E 6
E 2

I 10
ALLPRINT =	3180.kbd 3270pc.kbd unix.kbd ${ALLH} ${ALLC}

ALLSOURCE =	${ALLPRINT} makefile makefile.mak

E 10
D 3
MOSTO =	dctype.o ebc_disp.o genbsubs.o inbound.o options.o outbound.o
E 3
I 3
D 6
MOSTO =	dctype.o ebc_disp.o inbound.o options.o outbound.o
E 3

ALLO	= $(MOSTO)

E 6
.s.o:
	/lib/cpp -E $< | as -o $@

I 12
.c.obj:
	${CC} ${CFLAGS} -c $<

E 12
D 7
ctlrlib:	${ALLO}
	ar cr ctlrlib ${ALLO}
	ranlib ctlrlib
E 7
I 7
D 11
ctlr.lib:	${ALLO}
	ar cr ctlr.lib ${ALLO}
	ranlib ctlr.lib
E 11
I 11
ctlrlib.a:	${ALLO}
D 12
	ar cr ctlrlib.a ${ALLO}
	ranlib ctlrlib.a
E 12
I 12
	${RM} $@
D 13
	for i in ${ALLO}; do (${AR} cr $@ $C $$i); done
E 13
I 13
	for i in ${ALLO}; do (${AR} ${AR1} $@ ${AR2} $$i${AR3}); done
E 13
	${RANLIB} $@
E 12
E 11
E 7

clean:
D 7
	rm -f $(ALLO) mset tn3270 prt3270 m4.out errs makefile.bak ctlrlib
E 7
I 7
D 11
	rm -f $(ALLO) mset tn3270 prt3270 m4.out errs makefile.bak ctlr.lib
E 11
I 11
D 12
	rm -f $(ALLO) mset tn3270 prt3270 m4.out errs makefile.bak ctlrlib.a
E 11
E 7
D 4
	rm -f 3270pc.out
E 4
I 4
	rm -f kbd.out TMPfunc.out TMPfunc.c
E 12
I 12
	for i in $(ALLO) mset tn3270 prt3270 m4.out errs \
D 13
		makefile.bak ctlrlib.a kbd.out TMPfunc.out TMPfunc.c; \
E 13
I 13
		makefile.bak ctlrlib.a kbd.out TMPfunc.out; \
E 13
			do (${RM} $$i); done

sccsclean:
E 12
I 11
	-sccs clean
	-sccs get makefile
E 11
E 4

I 10
sourcelist:	${ALLSOURCE}
	@for i in ${ALLSOURCE}; \
D 11
		do (echo ${DIRPATH}/$$i); done
E 11
I 11
		do (echo ${DIRPATH}$$i); done
E 11

E 10
print:
D 10
	${PRINT} ${ALLH} ${M4FILE} default.map
D 6
	${PRINT} ${MOSTC}
D 2
	${PRINT} ${SUBS} ${MSMAIN} ${TNMAIN} ${PRT3270MAIN}
E 2
I 2
	${PRINT} ${MSMAIN} ${TNMAIN} ${PRT3270MAIN}
E 6
I 6
	${PRINT} ${ALLC}
	${PRINT} ${PRT3270MAIN}
E 10
I 10
	${PRINT} ${ALLPRINT}
E 10
E 6
E 2

tags:	${ALLC} ${ALLH}
	ctags -t ${ALLC} ${ALLH}

I 5
action:
	${ACTION}

E 5
lint:
D 6
	lint ${LINTFLAGS} ${INCLUDES} ${DEFINES} -DTN3270 \
				${TNMAIN} ${MOSTC} -lcurses
	lint ${LINTFLAGS} ${INCLUDES} ${DEFINES} ${MSMAIN} map3270.c -lcurses
E 6
I 6
	lint ${LINTFLAGS} ${INCLUDES} ${DEFINES} -DTN3270 ${ALLC} -lcurses
E 6

.DEFAULT:
	sccs get $<

D 4
3270pc.out:	3270pc.kbd hostctlr.h
E 4
I 4
kbd.out:	$(KBD) hostctlr.h
E 4
D 12
	(cd ../tools; make mkhits $(MFLAGS) )
D 2
	-/bin/rm $@
	../tools/mkhits < 3270pc.kbd > $@
E 2
I 2
D 4
	-/bin/rm $@ function.out TMPfunc.c
E 4
I 4
D 11
	-/bin/rm $@ TMPfunc.out TMPfunc.c
E 11
I 11
	-/bin/rm -f $@ TMPfunc.out TMPfunc.c
E 12
I 12
D 16
	(cd ../tools; make mkhits )
E 16
I 16
	(cd ../tools; make mkhits$X )
E 16
D 13
	${RM} $@ TMPfunc.out TMPfunc.c
E 12
E 11
E 4
	/bin/echo \#include \"function.h\" > TMPfunc.c
D 4
	$(CC) $(CFLAGS) -E TMPfunc.c > function.out
	../tools/mkhits - ../ctlr/function.out < 3270pc.kbd > $@
	-/bin/rm function.out TMPfunc.c
E 4
I 4
	$(CC) $(CFLAGS) -E TMPfunc.c > TMPfunc.out
E 13
I 13
	${RM} $@ TMPfunc.out
D 14
	$(CC) $(CFLAGS) -E function.h > TMPfunc.out
E 14
I 14
	$(CC) $(CFLAGS) -E function.c > TMPfunc.out
E 14
E 13
	../tools/mkhits - ../ctlr/TMPfunc.out < $(KBD) > $@
D 11
	-/bin/rm TMPfunc.out TMPfunc.c
E 11
I 11
D 12
	-/bin/rm -f TMPfunc.out TMPfunc.c
E 12
I 12
D 13
	${RM} TMPfunc.out TMPfunc.c
E 13
I 13
	${RM} TMPfunc.out
E 13
E 12
E 11
E 4
E 2

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

I 15
api$O: api.h ../general/general.h ../api/disp_asc.h screen.h oia.h
api$O: ../general/globals.h
function$O: function.h
E 15
D 11
dctype.o: dctype.h
E 11
D 7
inbound.o: ../general.h function.h hostctlr.h scrnctlr.h screen.h options.h
inbound.o: dctype.h ebc_disp.h ../system/globals.h inbound.ext outbound.ext
D 4
inbound.o: ../telnet.ext 3270pc.out
E 4
I 4
inbound.o: ../telnet.ext kbd.out
E 4
options.o: options.h ../system/globals.h options.ext
outbound.o: hostctlr.h screen.h ebc_disp.h ../system/globals.h options.ext
D 3
outbound.o: ../telnet.ext inbound.ext outbound.ext bsubs.ext
E 3
I 3
outbound.o: ../telnet.ext inbound.ext outbound.ext
E 7
I 7
D 9
inbound.o: ../general/general.h function.h hostctlr.h scrnctlr.h screen.h
E 9
I 9
D 12
inbound.o: ../general/general.h function.h hostctlr.h oia.h scrnctlr.h screen.h
E 9
D 11
inbound.o: options.h dctype.h ebc_disp.h ../general/globals.h inbound.ext
inbound.o: outbound.ext ../telnet.ext kbd.out
E 11
I 11
inbound.o: options.h ../apilib/dctype.h ../apilib/ebc_disp.h
inbound.o: ../general/globals.h inbound.ext outbound.ext ../telnet.ext kbd.out
E 11
D 9
oia.o: oia.h
E 9
I 9
oia.o: ../general/general.h oia.h ../general/globals.h
E 9
options.o: options.h ../general/globals.h options.ext
D 9
outbound.o: ../general/general.h hostctlr.h screen.h ebc_disp.h
E 9
I 9
D 11
outbound.o: ../general/general.h hostctlr.h oia.h screen.h ebc_disp.h
E 11
I 11
outbound.o: ../general/general.h hostctlr.h oia.h screen.h ../apilib/ebc_disp.h
E 11
E 9
outbound.o: ../general/globals.h options.ext ../telnet.ext inbound.ext
outbound.o: outbound.ext ../general/bsubs.ext
E 12
I 12
inbound$O: ../general/general.h function.h hostctlr.h oia.h scrnctlr.h screen.h
D 15
inbound$O: options.h ../apilib/dctype.h ../apilib/ebc_disp.h
inbound$O: ../general/globals.h inbound.ext outbound.ext ../telnet.ext kbd.out
E 15
I 15
inbound$O: options.h ../api/dctype.h ../api/ebc_disp.h ../general/globals.h
inbound$O: inbound.ext outbound.ext ../telnet.ext kbd.out
E 15
oia$O: ../general/general.h oia.h ../general/globals.h
options$O: options.h ../general/globals.h options.ext
D 15
outbound$O: ../general/general.h hostctlr.h oia.h screen.h ../apilib/ebc_disp.h
E 15
I 15
outbound$O: ../general/general.h hostctlr.h oia.h screen.h ../api/ebc_disp.h
E 15
outbound$O: ../general/globals.h options.ext ../telnet.ext inbound.ext
outbound$O: outbound.ext ../general/bsubs.ext
E 12
E 7
E 3
E 1
