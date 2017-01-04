h00462
s 00010/00005/00069
d D 5.7 88/06/18 14:39:17 bostic 14 13
c install approved copyright notice
e
s 00009/00003/00065
d D 5.6 88/03/10 16:28:50 bostic 13 12
c add Berkeley specific header, Ken Arnold says written @ Berkeley
e
s 00003/00002/00065
d D 5.5 87/09/21 11:43:51 bostic 12 9
c integrate with dm
e
s 00005/00002/00065
d R 5.5 87/09/19 17:04:15 bostic 11 9
c integrate with dm
e
s 00004/00002/00065
d R 5.5 87/09/19 16:52:22 bostic 10 9
c integrate with dm
e
s 00047/00029/00020
d D 5.4 87/06/03 12:21:53 bostic 9 8
c new template
e
s 00002/00000/00047
d D 5.3 87/05/31 20:58:52 bostic 8 7
c added depend label
e
s 00004/00003/00043
d D 5.2 86/05/15 05:29:49 lepreau 7 4
c DESTDIR, clean junk
e
s 00004/00003/00043
d R 5.2 86/05/15 05:27:10 lepreau 6 4
c DESTDIR
e
s 00005/00003/00043
d R 5.2 86/05/15 05:19:29 lepreau 5 4
c DESTDIR
e
s 00006/00002/00040
d D 5.1 85/05/30 19:48:27 mckusick 4 3
c Add copyright
e
s 00002/00002/00040
d D 1.3 83/09/06 12:53:55 arnold 3 2
c make compilation of test work again
e
s 00021/00022/00021
d D 1.2 83/05/19 12:22:44 arnold 2 1
c add sccs keywords
e
s 00043/00000/00000
d D 1.1 83/05/18 15:50:34 arnold 1 0
c date and time created 83/05/18 15:50:34 by arnold
e
u
U
t
T
I 2
#
D 4
# make file for cribbage
E 4
I 4
D 9
# Copyright (c) 1980 Regents of the University of California.
E 9
I 9
# Copyright (c) 1987 Regents of the University of California.
E 9
D 13
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 13
I 13
# All rights reserved.
E 13
E 4
#
D 4
# %W% (Berkeley) %G%
E 4
I 4
D 9
#	%W% (Berkeley) %G%
E 9
I 9
D 13
#	%W%	(Berkeley)	%G%
E 13
I 13
# Redistribution and use in source and binary forms are permitted
D 14
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 14
I 14
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
E 14
#
#	%W% (Berkeley) %G%
E 13
E 9
#
D 9
# make file for cribbage
E 4
#
E 9
I 9
CFLAGS=	-O
LIBC=	/lib/libc.a
LIBS=	-lcurses -ltermlib
E 9
E 2
I 1
HDRS=	cribbage.h deck.h cribcur.h
I 9
SRCS=	extern.c crib.c support.c cards.c score.c io.c
E 9
D 2
OBJS=	extern.o crib.o support.o cards.o score.o io.o addch.o
CFILES=	extern.c crib.c support.c cards.c score.c io.c addch.c
E 2
I 2
OBJS=	extern.o crib.o support.o cards.o score.o io.o
D 9
CFILES=	extern.c crib.c support.c cards.c score.c io.c
E 9
E 2
D 3
TOBJS=	test.o cards.o score.o io.o
E 3
I 3
TOBJS=	test.o cards.o score.o io.o extern.o
E 3
D 2
CFLAGS=	-g
E 2
I 2
D 9
CFLAGS=	-O
I 7
DESTDIR=
E 9
E 7
E 2

I 2
D 9
cribbage:	${OBJS}
	${CC} ${CFLAGS} -o cribbage ${OBJS} -lcurses -ltermlib

E 9
E 2
all: cribbage crib.instr

D 2
.c.o:
		@echo ${CC} -c ${CFLAGS} $*.c
		@cc -E ${CFLAGS} $*.c | xstr -c -
		@cc -c ${CFLAGS} x.c
		@mv x.o $*.o

