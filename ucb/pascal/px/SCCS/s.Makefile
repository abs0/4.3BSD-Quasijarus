h37312
s 00003/00003/00115
d D 5.5 88/01/03 00:19:10 bostic 27 26
c don't use full path names
e
s 00001/00004/00117
d D 5.4 87/10/27 07:46:24 bostic 26 22
c fix depend label
e
s 00022/00043/00077
d R 5.6 87/10/26 08:18:43 bostic 25 24
c fix depend label
e
s 00001/00001/00119
d R 5.5 87/10/26 07:52:45 bostic 24 23
c don't use bin/grep, it's not there
e
s 00000/00001/00120
d R 5.4 87/10/26 07:40:03 bostic 23 22
c MACHINE defined by make(1), now
e
s 00004/00003/00117
d D 5.3 87/05/10 16:22:56 mckusick 22 21
c update for machine independence
e
s 00001/00001/00119
d D 5.2 85/09/07 15:44:30 mckusick 21 20
c strip on install
e
s 00007/00000/00113
d D 5.1 85/06/05 14:20:46 dist 20 19
c Add copyright
e
s 00000/00000/00113
d D 2.1 84/02/08 20:29:37 aoki 19 18
c synchronize to version 2
e
s 00036/00030/00077
d D 1.17 83/02/03 13:14:32 mckusick 18 17
c mods to use ../src
e
s 00009/00008/00098
d D 1.16 83/01/22 01:17:17 mckusick 17 16
c makefile becomes Makefile
e
s 00002/00002/00104
d D 1.15 82/10/13 17:54:12 mckusick 16 15
c move home from cmd to ucb
e
s 00006/00006/00100
d D 1.14 82/09/09 21:52:29 peter 15 14
c `make' should make px, not sources.
e
s 00000/00001/00106
d D 1.13 82/08/29 16:32:50 mckusick 14 13
c get rid of header file in utilities.c
e
s 00002/00002/00105
d D 1.12 82/08/03 17:37:47 mckusick 13 12
c fix-up to clean directive
e
s 00002/00002/00105
d D 1.11 82/02/11 10:55:37 mckusic 12 10
c fix up dependancies, and locations of sources
e
s 00002/00002/00105
d R 1.11 82/02/03 00:39:39 mckusic 11 10
c use -lnm instead of -lm
e
s 00005/00012/00102
d D 1.10 82/02/03 00:00:38 mckusic 10 9
c get rid of panics, so that all signals and errors pass through ERROR()
e
s 00002/00003/00112
d D 1.9 81/06/10 01:45:13 mckusic 9 8
c change over to new error message format
e
s 00006/00007/00109
d D 1.8 81/04/05 16:24:16 mckusic 8 7
c fix def of DESTDIR
e
s 00016/00006/00100
d D 1.7 81/03/18 23:50:29 mckusic 7 6
c fix up vgrind command
e
s 00003/00003/00103
d D 1.6 81/03/06 23:01:42 mckusic 6 5
c add onyx code
e
s 00003/00002/00103
d D 1.5 81/02/04 15:40:31 mckusic 5 4
c align O_RV, run pc2 after /lib/c2
e
s 00003/00002/00102
d D 1.4 81/01/24 15:08:39 mckusic 4 3
c change "movd" instructions to "movq" to avoid `normalizing' records
e
s 00005/00004/00099
d D 1.3 81/01/16 18:56:02 mckusic 3 2
c Update FOR*, add runtime tests
e
s 00029/00024/00074
d D 1.2 81/01/10 18:25:06 mckusic 2 1
c add "ap" and "fp" notion, fix SUCC and PRED
e
s 00098/00000/00000
d D 1.1 81/01/07 16:55:48 mckusick 1 0
c date and time created 81/01/07 16:55:48 by mckusick
e
u
U
t
T
I 20
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
E 20
I 1
SCCSID = "%Z%%M% %I% %G%"

