h24699
s 00044/00022/00011
d D 5.3 87/12/01 20:35:16 bostic 5 3
c new template
e
s 00044/00022/00011
d R 5.3 87/06/16 19:08:14 bostic 4 3
c new template
e
s 00002/00000/00031
d D 5.2 87/05/31 21:15:38 bostic 3 2
c added depend label
e
s 00006/00001/00025
d D 5.1 85/06/06 09:27:48 dist 2 1
c Add copyright
e
s 00026/00000/00000
d D 4.1 82/10/19 00:52:09 mckusick 1 0
c date and time created 82/10/19 00:52:09 by mckusick
e
u
U
t
T
I 1
D 2
#	%W%	(Berkeley)	%G%
E 2
I 2
#
D 5
# Copyright (c) 1980 Regents of the University of California.
E 5
I 5
# Copyright (c) 1987 Regents of the University of California.
E 5
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
D 5
#	%W% (Berkeley) %G%
E 5
I 5
#	%W%	(Berkeley)	%G%
E 5
E 2
#
D 5
DESTDIR=
CFLAGS=-O 
SOURCES=vfontedpr.c vgrindefs.c regexp.c retest.c
CMDS=vfontedpr retest
OBJS=retest.o regexp.o vfontedpr.o vgrindefs.o
E 5
I 5
CFLAGS=	-O
LIBC=	/lib/libc.a
RSRCS=	retest.c regexp.c
ROBJS=	retest.o regexp.o
VSRCS=	regexp.c vfontedpr.c vgrindefs.c
VOBJS=	regexp.o vfontedpr.o vgrindefs.o
E 5

D 5
all:	$(CMDS) ${OBJS}
E 5
I 5
all: retest vfontedpr
E 5

D 5
vfontedpr: vfontedpr.o vgrindefs.o regexp.o
	cc ${CFLAGS} -o vfontedpr vfontedpr.o vgrindefs.o regexp.o
retest: retest.o regexp.o
	cc ${CFLAGS} -o retest retest.c regexp.o
E 5
I 5
vfontedpr: ${VOBJS} ${LIBC}
	${CC} ${CFLAGS} -o $@ ${VOBJS}
E 5

D 5
install: all
	install -s vfontedpr ${DESTDIR}/usr/lib/vfontedpr
	install -c vgrind.sh ${DESTDIR}/usr/ucb/vgrind
	install -c vgrindefs.src ${DESTDIR}/usr/lib/vgrindefs
	install -c tmac.vgrind ${DESTDIR}/usr/lib/tmac/tmac.vgrind
E 5
I 5
retest: ${ROBJS} ${LIBC}
	${CC} ${CFLAGS} -o $@ ${ROBJS}
E 5

D 5
clean:
	rm -f ${CMDS} ${OBJS}
E 5
I 5
clean: FRC
	rm -f ${OBJS} ${ROBJS} ${VOBJS} core retest vfontedpr
E 5

I 3
D 5
depend:
E 5
I 5
depend: FRC
	mkdep ${CFLAGS} ${RSRCS} ${VSRCS}
E 5

E 3
D 5
vprintall:
	csh /usr/ucb/vprint ${SOURCES}
E 5
I 5
install: FRC
	install -s -o bin -g bin -m 755 vfontedpr ${DESTDIR}/usr/lib/vfontedpr
	install -c -o bin -g bin -m 755 vgrind.sh ${DESTDIR}/usr/ucb/vgrind
	install -c -o bin -g bin -m 755 vgrindefs.src ${DESTDIR}/usr/lib/vgrindefs
	install -c -o bin -g bin -m 755 tmac.vgrind ${DESTDIR}/usr/lib/tmac/tmac.vgrind

lint: FRC
	lint ${CFLAGS} ${RSRCS}
	lint ${CFLAGS} ${VSRCS}

tags: FRC
	ctags ${RSRCS}
	ctags -a ${VSRCS}
	sort -o tags tags

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

retest.o: retest.c /usr/include/ctype.h
regexp.o: regexp.c /usr/include/ctype.h regexp.c /usr/include/ctype.h
vfontedpr.o: vfontedpr.c /usr/include/ctype.h /usr/include/stdio.h
vfontedpr.o: /usr/include/sys/types.h /usr/include/sys/stat.h
vgrindefs.o: vgrindefs.c /usr/include/ctype.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 5
E 1
