h16853
s 00010/00005/00076
d D 5.12 88/06/29 19:22:54 bostic 36 35
c install approved copyright notice
e
s 00002/00002/00079
d D 5.11 88/05/05 17:49:42 bostic 35 34
c gprof.{callg,flag} are 444
e
s 00065/00047/00016
d D 5.10 88/01/02 23:26:54 bostic 34 33
c new template; no full pathnames
e
s 00004/00004/00059
d D 5.9 87/06/16 18:26:34 bostic 33 32
c fixed install
e
s 00000/00001/00063
d D 5.8 87/05/31 21:23:16 bostic 32 31
c MACHINE is in make, now
e
s 00002/00000/00062
d D 5.7 87/05/31 21:10:43 bostic 31 30
c added depend label
e
s 00010/00002/00052
d D 5.6 87/05/10 16:18:56 mckusick 30 28
c update for multiple machines
e
s 00006/00001/00053
d R 5.6 87/05/10 16:00:20 mckusick 29 28
c update from Jim McKie
e
s 00001/00001/00053
d D 5.5 87/04/11 15:40:23 mckusick 28 27
c no longer needs to be setgid kmem
e
s 00001/00002/00053
d D 5.4 86/10/21 20:26:34 mckusick 27 26
c use makefile to define MACHINE
e
s 00017/00017/00038
d D 5.3 86/01/07 00:04:54 sam 26 25
c everyone wants to rename calls to callf (or similar), make it just findcall
e
s 00001/00001/00054
d D 5.2 85/06/18 19:46:54 mckusick 25 24
c must install setgid kmem
e
s 00007/00000/00048
d D 5.1 85/06/04 13:32:21 dist 24 23
c Add copyright
e
s 00002/00002/00046
d D 1.22 85/05/03 23:04:09 edward 23 22
c install gprof.flat and gprof.callg with mode 644
e
s 00006/00006/00042
d D 1.21 85/03/26 17:11:30 mckusick 22 21
c clean up those ridiculously long names
e
s 00009/00009/00039
d D 1.20 83/03/31 12:02:08 peter 21 20
c add vax.h as a header.  dependencies are a little strong, but ... .
e
s 00006/00005/00042
d D 1.19 83/03/30 20:32:35 peter 20 19
c changes by richard tuck from sun.
e
s 00004/00004/00043
d D 1.18 83/01/15 13:14:57 peter 19 18
c make the names of the blurb files more reasonable;
c and distribute them less around the code.
e
s 00006/00003/00041
d D 1.17 83/01/11 15:06:06 peter 18 17
c sampling frequency changes from a constant to a variable.
e
s 00001/00001/00043
d D 1.16 82/06/21 00:44:39 mckusick 17 16
c install directory is /usr/ucb
e
s 00005/00005/00039
d D 1.15 82/06/17 11:09:07 peter 16 14
c pr -f doesn't seem to work over the ether.
e
s 00004/00004/00040
d R 1.15 82/06/17 11:07:52 peter 15 14
c pr -f doesn't seem to work over the ether.
e
s 00005/00004/00039
d D 1.14 82/06/14 18:08:53 peter 14 13
c -f and -e flags.
e
s 00007/00000/00036
d D 1.13 82/01/14 12:34:49 peter 13 12
c add `make print' entry.
e
s 00004/00000/00032
d D 1.12 81/12/03 22:25:56 mckusic 12 11
c add clean entry
e
s 00003/00000/00029
d D 1.11 81/11/29 23:39:38 mckusic 11 10
c move gcrt0.h to /usr/src/libc/csu to be with gcrt0.c
e
s 00006/00014/00023
d D 1.10 81/11/23 18:05:32 mckusic 10 9
c get rid of random junk
e
s 00017/00058/00020
d D 1.9 81/11/12 14:49:15 mckusic 9 8
c "gmcrt0" becomes "gcrt0"; eliminate stdio in gcrt0.c
e
s 00002/00002/00076
d D 1.8 81/11/10 13:53:08 peter 8 7
c profiling libraries moved.
e
s 00003/00003/00075
d D 1.7 81/11/09 13:58:14 peter 7 6
c calls.h included in gprof.h to avoid lint.
e
s 00006/00006/00072
d D 1.6 81/11/06 17:23:32 peter 6 5
c cp preserves access rights, too.  get around that.
e
s 00006/00006/00072
d D 1.5 81/11/03 21:44:34 peter 5 4
c linking to things read-only under sccs is a lose for rm.
e
s 00012/00006/00066
d D 1.4 81/11/02 14:32:37 peter 4 3
c gather and use static call graph from a.out file.
e
s 00040/00055/00032
d D 1.3 81/10/20 15:49:24 peter 3 2
c name change to confuse to innocent/
e
s 00002/00001/00085
d D 1.2 81/10/19 14:51:34 peter 2 1
c make sources from sccs directory.
e
s 00086/00000/00000
d D 1.1 81/10/15 14:07:53 peter 1 0
c date and time created 81/10/15 14:07:53 by peter
e
u
U
t
T
I 24
#
D 34
# Copyright (c) 1983 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 34
I 34
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.
E 34
#
D 33
#	%W% (Berkeley) %G%
E 33
I 33
D 34
#	@(#)Makefile	5.8 (Berkeley) 5/31/87
E 34
I 34
# Redistribution and use in source and binary forms are permitted
D 36
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific written prior permission. This software
# is provided ``as is'' without express or implied warranty.
E 36
I 36
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 36
E 34
E 33
#
E 24
I 1
D 26
SCCSID = %W% (Berkeley) %G%
E 26
I 26
D 34
DESTDIR=
DFLAGS= 
CFLAGS=	-O ${DFLAGS}
LINTFLAGS= -x -a -n ${DFLAGS}
E 34
I 34
#	%W% (Berkeley) %G%
#
CFLAGS=	-O
LIBC=	/lib/libc.a
HDRS=	gprof.h ${MACHINE}.h
SRCS=	gprof.c arcs.c dfn.c lookup.c ${MACHINE}.c hertz.c \
	printgprof.c printlist.c
OBJS=	gprof.o arcs.o dfn.o lookup.o ${MACHINE}.o hertz.o \
	printgprof.o printlist.o
E 34
E 26
D 3
RRHBIN = /va/staff/rrh/bin
NCC = ${RRHBIN}/ncc
E 3

D 3
CFLAGS = -DDEBUG
E 3
I 3
D 4
CFLAGS =
E 4
D 26
DFLAGS = 
I 4
D 9
CFLAGS = ${DFLAGS}
E 9
I 9
CFLAGS = -O ${DFLAGS}
D 14
LINTFLAGS = -x -a -n
E 14
I 14
LINTFLAGS = -x -a -n ${DFLAGS}
E 14
E 9
E 4
E 3

E 26
I 12
D 34
RM=	/bin/rm -f
E 12
I 10
D 22
INSTALL=cp
E 22
I 22
INSTALL=install
E 22
I 20
PR=pr
E 20
D 26

E 10
D 3
DPROFHDRS =	dprof.h
DPROFSRCS =	dprof.c arcs.c dfn.c lookup.c printdprof.c
DPROFOBJS =	dprof.o arcs.o dfn.o lookup.o printdprof.o
OTHERS =	mcrt0.s monitor.h monitor.c monitor.ex
E 3
I 3
D 4
GPROFHDRS =	gprof.h
GPROFSRCS =	gprof.c arcs.c dfn.c lookup.c printgprof.c
GPROFOBJS =	gprof.o arcs.o dfn.o lookup.o printgprof.o
E 4
I 4
D 7
GPROFHDRS =	gprof.h calls.h
E 7
I 7
D 21
GPROFHDRS =	gprof.h
E 21
I 21
GPROFHDRS =	gprof.h vax.h
E 21
E 7
D 14
GPROFSRCS =	gprof.c arcs.c dfn.c lookup.c printgprof.c calls.c
GPROFOBJS =	gprof.o arcs.o dfn.o lookup.o printgprof.o calls.o
E 14
I 14
D 18
GPROFSRCS =	gprof.c arcs.c dfn.c lookup.c printgprof.c calls.c printlist.c
GPROFOBJS =	gprof.o arcs.o dfn.o lookup.o printgprof.o calls.o printlist.o
E 18
I 18
GPROFSRCS =	gprof.c arcs.c dfn.c lookup.c calls.c hertz.c \
E 26
I 26
D 27
#MACHINE=	${MACHINE}
MACHINE=	tahoe
E 27
I 27
D 32
MACHINE=	unknown
E 32
E 27
GPROFHDRS=	gprof.h ${MACHINE}.h
GPROFSRCS=	gprof.c arcs.c dfn.c lookup.c ${MACHINE}.c hertz.c \
E 26
		printgprof.c printlist.c
D 26
GPROFOBJS =	gprof.o arcs.o dfn.o lookup.o calls.o hertz.o \
E 26
I 26
GPROFOBJS=	gprof.o arcs.o dfn.o lookup.o ${MACHINE}.o hertz.o \
E 26
		printgprof.o printlist.o
E 34
I 34
all: gprof
E 34
E 18
E 14
E 4
D 9
OTHERS =	gmcrt0.c gmcrt0.h gmcrt0.ex
E 9
I 9
D 10
OTHERS =	gcrt0.c gcrt0.h gcrt0.ex
E 10
E 9
E 3

D 3
dprof: $(DPROFOBJS)
	cc -o dprof ${CFLAGS} $(DPROFOBJS)
E 3
I 3
D 34
gprof: ${GPROFOBJS}
	cc -o gprof ${CFLAGS} ${GPROFOBJS}
E 34
I 34
gprof: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS}
E 34
E 3

D 3
.c.o:
	cc -c ${CFLAGS} $*.c
E 3
I 3
D 9
gmcrt0.o: gmcrt0.s
	as -o gmcrt0.o gmcrt0.s
E 9
I 9
D 10
gcrt0.o: gcrt0.s
	as -o gcrt0.o gcrt0.s
E 10
I 10
D 19
install: gprof flat.blurb callg.blurb
E 19
I 19
D 22
install: gprof gprof.flat.blurb gprof.callg.blurb
E 19
D 17
	${INSTALL} gprof ${DESTDIR}/usr/bin/gprof
E 17
I 17
	${INSTALL} gprof ${DESTDIR}/usr/ucb/gprof
E 17
D 19
	cp flat.blurb ${DESTDIR}/usr/lib/flat.blurb
	cp callg.blurb ${DESTDIR}/usr/lib/callg.blurb
E 19
I 19
	cp gprof.flat.blurb ${DESTDIR}/usr/lib
	cp gprof.callg.blurb ${DESTDIR}/usr/lib
E 22
I 22
D 34
install: gprof gprof.flat gprof.callg
E 34
I 34
gcrt0.h: FRC
	-if [ -r gcrt0.h ] && \
		cmp -s gcrt0.h ../../lib/libc/${MACHINE}/csu/gmon.h; then \
		:; \
	else \
		rm -f gcrt0.h; \
		cp ../../lib/libc/${MACHINE}/csu/gmon.h gcrt0.h; \
	fi

clean: FRC
	rm -f ${OBJS} core gprof

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
E 34
D 25
	install -s gprof ${DESTDIR}/usr/ucb/gprof
E 25
I 25
D 28
	install -s -g kmem -m 2755 gprof ${DESTDIR}/usr/ucb/gprof
E 28
I 28
D 33
	install -s gprof ${DESTDIR}/usr/ucb/gprof
E 28
E 25
D 23
	install -c gprof.flat ${DESTDIR}/usr/lib
	install -c gprof.callg ${DESTDIR}/usr/lib
E 23
I 23
	install -c -m 644 gprof.flat ${DESTDIR}/usr/lib
	install -c -m 644 gprof.callg ${DESTDIR}/usr/lib
E 33
I 33
	install -s -o bin -g bin -m 755 gprof ${DESTDIR}/usr/ucb/gprof
D 35
	install -c -o bin -g bin -m 644 gprof.flat ${DESTDIR}/usr/lib
	install -c -o bin -g bin -m 644 gprof.callg ${DESTDIR}/usr/lib
E 35
I 35
	install -c -o bin -g bin -m 444 gprof.flat ${DESTDIR}/usr/lib
	install -c -o bin -g bin -m 444 gprof.callg ${DESTDIR}/usr/lib
E 35
E 33
E 23
E 22
E 19
I 12

D 34
clean:
	${RM} ${GPROFOBJS} errs gprof
E 34
I 34
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 34
E 12
E 10
E 9
E 3

I 11
D 30
gcrt0.h:
	cp /usr/src/libc/csu/gcrt0.h gcrt0.h
E 30
I 30
D 34
gcrt0.h: FRC
	-if [ -r gcrt0.h ] && \
	   cmp -s gcrt0.h /usr/src/lib/libc/${MACHINE}/csu/gmon.h; then \
	       :; \
	else \
	       rm -f gcrt0.h; \
	       cp /usr/src/lib/libc/${MACHINE}/csu/gmon.h gcrt0.h; \
	fi
E 34
I 34
tags: FRC
	ctags ${SRCS}
E 34

FRC:
E 30

I 13
D 34
print:
D 16
	@ ls -l | pr -f
	@ pr -f makefile
	@ pr -f gcrt0.h
	@ pr -f ${GPROFHDRS} ${GPROFSRCS}
	@ pr -f flat.blurb callg.blurb
E 16
I 16
D 20
	@ ls -l | pr
	@ pr makefile
	@ pr gcrt0.h
	@ pr ${GPROFHDRS} ${GPROFSRCS}
D 19
	@ pr flat.blurb callg.blurb
E 19
I 19
	@ pr gprof.flat.blurb gprof.callg.blurb
E 20
I 20
	@ ls -l | ${PR}
	@ ${PR} makefile
	@ ${PR} gcrt0.h
	@ ${PR} ${GPROFHDRS} ${GPROFSRCS}
D 22
	@ ${PR} gprof.flat.blurb gprof.callg.blurb
E 22
I 22
	@ ${PR} gprof.flat gprof.callg
E 34
I 34
# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.
E 34
E 22
E 20
E 19
E 16

E 13
E 11
D 3
mcrt0.o: mcrt0.s
	as -o mcrt0.o mcrt0.s
	-ld -x -r mcrt0.o
	mv a.out mcrt0.o
E 3
I 3
D 9
gmcrt0.s: gmcrt0.c gmcrt0.h gmcrt0.ex
	cc -S ${DFLAGS} gmcrt0.c
	ex - gmcrt0.s < gmcrt0.ex
	/lib/cpp gmcrt0.s > gmcrt0.S
	mv gmcrt0.S gmcrt0.s
E 9
I 9
D 10
gcrt0.s: gcrt0.c gcrt0.h gcrt0.ex
	cc -S ${DFLAGS} gcrt0.c
	ex - gcrt0.s < gcrt0.ex
	/lib/cpp gcrt0.s > gcrt0.S
	mv gcrt0.S gcrt0.s
E 9
E 3

E 10
D 3
monitor.o: monitor.s
	as -o monitor.o monitor.s
E 3
I 3
D 9
profit: profit.o gmcrt0.o
D 8
	/bin/ld -X gmcrt0.o -o profit profit.o -lcp
E 8
I 8
	/bin/ld -X gmcrt0.o -o profit profit.o -lc_p
E 8
E 3

D 3
monitor.s: monitor.c monitor.ex monitor.h
	cc -S -DMONITOR monitor.c
	ex - monitor.s < monitor.ex
	/lib/cpp monitor.s > monitor.S
	mv monitor.S monitor.s

#
#	NB: -x option to ncc is like -p, but uses
#	different files to load at the beginning of
#	the executable.
#
profit: profit.o monitor.o mcrt0.o
	/bin/ld -X mcrt0.o monitor.o -o profit profit.o -lcp
#	${NCC} -x -p "-?" profit.o -o profit

E 3
profit.o:
D 3
	${NCC} -x -p -c "-?" profit.c
E 3
I 3
	cc -p -c profit.c
E 3

D 3
dprof.o: dprof.c dprof.h
arcs.o: arcs.c dprof.h
lookup.o: lookup.c dprof.h
dfn.o: dfn.c dprof.h
printdprof.o: printdprof.c dprof.h
E 3
I 3
gprof.o: gprof.c gprof.h
arcs.o: arcs.c gprof.h
lookup.o: lookup.c gprof.h
dfn.o: dfn.c gprof.h
printgprof.o: printgprof.c gprof.h
I 4
D 7
calls.o: calls.c calls.h gprof.h
E 7
I 7
calls.o: calls.c gprof.h
E 7
E 4
E 3

D 3
PDPROF = p.dprof.o p.arcs.o p.dfn.o p.lookup.o p.printdprof.o
E 3
I 3
D 4
PGPROF = p.gprof.o p.arcs.o p.dfn.o p.lookup.o p.printgprof.o
E 4
I 4
PGPROF = p.gprof.o p.arcs.o p.dfn.o p.lookup.o p.printgprof.o p.calls.o
E 4
E 3

D 3
p.dprof: ${PDPROF}
	/bin/ld -X mcrt0.o monitor.o -o p.dprof ${PDPROF} -lcp
E 3
I 3
p.gprof: ${PGPROF}
D 8
	/bin/ld -X gmcrt0.o -o p.gprof ${PGPROF} -lcp
E 8
I 8
	/bin/ld -X gmcrt0.o -o p.gprof ${PGPROF} -lc_p
E 8
E 3

D 3
p.dprof.o: dprof.c dprof.h
	ln dprof.c p.dprof.c
	cc -c -p ${CFLAGS} p.dprof.c
	rm p.dprof.c
E 3
I 3
p.gprof.o: gprof.c gprof.h
D 5
	ln gprof.c p.gprof.c
E 5
I 5
D 6
	cp gprof.c p.gprof.c
E 6
I 6
	cat gprof.c > p.gprof.c
E 6
E 5
	cc -c -p ${CFLAGS} p.gprof.c
	rm p.gprof.c
E 3

D 3
p.arcs.o: arcs.c dprof.h
E 3
I 3
p.arcs.o: arcs.c gprof.h
E 3
D 5
	ln arcs.c p.arcs.c
E 5
I 5
D 6
	cp arcs.c p.arcs.c
E 6
I 6
	cat arcs.c > p.arcs.c
E 6
E 5
	cc -c -p ${CFLAGS} p.arcs.c
	rm p.arcs.c

D 3
p.dfn.o: dfn.c dprof.h
E 3
I 3
p.dfn.o: dfn.c gprof.h
E 3
D 5
	ln dfn.c p.dfn.c
E 5
I 5
D 6
	cp dfn.c p.dfn.c
E 6
I 6
	cat dfn.c > p.dfn.c
E 6
E 5
	cc -c -p ${CFLAGS} p.dfn.c
	rm p.dfn.c

D 3
p.lookup.o: lookup.c dprof.h
E 3
I 3
p.lookup.o: lookup.c gprof.h
E 3
D 5
	ln lookup.c p.lookup.c
E 5
I 5
D 6
	cp lookup.c p.lookup.c
E 6
I 6
	cat lookup.c > p.lookup.c
E 6
E 5
	cc -c -p ${CFLAGS} p.lookup.c
	rm p.lookup.c

D 3
p.printdprof.o: printdprof.c dprof.h
	ln printdprof.c p.printdprof.c
	cc -c -p ${CFLAGS} p.printdprof.c
	rm p.printdprof.c
E 3
I 3
p.printgprof.o: printgprof.c gprof.h
D 5
	ln printgprof.c p.printgprof.c
E 5
I 5
D 6
	cp printgprof.c p.printgprof.c
E 6
I 6
	cat printgprof.c > p.printgprof.c
E 6
E 5
	cc -c -p ${CFLAGS} p.printgprof.c
	rm p.printgprof.c
E 3

I 4
D 7
p.calls.o: calls.c calls.h gprof.h
E 7
I 7
p.calls.o: calls.c gprof.h
E 7
D 5
	ln calls.c p.calls.c
E 5
I 5
D 6
	cp calls.c p.calls.c
E 6
I 6
	cat calls.c > p.calls.c
E 6
E 5
	cc -c -p ${CFLAGS} p.calls.c
	rm p.calls.c

E 4
LINTFLAGS = -x -a -n
E 9
D 34
lint:
D 3
	lint ${CFLAGS} ${LINTFLAGS} dprof.c arcs.c dfn.c lookup.c printdprof.c
E 3
I 3
D 4
	lint ${CFLAGS} ${LINTFLAGS} gprof.c arcs.c dfn.c lookup.c printgprof.c
E 4
I 4
D 14
	lint ${CFLAGS} ${LINTFLAGS} ${GPROFSRCS}
E 14
I 14
	lint ${LINTFLAGS} ${DFLAGS} ${GPROFSRCS}
E 34
I 34
gprof.o: gprof.c gprof.h /usr/include/stdio.h /usr/include/sys/types.h
gprof.o: /usr/include/sys/stat.h /usr/include/a.out.h /usr/include/sys/exec.h
gprof.o: gcrt0.h tahoe.h
arcs.o: arcs.c gprof.h /usr/include/stdio.h /usr/include/sys/types.h
arcs.o: /usr/include/sys/stat.h /usr/include/a.out.h /usr/include/sys/exec.h
arcs.o: gcrt0.h tahoe.h
dfn.o: dfn.c /usr/include/stdio.h gprof.h /usr/include/stdio.h
dfn.o: /usr/include/sys/types.h /usr/include/sys/stat.h /usr/include/a.out.h
dfn.o: /usr/include/sys/exec.h gcrt0.h tahoe.h
lookup.o: lookup.c gprof.h /usr/include/stdio.h /usr/include/sys/types.h
lookup.o: /usr/include/sys/stat.h /usr/include/a.out.h /usr/include/sys/exec.h
lookup.o: gcrt0.h tahoe.h
tahoe.o: tahoe.c gprof.h /usr/include/stdio.h /usr/include/sys/types.h
tahoe.o: /usr/include/sys/stat.h /usr/include/a.out.h /usr/include/sys/exec.h
tahoe.o: gcrt0.h tahoe.h
hertz.o: hertz.c /usr/include/sys/time.h /usr/include/time.h
printgprof.o: printgprof.c gprof.h /usr/include/stdio.h
printgprof.o: /usr/include/sys/types.h /usr/include/sys/stat.h
printgprof.o: /usr/include/a.out.h /usr/include/sys/exec.h gcrt0.h tahoe.h
printlist.o: printlist.c gprof.h /usr/include/stdio.h /usr/include/sys/types.h
printlist.o: /usr/include/sys/stat.h /usr/include/a.out.h
printlist.o: /usr/include/sys/exec.h gcrt0.h tahoe.h
E 34
E 14
E 4
E 3
D 10

D 3
${DPROFHDRS} ${DPROFSRCS} ${OTHERS}:
E 3
I 3
${GPROFHDRS} ${GPROFSRCS} ${OTHERS}:
E 3
D 2
	${GET} $@
E 2
I 2
	sccs get $@
E 2

I 2
D 3
sources: ${DPROFHDRS} ${DPROFSRCS} ${OTHERS}
E 3
I 3
sources: ${GPROFHDRS} ${GPROFSRCS} ${OTHERS}
E 10
I 9

I 31
D 34
depend:

E 31
D 21
gprof.o: gprof.c gprof.h gcrt0.h
arcs.o: arcs.c gprof.h gcrt0.h
lookup.o: lookup.c gprof.h gcrt0.h
dfn.o: dfn.c gprof.h gcrt0.h
D 18
printgprof.o: printgprof.c gprof.h gcrt0.h
E 18
calls.o: calls.c gprof.h gcrt0.h
I 18
hertz.o: gprof.h hertz.c
printgprof.o: printgprof.c gprof.h gcrt0.h
E 18
I 14
printlist.o: printlist.c gprof.h gcrt0.h
E 21
I 21
D 26
gprof.o: gprof.c gprof.h vax.h gcrt0.h
arcs.o: arcs.c gprof.h vax.h gcrt0.h
lookup.o: lookup.c gprof.h vax.h gcrt0.h
dfn.o: dfn.c gprof.h vax.h gcrt0.h
calls.o: calls.c gprof.h vax.h gcrt0.h
hertz.o: gprof.h vax.h hertz.c
printgprof.o: printgprof.c gprof.h vax.h gcrt0.h
printlist.o: printlist.c gprof.h vax.h gcrt0.h
E 26
I 26
gprof.o: gprof.c gprof.h ${MACHINE}.h gcrt0.h
arcs.o: arcs.c gprof.h ${MACHINE}.h gcrt0.h
lookup.o: lookup.c gprof.h ${MACHINE}.h gcrt0.h
dfn.o: dfn.c gprof.h ${MACHINE}.h gcrt0.h
${MACHINE}.o: ${MACHINE}.c gprof.h ${MACHINE}.h gcrt0.h
hertz.o: gprof.h ${MACHINE}.h hertz.c
printgprof.o: printgprof.c gprof.h ${MACHINE}.h gcrt0.h
printlist.o: printlist.c gprof.h ${MACHINE}.h gcrt0.h
E 34
I 34
# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 34
E 26
E 21
E 14
E 9
E 3
E 2
E 1