D 2
CFLAGS = -O -DVAX -DOBJ
E 2
I 2
D 18
CFLAGS = -O
E 18
D 3
DEFS = -DVAX -DOBJ
E 3
I 3
D 4
DEFS = -DVAX -DOBJ -DDEBUG
E 4
I 4
D 6
DEFS = -DVAX -DOBJ
E 6
I 6
D 8
DEFS =
I 7
SRCDIR =/usr/ucb
E 7
E 6
E 4
E 3
E 2
DESTDIR =/usr/ucb
LIBDIR =/usr/lib
E 8
I 8
DESTDIR =
D 18
SRCDIR = /usr/ucb
E 18
I 18
BINDIR = /usr/ucb
E 18
LIBDIR = /usr/lib
E 8
D 16
PASCALDIR = /usr/src/cmd/pascal
LIBPCDIR = /usr/src/lib/libpc
E 16
I 16
D 18
PASCALDIR = /usr/src/ucb/pascal
E 18
I 18
SRCDIR = ../src
E 18
D 27
LIBPCDIR = /usr/src/usr.lib/libpc
E 27
I 27
LIBPCDIR = ../../../usr.lib/libpc
E 27
E 16
CC = cc
I 18
CFLAGS = -O -I${SRCDIR} -I${LIBPCDIR}
E 18
I 4
OPT = /lib/c2
E 4
AS = as
RM = rm -f
I 22
D 26
MACHINE = unknown
E 26
E 22

D 2
PXHDR =	${PASCALDIR}/OPnames.h ${PASCALDIR}/objfmt.h\
	${LIBPCDIR}/libpc.h ${LIBPCDIR}/h01errs.h\
	newvars.h machdep.h
E 2
I 2
D 6
PSHDR =	OPnames.h objfmt.h opc.c pic.c
E 6
I 6
D 18
PSHDR =	OPnames.h whoami.h objfmt.h opc.c pic.c
E 6
D 9
PCHDR =	libpc.h h01errs.h
E 9
I 9
PCHDR =	libpc.h
E 18
I 18
PSHDR =	opc.c pic.c
E 18
E 9
E 2

I 2
PXHDR =	vars.h machdep.h

E 2
D 10
PXSRC =	int.c interp.c except.c utilities.c
E 10
I 10
PXSRC =	int.c interp.c utilities.c
E 10

D 10
PXOBJ =	int.o interp.o except.o utilities.o
E 10
I 10
PXOBJ =	int.o interp.o utilities.o
E 10

D 2
PXUTL =	${PASCALDIR}/opc.c ${PASCALDIR}/pic.c ${PASCALDIR}/version.c\
	make.ed1 panics interp.sed clean.sed
E 2
I 2
D 10
PXUTL =	make.ed1 panics interp.sed clean.sed version.c
E 10
I 10
D 22
PXUTL =	interp.sed clean.sed version.c
E 22
I 22
PXUTL =	${MACHINE}.sed clean.sed version.c
E 22
E 10
E 2

D 15
sources: ${PXHDR} ${PXSRC} ${PXUTL}
D 2
${PXHDR} ${PXUTL}:
	cp $@ .
E 2
I 2
${PSHDR}:
	cp ${PASCALDIR}/$@ $@
${PCHDR}:
	cp ${LIBPCDIR}/$@ $@
E 2

E 15
I 2
.c.o:
D 8
	${CC} ${CFLAGS} ${DEFS} -c $*.c
E 8
I 8
	${CC} ${CFLAGS} -c $*.c
E 8

E 2
px: Version.c ${PXOBJ}
D 2
	${CC} -O -o px Version.c ${PXOBJ} /usr/src/lib/libpc/pclib -lm
Version.c: ${PASCALDIR}/version.c
	${CC} -o version ${PASCALDIR}/version.c
E 2
I 2
D 3
	${CC} ${CFLAGS} -o px Version.c ${PXOBJ} /usr/src/lib/libpc/libpc -lm
E 3
I 3
D 6
	${CC} ${CFLAGS} -o px Version.c ${PXOBJ} -lpc -lnm
E 6
I 6
	${CC} ${CFLAGS} -o px Version.c ${PXOBJ} -lpc -lm
E 6
E 3
Version.c: version.c
	${CC} ${CFLAGS} -o version version.c
E 2
	./version >Version.c
	${RM}  version
D 17
interp.o interp.s: interp.c
E 17
I 17
D 22
interp.o interp.s: interp.c interp.sed
E 22
I 22
interp.o interp.s: interp.c ${MACHINE}.sed
E 22
E 17
D 2
	${CC} -S interp.c
E 2
I 2
D 8
	${CC} ${DEFS} -S interp.c
E 8
I 8
D 18
	${CC} -S interp.c
E 18
I 18
	${CC} -S -I${SRCDIR} -I${LIBPCDIR} interp.c