cribbage:	${OBJS} xs.o
		${CC} ${CFLAGS} -o cribbage xs.o ${OBJS} -lcurses -ltermlib

xs.o: strings
		xstr
		${CC} -c ${CFLAGS} xs.c

E 2
D 9
crib.o io.o support.o: cribcur.h
E 9
I 9
cribbage: ${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS} ${LIBS}
E 9

D 9
test:		${TOBJS}
D 2
		${CC} ${CFLAGS} -o test ${TOBJS}
E 2
I 2
D 3
	${CC} ${CFLAGS} -o test ${TOBJS}
E 3
I 3
	${CC} ${CFLAGS} -o test ${TOBJS} -lcurses -ltermlib
E 9
I 9
test: ${TOBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${TOBJS} ${LIBS}
E 9
E 3
E 2

crib.instr: cribbage.n macro
D 2
		nroff cribbage.n > crib.instr
E 2
I 2
	nroff cribbage.n > crib.instr
E 2

D 9
tags: ${HDRS} ${CFILES}
D 2
		ctags -u $?
		ed - tags < :ctfix
		sort tags -o tags
E 2
I 2
	ctags -u $?
	ed - tags < :ctfix
	sort tags -o tags
E 9
I 9
clean: FRC
	rm -f ${OBJS} core crib.instr cribbage test
E 9
E 2

I 8
D 9
depend:
E 9
I 9
depend: FRC
	mkdep ${CFLAGS} ${SRCS}
E 9

E 8
D 9
clean:
D 2
		rm -f ${OBJS} ? a.out core crib.instr
E 2
I 2
D 7
	rm -f ${OBJS} ? a.out core crib.instr cribbage
E 7
I 7
	rm -f ${OBJS} ? a.out core crib.instr cribbage errs
E 9
I 9
install: FRC
D 12
	install -s -o bin -g bin -m 755 cribbage ${DESTDIR}/usr/games/cribbage
	install -o bin -g bin -m 644 crib.instr ${DESTDIR}/usr/games/lib/crib.instr
E 12
I 12
	install -o games -g bin -m 400 crib.instr ${DESTDIR}/usr/games/lib/crib.instr
	install -s -o games -g bin -m 4700 cribbage ${DESTDIR}/usr/games/hide
	(cd ${DESTDIR}/usr/games; rm -f cribbage; ln -s dm cribbage; chown games.bin cribbage)
E 12
E 9
E 7
E 2

D 9
crib.o:		deck.h	cribbage.h	cribcur.h
support.o:	deck.h	cribbage.h	cribcur.h
test.o:		deck.h
cards.o:	deck.h
score.o:	deck.h
io.o:		deck.h			cribcur.h
E 9
I 9
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 9
I 2

D 9
install: cribbage crib.instr
D 7
	install -c -s cribbage /usr/games/
	install -c crib.instr /usr/games/lib/
E 7
I 7
	install -s cribbage $(DESTDIR)/usr/games
	install -m 644 crib.instr $(DESTDIR)/usr/games/lib
E 9
I 9
tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

extern.o: extern.c /usr/include/curses.h /usr/include/stdio.h
extern.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
extern.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h deck.h
extern.o: cribbage.h
crib.o: crib.c /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
crib.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
crib.o: /usr/include/sys/ttydev.h /usr/include/signal.h deck.h cribbage.h
crib.o: cribcur.h
support.o: support.c /usr/include/curses.h /usr/include/stdio.h
support.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
support.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h deck.h
support.o: cribbage.h cribcur.h
cards.o: cards.c /usr/include/stdio.h deck.h
score.o: score.c /usr/include/stdio.h deck.h cribbage.h
io.o: io.c /usr/include/curses.h /usr/include/stdio.h /usr/include/sgtty.h
io.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
io.o: /usr/include/sys/ttydev.h /usr/include/ctype.h /usr/include/signal.h
io.o: deck.h cribbage.h cribcur.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 9
E 7
E 2
E 1
