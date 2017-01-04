h44224
s 00010/00005/00046
d D 5.8 88/06/29 18:54:53 bostic 10 9
c install approved copyright notice
e
s 00017/00011/00034
d D 5.7 88/05/05 18:05:14 bostic 9 8
c add Berkeley specific header, minor cleanup
e
s 00035/00011/00010
d D 5.6 87/06/16 19:03:44 bostic 8 7
c new template
e
s 00002/00000/00019
d D 5.5 87/05/31 21:15:09 bostic 7 6
c added depend label
e
s 00001/00001/00018
d D 5.4 86/04/28 08:28:52 lepreau 6 5
c depends on tset.delays.h
e
s 00005/00001/00014
d D 5.3 85/11/05 15:58:52 bloom 5 4
c link reset and tset
e
s 00001/00001/00014
d D 5.2 85/08/05 11:45:58 bloom 4 2
c install should depend upon binary
e
s 00001/00001/00014
d R 5.2 85/07/24 10:17:11 bloom 3 2
c should define UCB_NTTY for compilation
e
s 00007/00000/00008
d D 5.1 85/06/06 09:25:46 dist 2 1
c Add copyright
e
s 00008/00000/00000
d D 1.1 81/11/22 16:52:45 root 1 0
c date and time created 81/11/22 16:52:45 by root
e
u
U
t
T
I 2
#
D 8
# Copyright (c) 1980 Regents of the University of California.
E 8
I 8
# Copyright (c) 1987 Regents of the University of California.
E 8
D 9
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 9
I 9
# All rights reserved.
E 9
#
D 8
#	%W% (Berkeley) %G%
E 8
I 8
D 9
#	%W%	(Berkeley)	%G%
E 9
I 9
# Redistribution and use in source and binary forms are permitted
D 10
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
E 8
#
I 9
#	%W% (Berkeley) %G%
#
E 9
E 2
I 1
D 8
DESTDIR=
CFLAGS=-O
D 6
tset:	tset.c
E 6
I 6
tset:	tset.c tset.delays.h
E 6
	${CC} ${CFLAGS} tset.c -o tset -ltermlib
E 8
I 8
CFLAGS=	-O
LIBC=	/lib/libc.a
SRCS=	tset.c
D 9
OBJS=	tset.o
E 9
E 8
I 5

E 5
D 4
install:
E 4
I 4
D 8
install: tset
E 4
	install -s tset ${DESTDIR}/usr/ucb
E 8
I 8
all: tset

D 9
tset:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS} -ltermlib
E 9
I 9
tset: ${SRCS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${SRCS} -ltermlib
E 9

clean: FRC
	rm -f ${OBJS} core tset

depend: FRC
D 9
	mkdep ${CFLAGS} ${SRCS}
E 9
I 9
	mkdep -p ${CFLAGS} ${SRCS}
E 9

install: FRC
	install -s -o bin -g bin -m 755 tset ${DESTDIR}/usr/ucb/tset
E 8
I 5
	rm -f ${DESTDIR}/usr/ucb/reset
	ln ${DESTDIR}/usr/ucb/tset ${DESTDIR}/usr/ucb/reset

E 5
D 8
clean:
D 5
	rm -f *.o tset
E 5
I 5
	rm -f *.o tset reset
E 8
I 8
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 8
I 7

D 8
depend:
E 8
I 8
tags: FRC
	ctags ${SRCS}

FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

D 9
tset.o: tset.c /usr/include/ttyent.h /usr/include/sgtty.h
tset.o: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
tset.o: /usr/include/sys/ttydev.h /usr/include/stdio.h /usr/include/signal.h
tset.o:tset.delays.h
E 9
I 9
tset: tset.c /usr/include/ttyent.h /usr/include/sgtty.h
tset: /usr/include/sys/ioctl.h /usr/include/sys/ttychars.h
tset: /usr/include/sys/ttydefaults.h /usr/include/sys/ttydev.h
tset: /usr/include/stdio.h /usr/include/signal.h /usr/include/machine/trap.h
tset: tset.delays.h
E 9

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 8
E 7
E 5
E 1