E 18
E 8
E 2
D 22
	sed -f interp.sed <interp.s >tmp
E 22
I 22
	sed -f ${MACHINE}.sed <interp.s >tmp
E 22
I 2
D 5
	/usr/lib/pc2 <tmp >interp.s
D 4
	/lib/c2 interp.s tmp
E 4
I 4
	${OPT} interp.s tmp
E 5
I 5
	${OPT} tmp interp.s
	/usr/lib/pc2 <interp.s >tmp
E 5
E 4
E 2
	mv tmp interp.s
	as -o interp.o interp.s
D 10
panics.h: panics make.ed1
	ex - <make.ed1
E 10
D 2
h02opcs.h: ${PASCALDIR}/OPnames.h ${PASCALDIR}/opc.c
	${CC} ${PASCALDIR}/opc.c -o opc
E 2
I 2
D 18
h02opcs.h: OPnames.h opc.c
E 18
I 18
h02opcs.h: ${SRCDIR}/OPnames.h opc.c
E 18
	${CC} ${CFLAGS} opc.c -o opc
E 2
	./opc >h02opcs.h
	${RM} opc

install: px
D 8
	cp px ${DESTDIR}/px
E 8
I 8
D 18
	cp px ${DESTDIR}/usr/ucb/px
E 18
I 18
D 21
	install px ${DESTDIR}/usr/ucb/px
E 21
I 21
	install -s px ${DESTDIR}/usr/ucb/px
E 21
E 18
I 15

sources: ${PXHDR} ${PXSRC} ${PXUTL}
${PSHDR}:
D 18
	cp ${PASCALDIR}/$@ $@
${PCHDR}:
	cp ${LIBPCDIR}/$@ $@
E 18
I 18
	ln -s ${SRCDIR}/$@ $@
E 18
E 15
E 8

clean:
D 3
	${RM}  *.o *.s px version.* opc* pic* OPnames.h objfmt.h libpc.h\
		panics.h h02opcs.h errs lpr core tmp
E 3
I 3
D 13
	${RM}  *.o *.s px version opc* pic* OPnames.h objfmt.h libpc.h\
D 9
		panics.h h01errs.h h02opcs.h errs lpr core tmp
E 9
I 9
D 10
		panics.h h02opcs.h errs lpr core tmp
E 10
I 10
		h02opcs.h errs lpr core tmp
E 13
I 13
	${RM} *.o *.s px version opc* pic*
D 18
	${RM} OPnames.h objfmt.h libpc.h h02opcs.h errs lpr core tmp
E 18
I 18
	${RM} h02opcs.h errs lpr core tmp
E 18
E 13
E 10
E 9
E 3

prt: interp.s
	sed -f clean.sed <interp.s

D 12
grind: sources
E 12
I 12
D 18
grind: sources ${PSHDR} ${PCHDR}
E 12
D 7
	@vpr READ_ME makefile
D 2
	@${CC} -o pic pic.c
E 2
I 2
	@${CC} ${CFLAGS} -o pic pic.c
E 2
	@./pic | vpr
D 2
	@/usr/ucb/vgrind newvars.h objfmt.h machdep.h
E 2
I 2
	@/usr/ucb/vgrind vars.h objfmt.h machdep.h
E 2
	@/usr/ucb/vgrind ${PXSRC}
	@${RM} pic*
E 7
I 7
	${SRCDIR}/ctags -v *.h *.c *.s | sort -f >index
	${SRCDIR}/vgrind -t -x index >lpr
E 18
I 18
grind: sources
	${BINDIR}/ctags -v *.h *.c *.s | sort -f >index
	${BINDIR}/vgrind -t -x index >lpr
E 18
	${CC} ${CFLAGS} -o pic pic.c
D 17
	${SRCDIR}/vgrind -t -n READ_ME makefile lst >>lpr
E 17
I 17
D 18
	${SRCDIR}/vgrind -t -n READ_ME Makefile lst >>lpr
E 17
D 10
	${SRCDIR}/vgrind -t ${PCHDR} ${PXHDR} objfmt.h panics.h whoami.h >>lpr
E 10
I 10
	${SRCDIR}/vgrind -t ${PCHDR} ${PXHDR} objfmt.h whoami.h >>lpr
E 10
	${SRCDIR}/vgrind -t ${PXSRC} >>lpr
