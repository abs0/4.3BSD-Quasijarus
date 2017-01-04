h49742
s 00010/00005/00049
d D 5.5 88/06/29 19:17:46 bostic 8 7
c install approved copyright notice
e
s 00010/00004/00044
d D 5.4 88/05/05 14:55:25 bostic 7 6
c add Berkeley specific header
e
s 00035/00020/00013
d D 5.3 87/06/16 18:34:16 bostic 6 5
c new template
e
s 00002/00000/00031
d D 5.2 87/05/31 21:11:53 bostic 5 4
c added depend label
e
s 00006/00001/00025
d D 5.1 85/06/04 15:26:16 dist 4 3
c Add copyright
e
s 00001/00001/00025
d D 4.3 83/11/21 10:10:44 ralph 3 2
c doesn't need curses library
e
s 00001/00002/00025
d D 4.2 83/07/03 16:13:44 sam 2 1
c no more uparm.h
e
s 00027/00000/00000
d D 4.1 83/02/17 21:03:04 sam 1 0
c date and time created 83/02/17 21:03:04 by sam
e
u
U
t
T
I 1
D 2
#	%W%	%G%
E 2
I 2
D 4
#	%M%	%I%	%E%
E 4
I 4
#
D 6
# Copyright (c) 1980 Regents of the University of California.
E 6
I 6
D 7
# Copyright (c) 1987 Regents of the University of California.
E 6
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
E 7
I 7
# Copyright (c) 1988 Regents of the University of California.
# All rights reserved.
E 7
#
D 6
#	%W% (Berkeley) %G%
E 6
I 6
D 7
#	%W%	(Berkeley)	%G%
E 7
I 7
# Redistribution and use in source and binary forms are permitted
D 8
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
#
#	%W% (Berkeley) %G%
E 7
E 6
E 4
E 2
#
CFLAGS=	-O
D 6
DESTDIR=
E 6
I 6
LIBC=	/lib/libc.a
SRCS=	more.c
OBJS=	more.o
E 6

D 6
more:	more.o
D 3
	${CC} -o more more.o -lcurses -ltermcap
E 3
I 3
	${CC} -o more more.o -ltermcap
E 6
I 6
all: more
E 6
E 3

D 6
install: more more.help
	install -s more ${DESTDIR}/usr/ucb/more
E 6
I 6
more:	${OBJS} ${LIBC}
	${CC} -o $@ ${CFLAGS} ${OBJS} -ltermcap

clean: FRC
	rm -f ${OBJS} core more

depend: FRC
	mkdep ${CFLAGS} ${SRCS}

install: FRC
	install -s -o bin -g bin -m 755 more ${DESTDIR}/usr/ucb/more
E 6
	rm -f ${DESTDIR}/usr/ucb/page
	ln ${DESTDIR}/usr/ucb/more ${DESTDIR}/usr/ucb/page
D 6
	install -c more.help ${DESTDIR}/usr/lib/more.help
E 6
I 6
	install -c -o bin -g bin -m 644 more.help ${DESTDIR}/usr/lib/more.help
E 6

D 6
more.o:	more.c
more.o:	/usr/include/stdio.h
more.o:	/usr/include/ctype.h
more.o:	/usr/include/signal.h
more.o:	/usr/include/errno.h
more.o:	/usr/include/sgtty.h
more.o:	/usr/include/setjmp.h
more.o:	/usr/include/sys/types.h
more.o:	/usr/include/sys/stat.h
E 6
I 6
lint: FRC
	lint ${CFLAGS} ${SRCS}
E 6
D 2
more.o:	/usr/include/local/uparm.h
E 2

D 6
clean:
	rm -f more more.o core a.out errs
E 6
I 6
tags: FRC
	ctags ${SRCS}
E 6
I 5

D 6
depend:
E 6
I 6
FRC:

# DO NOT DELETE THIS LINE -- mkdep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

more.o: more.c /usr/include/stdio.h /usr/include/sys/types.h
more.o: /usr/include/ctype.h /usr/include/signal.h /usr/include/errno.h
more.o: /usr/include/sgtty.h /usr/include/sys/ioctl.h
more.o: /usr/include/sys/ttychars.h /usr/include/sys/ttydev.h
more.o: /usr/include/setjmp.h /usr/include/sys/stat.h /usr/include/sys/file.h
more.o: /usr/include/sys/exec.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
E 6
E 5
E 1