E 18
I 18
	${BINDIR}/vgrind -t -n READ_ME Makefile lst >>lpr
	${BINDIR}/vgrind -t ${PXSRC} >>lpr
E 18
	./pic >lst
D 18
	${SRCDIR}/vpr lst
	${SRCDIR}/vpr -t lpr
E 18
I 18
	${BINDIR}/vpr lst
	${BINDIR}/vpr -t lpr
E 18
	${RM} index pic lst
E 7

depend:	sources
D 18
	/bin/grep '^#[ 	]*include' *.c \
		| sed '/<.*>/d' \
		| sed 's/:[^"]*"\([^"]*\)".*/: \1/' \
		| sed 's/\.c/.o/' >makedep
E 18
I 18
	ls *.c | sed 's;^\(.*\)\.c;\1.o: \1.c;' >makedep
D 26
	/bin/grep '^#[ 	]*include' *.c | sed \
E 26
I 26
	grep '^#[ 	]*include' *.c | sed \
E 26
		-e '/<.*>/d' \
		-e 's;:[^"]*"\([^"]*\)".*;: \1;' \
		-e 's/\.c/\.o/' \
		-e 's;: libpc.h;: ${LIBPCDIR}/libpc.h;' \
		-e 's;: objfmt.h;: ${SRCDIR}/objfmt.h;' \
		-e 's;: OPnames.h;: ${SRCDIR}/OPnames.h;' >>makedep
E 18
	echo '/^# DO NOT DELETE THIS LINE/+2,$$d' >eddep
	echo '$$r makedep' >>eddep
	echo 'w' >>eddep
D 17
	cp makefile makefile.bak
	ed - makefile < eddep
E 17
I 17
	cp Makefile Makefile.bak
	ed - Makefile < eddep
E 17
	rm eddep makedep
D 17
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> makefile
	echo '# see make depend above' >> makefile
E 17
I 17
	echo '# DEPENDENCIES MUST END AT END OF FILE' >> Makefile
	echo '# IF YOU PUT STUFF HERE IT WILL GO AWAY' >> Makefile
	echo '# see make depend above' >> Makefile
E 17

# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
I 18
Version.o: Version.c
int.o: int.c
interp.o: interp.c
D 26
opc.o: opc.c
E 26
utilities.o: utilities.c
version.o: version.c
E 18
I 7
D 10
except.o: whoami.h
E 7
except.o: panics.h
D 2
int.o: newvars.h
E 2
I 2
except.o: vars.h
E 10
I 7
int.o: whoami.h
E 7
int.o: vars.h
I 12
D 18
int.o: libpc.h
E 12
E 2
int.o: objfmt.h
E 18
I 18
D 27
int.o: /usr/src/usr.lib/libpc/libpc.h
E 27
I 27
int.o: ../../../usr.lib/libpc/libpc.h
E 27
int.o: ../src/objfmt.h
E 18
I 7
interp.o: whoami.h
D 17
interp.o: objfmt.h
E 17
E 7
D 2
interp.o: newvars.h
E 2
I 2
interp.o: vars.h
I 17
D 18
interp.o: objfmt.h
E 18
I 18
interp.o: ../src/objfmt.h
E 18
E 17
E 2
D 10
interp.o: panics.h
E 10
interp.o: h02opcs.h
interp.o: machdep.h
I 2
D 9
interp.o: h01errs.h
E 9
E 2
D 18
interp.o: libpc.h
I 3
opc.o: OPnames.h
E 18
I 18
D 27
interp.o: /usr/src/usr.lib/libpc/libpc.h
E 27
I 27
interp.o: ../../../usr.lib/libpc/libpc.h
E 27
D 26
opc.o: ../src/OPnames.h
E 26
E 18
I 5
D 12
pic.o: OPnames.h
E 12
I 7
utilities.o: whoami.h
E 7
E 5
E 3
D 2
opc.o: OPnames.h
panic.o: newvars.h
panic.o: panics.h
pic.o: OPnames.h
stats.o: newvars.h
utilities.o: newvars.h
E 2
I 2
utilities.o: vars.h
I 17
D 18
utilities.o: objfmt.h
E 18
I 18
utilities.o: ../src/objfmt.h
E 18
E 17
E 2
D 10
utilities.o: panics.h
E 10
D 14
utilities.o: h02opcs.h
E 14
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
E 1
